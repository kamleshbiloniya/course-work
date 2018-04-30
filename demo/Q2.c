#include <stdio.h>
#include<stdlib.h>


struct node {
	int data;
	struct node* next;
};
typedef struct node NODE;

NODE *newNode(int data);
int isEmpty(NODE * queue){
    if(queue == NULL)return 1;
    return 0;
}


NODE *reverse(NODE* list){
    NODE *newList=(NODE *)malloc(sizeof(NODE));
    newList =NULL;
    while(list !=NULL){
        NODE *new_node=newNode(list->data);
        if(newList == NULL)newList=new_node;
        else {
            new_node->next = newList;
            newList=new_node;
        }
        list=list->next;
    }
    return newList;
}

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



int main(void) {
int t;
scanf("%d",&t);
for(int i=0; i<t; i++){
    int q;
    NODE *queue=(NODE *)malloc(sizeof(NODE));
    queue=NULL;
    scanf("%d",&q);
    for(int j=0; j<q; j++){
        int opcode;
        scanf("%d",&opcode);
        if(opcode==1){
            int val;
            scanf("%d",&val);
            queue=reverse(queue);
            addNode(&queue,val);
            printf("%d\n",queue->data);
            queue=reverse(queue);
        }
        else if(opcode == 2){
            if(isEmpty(queue)){
                printf("Empty\n");
            }
            else{
              printf("%d\n",queue->data);
              queue=queue->next;
            }
        }
        else {
            if(isEmpty(queue))printf("True\n");
            else printf("False\n");
        }
    }
}
	return 0;
}


