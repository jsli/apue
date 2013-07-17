/*************************************************************************
	> File Name: sample3-1.c
	> Author: Manson
	> Mail: manson.li3307@gmail.com 
	> Created Time: 2013年07月17日 星期三 18时36分29秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define FILE_MODE   (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void) {
	int fd;
	if ((fd = creat("file.hole", FILE_MODE)) < 0) {
		printf("Can't create file.hole\n");
	}

	if (write(fd, buf1, 10) != 10) {
		printf("Can't write buf1\n");
	}

	if (lseek(fd, 16384, SEEK_SET) == -1) {
		printf("Can't seek\n");
	}

	if (write(fd, buf2, 10) != 10) {
		printf("Can't write buf2\n");
	}
	return 0;
}
