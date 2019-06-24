/**
 * 
 */
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
typedef unsigned int UINT;
typedef char  String[31];
typedef struct _book{
	UINT id;
	String name;
}Book;

typedef struct _person{
	UINT id;
	String name;
	UINT age;
	UINT sex;
}Person;
typedef struct _student{
	UINT id;
	String school;
	Person P;
	Book B;
	
}Student;
typedef struct _employee{
	String number;
	float wage;
	String address;
	Person P;
}Employee;

int student_print(Student stu);
int student_input(Student *s);
int file(FILE *fp,Student *arr);
int main(int argc,char *argv[]) 
{
	FILE *fp;
	UINT i;
	Student *s,su,arr[SIZE];
	char * name = "student_list";
	fp = fopen(name,"rb");
	if(NULL == fp ||  (fread(&arr,sizeof(arr),SIZE,fp) != SIZE)){
		fp = fopen(name,"wb+");
		if(NULL == fp){
			puts("ERROR: cannot opent the file!");
			fclose(fp);
			exit(1);
		}
		
		for(i=0;i < SIZE; i++){
			system("clear");
			s = &arr[i];
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
	if(fwrite(&arr,sizeof(Student),SIZE,fp) != SIZE ){
		puts("ERROR: Write file error!");
		fclose(fp);
		exit(1);
	}
	rewind(fp);
	if(fread(&arr,sizeof(arr),SIZE,fp) != SIZE){
		puts("ERROR:read file error!");
		
	}
	
}
int student_input(Student *s){
	puts("ID:");
	scanf("%d",&s->id);

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

	static n =0;
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




