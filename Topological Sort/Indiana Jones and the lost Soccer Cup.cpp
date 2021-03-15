/*
    * Author: HungVoCs47
    * Status: AC
*/
# include <bits/stdc++.h>
using namespace std;
vector<int>bfs[100005];
bool ok[100005];
int indegre[100005]={0};
vector<int>result;
int V;
bool visited[100005]={false};
bool BFS(int u)
{
   	queue<int>q;
   	q.push(u);
   	while(q.size()>0)
   	{
   		int top=q.front();q.pop();
   		//cout<<top<<" ";
   		result.push_back(top);
   		visited[top]=true;
   		for(int i=0;i<bfs[top].size();i++)
   		{
   			indegre[bfs[top][i]]--;
   			if(indegre[bfs[top][i]]==0 && !visited[bfs[top][i]])
   			{
   				q.push(bfs[top][i]);
   			}
   		}
   	}
}
/*void dfs(int u)
{
	visited[u]=true;
	for(int i=0;i<bfs[u].size();i++)
	{
		int v=bfs[u][i];
		if(!visited[v]) dfs(v);
	}
}*/
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
	//int z,y;
	//z=y=V;
	int E;
	cin>>V>>E;
	int luu_vet[V+10]={0};
	memset(luu_vet,0,sizeof(luu_vet));
	for(int i=0;i<E;i++)
	{
		int a,b;
		cin>>a>>b;
		bfs[a].push_back(b);
		luu_vet[a]++;
		luu_vet[b]++;
		indegre[b]++;
	}
	for(int i=1;i<=V;i++)
	{
		if(!visited[i] && indegre[i]==0) BFS(i);
	}
	memset(visited,false,sizeof(visited));
	int cnt=0;
	//cout<<luu_vet[3]<<" ";
	for(int i=1;i<=V;i++)
	{
		if(luu_vet[i]==0) cnt++;
	}
    if(result.size()!=V) cout<<"recheck hints";
	else
	{
		if(cnt==0)
		{
		for(int i=0;i<result.size();i++) cout<<result[i]<<" ";
	    }
		else cout<<"missing hints";
	}
	cout<<"\n";
	for(int i=1;i<=V;i++) bfs[i].clear();
	memset(indegre,0,sizeof(indegre));
	memset(visited,false,sizeof(visited));
	result.clear();
    }
	return 0;
}

