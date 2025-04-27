#include "krect.h"

#include <linux/module.h>

static int  krect01_init(void) __init;
static void krect01_exit(void) __exit;

static struct krect *krect = NULL;

static int __init krect01_init(void) 
{
    pr_info("krect01_init(): Alice has a cat\n");

    int e = krect_new(10, 20, false, &krect);

    if(e)
    {
        pr_err("krect01_init(): krect_new() has failed: e=%d\n", e);
        return e;
    }

    return 0;
}

static void __exit krect01_exit(void) 
{
    pr_info("krect01_exit(): The cat has Alice\n");

    if(krect) krect_put(krect);
}

module_init(krect01_init);
module_exit(krect01_exit);

MODULE_LICENSE("GPL");
