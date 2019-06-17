#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
struct TelBook
{
	int index;
	char name[12];
	char MTel[12];
	char Tel[12];
};
void set(struct TelBook* p);
void get(struct TelBook* p);
int main(int argc,char *argv[])
{
	struct TelBook *p;
	char ch;
	printf("do you add a user? Y/N\n");
	ch = getchar();
	if('y' == ch || 'Y' == ch){
		p = (struct TelBook *)malloc(sizeof(struct TelBook));
		set(p);
		get(p);
		free(p);
	}
	printf("page size=%d\n",getpagesize());
	return 0;
}


void set(struct TelBook* p)
{
	register  int  i =0;
	p->index = ++i;
	printf("User name:");
	scanf("%s",p->name);
	printf("Mobile:");
	scanf("%s",p->MTel);
		
}

void get(struct TelBook* p)
{
	printf("index:%d \n",p->index);
	printf("name:%s \n",p->name);
	printf("MoveTel:%s \n",p->MTel);
	printf("HomeTel:%s \n",p->Tel);
		
}


