
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
typedef unsigned int UINT;
typedef char* STRINGS;

typedef struct book{
	UINT id;
	STRINGS name;
}book;

typedef struct person{
	UINT id;
	STRINGS name;
	UINT age;
	UINT sex;
}person;
typedef struct student{
	UINT id;
	STRINGS school;
	person P;
	book B;
	
}student;

int main(void) 
{
	student stu,*s;
	s = &stu;
	s->id++;
	s->school = "xxxxxxx";
	s->P.id++;
	s->P.name = "linux";
	s->P.sex=1;
	s->P.age=30;
	s->B.id=10245500;
	s->B.name="java";


	puts("+------------------------------------------------------------------------+");
	puts("| id   | name  |  age  |     school |      bookId  |        bookName     |");
	puts("--------------------------------------------------------------------------");
	printf("|%3d   |%6s |%5d  |     %6s|      %3d |             %5s  |\n",
	stu.id,
	stu.P.name,
	stu.P.age,
	stu.school,
	stu.B.id,
	stu.B.name
	);
	puts("+------------------------------------------------------------------------+");

	return 0;

}




