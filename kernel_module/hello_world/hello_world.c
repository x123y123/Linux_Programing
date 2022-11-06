/* simple kernel moudule hello_world */
#include <linux/init.h>
#include <linux/module.h>

static int __init hello_init(void)
{
    printk(KERN_INFO "Hello World\n");
    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_INFO "Bye~\n");
}

module_init(hello_init); //using insmod, it will enter hello_init
module_exit(hello_exit); //using rmmod, it will enter hello_exit

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Hello world\n");
