#include "krect.h"

//#include <linux/slab.h>

#define to_krect(ptr) container_of(ptr, struct krect, kobj)

static void krect_release(struct kobject* kobj)
{
    struct krect* krect = to_krect(kobj);

    pr_info("krect_release(): %s(): width=%d, height=%d\n", __func__, krect->width, krect->height);

    kfree(krect);
}

static struct kobj_type krect_type = {
    .release = krect_release
};

int krect_new(int width, int height, bool raise_uevent, struct krect** out)
{
    if(!out) return -EINVAL;
    
    struct krect *krect = kzalloc(sizeof(*krect), GFP_KERNEL);
    if(!krect)
    {
        pr_debug("krect_new(): kzalloc() has failed\n");
        return -ENOMEM;
    }

    int e = kobject_init_and_add(&krect->kobj, &krect_type, kernel_kobj, "krect01");
    if(e)
    {
        pr_debug("krect_new(): kobject_init_and_add() has failed: e=%d\n", e);
        kobject_put(&krect->kobj);
        return e;
    }

    if(raise_uevent)
    {
        int e = kobject_uevent(&krect->kobj, KOBJ_ADD);
        if(e)
        {
            pr_debug("krect_new(): kobject_uevent() has failed: e=%d\n", e);
            kobject_put(&krect->kobj);
            return e;
        }
    }

    *out = krect;

    return 0;
}

struct krect *krect_get(struct krect *krect)
{
    if(krect) kobject_get(&krect->kobj);

    return krect;
}

void krect_put(struct krect *krect)
{
    if(krect) kobject_put(&krect->kobj);
}
