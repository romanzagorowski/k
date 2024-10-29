#include <linux/module.h>
#include <linux/sched.h>
#include <linux/string.h>
#include <linux/sched/signal.h>
#include <linux/init.h>

static int  skel01_init(void) __init;
static void skel01_exit(void) __exit;

static void print_all_processes(void) {
    struct task_struct *task;

    for_each_process(task) {
        // pointlessly print the name and pid of each task
        printk("%s[%d]\n", task->comm, task->pid);
    }
}

static int __init skel01_init(void) {
    printk("skel01_init(): Alice has a cat\n");

/*  iterate over current process's children
    struct list_head *list;

    list_for_each(list, &current->children) {
        struct task_struct *task = list_entry(list, struct task_struct, sibling);
    }
*/
    print_all_processes();

    return 0;
}

static void __exit skel01_exit(void) {
    printk("skel01_exit(): The cat has Alice\n");
}

module_init(skel01_init);
module_exit(skel01_exit);

MODULE_LICENSE("GPL");
