#include<stdio.h>

int main(){
	int n,bt[20], waitTime[20], turnAroundTime[20], averageWaitTime=0, totalWaitTime=0, averageTurnAroundTime=0,  i, j;
	int time_quantum, remain=0,remainTime[20], time,flag=0,arrivalTime[20];
	printf("ENter total number of processes(maximum 20):");
	scanf("%d",&n);
	remain=n;
	printf("\nEnter Arrival Time and Process Burst Time\n");
	for(i=0; i<n; i++){
		printf("P[%d]:",i+1);		
		scanf("%d",&arrivalTime[i]);	
		scanf("%d",&bt[i]);
		remainTime[i]=bt[i];
	}
	
	for(i=0;i<n;i++){
		waitTime[i]=0;
		for(j=0;j<i;j++){
			waitTime[i]+=bt[j];
			
		}
	}

	/*
	printf("\nFor FirstComeFirstServe : \n");
	printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
	
	for(i=0;i<n;i++){
		turnAroundTime[i]=bt[i]+waitTime[i];
		totalWaitTime+= waitTime[i];
		averageTurnAroundTime+=turnAroundTime[i];
		printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],waitTime[i],turnAroundTime[i]);
	}

	averageWaitTime=totalWaitTime/i;
	averageTurnAroundTime/=i;
	printf("\n\nTotal Wait Time:%d",totalWaitTime);
	printf("\nAverage Waiting Time:%d",averageWaitTime);
	printf("\nAverage Turnaround Time:%d",averageTurnAroundTime);
	*/

	printf("\n\nFor Round Robin : \n");
	printf("\nEnter Time Quantum:\t");
	scanf("%d",&time_quantum);
	totalWaitTime=0;
	averageWaitTime=0;
	averageTurnAroundTime=0;
	printf("\nProcess\t\tTurnaroundTime\t\tWaitingTime\n\n");
	for(time=0,i=0;remain!=0;){
		if(remainTime[i]<=time_quantum && remainTime[i]>0){
			time+= remainTime[i];
			remainTime[i] = 0;
			flag=1;
		}
		else if(remainTime[i]>0){
			remainTime[i]-=time_quantum;
			time+=time_quantum;
		}
		if(remainTime[i]==0 && flag ==1){
			remain--;
			turnAroundTime[i] = time-arrivalTime[i];
			waitTime[i] = time-arrivalTime[i]-bt[i];
			printf("\nP[%d]\t\t%d\t\t%d\n", i+1,turnAroundTime[i] ,waitTime[i] );
			totalWaitTime+= waitTime[i];
			averageTurnAroundTime+=turnAroundTime[i];
			flag=0;
		}
		if(i ==n-1)
			i=0;
		else if(arrivalTime[i-1]<= time)
			i++;
		else
			i =0;
	}
	averageWaitTime=totalWaitTime/i;
	averageTurnAroundTime/=i;
	printf("\n\nTotal Wait Time:%d",totalWaitTime);
	printf("\nAverage Waiting Time:%d",averageWaitTime);
	printf("\nAverage Turnaround Time:%d",averageTurnAroundTime);
	
	
	return 0;
}

