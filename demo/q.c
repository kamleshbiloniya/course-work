#include <stdio.h>
int expo(int n,int k){
    if(k<0)return expo(1/n, -k);
    else if (k==0)return 0;
    else if (k==1)return n;
    else if (k%2 ==0)return expo(n*n, k/2);
    else if(k%2 ==1)return n*expo(n*n , k-1/2);
}
int main(void) {
	int n,k;
	scanf("%d %d",&n,&k);

	printf("%d",expo(n,k));
	return 0;
}


