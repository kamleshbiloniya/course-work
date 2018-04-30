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

int isGrater(NODE *num1 ,NODE *num2){
   int flage=1,sign=1;
   
    while(flage && num1 !=NULL){
        if((num1->data - num2->data )< 0 ){
            sign =0;
        num1=num1->next;
        num2=num2->next;
        if(num1 !=NULL)num1->data =num1->data-1;
        else flage=0;
      
        }
        else{
            sign=1;
          num1=num1->next; 
          num2=num2->next;
        }
    }
    return sign;
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
	if(carry){
         	NODE *new_node=newNode(sum);
        	new_node->next=result;
        	result=new_node;
	}
    while(result->data == 0){
        result=result->next;
    }
    
    return result;
}


NODE *subtract(NODE *num1 , NODE * num2){
    int sub;
    NODE *result=NULL;
    while(num1 !=NULL && num2 !=NULL){
        if((num1->data -num2->data) <0){
           
            sub=10+(num1->data - num2->data);
            num1=num1->next;
            num2=num2->next;
            num1->data=num1->data - 1;
        }
        else  {sub=(num1->data - num2->data);
        
        num1=num1->next;
        num2 =num2->next;
        }
        NODE *new_node=newNode(sub);
        new_node->next=result;
        result=new_node;
    }
    while(num1 !=NULL){
        sub=num1->data;
        num1=num1->next;
        NODE *new_node=newNode(sub);
        new_node->next=result;
        result=new_node;
    }
    return result;
}

NODE *multiply(NODE *num1, NODE * num2 ,int n1,int n2){
    NODE *prevList=(NODE *)malloc(sizeof(NODE));
    prevList =NULL;
    for(int i=0; i<n2;i++){
   
       NODE *tmp=num1;
        if (i==0){
             int cross,carry=0;
            while(tmp != NULL){
        
                cross=(tmp->data * num2->data) +carry;
                carry=cross/10;
                cross=cross%10;
                
                NODE *new_node =newNode(cross);
                new_node->next=prevList;
                prevList=new_node;
                tmp=tmp->next;
                 
            }
            if(carry){
                NODE *new_node =newNode(carry);
                new_node->next=prevList;
                prevList=new_node;
            }
            
           
        }
        else {
            NODE *curntList = (NODE*)malloc(sizeof(NODE));
            curntList=NULL;
            int cross,carry=0;
            for(int j=0; j<i; j++){
                NODE * new_node=newNode(0);
                new_node->next=curntList;
                curntList=new_node;
            }
            while(tmp != NULL){
               
            
                cross=(tmp->data * num2->data) +carry;
                carry=cross/10;
                cross=cross%10;
                
                NODE *new_node =newNode(cross);
                new_node->next=curntList;
                curntList=new_node;
                tmp=tmp->next;
            }
            
              if(carry){
                NODE *new_node =newNode(carry);
                new_node->next=curntList;
                curntList=new_node;
            }
            
            prevList=reverse(prevList);
            
            curntList=reverse(curntList);
            
            NODE *addition=addNumber(prevList,curntList);
            prevList=addition;
            
            free(curntList);
            
            
        }
        num2=num2->next;
        
    
    }
    return prevList;
} 





int main(){
    int t,opcode;
   
    scanf("%d",&t);
    for(int i=0; i<t; i++){
        NODE * first=NULL;
        NODE * second = NULL;
        NODE *sum = NULL;
        NODE *sub =NULL;
        NODE *multiplication=NULL;
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
       
      switch(opcode){
         case 1:{sum=addNumber(first,second); printList(sum);break;}
         case 2: {
              if(n1>n2){
                  
                  sub=subtract(first,second);
                  printList(sub);
                  break;
                  }
              else if(n2>n1){
                  printf("-");
                  sub=subtract(second,first);
                  printList(sub);
                  break;
                } 
              else {
                  if(1/*isGrater(first,second)*/){
                      sub=subtract(first,second);
                      printList(sub);
                     
                      break;
                  }
                  else{
                     printf("-");
                     sub=subtract(second,first);
                     printList(sub);
                     break;
                  }
              }
          }
          case 3:{multiplication=multiply(first,second,n1,n2);printList(multiplication);break;}
          case 5:printf("%d",isGrater(first,second));break;
          default:printf("ERROR:use opcode from 1 to 4");
      
      }
        
       
        printf("\n");
    }
    return 0;
}
