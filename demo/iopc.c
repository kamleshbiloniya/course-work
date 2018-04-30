#include<stdio.h>
#include<iostream>
using namespace std;

int findLCM(int x,int y);
int findLCM(int x,int y){
  int t,lcm,gcd;
int  a = x;
  int b = y;

  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }

  gcd = a;
  lcm = (x*y)/gcd;

return lcm;
}


  int main() {
  int x, y,sum=0;

  scanf("%d %d", &x, &y);
  for(int i=1;i<=x;i++){
    for(int j=1; j<=y; j++){

    sum+=findLCM(i,j);
    }
  }
printf("%d\n",sum );
  return 0;
}
