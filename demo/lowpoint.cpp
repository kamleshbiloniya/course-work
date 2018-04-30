#include <iostream>
#include<stdio.h>
#include<string.h>
#include <vector>
#include <string>
#include <cctype>
#include<math.h>

using namespace std;
int parent[1000000];
int dtime[1000000];
int lowtime[1000000];
int visited[1000000];
int result[1000000];
int count=0;
int flag=0;
typedef struct Node{
  int val;                     //mode number                     //weight
  struct Node *next;
}node;
node *arr[1000000];

node* createNode(int a){
  node *newnode=(node*)malloc(sizeof(node));
  newnode->val=a;
  newnode->next=NULL;
  return newnode;
}
void addNode(int i,int val){    //given graph
  node *newnode=createNode(val);
  if(arr[i]==NULL){
    arr[i]=newnode;
  }
  else{
    node *ptr=arr[i];
    while(ptr->next!=NULL){
      ptr=ptr->next;
    }
    ptr->next=newnode;
  }
}

void DFS(int start){
  //std::cout << "yes "<<start << '\n';
  visited[start]=1;
  lowtime[start]=count;
  dtime[start]=count;
  node *p=arr[start];
  while(p!=NULL){
    if(visited[p->val]==0){
      parent[p->val]=start;
      count++;
      if(start==0)flag++;
      //std::cout << "flag "<<flag << '\n';
      DFS(p->val);
      if(lowtime[start]>lowtime[p->val]){
        lowtime[start]=lowtime[p->val];

      }
       if(dtime[start]<=lowtime[p->val]){
        result[start]=1;
      }

    }

    else if (parent[start]==p->val){
    //do nothing

    }
    else{
      if(dtime[p->val]<=lowtime[start]){
        lowtime[start]=lowtime[p->val];
        //result[p->val]=1;

      }
    }
    p=p->next;
  }
  return;
}

int main(){
  int n,m;
  cin>>n>>m;
  for(int i=0; i<n;i++){
    arr[i]=NULL;
    result[i]=0;
  }

  for(int i=0;i<m;i++){         //store the input into adjasency list
    int a,b;
    cin>>a>>b;
    addNode(a,b);
    addNode(b,a);
  }
  // for(int i=0;i<n;i++){
  //   std::cout <<"index " <<i<< '=';
  //   if(arr[i]==NULL){
  //     std::cout <<"-1"<< '\n';
  //   }
  //   else{
  //     node *p=arr[i];
  //     while(p->next!=NULL){
  //       std::cout << p->val<<" ";
  //       p=p->next;
  //     }
  //     std::cout << p->val<<" ";
  //     std::cout << '\n';
  //   }
  // }

  DFS(0);
  if(flag==1)result[0]=0;
  // std::cout << "flag "<<flag << '\n';
  for (int i=0; i<n; i++){
    if(result[i]==1){
      std::cout <<i << '\n';
    }
  }
  for (int i=0; i<n; i++){

  //  std::cout << "parentof "<<i<<" "<<parent[i] << '\n';

  }

  return 0;
}


//
// 7 7
// 0 5
// 2 0
// 3 1
// 2 3
// 4 3
// 1 4
// 4 6
