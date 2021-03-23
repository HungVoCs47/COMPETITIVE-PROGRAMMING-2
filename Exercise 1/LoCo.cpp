# include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>ii;
const int MAXN=1e4+5;
vector<ii>adj[MAXN];
bool visited[MAXN];
vector<int>result;
int d[MAXN]={0};
int ans=-1e9;
int n;
int indegree[MAXN];
void kahn(){
	queue<int>q;
    for(int i=0;i<n;i++) if(indegree[i]==0)
	q.push(i);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		result.push_back(u);
		//cout<<u<<" ";
		for(ii v:adj[u])
		{
			indegree[v.second]--;
			if(indegree[v.second]==0) q.push(v.second);
		}
	}
}
void dijkstra(int uu){
    priority_queue<ii>pq;
    d[uu]=0;
    pq.push(ii(0,uu));
    while(pq.size()) {
        int u=pq.top().second;
        int du=pq.top().first;
        pq.pop();
        if (du!=d[u])
            continue;
        for (int i=0;i<adj[u].size();i++) {
            int v=adj[u][i].second;
            int uv=adj[u][i].first;
            if (d[v]<du+uv) {
                d[v]=du+uv;
                pq.push(ii(d[v],v));
                ans=max(ans,d[v]);
            }
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	map<int,int>m;
	cin>>n;
	int a[n+10];
	for(int i=0;i<n;i++) cin>>a[i],m[a[i]]=i;
	sort(a,a+n);
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int k=a[i]+a[j];
			int kk=lower_bound(a,a+n,k)-a;
			if(a[kk]==k) 
			{
				adj[m[a[i]]].push_back(ii(1,m[a[kk]]));
				adj[m[a[j]]].push_back(ii(1,m[a[kk]]));
				indegree[m[a[kk]]]+2;
			}
		}
	}
	memset(visited,false,sizeof(visited));
	kahn();
	for(int i=0;i<result.size();i++)
	{
		if(!d[result[i]]) dijkstra(i);
	}
	cout<<ans+1;
	return 0;
}