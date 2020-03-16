//打印文件名称，行号
#define LOG(format,...) printf("%s %s:%d: "format"\n",__TIME__,__FILE__, __LINE__, ##__VA_ARGS__)

typedef struct _SDS{
    int len;
    int free;
    char* buf;
}SDS;

char* itoa(int num,char* str,int radix);
int split(char dst[][80], char* str, const char* spl);
void swap(char *a,char *b);
void order(char* str,const char* literal);
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


char* itoa(int num,char* str,int radix)
{
        char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";//索引表
        unsigned unum;//存放要转换的整数的绝对值,转换的整数可能是负数
        int i=0,j,k;//i用来指示设置字符串相应位，转换之后i其实就是字符串的长度；转换后顺序是逆序的，有正负的情况，k用来指示调整顺序的开始位置;j用来指示调整顺序时的交换。
 
        //获取要转换的整数的绝对值
        if(radix==10&&num<0)//要转换成十进制数并且是负数
        {
                unum=(unsigned)-num;//将num的绝对值赋给unum
                str[i++]='-';//在字符串最前面设置为'-'号，并且索引加1
        }
        else unum=(unsigned)num;//若是num为正，直接赋值给unum
 
        //转换部分，注意转换后是逆序的
        do
        {
                str[i++]=index[unum%(unsigned)radix];//取unum的最后一位，并设置为str对应位，指示索引加1
                unum/=radix;//unum去掉最后一位
 
        }while(unum);//直至unum为0退出循环
 
        str[i]='\0';//在字符串最后添加'\0'字符，c语言字符串以'\0'结束。
 
        //将顺序调整过来
        if(str[0]=='-') k=1;//如果是负数，符号不用调整，从符号后面开始调整
        else k=0;//不是负数，全部都要调整
 
        char temp;//临时变量，交换两个值时用到
        for(j=k;j<=(i-1)/2;j++)//头尾一一对称交换，i其实就是字符串的长度，索引最大值比长度少1
        {
                temp=str[j];//头部赋值给临时变量
                str[j]=str[i-1+k-j];//尾部赋值给头部
                str[i-1+k-j]=temp;//将临时变量的值(其实就是之前的头部值)赋给尾部
        }
 
        return str;//返回转换后的字符串

}

// 将str字符以spl分割,存于dst中，并返回子字符串数量
int split(char dst[][80], char* str, const char* spl)
{
    int n = 0;
    char *result = NULL;
    result = strtok(str, spl);
    while( result != NULL )
    {
        strcpy(dst[n++], result);
        result = strtok(NULL, spl);
    }
    return n;
}


void swap(char *a,char *b)
{
    char c;
    c = *a;
    *a = *b;
    *b = c;
}

void order(char* str,const char* literal)
{
   int n = len(str);
   for(int i=0;i < n;i++){
        for(int j = i+1;j < n; j++){
                if(0 == strcmp("ASC",literal)){
                        if(str[i] < str[j]){
                                swap(str+i,str+j);
                        }
                }else if(0 == strcmp("DESC",literal)){
                        if(str[i] > str[j]){
                                swap(str+i,str+j);
                        }
                }
                
        }
   }
}

