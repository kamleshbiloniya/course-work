#include <iostream>
#include<stdio.h>
#include<string.h>
#include <vector>
#include <string>
#include <cctype>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef struct Node{
  int val;
  struct Node* next;
}node;
node *newNode(int a){
  node *newnode= (node *)malloc(sizeof(node));
  newnode->val=a;
  newnode->next=NULL;
  return newnode;
}
void addlink(node *arr,int a,int b){
  node *ptra=arr+a-1;
  node *ptrb=arr+b-1;
  ptra->next=newNode(a);
  newNode(a)->next=ptra->next->next;
  ptrb->next=newNode(b);
  newNode(b)->next=ptrb->next->next;
}

int main(){
  int n,op;
  std::cin >> n>>op;
  std::vector<node*> arr[n];
  //node* arr[n];//={newNode(0)};
  for(int i=0; i< n; i++){
    std::cout << "hello" << '\n';
    arr[i]= *newNode(0);

  }
  for(int i=0; i<n; i++){

    string s;
    std::cin >> s;
    if(s[3]=='n'){
      int a;
      std::cin >> a;
      arr[a-1]=newNode(a);
    }
    else if(s[3]=='l'){
      int a,b;
      std::cin >> a>>b;
      addlink(*arr,a,b);
    }
     else if (s[0]=='d'){
      int a;
      //delnode(arr,a);
    }
    else{
      int a;
      std::cin >> a;
    //  remlink(arr,a);
    }
  }
  return 0;
}
