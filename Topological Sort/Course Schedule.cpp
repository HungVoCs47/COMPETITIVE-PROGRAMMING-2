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
int main()
{
	int E;
	cin>>V>>E;
	for(int i=1;i<=V;i++)
	{
		int a;
		cin>>a;
		bfs[i].push_back(a);
		indegre[a]++;
	}
	for(int i=1;i<=V;i++)
	{
		if(!visited[i] && indegre[i]==0) BFS(i);
	}
	for(int i=0;i<result.size();i++) cout<<result[i]<<" ";
	if(result.size()!=V) cout<<"IMPOSSIBLE";
	else
	{
		for(int i=0;i<result.size();i++) cout<<result[i]<<" ";
	}
	return 0;
}

