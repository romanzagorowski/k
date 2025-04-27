#include "mydrv.h"

static int mydrv_runtime_suspend(struct device *dev);
static int mydrv_runtime_resume(struct device *dev);
static int mydrv_runtime_idle(struct device *dev);

static struct dev_pm_ops mydrv_dev_pm_ops = {
    .runtime_suspend = mydrv_runtime_suspend,
    .runtime_resume = mydrv_runtime_resume,
    .runtime_idle = mydrv_runtime_idle
};

struct device_driver mydrv = {
    .name = "mydrv",
    .bus = NULL,
    .pm = &mydrv_dev_pm_ops
};

int mydrv_runtime_suspend(struct device *dev)
{
    return 0;
}

int mydrv_runtime_resume(struct device *dev)
{
    return 0;
}

static int foo(void);

int mydrv_runtime_idle(struct device *dev)
{
    return foo();
}

#include <linux/pm.h>

static int foo(void)
{
    struct dev_pm_domain *d = NULL;
    struct bus_type *bt = NULL;
    struct device_type *dt = NULL;
    struct class *c = NULL;

    pm_runtime_allow();

    return 0;
}