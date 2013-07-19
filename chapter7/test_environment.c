/*************************************************************************
	> File Name: test_environment.c
	> Author: Manson
	> Mail: manson.li3307@gmail.com 
	> Created Time: 2013年07月18日 星期四 19时30分31秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

extern char **environ;
char buf[32] = "PATH";

int main(int argc, char* argv[]) {
	//we can't use environ directly, if we do this, environment table's  position is unkonwable.
	//After that, some methods wouldn't  work, such as getenv
	char **temp = environ;
	
	putenv("XXXX=DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD");
	setenv("XXXX", "CCCCCCCCCCCCCCCCCCCCCCCCCCCCC", 1);
	while (*temp) {
		printf("%s\n", *temp++);
	}
	
	printf("======================================\n");
	//char *home = getenv("HOME");
	//printf("HOME:%s\n", home);
	printf("HOME:%s\n", getenv("HOME"));
	return 0;
}
