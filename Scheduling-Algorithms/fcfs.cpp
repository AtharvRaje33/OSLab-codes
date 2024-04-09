#include<stdio.h>
#include<stdlib.h>

void fcfs(int*at, int*bt,int n){
	int j,k,key,key2;
	for(int i=1; i<n; i++){
		j=i-1;
		k=i-1;
		key=at[i];
		key2=bt[i];
		while(j>=0 && key<at[j]){
			at[j+1]=at[j];
			bt[k+1]=bt[k];
			j--;
			k--;
		}
		at[j+1]=key;
		bt[k+1]=key2;
	}
}

int main(){
	int no_of_processes;
	printf("Enter How many no of processes you have? : ");
	scanf("%d",&no_of_processes);
	printf("\n");
	
	int* at=(int*)malloc(no_of_processes*sizeof(int));
	int* bt=(int*)malloc(no_of_processes*sizeof(int));
	
	printf("AT BT\n");
	for(int p=0; p<no_of_processes; p++){
		scanf("%d%d",&at[p],&bt[p]);
	}
	printf("\n");
	
	fcfs(at,bt,no_of_processes);
	
	int* ct=(int*)malloc(no_of_processes*sizeof(int));
	ct[0]=at[0]+bt[0];
	for(int q=1;q<no_of_processes;q++){
		if(ct[q-1]>at[q])
			ct[q]=bt[q]+ct[q-1];
		else
			ct[q]=(at[q]-ct[q-1])+bt[q]+ct[q-1];
	}
	int* tat=(int*)malloc(no_of_processes*sizeof(int));
	int* wt=(int*)malloc(no_of_processes*sizeof(int));
	float sum_tat=0,sum_wt=0;
	for(int i=0; i<no_of_processes; i++){
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
		sum_tat+=tat[i];
		sum_wt+=wt[i];
	}
	
	printf("Arrival Time\tBurst Time\tCompletion Time\t\tTurn Around Time\tWaiting Time\n");
	for(int i=0; i<no_of_processes; i++){
		printf("%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n",at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	
	printf("Avg Turn Around Time: %f\nAvg Wating Time: %f\n",sum_tat/no_of_processes,sum_wt/no_of_processes);
}
