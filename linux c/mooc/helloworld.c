#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

static int __init lkm_init(void) {
  printk("Hello World\n");
  return 0;
}

static void __exit lkm_exit(void) { printk("Good Bye\n"); }

module_init(lkm_init);
module_exit(lkm_exit);

MODULE_LICENSE("GPL");
