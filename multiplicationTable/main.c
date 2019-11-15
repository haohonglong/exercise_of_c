#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void run(int row,int col);
int main(int argc,char* argv[])
{
  int row = 9;
  int col = 9;
  run(row,col);
  return 0;
}

void run(int row,int col)
{
   int i,j;
   for(i = 1;i<=row;i++){
     for(j = 1 ; j<=i; j++){
       printf("%d * %d = %d",j,i,i*j);
       printf("   ");
     }	
     printf("\n");
   }
   
}

