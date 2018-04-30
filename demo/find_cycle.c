#include <stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};
typedef struct node  NODE;


void printList(NODE* list){
  while(list != NULL){
    printf("%d",list->data);
    list=list->next;
    }
}



NODE *crete_node(int n){
    NODE*new_node=(NODE*)malloc(sizeof(NODE));
    new_node->data=n;
    new_node->next=NULL;
    return new_node;
    
}
int check_cycle(NODE * head){
    int flag=1,cout=1;
    NODE * initial=head;
    while(head->next == NULL || flag){
        NODE *current=initial;
        for(int i=0; i<cout; i++){
            if(head->next == current ){flag=0;break;}
            else current=current->next;
        }
        cout++;
        head=head->next;
    }
    return flag?0:1;
}

int main(void) {
    NODE*head;
for(int i=1; i<=10; i++){
    NODE*node=crete_node(i);
    head->next=node;
    head=head->next;
}
//printList(head);
printf("%d",check_cycle(head));
	
	return 0;
}


