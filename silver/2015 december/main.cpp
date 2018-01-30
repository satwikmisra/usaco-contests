#include <bits/stdc++.h>

using namespace std;

int pref[100001][4];
int n,q;

int main()
{
    ifstream cin("bcount.in"); ofstream cout("bcount.out");
    for(int i=1;i<=3;i++){
        pref[0][i]=0;
    }
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int id; cin>>id;
        for(int j=1;j<=3;j++){
            pref[i][j]=pref[i-1][j];
        }
        pref[i][id]++;
    }
    for(int i=0;i<q;i++){
        int a,b; cin>>a>>b;
        cout<<
        pref[b][1]-pref[a-1][1]<<" "<<
        pref[b][2]-pref[a-1][2]<<" "<<
        pref[b][3]-pref[a-1][3]<<"\n";
    }

    return 0;
}
