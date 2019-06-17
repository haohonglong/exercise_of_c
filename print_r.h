void print_r(char* tr);
#define String char*
#define print(s) printf("%s\n",s)
void print_r(String tr)
{
	String p;
	p = tr+(strlen(tr)-1);
	int i=0;
	while(*p){
		print(p);
		p--;
		i++;

	}
	p = tr+1;
	while(*p){
		print(p);
		p++;

	}


	printf("i: %d\n",i);
	printf("int is ---------> %d\n",sizeof(int)*2);

}
