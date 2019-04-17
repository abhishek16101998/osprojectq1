#include<bits/stdc++.h>
using namespace std;

int main()
{
	static int c=0;
	int pno;
	cout<<"Enter total number of processes\n";
	cin>>pno;
	string processname[pno];
	int arrival[pno];
	int burst[pno];
	int cpyburst[pno];
//	string processname[4]={"P1","P2","P3","P4"};
//	int arrival[4]={0,2,4,13};
//	int burst[4]={18,23,13,10};
//	int cpyburst[4]={18,23,13,10};
	string completed[pno];
	int clock=0;
	int avwait=0, avturn=0;
	int i,j;
	cout<<"Enter Process Number, Arrival Time, Burst Time for each process\n";
	for(i=0;i<pno;i++)
	{
	cin>>processname[i];
	cin>>arrival[i];
	cin>>burst[i];
	cpyburst[i]=burst[i];
	}
	cout<<endl<<endl;
	for(i=0;i<pno;i++)
	{
		for(j=i+1;j<pno;j++)
		{
			if(arrival[j]<arrival[i])
			{
				int t;
				t=arrival[i];
				arrival[i]=arrival[j];
				arrival[j]=t;
				
				string s;
				s=processname[i];
				processname[i]=processname[j];
				processname[j]=s;
				
				t=burst[i];
				burst[i]=burst[j];
				burst[j]=t;
				
				t=cpyburst[i];
				cpyburst[i]=cpyburst[j];
				cpyburst[j]=t;
			}
			
		}
	}
	
	
	for(i=0;i<pno;i++)
	{
		if(burst[i]<=3&&arrival[i]<=clock)
		{
			clock+=burst[i];
			cout<<"Process "<<processname[i]<<" completed at clock "<<clock<<endl;
			cout<<"Turnaround Time: "<<clock-arrival[i]<<" and Waiting Time: "<<clock-arrival[i]-cpyburst[i]<<endl;
			avturn+=clock-arrival[i];
			avwait+=clock-arrival[i]-cpyburst[i];
			burst[i]=0;
		}
		else if(arrival[i]<=clock)
		{
			burst[i]=burst[i]-3;
			clock+=3;
		}
	
	}
	
/*	for(i=0;i<4;i++)
	{
		if(burst[i]==0)
		{
		
		completed[c]=processname[i];
		c++;
		cout<<"Process "<<processname[i]<<" completed\n";
		cout<<"Turnaround Time: "<<clock-arrival[i]<<" and Waiting Time: "<<
		}
	}*/
	
	for(i=0;i<pno;i++)
	{
		if(burst[i]==0)
		continue;
		else if(burst[i]<=6&&arrival[i]<=clock)
		{
			clock+=burst[i];
			avturn+=clock-arrival[i];
			avwait+=clock-arrival[i]-burst[i];
			cout<<"Process "<<processname[i]<<" completed at clock "<<clock<<endl;
			cout<<"Turnaround Time: "<<clock-arrival[i]<<" and Waiting Time: "<<clock-arrival[i]-cpyburst[i]<<endl;
			burst[i]=0;
		/*	burst[i]=0;
			completed[c]=processname[i];
			c++;
		*/
		}
		else if(arrival[i]<=clock)
		{
			burst[i]=burst[i]-6;
			clock+=6;
		}
	}
	
	for(i=0;i<pno;i++)
	{
		for(j=i+1;j<pno;j++)
		{	
			if(burst[j]<burst[i])
			{
				int t;
				t=burst[j];
				burst[j]=burst[i];
				burst[i]=t;
				
				t=cpyburst[j];
				cpyburst[j]=cpyburst[i];
				cpyburst[i]=t;
				
				string s;
				s=processname[i];
				processname[i]=processname[j];
				processname[j]=s;
				
				int a;
				a=arrival[i];
				arrival[i]=arrival[j];
				arrival[j]=a;
				
			}
		}
	}
	
	
	for(i=0;i<pno;i++)
	{
		if(burst[i]==0)
		continue;
		else
		{
			clock+=burst[i];
			avturn+=clock-arrival[i];
			avwait+=clock-arrival[i]-burst[i];
			cout<<"Process "<<processname[i]<<" completed at clock "<<clock<<endl;
			cout<<"Turnaround Time: "<<clock-arrival[i]<<" and Waiting Time: "<<clock-arrival[i]-cpyburst[i]<<endl;
			burst[i]=0;
		}
	}
	
	cout<<"\nAverage Waiting Time: "<<avwait/pno<<endl;
	cout<<"Average TurnAround Time: "<<avturn/pno<<endl;
	
}
