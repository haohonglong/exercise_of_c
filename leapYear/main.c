#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leap.h"
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
