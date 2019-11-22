#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define String char*
#define BR printf("\n")
#define HEAD "\n ********************************** \n"
void calendar(String date[],int* idate);

int main(int argc,String argv[])
{
	if(1 == argc){
		printf("\n ERROR! you forgot to enter the date you want to view \n");
		exit(0);
	}
	int idate[3];
	printf("\n the calendar of this month as following \n");
	printf(HEAD);
	printf("SUN  MON  TUE  WEN  THU  FRI  STA \n");
	for(int i=1;i<=31;i++){
		//delay(200);
		printf("%3d  ",i);
		if(0 == i%7)
			printf("\n");
	}
	printf("\n");
	exit(0);
	calendar(argv,idate);
	printf(HEAD);
	printf("\n year->%d\n",idate[0]);
	printf("\n month->%d\n",idate[1]);
	printf("\n day->%d\n",idate[2]);

	return 0;
}
void calendar(String date[],int* idate)
{
	int year =0,month=0,day=0,week;
	int d,i,dm,dy,m2;
	char WEEK[9],cdate;
	i=0;d=-1;
	char* _date = date[1];
	while(cdate = _date[i]){
		
		if('/' == cdate || '.' == cdate) {
			if(-1 == d){
				d = 0;
			}else if(0 == d){
				d = 1;
			}
			i++;continue;
		}

		switch(d){
		    case -1:
				year = year * 10+ cdate-'0';
			   break;
			case 0:
		   	   month = month * 10+ cdate-'0';
			   break;
			case 1:
				day = day * 10+ cdate-'0';
			   break;

	    }	
		i++;
	}
	idate[0] = year;
	idate[1] = month;
	idate[2] = day;
	

}
