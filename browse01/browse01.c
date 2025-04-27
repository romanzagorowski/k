//#define DEBUG

#include <linux/module.h>

static int browse01_init(void)
{
    pr_info("browse01_init: pr_info\n");
    pr_debug("browse01_init: pr_debug\n");
    return 0;
}

static void browse01_exit(void)
{
    pr_info("browse01_exit: pr_info\n");
    pr_debug("browse01_exit: pr_debug\n");
}

module_init(browse01_init);
module_exit(browse01_exit);

MODULE_LICENSE("GPL");
