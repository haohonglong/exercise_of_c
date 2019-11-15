#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char* argv[])
{
   int i = 1,j = 1;
   int class_ = atoi(argv[1]);
   int stu = atoi(argv[2]);
   float score = 0.0,sum = 0.0,total = 0.0;
   for(j = 1;j<=class_;j++){
     sum = 0.0;
     for(i = 1 ; i<=stu; i++){
       printf("please input the score of sutdent which the number %d student in class %d \n",i,j);
       scanf("%f",&score);
       sum += score;
     }	
     printf("the average is %f who students are score of total \n",sum/stu);
     total += sum;
   }
   printf("total average are %f who students of the 3 classes \n",total / (class_*stu));
   return 0;
}
