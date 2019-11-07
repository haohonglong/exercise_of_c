#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib.h"
#define N 10

static char str[255];
int main(int argc,char* argv[])
{
    SDS *s,sds;
    s = &sds;
    int size = N*sizeof(int);
    char ch;
    while(1){
        printf("q is quit or anything that continue:");
        scanf("%c",&ch);
        printf("the ch is %c \n",ch);
        if('q' != ch){
            puts("input some string:");
            scanf("%s",str);
            input(s,size);
        }else{
            break;
        }
    }
   
   
    return 0;
}
int input(SDS *s,int size)
{
    register int n;
   
    n = len(str);
    s->buf = (char*)malloc(size);
    s->len = n;
    s->free = size - n;
    strcpy(s->buf,str);
    printf("the int: %d \n",sizeof(int));
    printf("the size of memory: %d \n",size);
    printf("the free: %d \n",s->free);
    printf("the len: %d \n",s->len);
    printf("the buf: %d \n",len(s->buf));
    printf("the length: %d \n",strlen(str));

    return 0;

}
