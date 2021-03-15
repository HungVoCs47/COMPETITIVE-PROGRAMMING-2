/*
    * Author: HungVoCs47
    * Status: AC
*/
# include <bits/stdc++.h>
using namespace std;
vector<int>adj[100007];
bool visited[100007];
void dfs(int s,vector<int>&result)
{
	visited[s]=true;
	for(int i=0;i<adj[s].size();i++)
	{
		int v=adj[s][i];
		if(!visited[v]) dfs(v,result);
	}
	result.push_back(s);
}
void dfs_1(int ss)
{
	visited[ss]=true;
	for(int i=0;i<adj[ss].size();i++)
	{
		int v=adj[ss][i];
		if(!visited[v]) dfs_1(v);
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
	}
	int ans=0;
	vector<int>result;
	memset(visited,false,sizeof(visited));
	for(int i=1;i<=n;i++)
	   if(!visited[i]) dfs(i,result);
	memset(visited,false,sizeof(visited));
	reverse(result.begin(),result.end());
	//for(int i=0;i<n;i++) cout<<result[i]<<" ";
	for(int i=0;i<n;i++)
	{
    int u=result[i];
		if(!visited[u])
		{
		   dfs_1(u);
		   ans++;
	    }
	}
	cout<<ans<<"\n";
	for(int i=1;i<=100005;i++) adj[i].clear();
    }
	return 0;
}
