#define __STDC_WANT_LIB_EXT1__ 1
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
 #define LEN 10
int main(void) 
{
	char tr[]    = "+-----------------------------------------+\n";
	char td[]    = "|---------|-----------|----------|--------|\n";
	char *table = (char *) malloc((strlen(tr) + strlen(td))*LEN);
	sprintf(table,"%s%s",tr,td);
	printf("%s\n", table);
	free(table);
	return 0;

}
