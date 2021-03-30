# include <bits/stdc++.h>
using namespace std;
void gen(int A[], int n){
    ++A[n-1];
    for(int i=n-1;i>0;i--){
        if (A[i]>1){
            ++A[i-1];
            A[i]-=2;
        }
    }
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,l,r,x;
    cin>>n>>l>>r>>x;
    int ss[n+10];
    for(int i=0;i<n;i++) cin>>ss[i];
    int *A=new int[n];
    for (int i=0;i<n;i++) A[i]=0;
    int ans=0;
    for(int i=0;i<pow(2,n);i++){
        int sum=0;
        int maxx=-1e9;
        int minn=1e9;
        for(int i=0;i<n;i++)
        {
        	if(A[i]==1)
        	sum+=ss[i],minn=min(minn,ss[i]),maxx=max(maxx,ss[i]);
		}
		if( sum>=l and sum<=r and maxx-minn>=x) ans++;
		//cout<<sum<<" ";
		//for(int i=0;i<n;i++) cout<<A[i]<<"";
		//cout<<"\n";
        gen(A,n);
    }
    cout<<ans<<" ";
    return 0;
}
 