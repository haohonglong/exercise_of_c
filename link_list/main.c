#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define String char*


typedef struct Node{
	int n;
	struct Node *next;
}node;
node *create();
int init();
int insert();
int find();
int traverse();
int delete(int n);
int show();
static node *first = NULL;
int main(int argc,String argv[])
{
	int n;
	node *first;
	do{
		
		printf("\nMENU\n\n"
			"1 -- delete\n"
			"2 -- find\n"
			"3 -- insert\n"
			"4 -- traverse\n"
			"-1 -- quit\n\n");
		printf("Command:  ");
		scanf("%d",&n);
		
		switch(n){
			case 1:
				printf("\n Number to delete  \n");
				scanf("%d",&n);
				delete(n); 
				break;
			case 2: find(); break;
			case 3: insert(); break;
			case 4: traverse(); break;
		
		}
		show();	
	
	}while(n != -1);
	return 0;
}

node *create()
{
	node *head = (node *)malloc(sizeof(node));
	return head;
}

int show()
{
	if(NULL == first){
		return 0;
	}else{
		node *head = first;
		while(head != NULL){
			printf("%d",head->n);
			if(head->next != NULL){
				printf("--->");
			}
			head = head->next;
		}
	}
	printf("\n\n");
}
	
int insert()
{	
	node *newptr = create();
	if(NULL !=  newptr){
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
	if(NULL != first){
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
int delete(int n)
{
	node *head = first;
	node *p;
	if(NULL != head){
		while(head != NULL && head->n !=n && head->next != NULL){
			p = head;
			head = head->next;
		
		}
		if(head->n == n){
			if(first == head){
				first = head->next;
				free(head);
			}else{
				p->next = head->next;	
			}
				
		}else{
			printf("\n %d could not been found",n);
		}
	}
	return 0;
}



