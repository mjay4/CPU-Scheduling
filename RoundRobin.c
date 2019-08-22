#include<stdio.h>

struct process{
  int bt;
  int at;
  int rt;
  int ct;
  int status;
};

int main(){
  int n,i,tq;
  int ct=0;
  int count=0;
  printf("Enter the no. of process:");
  scanf("%d",&n);
  struct process p[n];
  printf("Enter the arrival time and burst time for each process:");
  
  for(i=0;i<n;i++){
    scanf("%d",&p[i].at);
    scanf("%d",&p[i].bt);
    p[i].rt=p[i].bt;
    p[i].status=0;
    p[i].ct=0;
  }
  
  printf("Enter the time quantum: ");
  scanf("%d",&tq);
  
  while(1){
    for(i=0;i<n;i++){
      if(p[i].status==1){
        continue;
      }else {
        if(p[i].at<=ct){
          if(p[i].rt<=tq){
            ct+= p[i].rt;
            p[i].rt=0;
            p[i].ct = ct;
            p[i].status=1;
            count++;
          }else{
            ct+=tq;
            p[i].rt-=tq;
          }
        }
      }
    }
    if(count<n){
      tq*=2;
    }else{
      break;
    }
  }
  
  for(i=0;i<n;i++){
    printf("\n%d",p[i].bt);
    printf("Completion time: %d",p[i].ct);
  }
  
  return 0;
}
