#include <iostream>
#include<stdio.h>
#include<string.h>
#include <vector>
#include <string>
#include <cctype>
#include<math.h>
#define INF 99999999

using namespace std;

typedef struct Node{
  int val;                     //mode number
  int w;                      //weight
  struct Node *next;
}node;
node *arr[1000000];
int count=0;
int vis[10000000];
int total=0;
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
  int S[n];
  for(int i=0;i<n;i++){
  //  wt[i]=INF;
    S[i]=-1;                       //there is no node in S initially
    vis[i]=0;                     //mark all node unvisited
  }
  for(int i=0;i<m;i++){         //store the input into adjasency list
    int a,b,w;
    cin>>a>>b>>w;
    addNode(a,b,w);
    addNode(b,a,w);
  }
////////////////////////////////////prim's Algorithm////////////////////////////////////////////////////////////////////

  vis[0]=1;                        //visite first node (root)
  S[0]=0;                         //include node 0 into S
  while(count<n-1){              // S can contain maximum |V|-1 nodes
    int i=0,weight=INF;         //initialise minimum to infinity
    int min=0;
    while (S[i]!=-1) {
      node* ptr=arr[S[i]];
      while(ptr!=NULL){                               //check for each adjesent node
        if(vis[ptr->val]==0&&ptr->w<weight){         //check if a node is not visited and also have minimum weight
          min=ptr->val;                             //update minimum Node
          weight=ptr->w;                           //update minimum weight
        }
        ptr=ptr->next;
      }
      i++;
    }
    count++;                          //update # node in S
    S[count]=min;                    //include minimum weighted node in S
    total+=weight;                  //update total weight
    vis[min]=1;                    //mark visited

  }
  std::cout <<total<< '\n';
  return 0;
}
