/* 
    under "/proc/devices" devices is created by driver process, it can generate a major and offer a variable to "mknod"
    under "/dev" devices is created by mknod, user can visit driver by this device id
*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>


#define MYMAJOR 200

static int driver_open(struct inode *device_file, struct file *instance) {
    printk("device-number open was called!\n");
    return 0;
}

static int driver_close(struct inode *device_file, struct file *instance) {
    printk("device-number close was called!\n");
    return 0;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = driver_open,
    .release = driver_close
};

static int __init hello_init(void)
{
    int retval;
    printk(KERN_INFO "Hello World\n");
    
    retval = register_chrdev(MYMAJOR, "my_dev_nr", &fops);     // "cat /proc/devices" to pick dev nr, and i choose "200"
    if (retval == 0) {
        printk("device number MAJOR : %d, Minor : %d\n", MYMAJOR, 0);
    }
    else if (retval > 0) {
        printk("device number MAJOR : %d, Minor : %d\n", retval>>20, retval&0xfffff0);
    }
    else {
        printk("Could not register device number!\n");
        return -1;
    }

    return 0;
}

static void __exit hello_exit(void)
{
    unregister_chrdev(MYMAJOR, "my_dev_nr");
    printk(KERN_INFO "Bye~\n");
}

module_init(hello_init); //using insmod, it will enter hello_init
module_exit(hello_exit); //using rmmod, it will enter hello_exit

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Hello world\n");
