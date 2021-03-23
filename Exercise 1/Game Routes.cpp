# include <bits/stdc++.h>
using namespace std;
# define ll long long
int n,m;
const int MAXN=1e5+5;
const int MOD=1e9+7;
vector<int>adj[MAXN];
ll d[MAXN]={0};
bool visited[MAXN]={false};
vector<int>result;
void dfs(int u)
{
	visited[u]=true;
	for(int v:adj[u])
	{
		if(!visited[v]) dfs(v);
	}
	result.push_back(u);
}
/*void bfs()
{
	queue<int>q;
	q.push(1);
	d[1]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		//cout<<u<<" ";
		if()
		visited[u]=true;
		for(int v:adj[u])
		{
			q.push(v);
			d[v]++;
			d[v]%=MOD;
		}
	}
}*/
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=0,a,b;i<m;i++)
	{
		cin>>a>>b;
		adj[a].push_back(b);
	}
	dfs(1);
	reverse(result.begin(),result.end());
	d[1]=1;
	for(int i=0;i<result.size();i++)
	{
		for(int j:adj[result[i]]) d[j]+=d[result[i]],d[j]%=MOD;
	}
	cout<<d[n];
	return 0;
}
