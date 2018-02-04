#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int n;
vector<int>x;
vector<int>y;
vector<int>p;
bool pos[201][201];
bool visit[201];
int ret=0;
int ans=0;

void dfs(int cur){
    if(visit[cur]) return;
    visit[cur]=true;
    for(int i=0;i<n;i++){
        if(!visit[i] && pos[cur][i]){
            ret++;
            dfs(i);
        }
    }
}

int main()
{
    ifstream cin("moocast.in"); ofstream cout("moocast.out");
    cin>>n;
    for(int i=0;i<n;i++){
        int t1,t2,t3; cin>>t1>>t2>>t3;
        x.pb(t1); y.pb(t2); p.pb(t3);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int k= (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
            if(k <= p[i] * p[i]){
                pos[i][j]=true;
            }
            else pos[i][j]=false;
        }
    }
    for(int i=0;i<n;i++){
        ret=0;
        fill_n(visit,201,false);
        dfs(i);
        ans=max(ans, ret+1);
    }
    cout<<ans;

    return 0;
}
