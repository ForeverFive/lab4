#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/errno.h>
#include "inc/hello1.h"

// SPDX-License-Identifier: GPL-2.0
MODULE_AUTHOR("IO-15 Sydorchenko Iryna");
MODULE_DESCRIPTION("Hello, world from Linux Kernel Try Hello2");
MODULE_LICENSE("Dual BSD/GPL");

static unsigned int hello = 3;  // Параметр для hello2
module_param(hello, uint, 0444);
MODULE_PARM_DESC(hello, "How many times to display 'Hello, world!'");

static int __init hello2_init(void)
{
	if (hello == 0 || (hello >= 5 && hello <= 10)) {
		pr_warn("Wrong number of hello.\n");
	} else if (hello > 10) {
		pr_err("Wrong number of hello. This module is not loaded.\n");
		return -EINVAL;
	}
	pr_info("Hello2 module initialized.\n");
	print_hello(hello);
	// Виклик функції з hello1 з параметром
	return 0;
}

static void __exit hello2_exit(void)
{
	pr_info("Hello2 module exited.\n");
}

module_init(hello2_init);
module_exit(hello2_exit);

