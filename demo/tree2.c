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
    for(int a=0; a<n; a++){
        if(v[a]->p==i){
    for(int j=0; j<n; j++){
      if(v[a]->putr ==v[j]->p ){
          printchild(v[j]->p,v,n);break;
      }
    }
        }
    }
    int count=0;
    for(int t=0; t<n; t++){
        if(v[t]->p==i)count++;
    }
   // printf(" %d %d\n",i,count);
    
    for(int t=0; t<count/2; t++){
        int index,l;
        int min=100000;
        for(l=0; l<n; l++){
            if(v[l]->p==i&&((v[l]->putr)<min)){
                min=v[l]->putr;
                index=l;
                break;
            }
        }
        printf("%d ",min);
        v[l]->putr=100000;
         min=100000;
    }
   /* printf("%d",i);
       for(int t=0; t<count/2; t++){
            int min=100000;
        int index,l;
        for( l=0; l<n; l++){
            if(v[l]->p==i&&v[l]->putr<min){min=v[i]->putr;index=l;}
        }
        printf("%d",min);
        v[l]->putr=100000;
        min=100000;
    }*/
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
        for(int j=0; j<n; j++){
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
         
         printchild(1,v,n);
         
         
         
         
         
    }
    
    
    
    
    
   
    
	return 0;
}

