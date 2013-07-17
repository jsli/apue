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
#define FLAG (O_RDWR | O_APPEND)
//define FLAG (O_RDWR)

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void) {
	int fd;
	if ((fd = open("file.test", FLAG, FILE_MODE)) < 0) {
		printf("Can't open file.test\n");
	}

	if (lseek(fd, 5, SEEK_SET) == -1) {
		printf("Can't seek file.test\n");
	}

	/*lseek doesn't work here, if we specified O_APPEND flag before,
	 * it will write to the end of the file always*/
	if (write(fd, buf1, 10) != 10) {
		printf("Can't write buf1\n");
	}

	close(fd);
	return 0;
}
