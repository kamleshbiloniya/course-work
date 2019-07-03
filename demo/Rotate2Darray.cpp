#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    for (int test=1;test<=t;test++){
        int size;
        cin>>size;
        int arr[size][size];
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                cin>>arr[i][j];
            }
        }
        
        int ind = size-1;
        
        for(int loop=0;loop<size/2;loop++){
            for(int v=loop;v<=ind-loop-1;v++){
                int i= loop,j=v;
                int count =0;
                int prv = arr[i][j];
                while(count<4){
                   // cout<<i<<" "<<j<<"->>"<<j<<" "<<ind-i<<endl;
                    int next = arr[j][ind-i];
                    arr[j][ind-i] = prv;
                    prv = next;
                    int oldj = j;
                    j=ind-i;
                    i=oldj;
                    count++;
                }
            }
            
        }
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
}
