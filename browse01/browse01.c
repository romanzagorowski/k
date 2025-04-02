#include <linux/module.h>

static int browse01_init(void)
{
    pr_debug("static int browse01_init(void)\n");
    return 0;
}

static void browse01_exit(void)
{
    pr_debug("static void browse01_exit(void)\n");
}

module_init(browse01_init);
module_exit(browse01_exit);

MODULE_LICENSE("GPL");
