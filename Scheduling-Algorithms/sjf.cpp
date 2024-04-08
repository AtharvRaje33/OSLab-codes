#include<iostream>
#include<algorithm>

using namespace std;

struct Process{
	int pid;
	int at;
	int bt;
};

bool compare(Process a, Process b){
	return a.bt < b.bt;
}

void getCT(Process proc[],int n,int ct[]){
	sort(proc,proc+n,compare);
	
	int currentTime = 0;
	
	for(int i=0;i<n;i++){
		if(proc[i].at>currentTime){
			currentTime = proc[i].at;
		}
		
		ct[i]=currentTime + proc[i].bt;
		currentTime = ct[i];
	}
}


void getTAT(Process proc[],int n,int ct[],int tat[]){
	for(int i=0;i<n;i++){
		tat[i]= ct[i] - proc[i].at;
	}
}


void getWT(Process proc[],int n,int tat[],int wt[]){
	for(int i=0;i<n;i++){
		wt[i]=tat[i]-proc[i].bt;
	}
}

void result(Process proc[],int n){
	int ct[n],wt[n],tat[n];
	int totalwt=0;
	int totaltat=0;
	
	getCT(proc,n,ct);
	getTAT(proc,n,ct,tat);
	getWT(proc,n,tat,wt);	
	
	 cout << "Process\t\tArrival\t\tBurst\t\tComplete\tTAT\t  Waiting" << endl;
	 
	 for(int i=0;i<n;i++){
	 	totalwt+=wt[i];
	 	totaltat+=tat[i];
	 	
	 	 cout<<proc[i].pid<<"\t\t"<<proc[i].at<<"\t\t"<<proc[i].bt<<"\t\t"<<ct[i]<<"\t\t"<< tat[i]<<"\t\t"<<wt[i]<<endl;
	 }
	 
	 cout<<"Average TAT:"<<(float)totaltat/n<<endl;
	 cout<<"Average WT:"<<(float)totalwt/n<<endl;
}

int main(){
	cout<<"Shortest Job First Scheduling"<<endl;
	int n;
	cout<<"Enter number of processes:";
	cin>>n;
	
	Process proc[n];
	for(int i=0;i<n;i++){
		cout <<"Enter AT and BT for Process"<<i+1<<":";
        cin>>proc[i].at>>proc[i].bt;
        proc[i].pid=i+1;
	}
	
	result(proc,n);
	return 0;
}

