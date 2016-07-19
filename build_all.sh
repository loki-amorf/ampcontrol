#!/bin/sh

for DISPLAY in KS0108 ST7920
do
	make clean
	make DISPLAY=${DISPLAY}
done

make clean
