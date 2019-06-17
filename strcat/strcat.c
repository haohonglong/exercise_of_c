#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
 #define LEN 10
int main(int argc,char* argv[]) 
{
	char tr[]    = "+-----------------------------------------+\n";
	//char td[]  = "|---------|-----------|----------|--------|\n";
	char td[]    = "----%s---";
	char* data[] = {
		"li","zhao","qian","sun","li"
		
	};
	//char *table = (char *) malloc((strlen(tr) + strlen(td))*LEN);
	printf("%s", tr);
	int n = 0;
	size_t total = 5;
	for(int i=0;i<LEN;i++){
		printf("|");
		for(int j=0;j<4 && n < total;j++){
			printf(td,data[n]);
			printf("|");
			n++;
		}
		printf("\n");
	}
	printf("%s", tr);
	return 0;

}
