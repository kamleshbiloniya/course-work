#include<stdio.h>
#include<stdlib.h>
 int add(int x,int y) {

int z=0;
z=x+y;
return z;

}

int main(){

int a=5;
int b=10;
int c;

c=add(a,b);
printf("Sum of %d+%d = %d\n",a,b,c);



return 0;
}
