/**
 * 
 */
typedef unsigned int UINT;
typedef char  STR16[16];
typedef char  STR32[32];
typedef char  STR64[64];
typedef struct _book{
	UINT id;
	STR16 name;
}Book;

typedef struct _person{
	UINT id;
	STR16 name;
	UINT age;
	UINT sex;
}Person;
typedef struct _student{
	UINT id;
	STR64 school;
	Person P;
	Book B;
	
}Student;
typedef struct _employee{
	STR16 number;
	float wage;
	STR64 address;
	Person P;
}Employee;

int student_print(Student stu);
int student_input(Student *s);
int file(FILE *fp,Student *arr);

