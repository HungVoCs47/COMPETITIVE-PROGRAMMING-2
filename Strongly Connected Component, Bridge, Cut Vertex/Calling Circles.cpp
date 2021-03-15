# include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>ii;
vector<int>adj[30];
int cnt[30][30]={0};
bool used[30];
vector<int>low,num;
vector<bool>found;
vector<int>result[30];
stack<int>st;
int n,m;
int counter;
int testcase=1;
int ff;
void check(int u)
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
				check(v);
				low[u]=min(low[u],low[v]);
			}
		}
	}
	int ans=1e9;
	if(num[u]==low[u])
	{
		int v;
		do
		{
			v=st.top();
			st.pop();
            found[v]=true;
            result[ff].push_back(v);
		}while(v!=u);
		ff++;
	}
}
void tarjan()
{
	counter=0;
	low.assign(n+1,0);
	num.assign(n+1,0);
	found.assign(n+1,false);
	counter=0;
	ff=0;
	st=stack<int>();
	for(int i=1;i<=n;i++)
	{
		if(!num[i])
		{
			check(i);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while(1)
	{
	cin>>n>>m;
	if(n==0 && m==0) break;
	map<string,int>mm;
	map<int,string>bb;
	int k=1;
    for(int i=0;i<m;i++)
    {
    	string a,b;
    	cin>>a>>b;
        if(mm[a]==0)
        {
        	mm[a]=k;
        	bb[k]=a;
        	k++;
		}
		if(mm[b]==0)
		{
			mm[b]=k;
			bb[k]=b;
			k++;
		}
		if(cnt[mm[a]][mm[b]]==0)
		{
		adj[mm[a]].push_back(mm[b]);
		cnt[mm[a]][mm[b]]++;
		}
    }
    tarjan();
    cout<<"Calling circles for data set "<<testcase<<":\n";
    for(int i=0;i<ff;i++)
    {
    	for(int j=0;j<result[i].size()-1;j++)
    	{
    		cout<<bb[result[i][j]]<<", ";
		}
		cout<<bb[result[i][result[i].size()-1]]<<"\n";
		//cout<<"\n";
	}
    cout<<"\n";
	for(int i=0;i<28;i++) result[i].clear(),adj[i].clear();
	memset(cnt,0,sizeof(cnt));
	testcase++;
	}
 	return 0;
}
