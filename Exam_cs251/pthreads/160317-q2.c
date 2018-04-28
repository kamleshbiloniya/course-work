#include<stdio.h>
#include<stdlib.h>
// #include<sys/time.h>
#include<fcntl.h>
#include<pthread.h>
pthread_mutex_t lock;//= pthread_mutex_init;
#define THREADS 1
// #define NUM 10
// #define TDIFF(start, end) ((end.tv_sec - start.tv_sec) * 1000UL + (end.tv_usec - start.tv_usec))
typedef struct transaction{
        int seq_n;
        int type;
        float amount;

        int ac1,ac2;
}txn;

typedef struct account{

  int ac_n;
  int flag;
  float bal;
}acc;

acc *out_buff;
int txn_n,t; // t denotes number of threads and times denotes number of time work function executies on each call
int count=0;

void *work(void *arg1){

       txn *top=(txn*)arg1;
       txn *arg;
       while (1) {
      if(count>=txn_n){
        break;
      }
          arg=top+count;
         pthread_mutex_lock(&lock);
         count++;
         pthread_mutex_unlock(&lock);
            acc*out_buff2;
          acc* out_buff1=out_buff-1001+arg->ac1;
           if(arg->type==4){
            out_buff2=out_buff-1001+arg->ac2;
          }

            pthread_mutex_lock(&lock);


 switch (arg->type) {
   case 1:out_buff1->flag=1;
          out_buff1->bal=out_buff1->bal+arg->amount*0.99;
          out_buff1->flag=0;
          break;
   case 2:out_buff1->flag=1;
          out_buff1->bal=out_buff1->bal-arg->amount*1.01;
          out_buff1->flag=0;
          break;
   case 3:out_buff1->flag=1;
          out_buff1->bal=out_buff1->bal*1.0710;
          out_buff1->flag=0;
          break;
   case 4:out_buff1->flag=1;
          out_buff1->bal=out_buff1->bal-arg->amount*1.01;
          out_buff1->flag=0;
          out_buff2->flag=1;
          out_buff2->bal=out_buff2->bal+arg->amount*0.99 ;
          out_buff2->flag=0;
          break;

 }
pthread_mutex_unlock(&lock);

}
pthread_exit(NULL);
 return NULL;
}


int main(int argc, char **argv){
    acc *in_buff;
    txn *txn_buff;
    // int THREADS=atoi(argv[4]);
    FILE* fd;
    FILE* dd;
    struct timeval start, end;
    pthread_t threads[THREADS];


  if(argc !=5){
    printf("Usage:%s<filename> <acc.txt><txn.txt><number of entry in txn.txt file><number of thread>",argv[0]);
  }
  txn_n=atoi(argv[3]);
  t=atoi(argv[4]);
  t=1;
  txn_buff=malloc(txn_n*sizeof(txn));
  in_buff=malloc(10000*sizeof(acc));
  fd=fopen(argv[2],"r"); // given a file reference
  dd=fopen(argv[1],"r");
  txn* loc_ptr=txn_buff;
  acc* ptr=in_buff;
  int sz=sizeof(txn);
  int ss=sizeof(acc);

  for(int i=0;i<txn_n;i++){

    if(!fscanf(fd,"%d",&loc_ptr->seq_n))printf("%d error1\n",i);
      if(!fscanf(fd,"%d",&loc_ptr->type))printf("%d error2\n",i);
        if(!fscanf(fd,"%f",&loc_ptr->amount))printf("%d error3\n",i);
          if(!fscanf(fd,"%d",&loc_ptr->ac1))printf("%d error4\n",i);
            if(!fscanf(fd,"%d",&loc_ptr->ac2))printf("%d error5\n",i);
    loc_ptr=loc_ptr+1;
   }

  for(int i=0; i<10000; i++){

    // fscanf(dd,"%d",&(ptr->ac_n));
    // fscanf(dd,"%f",&(ptr->bal));
    if(!fscanf(dd,"%d",&ptr->ac_n))printf("error6\n");
    if(!fscanf(dd,"%f",&ptr->bal))printf("error7\n");
    ptr->flag=0;
    ptr=ptr+1;
  }
  out_buff=in_buff;







if(pthread_mutex_init(&lock,NULL)!=0){
  printf("\n mutex init has fail \n");
  return 1;
}

for(int i=0; i<t; i++){
  if(pthread_create(&threads[i],NULL,work,(void *)txn_buff) !=0)
  {

    perror("pthread_create");
    exit(-1);
  }

}

for(int i=0; i<t; i++){
  pthread_join(threads[i],NULL);
}

  for(int i=0; i<10000; i++){
      printf("%d %.2f\n",out_buff->ac_n,out_buff->bal);
      out_buff++;
  }
// free(txn_buff);
// free(in_buff);
// close(fd);
// close(dd);

  return 0;

}
