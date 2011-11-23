#! /bin/bash

echo "Removing the old object files"
rm  -f *.o

echo "Compiling pm_services layer"
arm-arago-linux-gnueabi-gcc -mcpu=cortex-m3 -mthumb -c -g -nostdlib -Wall -Iinclude/ pm_services/prcm_core.c
arm-arago-linux-gnueabi-gcc -mcpu=cortex-m3 -mthumb -c -g -nostdlib -Wall -Iinclude/ pm_services/pm_handlers.c

echo "Compiling sys_exec layer"
arm-arago-linux-gnueabi-gcc -mcpu=cortex-m3 -mthumb -c -g -nostdlib -Wall -Iinclude/ sys_exec/sys_init.c
arm-arago-linux-gnueabi-gcc -mcpu=cortex-m3 -mthumb -c -g -nostdlib -Wall -Iinclude/ sys_exec/system_am335.c
arm-arago-linux-gnueabi-gcc -mcpu=cortex-m3 -mthumb -c -g -nostdlib -Wall -Iinclude/ sys_exec/msg.c
arm-arago-linux-gnueabi-gcc -mcpu=cortex-m3 -mthumb -c -g -nostdlib -Wall -Iinclude/ sys_exec/trace.c
arm-arago-linux-gnueabi-gcc -mcpu=cortex-m3 -mthumb -c -g -nostdlib -Wall -Iinclude/ sys_exec/sync.c

echo "Compiling foundation layer"
arm-arago-linux-gnueabi-gcc -mcpu=cortex-m3 -mthumb -c -g -nostdlib -Wall -Iinclude/ foundation/cm3.c
arm-arago-linux-gnueabi-gcc -mcpu=cortex-m3 -mthumb -c -g -nostdlib -Wall -Iinclude/ foundation/startup.c
arm-arago-linux-gnueabi-gcc -mcpu=cortex-m3 -mthumb -c -g -nostdlib -Wall -Iinclude/ foundation/ext_intr_handlers.c
arm-arago-linux-gnueabi-gcc -mcpu=cortex-m3 -mthumb -c -g -nostdlib -Wall -Iinclude/ foundation/exception_handlers.c
arm-arago-linux-gnueabi-gcc -mcpu=cortex-m3 -mthumb -c -g -nostdlib -Wall -Iinclude/ foundation/rtc.c

echo "Linking all the object files"
arm-arago-linux-gnueabi-gcc -mcpu=cortex-m3 -mthumb -nostdlib -nostartfiles -fno-exceptions -Tfirmware.ld \
startup.o sys_init.o system_am335.o trace.o sync.o rtc.o prcm_core.o pm_handlers.o msg.o \
ext_intr_handlers.o exception_handlers.o cm3.o -o firmware.elf

echo "Generating the binary"
arm-arago-linux-gnueabi-objcopy -Obinary firmware.elf firmware.bin

echo "Moving things to the bin folder"
mv firmware.bin firmware.elf ../bin

echo "That's all folks!!!"
