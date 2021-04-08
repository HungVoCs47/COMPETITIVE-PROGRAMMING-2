# include <bits/stdc++.h>
using namespace std;
# define ll long long 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,w;
	cin>>n>>w;
	int v[n+10],ww[n+10];
	int value=0;
	for(int i=1;i<=n;i++)
	{
		cin>>ww[i]>>v[i];
		value+=v[i];
	}
	ll dp[100005];
	for(int i=1;i<=value;i++) dp[i]=1e13;
	//dp[0]=0;
    for(int i=1;i<=n;i++)
    {
    	int V=v[i],W=ww[i];
    	for(int j=value;j>=V;j--)
    	{
    		dp[j]=min(dp[j],dp[j-V]+W);
		}
	}
	for(int i=value;i>=0;i--){
		if(dp[i]<=w){
			cout<<i<<"\n";
			break;
		}
	}
	return 0;
}
