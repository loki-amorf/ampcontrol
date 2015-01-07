#include "ds1307.h"

#include "i2c.h"
#include "audio/audio.h"

static int8_t time[8];
static int8_t alarm[4];

static uint8_t _etm = NOEDIT;	/* Edit time mode */
static uint8_t _eam = NOEDIT;	/* Edit alarm mode */

int8_t getTime(uint8_t tm)
{
	return time[tm];
}

int8_t getAlarm(uint8_t am)
{
	return alarm[am - DS1307_A0_HOUR];
}

uint8_t getEtm(void)
{
	return _etm;
}

uint8_t getEam(void)
{
	return _eam;
}

static void calcWeekDay(void)
{
	uint8_t a, y, m;

	a = (time[DS1307_MONTH] > 2 ? 0 : 1);
	y = 12 + time[DS1307_YEAR] - a;
	m = time[DS1307_MONTH] + 12 * a - 2;

	time[DS1307_WDAY] = (time[DS1307_DATE] + y + (y / 4) + ((31 * m) / 12)) % 7;
	if (time[DS1307_WDAY] == 0)
		time[DS1307_WDAY] = 7;

	return;
}

static uint8_t daysInMonth()
{
	if (time[DS1307_MONTH] == 2) {
		if (time[DS1307_YEAR] & 0x03)
			return 28;
		return 29;
	}

	if (time[DS1307_MONTH] == 4 || time[DS1307_MONTH] == 6 || time[DS1307_MONTH] == 9 || time[DS1307_MONTH] == 11) {
		return 30;
	}

	return 31;
}

int8_t *readTime(void)
{
	uint8_t temp;
	uint8_t i;

	I2CStart(DS1307_ADDR);
	I2CWriteByte(DS1307_SEC);
	I2CStart(DS1307_ADDR | I2C_READ);
	for (i = DS1307_SEC; i < DS1307_YEAR; i++) {
		I2CReadByte(&temp, I2C_ACK);
		time[i] = BD2D(temp);
	}
	I2CReadByte(&temp, I2C_NOACK);
	time[DS1307_YEAR] = BD2D(temp);
	I2CStop();

	return time;
}

int8_t *readAlarm(void)
{
	uint8_t temp;
	uint8_t i;

	I2CStart(DS1307_ADDR);
	I2CWriteByte(DS1307_A0_HOUR);
	I2CStart(DS1307_ADDR | I2C_READ);
	for (i = DS1307_A0_HOUR; i < DS1307_A0_WDAY; i++) {
		I2CReadByte(&temp, I2C_ACK);
		alarm[i - DS1307_A0_HOUR] = temp;
	}
	I2CReadByte(&temp, I2C_NOACK);
	alarm[DS1307_A0_WDAY - DS1307_A0_HOUR] = temp;
	I2CStop();

	return alarm;
}

static void writeTime(void)
{
	uint8_t i;

	if (time[DS1307_DATE] > daysInMonth())
		time[DS1307_DATE] = daysInMonth();
	if (_etm >= DS1307_DATE)
		calcWeekDay();

	I2CStart(DS1307_ADDR);
	I2CWriteByte(DS1307_SEC);
	for (i = DS1307_SEC; i <= DS1307_YEAR; i++)
		I2CWriteByte(D2BD(time[i]));
	I2CStop();

	return;
}

static void writeAlarm(void)
{
	uint8_t i;

	I2CStart(DS1307_ADDR);
	I2CWriteByte(DS1307_A0_HOUR);
	for (i = DS1307_A0_HOUR; i <= DS1307_A0_WDAY; i++)
		I2CWriteByte(alarm[i - DS1307_A0_HOUR]);
	I2CStop();

	return;
}

void stopEditTime(void)
{
	_etm = NOEDIT;

	return;
}

void stopEditAlarm(void)
{
	_eam = NOEDIT;

	return;
}

uint8_t isETM(void)
{
	if (_etm == NOEDIT)
		return 0;
	return 1;
}

uint8_t isEAM(void)
{
	if (_eam == NOEDIT)
		return 0;
	return 1;
}

void editTime(void)
{
	switch (_etm) {
	case NOEDIT:
		_etm = DS1307_HOUR;
		break;
	case DS1307_HOUR:
	case DS1307_MIN:
		_etm--;
		break;
	case DS1307_SEC:
		_etm = DS1307_DATE;
		break;
	case DS1307_DATE:
	case DS1307_MONTH:
		_etm++;
		break;
	default:
		_etm = NOEDIT;
		break;
	}

	return;
}

