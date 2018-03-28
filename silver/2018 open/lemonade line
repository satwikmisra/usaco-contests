#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    ifstream cin("lemonade.in"); ofstream cout("lemonade.out");
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a, a+n);
    int ans=0; int i=n-1;
    while(a[i]>=ans){
        i--; ans++;
    }
    cout<<ans;
    return 0;
}
