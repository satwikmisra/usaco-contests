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
    int ans=0;
    for(int i=0;i<7;i++){
        int e=n;
        int b=0;
        for(int k=n;k>=0;k--){
            if(pref[k]%7==i){
                b=k;
                break;
            }
        }
        for(int k=0;k<=n;k++){
            if(pref[k]%7==i){
                e=k;
                break;
            }
        }
        ans=max(ans, b-e);
    }
    cout<<ans;
    return 0;
}
