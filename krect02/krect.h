#ifndef __KRECT_H__
#define __KRECT_H__

#include <linux/slab.h>
#include <linux/kobject.h>

struct krect
{
    struct kobject kobj;
    int width;
    int height;
};

int krect_new(int width, int height, bool raise_uevent, struct krect **out);
struct krect *krect_get(struct krect *krect);
void krect_put(struct krect *krect);

#endif /* __KRECT_H__ */
