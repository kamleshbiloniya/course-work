#include <iostream>
#include<stdio.h>
#include<string.h>
#include <vector>
#include <string>
#include <cctype>
#include<math.h>
using namespace std;

typedef struct Node{
  int val;                     //mode number
  int w;                      //weight
  struct Node *next;
}node;

node *arr[1000000]; //adjesency list
int dist[1000000]; //distance of node from root
int path[1000000];//
int count=0;
int vis[1000000];//colection of visited nodes
int total=0;

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
  dist[ptr->val]=ptr->w;
  total=total+ptr->w;
  // std::cout << "total========="<<total << '\n';
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
  for(int i=0; i<n+5;i++){
    //p[i]=-1;
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


  int dst=n-1;
  dist[0]=0;
  path[0]=0;
  int flag=0;
  while(count<dst){
    int i=0,min=9999999,row=-1,col=-1;
    while(path[i]!=-1){               //path[i] =rows that are visited
      int index=0;                    //first element of row
      node *pt=arr[path[i]];
      if(pt==NULL){
        // std::cout << "okkkkkkkkkkkkkkkkkkkkkkkkkk i= "<<i<<" path= "<<path[i]<< '\n';
      }

      else if(pt->next==NULL && (pt->w)< min){
        if(vis[pt->val]==0){ //means not visited yet
          min=pt->w;
          row=path[i];
          col=index;
        }
      }
      else{
        while (pt!=NULL){
          if((pt->w)<min){
            if(vis[pt->val]==0){ //node not visited yet
            min=pt->w;
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

    del(row,col);
}

  std::cout <<total<<'\n';

  return 0;
}
//
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
7 12
0 2 2
0 3 16
0 1 6
0 6 14
1 3 5
1 4 5
2 4 3
2 5 8
3 6 3
4 3 4
4 6 10
5 6 1
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
