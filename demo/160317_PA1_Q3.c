#include <stdio.h>
#include<stdlib.h>


struct node {
	int data;
	struct node* next;
	
};
typedef struct node NODE;

NODE *newNode(int data);
NODE *reverse(NODE* list);


int isEmpty(NODE * queue){
    if(queue == NULL)return 1;
    return 0;
}

NODE *printFirst(NODE *q){
    q=reverse(q);
    printf("%d\n",q->data);
    q=q->next;
    return reverse(q);
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
    int n,q;
    scanf("%d %d",&n,&q);
    NODE **queue;
    queue=(NODE**)malloc(n*sizeof(NODE*));
    
    
    for(int i=1; i<=n; i++){
        queue[i]=(NODE*)malloc(sizeof(NODE));
        queue[i]=NULL;
       
    }
    for(int j=0; j<q; j++){
        int opcode;
        scanf("%d",&opcode);
        if(opcode ==1){
            int i,val;
            scanf("%d %d",&val,&i);
            
            addNode(&queue[i],val);
         
            printf("%d\n",queue[i]->data);
            
        }
        else if(opcode==2){
            int i;
            scanf("%d",&i);
            if(isEmpty(queue[i]))printf("Empty\n");
            else {
                
                 queue[i]=printFirst(queue[i]);
            }
            
        }
        else{
            int i;
            scanf("%d",&i);
            if(isEmpty(queue[i]))printf("True\n");
            else printf("False\n");
            
        }
    }
    
    }  
	return 0;
}


