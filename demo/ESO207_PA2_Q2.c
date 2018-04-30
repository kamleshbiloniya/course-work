#include <iostream>
#include <stack>
#include <vector>
#include<stdio.h>
using namespace std;
struct Node {
    int  p;
    int putr;
	struct Node* son;
};
typedef struct Node NODE;

void printchild(int i, vector<NODE*>v,int n){
    
   // if(flag==0){
    int count=0;
    for(int t=0; t<n; t++){
        if(v[t]->p==i)count++;
    }
  if(count==0){
      printf("%d ",i);}
 else{ 
    for(int t=0; t<count/2; t++){
        int index,l;
        int min=100000;
        for(l=0; l<n; l++){
            if(v[l]->p==i){
                if(((v[l]->putr)<min)){
                min=v[l]->putr;
                index=l;}
                //break;
            }
            else{
                continue;
            }
        }
       printchild(min,v,n);
        v[index]->putr=100000;
        // min=100000;
    }
    printf("%d ",i);
    for(int t=0; t<count/2; t++){
        int index,l;
        int min=100000;
        for(l=0; l<n; l++){
            if(v[l]->p==i&&((v[l]->putr)<min)){
                min=v[l]->putr;
                index=l;
               // break;
            }
            else{
                continue;
            }
        }
        printchild(min,v,n);
        v[index]->putr=100000;
         //min=100000;
    }
  }
  
  
  /*int flag=0;int c=0;
    for(int a=0; a<n; a++){
        if(v[a]->p==i){
    for(int j=0; j<n; j++){
      if(v[a]->putr ==v[j]->p ){
          c++;
          printchild(v[j]->p,v,n);
          if(c%2 !=0){ printf("%d ",i);}
          flag=1;
           
          break;
      }
    }
   
        }
    }
  */
  
}

int main() {
    int t;
    scanf("%d",&t);
    for(int i=0; i<t; i++){
        int n;
        scanf("%d",&n);
        NODE *root=(NODE*)malloc(sizeof(NODE));
        root->p= 1;
        root->son =NULL;
       vector<NODE*> v;
       // v.push_back(root);
      // printf("%d\n",v[0]->p);
        for(int j=0; j<n-1; j++){
            int baap,beta,i=0;
            scanf("%d %d",&baap,&beta);
            NODE *child=(NODE*)malloc(sizeof(NODE));
            child->p=baap;
            child->putr=beta;
            child->son =NULL;
         v.push_back(child);
           
          
        }
        
        // printf("%d\n",v[3]->p);
         //printf("%d\n",v[3]->putr);
         
         printchild(1,v,n-1);
         
         
         
        printf("\n"); 
         
    }
    
    
    
    
    
   
    
	return 0;
}

