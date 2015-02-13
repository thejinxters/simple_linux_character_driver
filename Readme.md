# Simple Linux Character Driver

Create an inode at master 301
```bash
sudo mknod -m 777 /dev/simple_char_device 777 c 301 0
```

View the inode successfully created:
```bash
ls -la /dev | grep simple_char_device
```

To install the driver,
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


