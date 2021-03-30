# include <bits/stdc++.h>
using namespace std;
bool nextCombination(int n, int k, vector<int>&a)
{
	int i=k-1;
	while(i>=0 && a[i]==n-k+i+1) i--;
	if(i<0) return false;
	a[i]++;
	for(int j=i+1;j<k;j++)
	  a[j]=a[j-1]+1;
	  return true;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	int aa[n+10];
	int nn[n+10];
	vector<int>a;
	for(int i=1;i<=n;i++) a.push_back(i);
	for(int i=1;i<=n;i++)
	{
		cin>>aa[i];
		nn[i]=aa[i];
	}
	for(int i=n+1;i<=2*n;i++)
	{
		nn[i]=-aa[i-n];
	}
	bool done=false;
	do
	{
		int sum=0;
		vector<int>ans;
		for(int i=0;i<n;i++)
		{
		   ans.push_back(abs(nn[a[i]]));
	    }
	    sort(ans.begin(),ans.end());
	    for(int i=1;i<n;i++)
		{
			if(abs(ans[i])==abs(ans[i-1])) continue;
		}
		for(int i=0;i<n;i++)
		{
		 sum+=nn[a[i]];//cout<<a[i]<<" ";
		//cout<<"\n";
	    }
		if(sum==0 || sum==360)
		{
			done=true;
			break;
		}
	}while(nextCombination(2*n,n,a));
	if(!done) cout<<"NO\n";
	else cout<<"YES\n";
	return 0;
}