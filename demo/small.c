#include<stdio.h>
int main(){

unsigned int a=0xfffffff0;
unsigned int b=0xf;
int x=0xfffffff0;
int y=0xf;
if(a>b)printf("%d %d\n",a ,b);
if(x<y)printf("%d %d \n",x ,y);

	return 0;
}
