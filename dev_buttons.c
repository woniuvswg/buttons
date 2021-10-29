/*
* Platform device
*/

#include <linux/module.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <mach/regs-gpio.h>
#include <linux/interrupt.h>
#include <linux/device.h>
#include <linux/io.h>

static struct resource s3c2440_buttons_resource[] = 
{
	[0] = 
	{
		.start = S3C24XX_PA_GPIO,
		.end = S3C24XX_PA_GPIO + S3C24XX_SZ_GPIO - 1,
		.flags = IORESOURCE_MEM,
	},

	[1] = 
	{
		.start = IRQ_EINT8,
		.end = IRQ_EINT8,
		.flags = IORESOURCE_IRQ,
	},

	[2] = 
	{
		.start = IRQ_EINT11,
		.end = IRQ_EINT11,
		.flags = IORESOURCE_IRQ,
	},

	[3] = 
	{
		.start = IRQ_EINT13,
		.end =IRQ_EINT13,
		.flags = IORESOURCE_IRQ,
	},
	
	[4] = 
	{
		.start = IRQ_EINT14,
		.end = IRQ_EINT14,
		.flags = IORESOURCE_IRQ,
	},

	[5] = 
	{
		.start = IRQ_EINT15,
		.end =IRQ_EINT15,
		.flags = IORESOURCE_IRQ,
	},

	[6] = 
	{
		.start = IRQ_EINT19,
		.end = IRQ_EINT19,
		.flags = IORESOURCE_IRQ,
	},
};

struct platform_device *s3c2440_buttons;

static int __init dev_buttons_init(void)
{
	/* 平台设备分配button */
	s3c2440_buttons = platform_device_alloc("mini2440buttons", -1);

	/* button 设备添加到资源 */
	platform_device_add_resources(s3c2440_buttons, &s3c2440_buttons_resource, 7);

	/* 平台设备button注册 */
	platform_device_add(s3c2440_buttons);
}

static void dev_buttons_exit(void)
{
	platform_device_unregister(s3c2440_buttons);
}

module_init(dev_buttons_init);
module_exit(dev_buttons_exit);

MODULE_AUTHOR("Josef Luo");
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:mini2440buttons");
