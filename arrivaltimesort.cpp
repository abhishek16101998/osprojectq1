#include<bits/stdc++.h>
using namespace std;

int main()
{
	string processname[4]={"P1","P2","P3","P4"};
	int arrival[4]={0,2,4,13};
	int burst[4]={18,23,13,10};
	
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=i+1;j<4;j++)
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
			}
		}
	}
	

}
