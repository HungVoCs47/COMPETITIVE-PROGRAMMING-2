# include <bits/stdc++.h>
using namespace std;
int find_sub(string &p, string &s)
{
	int best=0;
	for(int i=0;i<s.length() and i<p.length();i++)
	{
	    if(p.substr(p.length()-1-i)==s.substr(0,i+1)) best=i+1;	
	}
	return best;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	for(int tc=1;tc<=t;tc++)
	{
		int n;
		cin>>n;
		vector<string>word;
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			word.push_back(s);
		}
		sort(word.begin(),word.end());
		int best=1e9;
		do
		{
			string cur=word[0];
			 for(int i=1;i<word.size();i++){
                int len=find_sub(cur,word[i]);
                cur += word[i].substr(len);
            }
             best=min(best,(int)cur.length());
		}while(next_permutation(word.begin(),word.end()));
	cout<<"Case "<<tc<<": "<<best<<"\n";
    }
	return 0;
}