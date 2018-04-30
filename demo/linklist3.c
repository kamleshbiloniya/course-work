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

int main(){
    int t,opcode;
    NODE * first=NULL;
    scanf("%d",&t);
    for(int i=0; i<t; i++){
        int n1,n2;
        scanf("%d %d",&n1,&n2);
        getchar();
        for(int i=0; i<n1; i++){
             char digit;
             digit = getchar();
             digit=digit-48;
             addNode(&first,digit);
             printf("%d",digit);
        }
        printf("\n");
        printList(first);
        printf("\n");
        getchar();
        for(int i=0; i<n2; i++){
            char digit;
            digit = getchar();
            digit=digit-48;
            printf("%d",digit);
        }
        printf("\n");
        getchar();
        scanf("%d",&opcode);
        printf("%d",opcode);
     printf("\n");
    }
   
    return 0;
}
