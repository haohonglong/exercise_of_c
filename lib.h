typedef struct _SDS{
    int len;
    int free;
    char* buf;
}SDS;

int len(char *s);
int input(SDS *s,int size);
int len(char *str)
{
    int i=0;
    char *s = str;
    while(*s != '\0'){
	i++;
        s++;
    }
    return i;
}
