/**
 * 
 */
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

