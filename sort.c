#include<stdio.h>
#include<string.h>
#define String char*
#define length(arr,type) (sizeof(arr) / sizeof(type))
int bubbling(int arr[],int n);
int select(int arr[],int n);
int swap(int *a,int *b);
int print(int *arr,int n);
int main(int argc,String argv[])
{
	int arr[]={ 10,6,5,2,3,8,7,4,9,1 };

	
	int n;
	int len = length(arr,int);
	print(arr,len);
	printf("MENU\n"
			"-- 1 bubbling\n"
			"-- 2 select\n");
	printf("\n\n");
	printf("Number to sort  ");
	scanf("%d",&n);
	switch(n){
		case 1:
			bubbling(arr,len);
			break;
		case 2:
			select(arr,len);
			break;	
	}
	print(arr,len);
	
	return 0;
}

int print(int *arr,int n){
	printf("\n\n");
	for(int i=0;i < n;i++){
		if(i>0){
			printf(",");
		}
		printf("%d",arr[i]);
	}
	printf("\n\n");
}

int bubbling(int arr[],int n)
{
	int len = n;
	int flag = 1;
	for(int i=0;i < len-1;i++){
		for(int j=0;j < len-i-1;j++){
			if(arr[j] > arr[j+1]){
				swap(&arr[j],&arr[j+1]);
				flag = 0;
			}
		}
		if(flag)
			break;
	}
}
int select(int arr[],int n)
{
	int len = n;
	int max;
	int flag = 0;
	for(int i=0;i < len;i++){
		max = i;
		flag = 0;
		for(int j=i+1;j < len;j++){
			if(arr[j] <  arr[max]){
				max = j;
				flag = 1;
			}
		}
		if(max != i){
			swap(&arr[i],&arr[max]);
		}
	}
}


int swap(int *a,int *b){
	int tem;
	tem = *b;
	*b = *a;
	*a = tem;
	return 0;
}
