#include <iostream>
#include<stdio.h>
#include<string.h>
#include <vector>
#include <string>
#include <cctype>
#include<math.h>

using namespace std;
int dfsn[10000];               //forward DFS number
int btn[10000];                //back track number
int mark[10000];
int vis[10000];
int revbtn[10000];
int krishan[10000];
 int Rama[101010];
 int laxman[101010];
int t=0;                           //time
int maximum=0;
int minimum;
int count=0;
int treecnt=0;

typedef struct Node{
  int val;                     //mode number                     //weight
  struct Node *next;
}node;
node *arr[10000];
node *revarr[10000];
node *result[10000];

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
void addRevNode(int i,int val){      //reversed edged graph
  node *newnode=createNode(val);
  if(revarr[i]==NULL){
    revarr[i]=newnode;
  }
  else{
    node *ptr=revarr[i];
    while(ptr->next!=NULL){
      ptr=ptr->next;
    }
    ptr->next=newnode;
  }
}

void addResult(int i,int value){      //reversed edged graph
  node *newnode=createNode(value);
  if(result[i]==NULL){
    result[i]=newnode;
  }
  else{
    node *ptr=result[i];
    if(ptr->val==value)return;
    while(ptr->next!=NULL){
      if(ptr->next->val==value){
        return;
      }
      ptr=ptr->next;
    }
    ptr->next=newnode;
  }
}

void DFS(int nd){        //DFS from node nd to onward

  if(arr[nd]==NULL){      //terminal node
    //return;
  }

  else{
    node*p=arr[nd];
    while(p!=NULL){
      if(mark[p->val]==0){
          mark[p->val]=1;
          dfsn[p->val]=t++;    //first visite time
          DFS(p->val);          //Go ahead
          btn[p->val]=t;
          revbtn[t++]=p->val;      // last visite time
      }
      else{                 //already visited node
      }
      p=p->next;
    }

  }
return;
}

void findresult(int start){                    //treecnt=tc
  // std::cout << "node = "<<start<<" dfsn "<<dfsn[start]<<" revbtn "<<revbtn[maximum]<<" backtrack no "<<btn[start] << '\n';
  vis[start]=1;
  if (start<minimum)minimum=start;
  krishan[start]=count;
  if(Rama[count]>start)Rama[count]=start;
  if(revarr[start]==NULL){
    if(btn[start]==maximum){
        maximum--;
      // std::cout << "maxi"<<maximum<<" node "<<start << '\n';

    }
    if(dfsn[start]==maximum){
      maximum--;
      // std::cout << "maxi"<<maximum<<" node "<<start << '\n';
    }
  }
  else{
    node *p=revarr[start];
    while (p!=NULL) {
      if(vis[p->val]==0){
        if(revbtn[maximum]==p->val){
          maximum--;
          // std::cout << "maxi"<<maximum<<" node "<<p->val << '\n';
        }
        if(dfsn[p->val]==maximum){
          maximum--;
          // std::cout << "maxi"<<maximum<<" node "<<p->val << '\n';
        }
        // std::cout << "maximum runing "<<maximum << '\n';
        findresult(p->val);
        krishan[p->val]=count;
      }
      else{
          if(krishan[p->val]<count){

            addResult(krishan[p->val],count);//reversed edge
          }
      }
      p=p->next;

    }
  }
  return;
}
int x;
int maxxx=888888;

int findmin(){
  int min=Rama[0];
  int j=0;
  for(int i=0; i<count; i++){
    if(Rama[i]<min){
      j=i;
      min=Rama[i];
    }
  }
  x=Rama[j];
  Rama[j]=maxxx++;
  return j;
}


