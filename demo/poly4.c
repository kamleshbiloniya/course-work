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
        
        
        int ln=0,i=0;
        int ar[j];
        while( i<j){
            int sum=0;
            while(arr[i]<58 && arr[i]> 47){
                sum=sum*10+arr[i]-48;
                i++;
                //printf("%dHi from loop\n",sum);
              if(arr[i]>=58 || arr[i]<=47){ar[ln]=sum;ln++;}
            }
            if(arr[i]=='x'){
               if((arr[i-1]<58 && arr[i-1]> 47) || arr[i-1]=='y'){
                   ar[ln-1]=(ar[ln-1])*a;
                   i++;
                   continue;
               }
               else{
                   sum=a;
                   i++;
               }
                //printf("Hi from x\n");
            }
           else if(arr[i]=='y'){
                if((arr[i-1]<58 && arr[i-1]> 47) || arr[i-1]=='x'){
                   // printf("%d from y b\n",ar[ln-1]);
                    ar[ln-1]=(ar[ln-1])*b;
                   // printf("%d from y A \n",ar[ln-1]);
                    i++;
                    continue;
                    
                }
                else{
                    sum=b;
                    i++;
                }
               // printf("Hi from y\n");
            }
            else if(arr[i]==' '){
                i++;
               // printf("Hi from space\n");
                continue;
            }
           else if(arr[i]=='+'){
                sum=0;
                i++;
                //printf("Hi from +\n");
            }
            else if(arr[i]=='-'){
                sum=1;
                i++;
               // printf("Hi from -\n");
            } 
            else if(arr[i]=='*'){
                sum=2;
                i++;
               // printf("Hi from *\n");
            } 
            else if(arr[i]=='/'){
                sum=3;
                i++;
               // printf("Hi from /\n");
            }
           else {
               i++;
           }
            ar[ln]=sum;
           // printf("%dHi from end\n",ar[ln]);
            sum=0;
            ln++;
        }
        
       // for(int k=0; k<ln-1; k++){
       //     printf("%d ",ar[k]);
       // }
       int l=ln-1;
       int narr[ln];
       int d=1;
       narr[0]=ar[0];
        i=1;
       while( i<l){
           if(ar[i]==2){
               narr[d-1]=(narr[d-1])*ar[i+1]; i=i+2;
           }
            else if(ar[i]==3){
               narr[d-1]=(narr[d-1])/ar[i+1];i=i+2;
           }
           else{
               narr[d]=ar[i];d++;i++;
           }
       }
       //printf("\n");
       /*for(int i=0; i<d;i++){
           printf("%d ",narr[i]);
       }*/
        
        
        int res=narr[0];
        for(int i=1;i<d;i=i+2){
            if(narr[i]==0){
                res=res+narr[i+1];
            }
            else {
                 res=res-narr[i+1];
            }
        }
       // printf("\n");
        printf("%d\n",res);
        
    }
    
    
	
	return 0;
}


