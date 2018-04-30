#include <stdio.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int minimumCost(int size,int *num){
     qsort(num,size,sizeof(int),cmpfunc);
     int result=0,cost=0;
     while(size !=1){
         result=num[0]+num[1];
         num[1]=result;
         for(int i=0; i<size-1; i++){
             num[i]=num[i+1];
         }
          qsort(num,size-1,sizeof(int),cmpfunc);
          cost=cost+result;
          size--;
     }
     return cost;
}



int main(void) {
int arr[5]={1,2,5,3,4};
int a=minimumCost(5,arr);
printf("%d",a);
	return 0;
}