int main(){
  int n;
  cin>>n;
  maximum=2*n-1;
  for(int i=0;i<n;i++){
    mark[i]=0;
    vis[i]=0;
    revbtn[i]=-1;
    int x;
    cin>>x;
    while(x!=-1){
      addNode(i,x);
      addRevNode(x,i);
      std::cin >>x;
    }

  }

  int s=0;                 //source vertex
  while(arr[s]!=NULL){       //find source vertex having outgoing edge
    s++;
  }

  int i=0;
  while(i<n){
    if(mark[i]==0){
      dfsn[i]=t++;
      mark[i]=1;
      DFS(i);
      btn[i]=t;
      revbtn[t++]=i;
    }
    i++;
  }
  // std::cout << "rev btn "<<revbtn[18] << '\n';
  // for(int i=0;i<n;i++){
  //   std::cout <<"index " <<i<< '=';
  //   if(arr[i]==NULL){
  //     std::cout << "NO" << '\n';
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
  // std::cout << "maximum time"<<t << '\n';
  int j=2*n-1;
  maximum=t-1;
  while(j>=0){
    if(vis[revbtn[maximum]]==0&&revbtn[maximum]>=0){
      Rama[count]=99999;
      //min=999999;
      // std::cout << "max  "<<maximum << '\n';
      findresult(revbtn[maximum]);
      count++;
    }
    // std::cout << "maxiiiii i "<<maximum << '\n';
    maximum--;
    j--;
  }
  // int b=0;
  // for(int i=0; i<count; i++){
  //   int a=Rama[0];
  //   int index=0;
  //   for(int j=0; j<count; j++){
  //     if(a<Rama[j]){
  //       a=Rama[j];
  //       index=j;
  //     }
  //   }
  //   Rama[index]=10000;
  //   laxman[index]=b++;
  // }


  for(int i=0; i<count; i++){
    // std::cout << "rama "<<Rama[i] << '\n';
  }
  int alpha=0;
  for(int i=0; i<count; i++){
    int index=findmin();
    // std::cout << "index "<<index << '\n';
    int flag=0;
    for(int i=0;i<n;i++){

        node *p=result[i];
        while(p!=NULL){
          if(p->val==index){
            p->val=alpha++;
            flag=1;
            // std::cout << "replacing "<<p->val<<" to "<<alpha-1 << '\n';
          }
          p=p->next;
        }

    }
    if(flag==0)alpha++;
  }
//
// for(int i=0;i<count; i++){
//   std::cout << "rama laxman"<<laxman[i] << '\n';
// }

  std::cout <<count << '\n';
  for(int i=0;i<count;i++){

    if(result[i]==NULL){
      std::cout <<"-1"<< '\n';
    }
    else{
      node *p=result[i];
      while(p!=NULL){
        std::cout << p->val<<" ";
        p=p->next;
      }
      std::cout <<"-1";
      std::cout << '\n';
    }
  }
  return 0;
}

//test1
// 11
// 1 3 -1
// 3 -1
// 8 1 -1
// 2 4 -1
// 3 -1
// 4 3 7 -1
// 5 8 -1
// 6 -1
// 9 -1
// 10 -1
// 8 -1
//test2
// 5
// 3 2 -1
// 0 -1
// 1 -1
// 4 -1
// -1
//test3
// 8
// 1 -1
// 2 5 4 -1
// 3 6 -1
// 2 7 -1
// 0 5 -1
// 6 -1
// 5 -1
// 3 6 -1
//test 4
// 8
// 1 5 -1
// 2 5 -1
// 3 6 -1
// -1
// 0 -1
// 4 6 -1
// 2 7 -1
// -1
//test5
// 11
// 8 9 -1
// 0 3 -1
// 1 -1
// 2 4 7 -1
// 5 6 8 -1
// 6 10 -1
// 7 -1
// 4 -1
// 9 -1
// 10 -1
// 8 -1
//test6
// 12
// 1 -1
// 2 3 4 -1
// 5 -1
// 4 6 -1
// 1 5 6 -1
// 2 7 -1
// 7 9 -1
// 6 -1
// 6 -1
// 8 10 -1
// 11 -1
// 9 -1
//test7
9
1 -1
4 2 3 -1 
5 -1
-1
0 -1
6 -1
7 -1
8 -1
2 -1
