#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib.h"
#define COMMA ","
int run(int n);
static char* arr;
int main(int argc,char* argv[])
{
  int num,sum;
  puts("put a number");
  scanf("%d",&num);
  sum = run(num);
  printf("%d \n",sum);
  // printf("%s \n",arr);
  return 0;
}

int run(int n)
{
  int a;
  char* b;
  if(1 == n || 2 == n){
    a = 1;
  }else {
    a = run(n - 1) + run(n - 2);
  }
  itoa(a,b,10);
  // strcat(arr,COMMA);
  // strcat(arr,b);
  return a;
  
}

