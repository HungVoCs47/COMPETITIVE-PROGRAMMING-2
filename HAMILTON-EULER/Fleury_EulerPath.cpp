/*
INPUT:
4 5
0 1 
1 2
2 3 
3 0
0 2
OUTPUT:
2 3 0 2 1 0
---> reverse:
0 1 2 0 3 2
*/
# include <bits/stdc++.h>
using namespace std;
# define _io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAXN=110;
int deg[MAXN][MAXN];
int n,m;
vector<int>result;
void findEulerPath(int u)
{
	for(int v=0;v<n;v++)
	{
		if(deg[u][v]>0)
		{
			deg[u][v]--;
			deg[v][u]--;
			findEulerPath(v);
		}
	}
	result.push_back(u);
}
int main()
{
	_io;
	cin>>n>>m;
	for(int u,v,i=0;i<m;i++)
	{
		cin>>u>>v;
		deg[u][v]++;
		deg[v][u]++;
	}
	findEulerPath(0);
	for(int v: result){
		cout<<v<<" ";
	}
	return 0;
}