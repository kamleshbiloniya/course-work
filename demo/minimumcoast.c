#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

    int divisioncost(int input1,int input2,int input3_size_rows, int input3_size_cols, int** input3)
    {
        if(input3_size_cols==1 && input3_size_rows==1)return 0;
        else if(input3_size_rows==1&&input3_size_cols==2) return input3[input1][input2]+input3[input1][input2+1];//+divisioncost(input1,input2,input3_size_rows,input3_size_cols/2,input3)+divisioncost(input1,input2+1,input3_size_rows,input3_size_cols/2,input3);
    
        else if(input3_size_rows==2&&input3_size_cols==1) return input3[input1][input2]+input3[input1+1][input2];//+divisioncost(input1,input2,input3_size_rows/2,input3_size_cols,input3)+divisioncost(input1+1,input2,input3_size_rows/2,input3_size_cols,input3);

      else {
          int min=0;
          for(int i=1;i<input3_size_rows-1;i++){
             int one=divisioncost(input1,input2,i,input3_size_cols,input3);
             int two=divisioncost(input1+i,input2,input3_size_rows-i,input3_size_cols,input3);
             if(one+two<min){
                 min=one+two;
                 
                 
             }
          }
          for(int j=1;j<input3_size_cols-1;j++){
              int one=divisioncost(input1,input2,input3_size_rows,j,input3);
              int two=divisioncost(input1,input2+j,input3_size_rows,input3_size_cols-j,input3);
              if(one+two<min){
                  min=one+two;
                 
                  
              }
              
          }
          
          
          int sum=0;
              for(int i=0;i<input3_size_rows;i++){
                  for(int j=0;j<input3_size_cols;j++){
                      sum=sum+input3[i][j];
                  }
              }
              return sum+min;
      }
    }






int main() {
    int output = 0;
    int ip1;
    scanf("%d", &ip1);
    int ip2;
    scanf("%d", &ip2);
    int ip3_rows = 0;
    int ip3_cols = 0;
    scanf("%d", &ip3_rows);
    scanf("%d", &ip3_cols);
    
    int** ip3 = (int**)malloc(ip3_rows*sizeof(int*));
    int ip3_init_i=0;
    for(ip3_init_i=0 ; ip3_init_i<ip3_rows ; ++ip3_init_i)
    {
        ip3[ip3_init_i] = (int*)malloc(ip3_cols*(sizeof(int)));
    }
    
    int ip3_i, ip3_j;
    for(ip3_i = 0; ip3_i < ip3_rows; ip3_i++) {
        for(ip3_j = 0; ip3_j < ip3_cols; ip3_j++) {
            int ip3_item;
            scanf("%d", &ip3_item);
            
            ip3[ip3_i][ip3_j] = ip3_item;
        }
    }
    output = divisioncost(ip1,ip2,ip3_rows, ip3_cols,ip3);
    printf("%d\n", output);
    return 0;
}

