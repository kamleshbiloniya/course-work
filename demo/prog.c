#include<stdio.h>
int main(){
  int n,m;
  scanf("%d %d",&n,&m);
  int arr[n];
  int max=0;
  for(int i=0; i<m; i++){
    int a,b,k;
    scanf("%d %d %d",&a,&b,&k);
    for(int j=a-1; j<b; i++){
      arr[j]+=k;
      if(max>arr[j])max=arr[j];
    }
  }
  printf("%d\n",max);
  return 0;
}
