#include <stdio.h>
#include<stdlib.h>
#define MAXSIZE 99
int main(void) {
    int t;
    scanf("%d",&t);
    for(int i=0; i<t; i++){
        char arr[MAXSIZE];
        int j=1;
        getchar();
        arr[0]=getchar();
        while(arr[j-1] != '\n'){
            arr[j]=getchar();
            j++;
        }
        
        int a,b;
        scanf("%d %d", &a,&b);
        
        int size=j,index=0;
        char arr2[MAXSIZE];
        for(int k=0; k<size; k++){
            if(arr[k+1]=='x'){
                arr2[index]=(arr[k]-48)*a;
                index++;
            }
            else if(arr[k+1]=='y'){
                arr2[index]=(arr[k]-48)*b;
                index++;
            }
            else if(arr[k]=='x' || arr[k]=='y' || arr[k]==' ')continue;
            else{
                arr2[index]=arr[k];
                index++;
            }
        }
        
        for(int i=0; i<index; i++){
            printf("%c",arr2[i]);
        }
        
        
        
        
        
        
        
        printf("%d\n",index);
        
    }
    
    
	
	return 0;
}


