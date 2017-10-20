#include <linux/linkage.h>
#include <linux/export.h>
#include <linux/time.h>
#include <asm/uaccess.h>
#include <linux/printk.h>
#include <linux/slab.h>

asmlinkage int sys_my_xtime(struct timespec __user *current_time){
	struct timespec xtime;
	
	if (!access_ok(VERIFY_WRITE, current_time, sizeof(struct timespec))){
		return -EFAULT;
	}
	
	xtime = current_kernel_time();
	// now copy xtime to userspace copy_to_user()
	
	//printk(KERN_ALERT "Xtime in nanoseconds: %lu\n", xtime.tv_nsec);
	//printk(KERN_ALERT "current time address, %p", current_time);
	int copyErrNum = 0;
	copyErrNum = copy_to_user(current_time, &xtime, sizeof(struct timespec));
	printk(KERN_ALERT "Current time in nanoseconds: %lu\n", xtime.tv_nsec);
        // return 0 ok?
	
	return copyErrNum;
}
EXPORT_SYMBOL(sys_my_xtime);
