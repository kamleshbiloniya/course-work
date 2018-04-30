#include <iostream>
#include<stdio.h>
#include<string.h>
#include <vector>
#include <string>
#include <cctype>
#include<math.h>
#include<stdlib.h>
using namespace std;

 // hashtable *head;
  string max_str;
  int max_count=0;
typedef struct TWODarry{
  int count;
  string x;
  struct TWODarry *next;
}cross;

typedef struct Array{
  int hash;
  cross *side;
  struct Array * next;
}hashtable;

 int hashfunction(string s){
  int hash=0;
  int len=s.length();
  // std::cout << "length" <<len<< '\n';
  for(int j=0; j< len; j++){
       hash=((hash*1024)+s[j])%(1010101);  //hash+=s[j];
  }
  // std::cout << "hashvalue" << hash<<'\n';
  return hash;
}

hashtable *head;
hashtable*newNode(int hash_value,cross *sidearry){
  hashtable*newnode=(hashtable*)malloc(sizeof(hashtable));
  newnode->hash=hash_value;
  newnode->side=sidearry;
  newnode->next=NULL;
  return newnode;
}

cross*sideNode(string s){
  cross*node= (cross*)malloc(sizeof(cross));
  node->x=s;
  node->count=1;
  node->next=NULL;
}

int main(){
  int n;
  std::cin >> n;
  for(int i=0;i<n;i++){
    string s;
    std::cin >> s;
    int h=hashfunction(s);
    hashtable*ptr=head;
    if(i==0){
      head=newNode(hashfunction(s),sideNode(s));
      max_count=1;
      max_str=s;
      // if(head->next==NULL)printf("yes\n");
      continue;
    }
    while(ptr->next!=NULL && ptr->hash!=h){
     // std::cout << "go front" << '\n';
      ptr=ptr->next;
    }

    if(ptr->hash==h){
      cross*gali=ptr->side;
      while(gali->next!=NULL&&gali->x!=s){
        // std::cout << "travelling side Array" << '\n';
        gali=gali->next;
      }

      if(gali->x==s){
        gali->count+=1;
        if(gali->count > max_count){
          max_count=gali->count;
          max_str=s;
         // cout<<"max_string till now is :"<<max_str<<" "<<max_count<<endl;
        }
      }
      else{
        gali->next=sideNode(s);
      // std::cout << "new side node added" << '\n';
      }
    }

    else{
      ptr->next=newNode(hashfunction(s),sideNode(s));
      // std::cout << "new fron node aaya" << '\n';
      }
  }

  std::cout <<max_str <<endl;

}
