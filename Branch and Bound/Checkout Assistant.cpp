# include <bits/stdc++.h>
using namespace std;
# define ll long long 
const int MAXN=2e3+10;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	ll c[MAXN],t[MAXN];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i]>>c[i];
		t[i]++;
	}
	ll dp[n+10][n+10]={0};
	for(int i=1;i<=n;i++) dp[0][i]=1e18;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j>=t[i])
			{
				dp[i][j]=min(dp[i-1][j],dp[i-1][j-t[i]]+c[i]);
			}
			else
			{
				dp[i][j]=min(dp[i-1][j],c[i]);
			}
		}
	}
	cout<<dp[n][n];
	return 0;
}
