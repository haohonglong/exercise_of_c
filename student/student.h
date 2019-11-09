/**
 * 
 */
typedef unsigned int uint;
typedef char  str8[8];
typedef char  str16[16];
typedef char  str32[32];
typedef char  str64[64];
typedef char  str128[128];
typedef char  str255[255];
typedef struct _book{
	uint id;
	str64 name;
}Book;

typedef struct _person{
	uint id;
	str32 name;
	uint age;
	uint sex;
}Person;
typedef struct _student{
	uint id;
	str64 school;
	Person P;
	Book B;
	
}Student;
typedef struct _employee{
	str16 number;
	float wage;
	str64 address;
	Person P;
}Employee;

int student_print(Student stu);
int student_input(Student *s);
int file(FILE *fp,Student *arr);

