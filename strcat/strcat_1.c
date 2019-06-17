#define __STDC_WANT_LIB_EXT1__ 1
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
 #define LEN 10
int main(int argc,char* argv[]) 
{
	char tr[]    = "+-----------------------------------------+\n";
	char td[]    = "|---------|-----------|----------|--------|\n";
	char *table = (char *) malloc((strlen(tr) + strlen(td))*LEN);
	strcpy(table, tr);
	int i=0;
	for(;i<LEN;i++){
		strcat(table, td);
		if(i == LEN-1)
			strcat(table, tr);
	}
	printf("%s\n", table);
	free(table);
	return 0;

}
