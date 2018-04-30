#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char H[11][10];

void deletemin(){
    string new_str=H[n];
    int n=n-1;
    int i=1;
    int left=2;
    int right=3;
    H[i]=new_str


    while(left<=n){
        if(H[i]<=H[left] && H[i]<=H[right])return;
        if(H[left]<=H[i]){
            string a=H[left];
            H[left]=H[i];
            H[i]=a;
        }
        else{
            string a=H[right];
            H[right]=H[i];
            H[i]=a;
        }

        left=2*i;
        right=left+1;

        }
    }
}

void insert(string s,int n){
    H[++n]=s;
    for(int k=n; k>1;k/=2){
        if(H[n].compare(H[n/2])>0){
            string a=H[n];
            H[n]=H[n/2];
            H[n/2]=a;
        }
    else break;

    }
}

int main() {
int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
    string s1,s2;
  //  string s3("learn");
    cin>>s1;
    if(s1[0]=='l'){
        cin>>s2;
        insert(s2,strlen(s2))
    }
    else if (s1[0]=='f'){
        deletemin();
    }
    else{
        report();
    }


    }





	return 0;
}
