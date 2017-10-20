#include <stdio.h>
#include <unistd.h>
#include <linux/unistd.h>
#include <linux/time.h>

int main(){
        int errNum = 0;
	struct timespec current_time;
        errNum = syscall(327, &current_time);
	printf("current time: %lu\n", current_time.tv_nsec);
        printf("syscall ret value: %d.\n", errNum);
        return 0;
}
