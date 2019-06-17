#include <stdio.h>
#include <stdlib.h>
 
int main(int argc,char* argv[])
{
	FILE* fp;
	char* name = argv[1];
	fp = fopen(name, "r");
	if(!fp){
		printf("file opening failed:");
		return EXIT_FAILURE;
	}
	int c;
	while((c = fgetc(fp)) != EOF){
		putchar(c);
	}
	if(ferror(fp)){
		puts("I/O error when reading");
	}else{
		puts("End of file reached successfully");
	}
	fclose(fp);
	return 0;
}



