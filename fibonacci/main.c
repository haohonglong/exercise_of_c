#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib.h"
#define COMMA ","
int run(int n);
int main(int argc,char* argv[])
{
  int n,a;
  char str[255],ss[8];
  puts("put a number");
  scanf("%d",&n);
  for(int i=1;i < n;i++){
    a = run(i);
    strcat(str,itoa(a,ss,10));
    strcat(str,", ");
    printf("%d, ",a);
  }
  printf("\n%s \n",str);

  return 0;
}

int run(int n)
{
  if(n < 3){
    return 1;
  }else {
    return run(n - 1) + run(n - 2);
  }
}

