#include<algorithm>
#include <iostream>
#include<cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
int a[20];
int n;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    bool flag=false;
    for(int i=0;i<1<<n;i++){
        int ans=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                ans+=a[j];
            }else{
                ans-=a[j];
            }
        }
        if(ans%360==0){
            flag=true;
            break;
        }
    }
    if(flag){
        printf("YES");
    }else{
        printf("NO");
    }
    return 0;
}
