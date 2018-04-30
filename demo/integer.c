#include<stdio.h>
int main(){

 long long int x=-10;
unsigned long long bits=*((unsigned long long *)&x);
printf("%#llx\n",bits);
}
