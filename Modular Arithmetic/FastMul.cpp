/*
INPUT:
1912345678 754 5
OUTPUT:
2
*/
# include <bits/stdc++.h>
using namespace std;
# define _io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int fastMul(int a, int b, int m)
{
	if(b==0) return 0;
	int res=fastMul(a,b/2,m);
	res=(res+res)%m;
	if(b%2==1)
	{
		res=(res+a)%m;
	}
	return res;
}
int main()
{
	_io;
    int a,b,m;
    cin>>a>>b>>m;
    cout<<fastMul(a,b,m);
	return 0;
}