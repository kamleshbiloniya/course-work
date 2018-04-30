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
        
        
        int ln=0;
        int ar[j];
        while( i<=j){
            int sum=0;
            while(arr[i]<58 && arr[i]> 47){
                sum=sum*10+arr[i]-48;
                i++;
                printf("%dHi from loop\n",sum);
                if(arr[i+1]>57 || arr[i+1]< 48){
                //sum=sum*10+arr[i]-48;
                i++;
                  ar[ln]=sum;
                printf("%dHi from loop end\n",ar[ln]);
                sum=0;
                ln++;
                continue;
                }
            }
            if(arr[i]=='x'){
               if(arr[i]<58 && arr[i]> 47){
                   ar[ln-1]=(ar[ln-1])*5;
                   i++;
                   continue;
               }
               else{
                   ar[ln]=a;
                   ln++;i++;
                   continue;
               }
                printf("Hi from x\n");
            }
           else if(arr[i]=='y'){
                if(arr[i]<58 && arr[i]> 47){
                    ar[ln-1]=(ar[ln-1])*6;
                    i++;
                    continue;
                    
                }
                else{
                    ar[ln]=b;
                    ln++;i++;
                    continue;
                }
                printf("Hi from y\n");
            }
            else if(arr[i]==' '){
                i++;
                printf("Hi from space\n");
                continue;
            }
           else if(arr[i]=='+'){
                sum=0;
                i++;
                printf("Hi from +\n");
            }
            else if(arr[i]=='-'){
                sum=1;
                i++;
                printf("Hi from -\n");
            } 
            else if(arr[i]=='*'){
                sum=2;
                i++;
                printf("Hi from *\n");
            } 
            else if(arr[i]=='/'){
                sum=3;
                i++;
                printf("Hi from /\n");
            }
            else {i++;
            }
            ar[ln]=sum;
            printf("%dHi from end\n",ar[ln]);
            sum=0;
            ln++;
        }
        
        for(int k=0; k<ln; k++){
            printf("%d ",ar[k]);
        }
        
        /*int size=j,index=0;
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
        
        */
        
        
        
        
        
        printf("%d\n",ln);
        
    }
    
    
	
	return 0;
}


