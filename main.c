#include<stdio.h>
#include<string.h>
#include"print_r.h"
#define String char*
int main(int argc,String argv[])
{
	String table="";
	String p;
	char tr[]    = "+-----------------------------------------+";
	char td[]    = "|---------|-----------|----------|--------|";
	/*
	char tr[] = "abcdefghijklmnopqrstuvwxyz";
	char td[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZhhhh";
	*/
	int n[] = {1,2,3,4,5,6,7,8,9};
	/*strcat(tr,td);*/
	printf("%s\n",tr);
	/*printf("%p\n",table);*/
	
	print_r(tr);
	printf("tr : %#x\n",tr);
	printf("address of tr : %#x\n",&tr);
	printf("array of tr : %#x\n",&(tr[0]));
	return 0;
}
