#include<stdio.h>
#include<stdlib.h>
 
struct Node {
	int data;
	struct Node* next;
};
typedef struct Node NODE;

struct NODE *newNode(int data){
	struct NODE *new_node = (struct NODE *)malloc (sizeof(struct NODE));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void push (struct NODE ** head_ref ,int val){       //value that to be added
	struct new_node = newNode(val);
	new_node->next = *head_ref;
	*head_ref = new_node;
}
void Exceptionmessage(int excode){ //error message printer
	if(excode ==1)printf("ERROR:both the given number are NULL\n");
}
struct NODE* addTwoNumber(struct NODE *num1 ,struct NODE *num2){
	struct NODE *result=NULL,*preNode=NULL;
	int sum ,carry=0;
	if(num1==NULL && num2 == NULL)Expceptionmessage(1);
	while(num1 !=NULL || num2 !=NULL){
		sum = carry + (num1? num1-> data: 0) + (num2? num->: 0);

		if(sum>=10 && sum <=19)carry=1;
		else if (sum >=20)carry=2;
		else carry =0;

		sum=sum % 10;
		tmp = newNode(sum);

		if (result == NULL) result = tmp;
		else {
			preNode->next =tmp ;
			preNode=tmp;
		}
	
		if (num1)num1=num1->next;
		if (num2)num2=num2->next;


	}
	if(carry>0)temp->next =newNode(carry);

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
 for(int a=0; a<t; a++){
 	int n1,n2;
	scanf("%d %d",&n1,&n2);
	struct NODE *first = NULL;
	struct NODE *second = NULL;
	struct NODE *resut = NULL;
	for (int i=0; i<n1; i++){
		int digit;
		scanf("%d",&digit);
		push(&first,digit);
	}
	for(int i=0;i<n2;i++){
		int digit;
		scanf("%d",&digit);
		push(&second,digit);
	}

	int opcode;
	scanf("%d",&opcode);
	switch(opcode){
		case 1:result=addTwoNumber(first,second);
		case 2:resurt=subTwoNumber(fist,second);
		case 2:result=mulTwoNumber(first,second);
		case 4:result=dividTwoNumber(first,second);
		default:printf("Please use opcode integer in range from 1 to 4\n");
			printf("1 for addition of two number\n");
			printf("2 for stubtract frist number from second \n");
			printf("3 for multiply two number\n");
			printf("4 for divid frist number by second number\n");
			 
	}
	printNumber(result);
	printf("\n");


	

 	
 }
 
 
 return 0;
 }
