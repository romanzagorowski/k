/* 
#include <linux/slab.h>
#include <linux/kobject.h>
 */
#include <linux/init.h>
#include <linux/module.h>

static int  pmrdrv_init(void) __init;
static void pmrdrv_exit(void) __exit;

static int __init pmrdrv_init(void) 
{
    pr_alert("pmrdrv_init(): Alice has a cat\n");

    return 0;
}

static void __exit pmrdrv_exit(void) 
{
    pr_alert("pmrdrv_exit(): The cat has Alice\n");
}

module_init(pmrdrv_init);
module_exit(pmrdrv_exit);

MODULE_LICENSE("GPL");
