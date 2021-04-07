// program to solve max chain of pair length problem

#include<bits/stdc++.h>
using namespace std;

struct val
{
	int first;
	int second;
};
#define vi vector<int>

int maxChainLen(struct val p[],int n)
{
vector<pair<int,int> > v;
  int i;
  for(i=0;i<n;i++)
  {
      v.push_back({p[i].second,p[i].first});
  }
  sort(v.begin(),v.end());
  int mini=v[0].first;int ans=1;
  for(i=1;i<n;i++)
  {
     if(v[i].second>mini)
     {
         mini=v[i].first;
         ans++;
     }
  }
  return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++){
			cin>>p[i].first>>p[i].second;
		}
		cout<<maxChainLen(p,n)<<endl;
	}
}