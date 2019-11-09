/**
 * 
 */
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include "./student.h"
#define SIZE 5
int main(int argc,char *argv[]) 
{
	FILE *fp;
	uint i;
	Student *s,su,arr[SIZE];
	str16 name = "student_list";
	fp = fopen(name,"rb");
	if(NULL == fp ||  (fread(arr,sizeof(arr),SIZE,fp) != SIZE)){
	puts("--------------------------");
		fp = fopen(name,"wb+");
		if(NULL == fp){
			puts("ERROR: cannot opent the file!");
			exit(1);
		}
		
		for(i=0;i < SIZE; i++){
			system("clear");
			s = arr+i;
			student_input(s);
		}
		file(fp,arr);
	
	}

	for(i=0;i < SIZE; i++){

		student_print(arr[i]);
	}
	fclose(fp);
	return 0;

}
int file(FILE *fp,Student *arr){
	if(fwrite(arr,sizeof(Student),SIZE,fp) != SIZE ){
		puts("ERROR: Write file error!");
		fclose(fp);
		exit(1);
	}
	rewind(fp);
	if(fread(arr,sizeof(arr),SIZE,fp) != SIZE){
		puts("ERROR:read file error!");
		
	}
	
}
int student_input(Student *s){
	static uint i=0;
	s->id = ++i;
        printf("please input the number %d member \n",i);	
	puts("age:");
	scanf("%d",&s->P.age);

	puts("name:");
	scanf("%s",s->P.name);

	puts("school:");
	scanf("%s",s->school);

	puts("book:");
	scanf("%s",s->B.name);

	puts("bookID:");
	scanf("%d",&s->B.id);

	return 0;
	
}
int student_print(Student stu){

	static int n =0;
	if(0 == n){
		puts("+------------------------------------------------------------------------+");
		puts("| id   | name  |  age  |     school |      bookId  |        bookName     |");
		puts("--------------------------------------------------------------------------");
	}
	printf("|% - 3d   |% - 6s |%5d  |     %6s|      %3d |             %5s  |\n",
	stu.id,
	stu.P.name,
	stu.P.age,
	stu.school,
	stu.B.id,
	stu.B.name
	);
	puts("+------------------------------------------------------------------------+");
	n++;
	return 0;
}




