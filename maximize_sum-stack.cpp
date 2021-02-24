// program to solve the problem maximize the tree sum stack problem
// link:https://www.geeksforgeeks.org/find-maximum-sum-possible-equal-sum-three-stacks/

#include <bits/stdc++.h>
using namespace std;

int maxSum(int stack1[], int stack2[], int stack3[], int n1, 
           int n2, int n3) 
{
	int sum1=0,sum2=0,sum3=0;
	
	// find the initial sum for all stacks
	for(int i=0;i<n1;i++){
		sum1+=stack1[i];
	}
	for(int i=0;i<n2;i++){
		sum2+=stack2[i];
	}
	for(int i=0;i<n3;i++){
		sum3+=stack3[i];
	}
	
	int i=0,j=0,k=0;
	
	while(true){
		if(i==n1 or j==n2 or k==n3){
			return 0;
		}
		
		if(sum1==sum2 and sum2==sum3){
			return sum1;
		}
		
		// now we remove the top element form the stack
		// which has highest sum
		if(sum1>=sum2 and sum1>=sum3){
			sum1-=stack1[i++];
		}
		else if(sum2>=sum3 and sum2>=sum1){
			sum2-=stack2[j++];
		}
		else if(sum3>=sum1 and sum3>=sum2){
			sum3-=stack3[k++];
		}
	}
	
}


int main(){
	int n1,n2,n3;
	cin>>n1>>n2>>n3;
	
	int st1[n1],st2[n2],st3[n3];
	for(int i=0;i<n1;i++){
		cin>>st1[i];
	}
	for(int i=0;i<n2;i++){
		cin>>st2[i];
	}
	for(int i=0;i<n3;i++){
		cin>>st3[i];
	}
	cout<<maxSum(st1,st2,st3,n1,n2,n3);
}
