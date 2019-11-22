#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define String char*


typedef struct Node{
	int n;
	struct Node *next;
}node;
int init();
int insert();
int find();
int traverse();
int delete();
int show();
static node *first = NULL;
int main(int argc,String argv[])
{
	int n;
	do{
		
		printf("\nMENU\n\n"
			"1 -- delete\n"
			"2 -- find\n"
			"3 -- insert\n"
			"4 -- traverse\n"
			"0 -- quit\n\n");
		printf("Command:  ");
		scanf("%d",&n);
		
		switch(n){
			case 1: delete(); break;
			case 2: find(); break;
			case 3: insert(); break;
			case 4: traverse(); break;
		
		}
		show();	
	
	}while(n != 0);
	return 0;
}

int show()
{
	if(NULL == first){
		return 0;
	}else{
		node *head = first;
		while(head != NULL){
			printf("%d--->",head->n);
			head = head->next;
		}
	}
	printf("\n\n");
}
	
int insert()
{	
	node *newptr = malloc(sizeof(node));
	if(NULL == newptr){
		return;
	}else{
		printf("Number to insert: ");
		scanf("%d",&newptr->n);
		newptr->next = NULL;
		if(NULL == first){
			first = newptr;
		}else if(newptr->n < first->n){
			newptr->next = first;
			first = newptr;
		}else{
			node *head = first;
			while(1){
				if(head->n == newptr->n){
					free(newptr);
					break;
				}else if(NULL == head->next){
					head->next = newptr;
					break;
				}else if(head->next->n > newptr->n){
					newptr->next = head->next;
					head->next = newptr;
					break;
				}
				head = head->next;
			}
		}		
	}

	return 0;

}

int find()
{
	node *head = first;
	int n;
	if(NULL == first){
		return;
	}else{
		printf("Number to find ");
		scanf("$d",&n);
		while(head != NULL){
			if(head->n == n){
				printf("\nNumber is %d\n\n",n);
				break;
			}

			head = head->next;
		}
	}	
	return 0;
	
}
int traverse()
{}
int delete()
{
	node *head = first;
	int n;
	if(NULL == head){
		return;
	}else{
		printf("Number to delete  ");
		scanf("%d",&n);
		while(head != NULL){
			if(n == head->n){
				printf("the number %d had deleted",n);
				if(NULL == head->next){
					free(head);
				}else{
					head->next = head->next->next;	
				}

				break;
			}
			head = head->next;
		}
	}
	return 0;
}



