/*************************************************************************
	> File Name: sample10-1.c
	> Author: Manson
	> Mail: manson.li3307@gmail.com 
	> Created Time: 2013年07月19日 星期五 10时28分59秒
 ************************************************************************/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<errno.h>

extern int errno;
static int pr_mask(void);

int main(void) {
	sigset_t set, oldset;
	sigemptyset(&set);
	pr_mask();
	sigaddset(&set, SIGQUIT);
	sigprocmask(SIG_BLOCK, &set, &oldset);
	pr_mask();
	return 0;
}

int pr_mask(void) {
	sigset_t sigset;
	int errno_save;
	printf("============================\n");
	errno_save = errno;
	if (sigprocmask(0, NULL, &sigset) < 0) {
		printf("sigprocmask error\n");
		return -1;
	}

	if (sigismember(&sigset, SIGINT)) {
		printf("SIGINT\n");
	}
	if (sigismember(&sigset, SIGQUIT)) {
		printf("SIGQUIT\n");
	}
	if (sigismember(&sigset, SIGUSR1)) {
		printf("SIGUSR1\n");
	}
	if (sigismember(&sigset, SIGALRM)) {
		printf("SIGALRM\n");
	}
	printf("\n");
	errno = errno_save;
	return 0;
}
