#!/bin/sh

for AUDIOPROC in TDA7313 TDA7318 TDA7439
do
	for DISPLAY in KS0108A KS0108B ST7920
	do
		for TUNER in LM7001 RDA5807 TEA5767 TUX032
		do
			make clean
			make AUDIOPROC=${AUDIOPROC} DISPLAY=${DISPLAY} TUNER=${TUNER}
		done
	done
done

make clean
