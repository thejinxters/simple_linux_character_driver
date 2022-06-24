# Install the driver
In this repo folder run:
```bash
make
sudo insmod simple_char_driver.ko
```

View that the device installed:
```bash
cat /proc/devices | grep simple_driver
```

To test simply run the tester
```bash
./simple_char_test
```


To remove the driver
```bash
sudo rmmod simple_char_driver
```


# Create /dev/simple_char_device
```bash
sudo mknod -m 777 /dev/simple_char_device  c 301 0
```

View the inode successfully created:
```bash
ls -la /dev | grep simple_char_device
```

# Build WSL kernel
clone WSL linux kernel to `$HOME/WSL2-Linux-Kernel`

checkout the git tag that matches $(uname -r) in your WSL

Save current kernel configuration to tmp file

```
zcat /proc/config/.gz > /tmp/kernel-config
```

build the kernel image
```
make KCONFIG_CONFIG=/tmp/kernel-config -j `nproc`
```

Now, you have built linux kernel image, bzImage.
