#include <avr/pgmspace.h>

const uint8_t icons_32[] PROGMEM = {
	// Mute ON
	0x03, 0x07, 0x0E, 0x1C, 0x38, 0x70, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0,
	0xF8, 0xFC, 0xFE, 0xFF, 0xFF, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0x70, 0x38, 0x1C, 0x0E, 0x07, 0x03,
	0x00, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFD, 0xFB, 0x07, 0xEE, 0xDD, 0xBB, 0x77, 0xEF, 0xDF,
	0xDF, 0xEF, 0x77, 0xBB, 0xDD, 0x0E, 0x67, 0xE3, 0xC1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0xBF, 0xDF, 0xE0, 0x77, 0xBB, 0xDD, 0xEE, 0xF7, 0xFB,
	0xFB, 0xF7, 0xEE, 0xDD, 0xBB, 0x70, 0xE6, 0xC7, 0x83, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xC0, 0xE0, 0x70, 0x38, 0x1C, 0x0E, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0F,
	0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0E, 0x1C, 0x38, 0x70, 0xE0, 0xC0,
	// Mute OFF
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0,
	0xF8, 0xFC, 0xFE, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x60, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x60, 0xE6, 0xCE, 0x1C, 0xF9, 0xE3, 0x0F, 0xFE, 0xF8, 0x00,
	0x00, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x06, 0x67, 0x73, 0x38, 0x9F, 0xC7, 0xF0, 0x7F, 0x1F, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0F,
	0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x06, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00,
	// Loudness ON
	0x00, 0x00, 0x88, 0x88, 0xFE, 0xFE, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0xFE,
	0xFE, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0xFE, 0xFE, 0x88, 0x88, 0x00, 0x00,
	0x00, 0x3C, 0x3C, 0x3C, 0xFF, 0xFF, 0x3C, 0x3C, 0x3C, 0x00, 0x00, 0x00, 0xC0, 0xC8, 0xC8, 0xFF,
	0xFF, 0xC8, 0xC8, 0xC0, 0x00, 0x00, 0x00, 0x3C, 0x3C, 0x3C, 0xFF, 0xFF, 0x3C, 0x3C, 0x3C, 0x00,
	0x00, 0x00, 0x11, 0x11, 0xFF, 0xFF, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x03, 0x13, 0x13, 0xFF,
	0xFF, 0x13, 0x13, 0x03, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0xFF, 0xFF, 0x11, 0x11, 0x00, 0x00,
	0x00, 0x00, 0x11, 0x11, 0x7F, 0x7F, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x7F,
	0x7F, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x7F, 0x7F, 0x11, 0x11, 0x00, 0x00,
	// Loudness OFF
	0x00, 0x00, 0x88, 0x88, 0xFE, 0xFE, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0xFE,
	0xFE, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0xFE, 0xFE, 0x88, 0x88, 0x00, 0x00,
	0x00, 0xC0, 0xC8, 0xC8, 0xFF, 0xFF, 0xC8, 0xC8, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0xC8, 0xC8, 0xFF,
	0xFF, 0xC8, 0xC8, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0xC8, 0xC8, 0xFF, 0xFF, 0xC8, 0xC8, 0xC0, 0x00,
	0x00, 0x03, 0x13, 0x13, 0xFF, 0xFF, 0x13, 0x13, 0x03, 0x00, 0x00, 0x00, 0x03, 0x13, 0x13, 0xFF,
	0xFF, 0x13, 0x13, 0x03, 0x00, 0x00, 0x00, 0x03, 0x13, 0x13, 0xFF, 0xFF, 0x13, 0x13, 0x03, 0x00,
	0x00, 0x00, 0x11, 0x11, 0x7F, 0x7F, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x7F,
	0x7F, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x7F, 0x7F, 0x11, 0x11, 0x00, 0x00,
	// Surround ON
	0x0C, 0x1E, 0xEF, 0xF7, 0xFA, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x7C, 0x3C, 0x18, 0x00, 0x00,
	0x00, 0x00, 0x18, 0x3C, 0x7C, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFA, 0xF7, 0xEF, 0x1E, 0x0C,
	0x00, 0x00, 0x1F, 0x3F, 0x3F, 0x1F, 0x0F, 0x07, 0xE3, 0xF9, 0x1C, 0xEE, 0xF6, 0x7B, 0xBB, 0xDB,
	0xDB, 0xBB, 0x7B, 0xF6, 0xEE, 0x1C, 0xF9, 0xE3, 0x07, 0x0F, 0x1F, 0x3F, 0x3F, 0x1F, 0x00, 0x00,
	0x00, 0x00, 0xF8, 0xFC, 0xFC, 0xF8, 0xF0, 0xE0, 0xC7, 0x9F, 0x38, 0x77, 0x6F, 0xDE, 0xDD, 0xDB,
	0xDB, 0xDD, 0xDE, 0x6F, 0x77, 0x38, 0x9F, 0xC7, 0xE0, 0xF0, 0xF8, 0xFC, 0xFC, 0xF8, 0x00, 0x00,
	0x30, 0x78, 0xF7, 0xEF, 0x5F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3E, 0x3C, 0x18, 0x00, 0x00,
	0x00, 0x00, 0x18, 0x3C, 0x3E, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x5F, 0xEF, 0xF7, 0x78, 0x30,
	// Surround OFF
	0x0B, 0x17, 0xEE, 0xDD, 0xBA, 0x74, 0xEC, 0xDC, 0xBC, 0x7C, 0xFC, 0x7C, 0x3C, 0x18, 0x00, 0x00,
	0x00, 0x00, 0x18, 0x3C, 0x7C, 0xFC, 0x7C, 0xBC, 0xDC, 0xEC, 0x74, 0xBA, 0xDD, 0xEE, 0x17, 0x0B,
	0x00, 0x00, 0x1F, 0x3F, 0x3F, 0x1F, 0x0E, 0x05, 0xE3, 0xF7, 0x0E, 0xDC, 0xBA, 0x73, 0xEB, 0xDB,
	0xDB, 0xEB, 0x73, 0xBA, 0xDC, 0x0E, 0xF7, 0xE3, 0x05, 0x0E, 0x1F, 0x3F, 0x3F, 0x1F, 0x00, 0x00,
	0x00, 0x00, 0xF8, 0xFC, 0xFC, 0xF8, 0x70, 0xA0, 0xC7, 0xEF, 0x70, 0x3B, 0x5D, 0xCE, 0xD7, 0xDB,
	0xDB, 0xD7, 0xCE, 0x5D, 0x3B, 0x70, 0xEF, 0xC7, 0xA0, 0x70, 0xF8, 0xFC, 0xFC, 0xF8, 0x00, 0x00,
	0xD0, 0xE8, 0x77, 0xBB, 0x5D, 0x2E, 0x37, 0x3B, 0x3D, 0x3E, 0x3F, 0x3E, 0x3C, 0x18, 0x00, 0x00,
	0x00, 0x00, 0x18, 0x3C, 0x3E, 0x3F, 0x3E, 0x3D, 0x3B, 0x37, 0x2E, 0x5D, 0xBB, 0x77, 0xE8, 0xD0,
	// Effect 3D ON
	0x00, 0x80, 0xC0, 0xC0, 0xE0, 0xE0, 0xF0, 0x70, 0x78, 0x38, 0x3C, 0x9C, 0xDE, 0xCE, 0x6F, 0x67,
	0x67, 0x6F, 0xCE, 0xDE, 0x9C, 0x3C, 0x38, 0x78, 0x70, 0xF0, 0xE0, 0xE0, 0xC0, 0xC0, 0x80, 0x00,
	0x00, 0xFF, 0xFF, 0x07, 0x07, 0x0E, 0x0E, 0x1C, 0x1C, 0x38, 0x3B, 0x73, 0x71, 0xE0, 0xE6, 0xC6,
	0xC6, 0xE6, 0xE0, 0x71, 0x73, 0x3B, 0x38, 0x1C, 0x1C, 0x0E, 0x0E, 0x07, 0x07, 0xFF, 0xFF, 0x00,
	0x00, 0xFF, 0xFF, 0x80, 0x80, 0x07, 0x1F, 0x38, 0x70, 0x63, 0xC7, 0xC6, 0xC0, 0x00, 0x00, 0xFF,
	0xFF, 0x00, 0x00, 0xC0, 0xC6, 0xC7, 0x63, 0x70, 0x38, 0x1F, 0x07, 0x80, 0x80, 0xFF, 0xFF, 0x00,
	0x00, 0x01, 0x01, 0x03, 0x03, 0x07, 0x07, 0x0E, 0x0E, 0x1C, 0x1C, 0x38, 0x38, 0x70, 0xF0, 0xFF,
	0xFF, 0x70, 0x70, 0x38, 0x38, 0x1C, 0x1C, 0x0E, 0x0E, 0x07, 0x07, 0x03, 0x03, 0x01, 0x01, 0x00,
	// Effect 3D OFF
	0x03, 0x87, 0xCE, 0xDC, 0xB8, 0x70, 0xE0, 0xD0, 0xB8, 0x38, 0x3C, 0x9C, 0xDE, 0xCE, 0x6F, 0x67,
	0x67, 0x6F, 0xCE, 0xDE, 0x9C, 0x3C, 0x38, 0xB8, 0xD0, 0xE0, 0x70, 0xB8, 0xDC, 0xCE, 0x87, 0x03,
	0x00, 0xFF, 0xFF, 0x07, 0x07, 0x0E, 0x0E, 0x1D, 0x1B, 0x37, 0x2E, 0x5D, 0x39, 0x70, 0xE6, 0xC6,
	0xC6, 0xE6, 0x70, 0x39, 0x5D, 0x2E, 0x37, 0x1B, 0x1D, 0x0E, 0x0E, 0x07, 0x07, 0xFF, 0xFF, 0x00,
	0x00, 0xFF, 0xFF, 0x80, 0x80, 0x07, 0x1F, 0xB8, 0xD0, 0xE3, 0x77, 0xBA, 0xDC, 0x0E, 0x07, 0xFB,
	0xFB, 0x07, 0x0E, 0xDC, 0xBA, 0x77, 0xE3, 0xD0, 0xB8, 0x1F, 0x07, 0x80, 0x80, 0xFF, 0xFF, 0x00,
	0xC0, 0xE1, 0x71, 0x3B, 0x1D, 0x0E, 0x07, 0x0B, 0x0D, 0x1C, 0x1C, 0x38, 0x38, 0x70, 0xF0, 0xFF,
	0xFF, 0x70, 0x70, 0x38, 0x38, 0x1C, 0x1C, 0x0D, 0x0B, 0x07, 0x0E, 0x1D, 0x3B, 0x71, 0xE1, 0xC0,
	// Tone defeat ON
	0x10, 0x10, 0x10, 0x10, 0x38, 0x38, 0x38, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
	0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x38, 0x38, 0x10, 0x10, 0x10, 0x10,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFC, 0x08, 0x08, 0x10, 0x10, 0x20, 0x20, 0x40,
	0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x04, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40,
	0xC0, 0x20, 0x20, 0x11, 0x11, 0x0A, 0x0A, 0x04, 0x04, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x02, 0x02, 0x01, 0x01, 0x00, 0x94, 0x94,
	0xF7, 0x94, 0x94, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// Tone defeat OFF
	0x10, 0x10, 0x10, 0x10, 0x38, 0xF8, 0x38, 0x00, 0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
	0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00, 0x38, 0xF8, 0x38, 0x10, 0x10, 0x10, 0x10,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFC, 0x08, 0x08, 0x10, 0x10, 0x20, 0x20, 0x40,
	0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x04, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40,
	0xC0, 0x20, 0x20, 0x11, 0x11, 0x0A, 0x0A, 0x04, 0x04, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x02, 0x02, 0x01, 0x01, 0x00, 0x94, 0x94,
	0xF7, 0x94, 0x94, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
