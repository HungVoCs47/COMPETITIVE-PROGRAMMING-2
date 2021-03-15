# include <bits/stdc++.h>
using namespace std;
vector<int>adj[100005];
bool visited[100005];
bool used[100005];
int a[300005],b[300005],outdegree[300005]={0};
vector<int>anss[100005];
int cost[100005];
int cnt=0;
const int MOD=1e9+7;
vector<int> low,num;
vector<bool>found;
vector<int>result;
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
			anss[cnt].push_back(cost[v]);
		}while(v!=u);
		result.push_back(cnt);
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
	cin>>n;
    for(int i=1;i<=n;i++) cin>>cost[i];
    cin>>m;
    for(int i=0;i<m;i++)
    {
    	cin>>a[i]>>b[i];
    	adj[a[i]].push_back(b[i]);
	}
	tarjan();
	long long min_cost=0;
	long long number_of_ways=1;
	for(int i=0;i<result.size();i++)
	{
		int minn=*min_element(anss[result[i]].begin(),anss[result[i]].end());
		int tt=0;
		for(int k=0;k<anss[result[i]].size();k++)
		{
			if(anss[result[i]][k]==minn) tt++;
		}
		min_cost+=minn;
		number_of_ways=(number_of_ways*tt)%MOD;
	}
	cout<<min_cost<<" "<<number_of_ways;
    return 0;
}

