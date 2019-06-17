#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
	char a;	
	for(char i=0;i < 127;i++){
		a = (char)i;
		printf("%d[%c]   ",i,i);
	}
	printf("\n");
	return 0;
}
