# include <bits/stdc++.h>
using namespace std;
# define _io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define ll long long
int N;
int a[15];
bool done=false;

void backtrack(int x, int k){
	ll left=1LL;
	ll right=1LL*N;
	for(int j=1;j<x;j++)
	{
		left*=1LL*(a[j]+1);
		right*=1LL*a[j];
	}
	if(left>=right) return;
	if(x==k)
	{
		if(left%(right-left)==0)
		{
			a[k]=left/(right-left);
			done=true;
		}
		return;
	}
	a[x]=a[x-1];
	bool found;
	do
	{
		found=false;
		for(int j=x;j<=k;j++)
		{
			left*=(a[x]+1);
			right*=a[x];
		}
		if(left>=right){
			found=true;
			backtrack(x+1,k);
			if(done==true)
			{
				return;
			}
		}
		for(int j=x;j<=k;j++)
		{
			left/=(a[x]+1);
			right/=a[x];
		}
		a[x]++;
	}while(found==true);
}
int main()
{
	_io;
	cin>>N;
	done=false;
	for(int i=0;i<15;i++) a[i]=0;
	a[0]=1;
	int k=1;
	while(1)
	{
		backtrack(1,k);
		if(done==true){
			break;
		}
		k++;
	}
	cout<<k<<" ";
	return 0;
}
