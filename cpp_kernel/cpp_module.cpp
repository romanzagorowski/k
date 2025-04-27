#include <linux/module.h>
#include <linux/init.h>
/*
#include <linux/sched.h>
#include <linux/string.h>
#include <linux/sched/signal.h>
*/

static int  skel01_init(void) __init;
static void skel01_exit(void) __exit;

static int __init skel01_init(void)
{
    printk("skel01_init(): Alice has a cat\n");

    return 0;
}

static void __exit skel01_exit(void)
{
    printk("skel01_exit(): The cat has Alice\n");
}

module_init(skel01_init);
module_exit(skel01_exit);

MODULE_LICENSE("GPL");
