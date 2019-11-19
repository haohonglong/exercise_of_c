#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib.h"
int run(char* str);
int main(int argc,char* argv[])
{
    char str[1];
    puts("please put a number that is four numbers");
    scanf("%s",str);
    run(str);
    return 0;
}

int run(char* str)
{
  static int total = 0;
  char desc[4],asc[4];
  int i_desc,i_asc,num;
  
  if(6174 == atoi(str)){
    printf("%s\n",str);
    printf("total is: %d\n",total);
  }else{
    total++;  
    strcpy(desc,str);
    strcpy(asc,str);
    order(asc,"ASC");
    order(desc,"DESC");
    i_desc = atoi(desc);
    i_asc = atoi(asc);
    num = i_asc - i_desc;
    itoa(num,str,10);
    printf("%d - %d = %d \n",i_asc,i_desc,num);
    run(str);
  }  
  return 0;
}

