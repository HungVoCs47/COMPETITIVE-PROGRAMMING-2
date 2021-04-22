# include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>ii;
#define ll long long
#define endl cout<<"\n"
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vp vector<ii>
#define sort_increase(a,n) sort(a,a+n)
#define sort_decrease(a,n) sort(a,a+n,greater<int>())
#define all(a) a.begin(),a.end()
#define _io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define loop0(n) for(int i=0;i<n;i++)
#define loop1(n) for(int i=1;i<=n;i++)
const int M=1e9+7;
const int N=3e5+10;
int merge(vector<int>&a, int l, int m, int r)
{
	vector<int>b(a.begin()+l,a.begin()+m+1);
	vector<int>c(a.begin()+m+1,a.begin()+r+1);
	int nB=m-l+1,nC=r-m;
	int i=0,j=0,k=l;
	int cnt=0;
	while(i<nB and j<nC)
	{
		if(b[i]>c[j]){
			a[k++]=c[j++];
		}
		else
		{
			a[k++]=b[i++];
			cnt+=j;
		}
	}
	while(i<nB)
	{
		a[k++]=b[i++];
		cnt+=j;
	}
	while(j<nC)
	{
		a[k++]=c[j++];
	}
	return cnt;
}
int DC(vector<int>&a, int l, int r)
{
	if(l>=r) return 0;
	int mid=(l+r)/2;
	int cnt_left=DC(a,l,mid);
	int cnt_right=DC(a,mid+1,r);
	int cnt_mid=merge(a,l,mid,r);
	return cnt_left+cnt_right+cnt_mid;
}
void solve()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	int left=0;
	int right=n-1;
	//int mid=(left+right)/2;
	cout<<DC(a,left,right);
}
int main()
{
	_io;
	int t=1;
	while(t--)
	{
	  solve();	
	}
	return 0;
}