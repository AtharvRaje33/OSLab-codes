#include<stdio.h>
#include<conio.h>

void main() {
	
	int numOfProcess;
	printf("Enter the number of processes: ");
	scanf("%d", &numOfProcess);
	int remProcess = numOfProcess;
	
	int at[numOfProcess], bt[numOfProcess];
	int remTime[numOfProcess];
	int i;
	printf("\nEnter Arrival Time and Burst Time for all processes");
	printf("\n---------------------------------------------------");
	for (i=0; i<numOfProcess; i++) {
		printf("\nArrival Time for Process %d: ", i);
		scanf("%d", &at[i]);
		printf("Burst Time for Process %d: ", i);
		scanf("%d", &bt[i]);
		remTime[i] = bt[i];
		
	}
	
	int timeQuantum;
	printf("\nEnter the time quantum: ");
	scanf("%d", &timeQuantum);
	
	int wt = 0, tat = 0, sumTime, finishFlag;
	printf("\nProcess No.\t\t Burst Time\t\t TAT\t\t WT");
	
	for(i=0, sumTime=0; remProcess!=0;) {
		
		if (remTime[i] > 0 && remTime[i] <= timeQuantum) {
			sumTime += remTime[i];
			remTime[i] = 0;
			finishFlag = 1;
		} else if (remTime[i] > 0){
			remTime[i] -= timeQuantum;
			sumTime += timeQuantum;
		}
		
		if (remTime[i] == 0 && finishFlag == 1) {
			--remProcess;
			printf("\nProcess[%d]\t\t %d\t\t\t %d\t\t %d", i, bt[i], sumTime-at[i], sumTime-at[i]-bt[i]);
			wt += sumTime - at[i] - bt[i];
			tat += sumTime - at[i];
			finishFlag = 0;
		}
		
		if(i == numOfProcess - 1) {
			i=0;
	    } else if (at[i] < sumTime) {
	    	i++;
		} else {
			i=0;
		}
	}
	
	float avg_wt = (float)wt/numOfProcess;
	float avg_tat = (float)tat/numOfProcess;
	printf("\nAvg TAT: %f", avg_tat);
	printf("\nAvg WT: %f", avg_wt);
}

