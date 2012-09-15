#!/bin/bash
repl=("Debug/makefile" "Debug/src/subdir.mk" "Debug/STMPeriLib/subdir.mk")

for f in ${repl[@]}; do
	echo "Replacing arm-none-eabi-gcc with arm-none-eabi-g++ in ${f}"
	sed -i 's/arm-none-eabi-gcc/arm-none-eabi-g++/g' $f
done

echo "Building"
cd Debug
make clean
make all -j
cd ..

echo "Uploading..."
st-flash write Debug/STM32Demo.hex 0x8000000

