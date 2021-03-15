# include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
vector<int>adj[MAXN];
int indegree[MAXN];
vector<int>result;
int n,m;
bool kahn(){
	queue<int>q;
    for(int i=1;i<=n;i++) if(indegree[i]==0)
	q.push(i);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		result.push_back(u);
		for(int i=0;i<adj[u].size();i++)
		{
			int v=adj[u][i];
			indegree[v]--;
			if(indegree[v]==0) q.push(v);
		}
	}
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
		indegree[b]++;
	}
	kahn();
	if(result.size()!=n) cout<<"IMPOSSIBLE\n";
	else
	{
		//reverse(result.begin(),result.end());
		for(int i=0;i<n;i++) cout<<result[i]<<" ";
	}
	return 0;
}
