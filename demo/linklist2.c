#include<stdio.h>
#include<stdlib.h>
 
struct NODE {
	int data;
	struct NODE* next;
};

struct NODE *newNode(int data){
	struct NODE *new_node = (struct NODE *)malloc (sizeof(struct NODE));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
	free(new_node);
}


void push (struct NODE ** head_ref ,int val){  
    static int num=1;//value that to be added
	struct NODE *new_node=(struct NODE*)malloc(sizeof (struct NODE));
	new_node = newNode(val);
	new_node->next = *head_ref;
	*head_ref = new_node;
    printf("%d th digit is %d\n",num ,new_node->data);num++;
	free(new_node);
}

struct NODE* addTwoNumber(struct NODE *num1 ,struct NODE *num2){
	struct NODE *result=NULL,*preNode=NULL,*tmp;
	int sum ,carry=0;
	
	while(num1 !=NULL || num2 !=NULL){
		sum = carry + (num1? num1->data: 0) + (num2? num2->data: 0);
 
		if(sum>=10 && sum <=19)carry=1;
		else if (sum >=20)carry=2;
		else carry =0;
 
		sum=sum % 10;
		tmp = newNode(sum);
 
		if (result == NULL){
		    result = tmp;
		    preNode=tmp;
		}
		else {
			preNode->next =tmp ;
			preNode=tmp;
		}
 
		if (num1)num1=num1->next;
		if (num2)num2=num2->next;
 
 
	}
	if(carry>0){
	    tmp=newNode(carry);
	    preNode->next =tmp;
	}
 
	return result;
 
}
 



void printNumber( struct NODE *n){

	while(n->next !=NULL){
		printf("%d",n->data);
		n=n->next;
	}
	printf("\n");


}


int main (){
	
 
 int t;//number of test cases
 scanf("%d",&t);
 printf("t=%d\n",t);
 for(int a=0; a<t; a++){
 	int n1,n2;
 	struct NODE *first = NULL;
	struct NODE *second = NULL;
	struct NODE *result = NULL;
	scanf("%d %d",&n1,&n2);

	for (int i=0; i<n1; i++){
		int digit;
		scanf("%d",&digit);
		push(&first,digit);
	}
	printNumber(first);
	for(int i=0;i<n2;i++){
		int digit;
		scanf("%d",&digit);
		push(&second,digit);
	}
	printf("\n");
	printNumber(second);
	printf("\n");
	int opcode;

	scanf("%d",&opcode);
	
	result=addTwoNumber(first,second);
    printNumber(result);
	
 }
   
 
 return 0;
 }
