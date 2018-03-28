#include <bits/stdc++.h>

using namespace std;

int n;
vector<int>v;

int main()
{
    ifstream cin("sort.in");
    ofstream cout("sort.out");
    cin>>n;
    for(int i=0;i<n;i++){
        int t; cin>>t;
        v.push_back(t);
    }
    int ans=0;
    for(int i=n-1;i>=ans;i--){
        int temp=0;
        for(int j=0;j<i;j++){
            if(v[j]>v[i]) temp++;
        }
        ans=max(ans, temp);
    }
    cout<<ans+1;
    return 0;
}
