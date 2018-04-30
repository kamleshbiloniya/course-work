#include<stdio.h>
#include<stdlib.h>
 
struct node {
	int data;
	struct node* next;
};

typedef struct node NODE;

NODE *newNode(int data){
    NODE *new_node=(NODE *)malloc(sizeof(NODE));
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}

void addNode(NODE **list ,int val){
    
    NODE *new_node=newNode(val);
    new_node->next=*list;
    *list=new_node;
    return;
    }
void printList(NODE* list){
  while(list != NULL){
    printf("%d",list->data);
    list=list->next;
    }
}


NODE * addNumber(NODE *num1 ,NODE *num2){
    int sum,carry=0;
    NODE *result=NULL;
    while(num1 !=NULL || num2 != NULL){
        sum=carry +(num1? num1->data : 0)+(num2? num2->data :0);
        if(sum>=10 &&sum<=19)carry=1;
        else if (sum>=20)carry=2;
        else carry=0;
        sum=sum%10;
        NODE *new_node=newNode(sum);
        new_node->next=result;
        result=new_node;
        if(num1)num1=num1->next;
        if(num2)num2=num2->next;
    }
    return result;
}


int main(){
    int t,opcode;
   
    scanf("%d",&t);
    for(int i=0; i<t; i++){
        NODE * first=NULL;
        NODE * second = NULL;
        NODE *sum = NULL;
        int n1,n2;
        scanf("%d %d",&n1,&n2);
        getchar();
        for(int i=0; i<n1; i++){
             char digit;
             digit = getchar();
             digit=digit-48;
             addNode(&first,digit);
             
        }
       
        getchar();
        for(int i=0; i<n2; i++){
            char digit;
            digit = getchar();
            digit=digit-48;
            addNode(&second,digit);
           
        }
     
        getchar();
        scanf("%d",&opcode);
       
      
    
        sum=addNumber(first,second);
        printList(sum);
        printf("\n");
    }
    return 0;
}
