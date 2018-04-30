#include <iostream>
#include<stdio.h>
#include<string.h>
#include <vector>
#include <string>
#include <cctype>
#include<math.h>
using namespace std;

typedef struct Node{
  int val;
  int w;                      //weight
  struct Node *next;
}node;
node *arr[1000000];
int dist[1000000];
int p[1000000];
int path[1000000];
int count=0;
int vis[1000000];

void del2(int row,int x) {
  node*ptr=arr[row];
  node *parent=ptr;
  while(ptr->val!=x){
    parent=ptr;
    ptr=ptr->next;
  }
  if(parent==ptr)arr[row]=ptr->next;
  else{
    parent->next=ptr->next;
  }
  return ;
}
void del(int row,int col) {
  node* ptr=arr[row];
  node *parent=ptr;
  int i=0;
  // std::cout << "chu chu col = "<<col << '\n';
  // std::cout << "chu chu row = "<<row << '\n';
  while(i!=col){
    parent=ptr;
    ptr=ptr->next;
    i++;
  }
  if(parent==ptr){
    arr[row]=ptr->next;
  }
  else{
    parent->next=ptr->next;
  }
  vis[ptr->val]=1;
  count++;
  path[count]=ptr->val;
  p[ptr->val]=row;
  dist[ptr->val]=ptr->w+dist[row];
  del2(ptr->val,row);
  return ;
}
node* createNode(int a,int b){
  node *newnode=(node*)malloc(sizeof(node));
  newnode->val=a;
  newnode->w=b;
  newnode->next=NULL;
  return newnode;
}
void addNode(int i,int val,int w){
  node *newnode=createNode(val,w);
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
int main(){
  int n,m;
  cin>>n>>m;
  // int p[n];

  for(int i=0; i<n;i++){
    p[i]=-1;
    arr[i]=NULL;
    path[i]=-1;
    dist[i]=-1;
    vis[i]=0;

  }

  for(int i=0;i<m;i++){         //store the input into adjasency list
    int a,b,w;
    cin>>a>>b>>w;
    addNode(a,b,w);
    addNode(b,a,w);
  }
  // for(int i=0;i<n;i++){
  //   std::cout <<"index " <<i<< '=';
  //   if(arr[i]==NULL){
  //     std::cout << "NO" << '\n';
  //   }
  //   else{
  //     node *p=arr[i];
  //     while(p->next!=NULL){
  //       std::cout << p->val<<" "<<p->w<<"   ";
  //       p=p->next;
  //     }
  //     std::cout << p->val<<" "<<p->w<<"   ";
  //     std::cout << '\n';
  //   }
  // }

  int dst=n-1;
  dist[0]=0;
  path[0]=0;
  int flag=0;
  while(path[count]!=dst){
  int i=0,min=99999999,wt,row=-1,col=-1;
  while(path[i]!=-1&&i<=count){               //path[i] =rows that are visited
    int index=0;                    //first element of row
    node *pt=arr[path[i]];
    if(pt==NULL){
      //i++;
      // std::cout << "okkkkkkkkkkkkkkkkkkkkkkkkkk i= "<<i<<" path= "<<path[i]<< '\n';
      //count++;
      // continue;
      // break;
    }

    else if(pt->next==NULL && (dist[path[i]]+pt->w)< min){
      if(vis[pt->val]==0){
        min=dist[path[i]]+pt->w;
        row=path[i];
        col=index;
      }
    }
    else{
      while (pt!=NULL){
        if((dist[path[i]]+pt->w)<min){
          if(vis[pt->val]==0){
          min=dist[path[i]]+pt->w;
          row=path[i];
          col=index;
          // std::cout << "min becomes ======"<<min<<"where i= "<<i<<"and path[i]="<<path[i]<< '\n';
        }
        }
        index++;
        pt=pt->next;
      }
    }
  i++;
  }
  if(row!=-1&&col!=-1){
    del(row,col);

    // for(int i=0;i<n;i++){
    //   std::cout <<"index " <<i<< '=';
    //   if(arr[i]==NULL){
    //     std::cout << "NULLLL" << '\n';
    //   }
    //   else{
    //     node *p=arr[i];
    //     while(p->next!=NULL){
    //       std::cout << p->val<<" "<<p->w<<"   ";
    //       p=p->next;
    //     }
    //     std::cout << p->val<<" "<<p->w<<"   ";
    //     std::cout << '\n';
    //   }
    // }


  }
  else{
    break;
  }
}

  std::cout <<dist[dst]<< '\n';

  return 0;
}

// for(int i=0;i<n;i++){
//   std::cout <<"index " <<i<< '=';
//   if(arr[i]==NULL){
//     std::cout << "NO" << '\n';
//   }
//   else{
//     node *p=arr[i];
//     while(p->next!=NULL){
//       std::cout << p->val<<" "<<p->w<<"   ";
//       p=p->next;
//     }
//     std::cout << p->val<<" "<<p->w<<"   ";
//     std::cout << '\n';
//   }
// }
// 7 12
// 0 2 2
// 0 3 16
// 0 1 6
// 0 6 14
// 1 3 5
// 1 4 5
// 2 4 3
// 2 5 8
// 3 6 3
// 4 3 4
// 4 6 10
// 5 6 1
//
// 7 8
// 0 2 2
// 0 3 16
// 0 1 6
// 1 3 5
// 1 4 5
// 2 4 3
// 2 5 8
// 4 3 4

// 9 14
// 0 1 4
// 0 7 8
// 1 2 8
// 1 7 11
// 2 3 7
// 2 5 4
// 2 8 2
// 3 4 9
// 3 4 14
// 4 5 10
// 5 6 2
// 6 8 6
// 6 7 1
// 7 8 7
//
// 9 11
// 0 1 4
// 0 7 8
// 1 7 11
// 2 3 7
// 2 5 4
// 2 8 2
// 3 4 9
// 3 4 14
// 4 5 10
// 5 6 2
// 6 8 6

// 8 7
// 0 1 1
// 1 2 2
// 2 3 3
// 3 4 4
// 4 5 5
// 5 6 6
// 6 7 7
//
// 6 8
// 0 1 3
// 0 4 4
// 0 2 2
// 1 2 8
// 1 5 10
// 2 3 1
// 3 4 3
// 3 5 15
