/*
    * Author: HungVoCs47
    * Status: AC
*/
#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
typedef long long ll;
const int MAXN=1e5+5;
const int mod =1e9+7;
using namespace std;
int cot[MAXN];
int nex[MAXN];
int deq[MAXN];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(cot,0,sizeof(cot));
    memset(nex,0,sizeof(nex));
    memset(deq,0,sizeof(deq));
    int n,k;
    cin>>n>>k;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(i==1&&x!=1)
        {
            ans++;
            continue;
        }
        else
        {
            nex[i]=x;
            cot[x]++;
        }
    }
    queue<int>Q;
    int t=0,h=0;
    for(int i=2;i<=n;i++)
        if(!cot[i])
            Q.push(i);
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        if(u==1)
            break;
 
        if(nex[u]!=1&&deq[u]==(k-1))
            ans++;
        else
        deq[nex[u]]=max(deq[nex[u]],deq[u]+1);
        cot[nex[u]]--;
        if(!cot[nex[u]])
            Q.push(nex[u]);
    }
    cout<<ans<<endl;
    return 0;
}

