#include<stdio.h>
#include<stdlib.h>

void itoa_(int value,char *string,int radix);

int
main(int argc,char* argv[])
{
	int num = 12345;
	char string[25];
	itoa_(num,string,10);
	//printf("\n%s\n",string);
	return 0;
}


void itoa_(int value,char *string,int radix)
{

	void fun()
	{
		printf("hello world");
	}
	fun();
printf("\nstring=%s\n",string);
	/*	int j=0,i=0;
	char *temp = string;
	for(;value;i++){
		temp[i] = value % radix+'0';
		value/=10;
	}
	temp[i] =0;
	i--;
	for(;i>=0;j++,i--){
		string[j] = temp[i];
		printf("%c--",string[j]);
	}
	string[j] = 0;
	*/
}