void editAlarm(void)
{
	switch (_eam) {
	case NOEDIT:
		_eam = DS1307_A0_HOUR;
		break;
	case DS1307_A0_HOUR:
		_eam = DS1307_A0_MIN;
		break;
	case DS1307_A0_MIN:
		_eam = DS1307_A0_INPUT;
		break;
	case DS1307_A0_INPUT:
		_eam = DS1307_A0_WDAY;
		break;
	default:
		_eam = NOEDIT;
		break;
	}

	return;
}

void changeTime(int diff)
{
	readTime();
	switch (_etm) {
	case DS1307_HOUR:
		time[DS1307_HOUR] += diff;
		if (time[DS1307_HOUR] > 23)
			time[DS1307_HOUR] = 0;
		if (time[DS1307_HOUR] < 0)
			time[DS1307_HOUR] = 23;
		break;
	case DS1307_MIN:
		time[DS1307_MIN] += diff;
		if (time[DS1307_MIN] > 59)
			time[DS1307_MIN] = 0;
		if (time[DS1307_MIN] < 0)
			time[DS1307_MIN] = 59;
		break;
	case DS1307_SEC:
		time[DS1307_SEC] = 0;
		break;
	case DS1307_DATE:
		time[DS1307_DATE] += diff;
		if (time[DS1307_DATE] > daysInMonth())
			time[DS1307_DATE] = 1;
		if (time[DS1307_DATE] < 1)
			time[DS1307_DATE] = daysInMonth();
		break;
	case DS1307_MONTH:
		time[DS1307_MONTH] += diff;
		if (time[DS1307_MONTH] > 12)
			time[DS1307_MONTH] = 1;
		if (time[DS1307_MONTH] < 1)
			time[DS1307_MONTH] = 12;
		break;
	case DS1307_YEAR:
		time[DS1307_YEAR] += diff;
		if (time[DS1307_YEAR] > 99)
			time[DS1307_YEAR] = 0;
		if (time[DS1307_YEAR] < 0)
			time[DS1307_YEAR] = 99;
		break;
	default:
		break;
	}
	writeTime();

	return;
}

void changeAlarm(int diff)
{
	readAlarm();
	switch (_eam) {
	case DS1307_A0_HOUR:
		alarm[DS1307_A0_HOUR - DS1307_A0_HOUR] += diff;
		if (alarm[DS1307_A0_HOUR - DS1307_A0_HOUR] > 23)
			alarm[DS1307_A0_HOUR - DS1307_A0_HOUR] = 0;
		if (alarm[DS1307_A0_HOUR - DS1307_A0_HOUR] < 0)
			alarm[DS1307_A0_HOUR - DS1307_A0_HOUR] = 23;
		break;
	case DS1307_A0_MIN:
		alarm[DS1307_A0_MIN - DS1307_A0_HOUR] += diff;
		if (alarm[DS1307_A0_MIN - DS1307_A0_HOUR] > 59)
			alarm[DS1307_A0_MIN - DS1307_A0_HOUR] = 0;
		if (alarm[DS1307_A0_MIN - DS1307_A0_HOUR] < 0)
			alarm[DS1307_A0_MIN - DS1307_A0_HOUR] = 59;
		break;
	case DS1307_A0_INPUT:
		alarm[DS1307_A0_INPUT - DS1307_A0_HOUR] += diff;
		if (alarm[DS1307_A0_INPUT - DS1307_A0_HOUR] >= CHAN_CNT)
			alarm[DS1307_A0_INPUT - DS1307_A0_HOUR] = 0;
		if (alarm[DS1307_A0_INPUT - DS1307_A0_HOUR] < 0)
			alarm[DS1307_A0_INPUT - DS1307_A0_HOUR] = CHAN_CNT - 1;
		break;
	case DS1307_A0_WDAY:
		alarm[DS1307_A0_WDAY - DS1307_A0_HOUR] += diff;
		if (alarm[DS1307_A0_WDAY - DS1307_A0_HOUR] < -64)
			alarm[DS1307_A0_WDAY - DS1307_A0_HOUR] = 0;
		if (alarm[DS1307_A0_WDAY - DS1307_A0_HOUR] < 0)
			alarm[DS1307_A0_WDAY - DS1307_A0_HOUR] = 127;
		break;
	default:
		break;
	}
	writeAlarm();

	return;
}
