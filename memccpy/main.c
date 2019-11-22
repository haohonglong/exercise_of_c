#include<stdio.h>
#include<string.h>
int main(int argc,char *argv[])
{
	char *a = "hello world!";
	char b[20];
	char *c;
	c = memccpy(b,a,'o',20);
	if(c){
		*c = '\0';
		printf("char found: %s.\n",b);
	}else{
		printf("char not found.\n");
	}
	printf("%s\n",b);
	c = memccpy(b,a,'\0',20);
	if(c){
		*c = '\0';
		printf("char found: %s.\n",b);
	}else{
		printf("char not found.\n");
	}
	printf("%s\n",b);
	return 0;
}
