#include<stdio.h>
void microkernel_sendmsg(char *);
void main(){
  printf("HElloword!\n");
  printf("This must be a monolithic design\n");
  microkernel_sendmsg("is more portable");
  printf("add one line in main\n");
}
void microkernel_sendmsg(char *a) {
  printf("microkernel:%s\n",a);
}
