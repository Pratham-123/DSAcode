You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.


#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
    int N=1e6+2;
	bool present[N];
	for(int i=0;i<N;i++)
	{
		present[i]=false;
	}
	for(int i=0;i<n;i++)
	{
		if(arr[i]>=0)
		{
			present[arr[i]]=true;
		}
	}
	int ans=-1;
	for(int i=1;i<N;i++)
	{
		if(present[i]==false)
		{
		   ans=i;
		   break;	
		}
}
	cout<<ans;
	return 0;
}

//Contributed by SAUMY SHARMA 
