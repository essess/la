arm-none-eabi-as -acghls -g --fatal-warnings -mcpu=cortex-m3 -mimplicit-it=never vectors.s -o vectors.o > vectors.lst
arm-none-eabi-as -acghls -g --fatal-warnings -mcpu=cortex-m3 -mimplicit-it=never start.s -o start.o > start.lst
arm-none-eabi-as -acghls -g --fatal-warnings -mcpu=cortex-m3 -mimplicit-it=never main.s -o main.o > main.lst
arm-none-eabi-ld -T la.ld --entry=start --fatal-warnings --gc-sections --print-gc-sections --no-undefined -nostdlib --unresolved-symbols=report-all --cref -Map la.map -o la.elf vectors.o start.o main.o
arm-none-eabi-objdump -D la.elf > la.lst