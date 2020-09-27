#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

/*
	编写程序,将"hello world"写入2.txt文件中
*/
int write_data(void)
{
	int fd = 0;
	ssize_t ret = 0;
	char buf[100] = "hello world";  //要写入的数据

	//打开文件
	fd = open("./2.txt",O_RDWR);
	if(-1 == fd)
	{
		perror("open file error");
		return -1;
	}

	//写入数据
	ret = write(fd,buf,11);
	if(-1 == ret || 0==ret)
	{
		perror("write error or no write");
		return -1;
	}

	//关闭文件
	close(fd);

	return 0;
}


