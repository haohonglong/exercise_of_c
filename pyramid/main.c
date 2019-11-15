#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void run1(int row,int col);
void up(int row,int col);
void down(int row,int col);
void up_empty(int row,int col);
void down_empty(int row,int col);
int main(int argc,char* argv[])
{
  int row = atoi(argv[1]);
  int col = atoi(argv[2]);
  int opt = atoi(argv[3]);
  switch (opt){
    case 1:
     run1(row,col);
     break;
    case 2:
     up(row,col);
     break;
    case 3:
     up(row,col);
     down(row-1,col);
     break;
    case 4:
     up_empty(row,col);
     down_empty(row-1,col);
     break;

  } 
  return 0;
}

void run1(int row,int col)
{
   int i,j;
   for(i = 0;i<=row;i++){
     for(j = 0 ; j<=i; j++){
       printf("*");
     }	
     printf("\n");
   }
   
}

void up(int row,int col)
{
   int i,j,k;
   for(i = 1;i<=row;i++){
     for(k = 1; k <= row-i;k++){
       printf(" ");	  
     }
     for(j = 1 ; j<=2*i-1; j++){
       printf("*");
     }	
     printf("\n");
   }
   
}

void down(int row,int col)
{
  int i,j,k;
  for(i=row;i>=1;i--){
   for(k=0;k <= row-i;k++){
    printf(" "); 
   }
   for(j = 2*i-1; j>=1; j--){
     printf("*");
   }
   printf("\n");
  }
}

void up_empty(int row,int col)
{
   int i,j,k;
   for(i = 1;i<=row;i++){
     for(k = 1; k <= row-i;k++){
       printf(" ");	  
     }
     for(j = 1 ; j<=2*i-1; j++){
       if(1 == j || j == 2*i-1){
          printf("*");
       }else{
          printf(" ");
       }
       
     }	
     printf("\n");
   }
   
}

void down_empty(int row,int col)
{
  int i,j,k;
  for(i=row;i>=1;i--){
   for(k=0;k <= row-i;k++){
    printf(" "); 
   }
   for(j = 2*i-1; j>=1; j--){
     if(j == 2*i-1 || j == 1){
      printf("*");
     }else{
      printf(" ");
     }
     
   }
   printf("\n");
  }
}
