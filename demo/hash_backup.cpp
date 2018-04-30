#include <iostream>
#include<stdio.h>
#include<string.h>
#include <vector>
#include <string>
#include <cctype>
#include<math.h>
using namespace std;

 // hashtable *head;
  string max_str;
  int max_count=0;

typedef struct Array{
  int count;
  unsigned int hash;
  struct Array * next;
}hashtable;
int hashfunction(string s){
  unsigned int hash=0;
  int len=s.length();
  for(int j=0; j< len; j++){
    hash=((hash*32)+s[j])%(100000);
  }
  return hash;
}
hashtable *head;
hashtable*newNode(unsigned int hash_value){
  hashtable*newnode= new hashtable();
  newnode->hash=hash_value;
  newnode->count=1;
  newnode->next=NULL;
  return newnode;
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
      head=newNode(hashfunction(s));
      max_count=1;
      max_str=s;
      //if(head->next==NULL)printf("yes\n");
      continue;
    }
    while(ptr->next!=NULL && ptr->hash!=h){
      //std::cout << "ohh yeah" << '\n';
      ptr=ptr->next;
    }

    if(ptr->hash==h){
      ptr->count+=1;
      if(ptr->count>max_count){
        max_count=ptr->count;
        max_str=s;
	//cout<<"max_string till now is :"<<max_str<<" "<<max_count<<endl;
      }
    }
    else{
      ptr->next=newNode(hashfunction(s));
      }
  }

  std::cout <<max_str << '\n';

}
