#include <bits/stdc++.h>

using namespace std;
int n;


int main()
{
    ifstream cin("div7.in"); ofstream cout("div7.out");
    cin>>n;
    int cows[n+1];
    for(int i=1;i<=n;i++){
        int t; cin>>t;
        t%=7;
        cows[i]=t;
    }
    int pref[n+1];
    pref[0]=0;
    for(int i=1;i<=n;i++){
        pref[i]=pref[i-1]+cows[i];
    }
    int ans=INT_MIN;
    for(int i=0;i<=n;i++){
        for(int j=n;j>i;j--){
            bool flag=false;
            if((pref[j]-pref[i])%7==0){
                ans=max(ans, j-i);
                flag=true;
            }
            if(flag) break;
        }
    }
    cout<<ans;
    return 0;
}
