#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib.h"
#define COMMA ","
int run(int n);
char* fib(int n);
int main(int argc,char* argv[])
{
  int n,a;
  char str[255],ss[4],*s_fib;
  puts("put a number");
  scanf("%d",&n);
  for(int i=1;i < n;i++){
    a = run(i);
    strcat(str,itoa(a,ss,10));
    strcat(str,", ");
    printf("%d, ",a);
  }
  printf("\n\n%s \n",str);
  
  s_fib = fib(n);
  printf("\n%s \n\n",s_fib);
  return 0;
}

char* fib(int n)
{
    char *str,ss[4];
    int arr[255];
    str = malloc(sizeof(char*));
    
    for(int i = 0;i < n;i++){
        if(i < 2){
            arr[i] = 1;
        }else{
            arr[i] = arr[i-1] + arr[i-2];
        }
        strcat(str,itoa(arr[i],ss,10));
        strcat(str,", ");
    }
    return str;
}

int run(int n)
{
  if(n < 3){
    return 1;
  }else {
    return run(n - 1) + run(n - 2);
  }
}

