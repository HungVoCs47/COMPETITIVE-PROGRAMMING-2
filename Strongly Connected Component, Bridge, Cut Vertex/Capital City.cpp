# include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>ii;
vector<int>adj[100005];
bool visited[100005];
bool used[100005];
int a[200005],b[200005],outdegree[100005]={0};
int cnt=0;
vector<int> low,num;
vector<bool>found;
stack<int>st;
int n,m;
int counter;
int luu_vet;
int id_cmd[100005]={0};
void check(int u,vector<int>&result)
{
	counter++;
	num[u]=low[u]=counter;
	st.push(u);
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(!found[v])
		{
			if(num[v]>0) low[u]=min(low[u],num[v]);
			else 
			{
				check(v,result);
				low[u]=min(low[u],low[v]);
			}
		}
	}
	if(num[u]==low[u])
	{
		cnt++;
		int v;
		do
		{
			v=st.top();
			st.pop();
			found[v]=true;
			id_cmd[v]=cnt;
		}while(v!=u);
	}
}
void tarjan()
{
	counter=0;
	low.assign(n+1,0);
	num.assign(n+1,0);
	found.assign(n+1,false);
	counter=0;
	st=stack<int>();
	vector<int>result;
	for(int i=1;i<=n;i++)
	{
		if(!num[i])
		{
			check(i,result);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t=1;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			cin>>a[i]>>b[i];
			adj[a[i]].push_back(b[i]);
		}
		tarjan();
		for(int i=0;i<m;i++)
		{
			if(id_cmd[a[i]]!=id_cmd[b[i]])
			{
				outdegree[id_cmd[a[i]]]++;
			}
		}
		int num_cnt=0;
		for(int i=1;i<=cnt;i++)
		{
			if(outdegree[i]==0) num_cnt++;
			if(num_cnt>=2)
			{
				cout<<0;
				return 0;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++) if(outdegree[id_cmd[i]]==0) ans++;
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++) if(outdegree[id_cmd[i]]==0) cout<<i<<" ";
		cout<<"\n";
	}
	return 0;
}
