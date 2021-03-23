# include <bits/stdc++.h>
using namespace std;
# define ll long long
typedef pair<int,int>ii;
int n,m;
const int MAXN=1e5+5;
const int MOD=1e9+7;
vector<int>adj[MAXN];
ll d[MAXN];
ll cnt[MAXN]={0};
bool visited[MAXN]={false};
void dijkstra()
{
	priority_queue<ii,vector<ii>,greater<ii>>q;
	memset(d,1e9,sizeof(d));
	q.push(ii(0,1));
	d[1]=0;
	while(!q.empty())
	{
		int u=q.top().second,du=q.top().first;q.pop();
		if(d[u]!=du);
		for(int v:adj[u])
		{
			if(d[v]<du+1)
			{
				d[v]=du+1;
				q.push(ii(d[v],v));
			}
			cnt[v]++;
			cnt[v]%=MOD;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=0,a,b;i<m;i++)
	{
		cin>>a>>b;
		adj[a].push_back(b);
	}
	dijkstra();
	//for(int i=1;i<=n;i++) cout<<d[i]<<" ";
	cout<<cnt[n];
	return 0;
}
