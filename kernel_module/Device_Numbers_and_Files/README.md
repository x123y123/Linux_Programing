## complie kernel_module
  $ sudo make 
## load kernel_module
  $ sudo insmod dev_nr.ko
## u can use "cat /proc/devices" to grep the dev_nr
  $ cat /proc/devices
## create a device file in the bash 
  $ sudo mknod /dev/mydevice c 90 0
## remove kernel_module
  $ sudo rmmod dev_nr
## list module loaded
  $ lsmod




