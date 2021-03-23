# include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>ii;
const int MAXN=805;
vector<int>adj[MAXN];
int n,m;
bool visited[MAXN];
int cnt;
void dfs(int u)
{
	visited[u]=true;
	cnt++;
	for(int v:adj[u])
	{
		if(!visited[v]) dfs(v);
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=0,a,b;i<m;i++)
	{
		cin>>a>>b;
		adj[a].push_back(b);
	}
	vector<ii>result;
	for(int i=1;i<=n;i++)
	{
	    cnt=0;
		memset(visited,false,sizeof(visited));
		dfs(i);
		result.push_back(ii(cnt,i));
		//cout<<cnt<<" ";
	}
	sort(result.begin(),result.end(),greater<ii>());
	memset(visited,false,sizeof(visited));
	int ans=0;
	for(ii i: result)
	{
		if(!visited[i.second]) dfs(i.second),ans++;
	}
	cout<<ans;
	return 0;
}