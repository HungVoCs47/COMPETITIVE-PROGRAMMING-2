// dieu kien do thi da xac dinh dc co chu trinh hay khong 
# include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
vector<int>adj[MAXN];
bool visited[MAXN];
vector<int>result;
int n,m;
void dfs(int u)
{
	visited[u]=true;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(!visited[v]) dfs(v);
	}
	result.push_back(u);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
	}
	for(int i=1;i<=n;i++)
	{
		if(!visited[i]) dfs(i);
	}
	for(int i=n-1;i>=0;i--)
	{
		cout<<result[i]<<" ";
	}
	return 0;
}
