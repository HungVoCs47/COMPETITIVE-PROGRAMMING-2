# include <bits/stdc++.h>
using namespace std;
# define _io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAXN=27;
vector<int>adj[MAXN];
int in_deg[MAXN];
int out_deg[MAXN];
int edge[MAXN];
bool visited[MAXN];
void dfs(int u)
{
	visited[u]=true;
	for(int v:adj[u])
	{
		if(!visited[v]) dfs(v);
	}
}
int main(){
	_io;
	map<char,int>m;
	int k=0;
	for(char i='a';i<='z';i++)
	{
		m[i]=k;
		k++;
	}
	int iTest;
	cin>>iTest;
	while(iTest--)
	{
		int n;
		cin>>n;
		memset(in_deg,0,sizeof(in_deg));
		memset(out_deg,0,sizeof(out_deg));
		memset(edge,0,sizeof(edge));
		while(n--)
		{
			string s;
			cin>>s;
			int l=s.length();
			adj[m[s[0]]].push_back(m[s[l-1]]);
			adj[m[s[l-1]]].push_back(m[s[0]]);
			edge[m[s[l-1]]]++;edge[m[s[0]]]++;
			out_deg[m[s[0]]]++;
			in_deg[m[s[l-1]]]++;
		}
		int cnt_pos=0;
		int v=-1,u=-1;
		bool check_1=true;
	    for(int i=0;i<26;i++)
	    {
	    	if(in_deg[i]!=out_deg[i])
	    	{
	    		if(v==-1) v=i;
	    		else if(u==-1) u=i;
	    		else 
				{
				 check_1=false;
	    		 break;
	    	    }
			}
		}
		bool check_2=false;
		if(check_1)
		{
			if((in_deg[v]-out_deg[v]==1 && out_deg[u]-in_deg[u]==1) or (out_deg[v]-in_deg[v]==1 && in_deg[u]-out_deg[u]==1))
			{
				check_2=true;
			}
		}
		if(v==-1) check_2=true;
		memset(visited,false,sizeof(visited));
		int cnt_connected=0;
		for(int i=0;i<26;i++) if(!visited[i] && edge[i]!=0) dfs(i),cnt_connected++;
		if(cnt_connected==1 && check_2==true && check_1==true) cout<<"Ordering is possible.\n";
		else cout<<"The door cannot be opened.\n";
		for(int i=0;i<26;i++) adj[i].clear();
	}
	return 0;
}
