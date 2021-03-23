#include <iostream>
#include <string.h>
using namespace std;
int c[30][30];
void C()
{
    for(int i=0;i<=26;i++){
		for(int j=0;j<=i;j++){
			if(i==0||j==0) c[i][j]=1;
			if(i==j) c[i][j]=1;
			else c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    C();
    while(cin>>s)
    {
        int len=s.length();
        int i;
        for(i=1;i<len;i++)
        {
            if(s[i]<=s[i-1])
                break;
        }
        if(i<len)
        {
            cout<<0<<"\n";
            continue;
        }
        int sum=0;
        for(i=1;i<len;i++)
          sum+=c[26][i]; 
            for(int k=0;k<len;k++) 
        {
            char ch=k==0?'a':(s[k-1]+1);
              for(char j=ch;j<s[k];j++)
                sum+=c['z'-j][len-1-k];
        }
                 cout<<sum+1<<"\n";
    }
    return 0;
}
