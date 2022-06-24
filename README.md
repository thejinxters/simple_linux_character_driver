# build WSL kernel
clone WSL linux kernel to $HOME/WSL2-Linux-Kernel
checkout the git tag that matches $(uname -r) in your WSL
zcat /proc/config/.gz > /tmp/kernel-config
make KCONFIG_CONFIG=/tmp/kernel-config -j `nproc`

Now, you have built linux kernel image, bzImage.

# build simple_char_drive
make
sudo insmod simple_char_drive.ko
"dmesg | tail" to check for messages coming from the driver being initialized.
sudo rmmod simple_char_drive.ko to remove it from kernel.
