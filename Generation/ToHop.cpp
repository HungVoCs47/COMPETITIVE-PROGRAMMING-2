# include <bits/stdc++.h>
using namespace std;
bool nextCombination(int n, int k, vector<int>&a)
{
	int i=k-1;
	while(i>=0 and a[i]==n-k+i+1) i--;
	if(i<0) return false;
	a[i]++;
	for(int j=i+1;j<k;j++) a[j]=a[j-1]+1;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,k;
	cin>>n>>k;
	vector<int>a;
	for(int i=1;i<=k;i++)
	{
		a.push_back(i);
	}
	do
	{
		for(int i=0;i<k;i++) cout<<a[i]<<" ";
		cout<<"\n";
	}while(nextCombination(n,k,a));
	return 0;
}