# include <bits/stdc++.h>
using namespace std;
bool visited[29];
vector<int>result;
vector<int>adj[100005];
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
	map<char,int>m;
	memset(visited,true,sizeof(visited));
	int k=1;
	for(char i='A';i<='Z';i++)
	{
		//cout<<i<<" ";
		m[i]=k;
		k++;
	}
	vector<string>book;
	string s;
	while(cin>>s)
	{
		if(s=="#") break;
	    book.push_back(s);
	    for(int i=0;i<s.size();i++)
	    {
	    	visited[m[s[i]]]=false;
		}
	}
	for(int i=1;i<book.size();i++)
	{
		string cur=book[i];
		string pre=book[i-1];
		for(int j=0;j<min(cur.size(),pre.size());j++)
		{
			if(cur[j]!=pre[j])
			{
				adj[m[pre[j]]].push_back(m[cur[j]]);
				break;
			}
		}
	}
	for(char i='A';i<='Z';i++)
	{
		if(!visited[m[i]])
		{
			dfs(m[i]);
		}
	}
	for(int i=result.size();i>=0;i--)
	{
		for(char j='A';j<='Z';j++)
		{
			if(m[j]==result[i]) cout<<j;
		}
	}
	return 0;
}
