#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int is_leap(int year);
int main(int argc,char* argv[])
{
  int year = atoi(argv[1]);
  if(1 == is_leap(year)){
    printf("%d is leap year \n",year);
  }else{
    printf("%d is not leap year \n",year);
  }
  return 0;
}

int is_leap(int year)
{
  if(0 == year%4 && year%100 != 0 || 0 == year%400){
    return 1;
  }
  return 0;
}