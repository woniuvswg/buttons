ifneq ($(KERNELRELEASE),)

obj-m := drv_buttons.o dev_buttons.o

else

KDIR := /opt/FriendlyARM/mini2440/linux-2.6.32.2

all: app-buttons
	make -C $(KDIR) M=$(PWD) modules ARCH=arm CROSS_COMPILE=arm-linux-

app-buttons: app-buttons.c 
	arm-linux-gcc -o $@ $<
	
clean:
	rm -rf *

endif

