KDIR ?= /lib/modules/$(shell uname -r)/build
# Uncomment to use WSL kernel. See README.md for installation details.
# KDIR ?= ${HOME}/WSL2-Linux-Kernel

obj-m :=simple_char_driver.o


all:
	make -C $(KDIR) M=$(PWD) modules 
	gcc simple_char_test.c -o simple_char_test

clean:
	make -C $(KDIR) M=$(PWD) clean
