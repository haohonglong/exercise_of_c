#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
 
int main(int argc,char* argv[])
{
	int fd;
	void* start;
	struct stat sb;
	char* file = argv[1];
	fd = open(file,O_RDONLY);
	fstat(fd,&sb);
	start = mmap(NULL,sb.st_size,PROT_READ,MAP_PRIVATE,fd,0);
	if(start == MAP_FAILED){
		return 0;
	}
	printf("%s\n",start);
	munmap(start,sb.st_size);
	close(fd);
	return 0;
}
