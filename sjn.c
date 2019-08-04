#include<stdio.h>


struct Process{
	int pid;
	int bt;
	int at;
	int status;
};
 /*
void sort(Process p[], int n){
	 int i, j;
	Process key; 
    for (i = 1; i < n; i++) { 
        key = p[i]; 
        j = i - 1; 
  
       
        while (j >= 0 && p[j].bt > key.bt &&(p[j].status==FALSE) { 
            p[j + 1] = p[j]; 
            j = j - 1; 
        } 
        p[j + 1] = key; 
    } 
}
*/
int dispatcher(Process p[], int n, int ct){
	int shortestProcess =10000;
	int i=0;
	while(p[i].at<ct && pt.status == 0){
		if(p[i].bt<shortestProcess){
			shortestProcess = p[i].bt;
		}
	}

	for(i=0;i<n;i++){
		if(p[i].bt==shortestProcess)
			return p[i].pid;
	}

}

int main(){
	
	int n,waitTime[20], turnAroundTime[20],i, j, ct=0;
	int averageWaitTime=0, totalWaitTime=0, averageTurnAroundTime=0; 
	int time_quantum, remain,remainTime[20], time,flag=0;
	printf("ENter total number of processes(maximum 20):");
	scanf("%d",&n);
	remain=n;
	printf("\nEnter Arrival Time and Process Burst Time\n");
	Process p[n]; 
	for(i=0; i<n; i++){
		printf("P[%d]:",i+1);		
		scanf("%d",&p[i].at);	
		scanf("%d",&p[i].bt);
		p[i].pid = i+1;
		p[i].status = 0;
	}
	
	printf("\nProcessId\tBurst Time\tWaiting Time\tTurnaround Time");
	

	//Dispatcher.
	for(i=0;i<n;i++){
		int pid =Dispatcher(p,n,ct);
	}
	for(i=0;i<n;i++){
		ct=ct+p[i].bt;	
		turnAroundTime[i]=ct-p[i].at;
		waitTime[i] = turnAroundTime[i]-p[i].bt;
		totalWaitTime+= waitTime[i];
		averageTurnAroundTime+=turnAroundTime[i];
		if(p[i].at<=ct){
			
			printf("\nP[%d]\t\t%d\t\t%d\t\t%d",p[i].pid,p[i].bt,waitTime[i],turnAroundTime[i]);
		}else{ sort(p,n);
			printf("\nP[%d]\t\t%d\t\t%d\t\t%d",p[i].pid,p[i].bt,waitTime[i],turnAroundTime[i]);
		}
		
	}

	averageWaitTime=totalWaitTime/i;
	averageTurnAroundTime/=i;
	printf("\n\nTotal Wait Time:%d",totalWaitTime);
	printf("\nAverage Waiting Time:%d",averageWaitTime);
	printf("\nAverage Turnaround Time:%d",averageTurnAroundTime);
	
	
	for(i=0;i<n;i++){
		printf("%d %d\n",p[i].pid,p[i].bt);
	}
	return 0;
}
	
