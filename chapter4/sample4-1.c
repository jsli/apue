/*************************************************************************
	> File Name: sample4-1.c
	> Author: Manson
	> Mail: manson.li3307@gmail.com 
	> Created Time: 2013年07月18日 星期四 11时09分45秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(void) {
	struct stat stat;
	
	lstat("/home/manson/temp/apue/chapter3/sample3-1.c", &stat);
	if (S_ISREG(stat.st_mode)) {
		printf("It's regular file\n");
	}
	return 0;
}
