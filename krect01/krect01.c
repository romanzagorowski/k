#include <linux/module.h>
// #include <linux/sched.h>
// #include <linux/string.h>
// #include <linux/sched/signal.h>
// #include <linux/init.h>
#include <linux/slab.h>
#include <linux/kobject.h>

static int  krect01_init(void) __init;
static void krect01_exit(void) __exit;

struct krect
{
    struct kobject kobj;
    int width;
    int height;
};

#define to_krect(ptr) container_of(ptr, struct krect, kobj)

void krect_release(struct kobject* kobj);

struct kobj_type krect_type = {
    .release = krect_release
};

static struct krect* krect = NULL;

static int __init krect01_init(void) 
{
    printk("krect01_init(): Alice has a cat\n");

    krect = kzalloc(sizeof(*krect), GFP_KERNEL);
    if(!krect) return -ENOMEM;

    kobject_init(&krect->kobj, &krect_type);
    
    int e = kobject_add(&krect->kobj, kernel_kobj, "krect");
    
    if(e)
    {
        printk("krect01_init(): kobject_add() has failed: e=%d\n", e);
        kobject_put(&krect->kobj);
        return e;
    }

    e = kobject_uevent(&krect->kobj, KOBJ_ADD);

    // if(e)
    // {
    //     printk("krect01_init(): kobject_uevent() has failed: e=%d\n", e);
    //     kobject_put(&krect->kobj);
    //     return e;
    // }

    return 0;
}

static void __exit krect01_exit(void) 
{
    printk("krect01_exit(): The cat has Alice\n");

    if(krect) kobject_put(&krect->kobj);
}

module_init(krect01_init);
module_exit(krect01_exit);

MODULE_LICENSE("GPL");

void krect_release(struct kobject* kobj)
{
    struct krect* krect = to_krect(kobj);

    pr_info("krect01: %s(): width=%d, height=%d\n", __func__, krect->width, krect->height);

    kfree(krect);
}
