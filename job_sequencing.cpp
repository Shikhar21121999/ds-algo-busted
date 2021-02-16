// Driver code starts here
// Program to find the max profit job sequence from a given array
// of jobs with deadlines and profits
// # include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// A structure to represent a job
struct Job
{
	int id;
	int dead;
	int profit;
};

bool comp(Job const& a, Job const& b)
{
	return (a.profit > b.profit);
}

// Prints minimum number of platforms reqquired

pair<int, int> JobScheduling(Job arr[], int n)
{
	// sort the Job array
	// in decreasing ordre of profit by each job
	sort(arr,arr+n,comp);

	// print the sorted job array
	 for (int i = 0; i < n; i++)
	 {
	 	cout << arr[i].id << " " << arr[i].dead << " " << arr[i].profit << "\n";
	 }

	// vector of int to keep track of appointment
	vector <int> appoint(101,0);
	
	
	int job_count = 0, profit = 0;

	cout<<"for loop starts \n";
	for (int i = 0; i < n; i++)
	{
		//if (appoint[arr[i].dead] ==0)
		//{
		//	profit += arr[i].profit;
		//	job_count++;
		//	appoint[arr[i].dead]=1;
		// }
		// look for a time slot that is empty and is less than deadline
		for(int j=arr[i].dead-1;j>=0;j--){
			if(appoint[j]==0){
				job_count+=1;
				profit+=arr[i].profit;
				break;
			}
		}
	}
	return make_pair(job_count, profit);
}

// Driver program to test methods
int main()
{
	int t;
	cin >> t;

	// test cases
	while (t--)
	{
		int n;

		// size of array
		cin >> n;
		Job arr[n];

		// adding id,deadline and profit
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i].id >> arr[i].dead >> arr[i].profit;
		}

		// function call
		pair<int, int> ans = JobScheduling(arr, n);
		cout << ans.first << " " << ans.second << "\n";
	}
}
