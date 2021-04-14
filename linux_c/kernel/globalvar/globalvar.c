#include <asm/fs.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");

#define MAJOR_NUM 254

static ssize_t globalvar_read(struct file *, char *, size_t, loff_t *);
static ssize_t globalvar_write(struct file *, const char *, size_t, loff_t *);

struct file_operations globalvar_fops = {
  read : globalvar_read,
  write : globalvar_write,
};

static int global_var = 0;

static int __init globalvar_init(void) {
  int ret;
  if ((ret = register_chrdev(MAJOR_NUM, "globalvar", &globalvar_fops))) {
    printk("globalvar register failure\n");
  } else {
    printk("globalvar register success\n");
  }
  return ret;
}

static void __exit globalvar_exit(void) {
  if (unregister_chrdev(MAJOR_NUM, "globalvar")) {
    printk("globalvar unregister failure\n");
  } else {
    printk("globalcar unregister success\n");
  }
}

static ssize_t globalvar_read(struct file *filp, char *buf, size_t len,
                              loff_t *off) {
  if (raw_copy_to_user(buf, &global_var, sizeof(int))) {
    return EFAULT;
  }
  return sizeof(int);
}

static ssize_t globalvar_write(struct file *filp, const char *buf, size_t len,
                               loff_t *off) {
  if (raw_copy_from_user(&global_var, buf, sizeof(int))) {
    return EFAULT;
  }
  return sizeof(int);
}

module_init(globalvar_init);
module_exit(globalvar_exit);
