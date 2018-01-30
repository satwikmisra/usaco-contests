#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

int n, m;
vector<pii> switches[101][101];
bool on[101][101];
bool visited[101][101];
int dr[4]={-1,1,0,0};
int dc[4]={0,0,1,-1};

bool inbounds(int r, int c){
    return (r>=0 && c>=0 && r<=n && c<=n);
}

void turn(int r, int c){
    if(!on[r][c]) return;
    if(visited[r][c]) return;
    visited[r][c]=true;
    for(int i=0;i<switches[r][c].size();i++){
        int nr=switches[r][c][i].first;
        int nc=switches[r][c][i].second;
        on[nr][nc]=true;
        for(int k=0;k<4;k++){
            int nnr=nr+dr[k];
            int nnc=nc+dc[k];
            if(!inbounds(nnr, nnc)) continue;
            if(visited[nnr][nnc]){
                turn(nr, nc);
            }
        }
    }
    for(int k=0;k<4;k++){
        int nr=r+dr[k];
        int nc=c+dc[k];
        if(!inbounds(nr, nc)) continue;
        if(!visited[nr][nc]){
            turn(nr,nc);
        }
    }
}

int main()
{
    ifstream cin("lightson.in"); ofstream cout("lightson.out");
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        int t1,t2; cin>>t1>>t2;
        switches[a][b].push_back(make_pair(t1,t2));
    }
    on[1][1]=true;
    turn(1,1);
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(on[i][j]) ans++;
        }
    }
    cout<<ans;

    return 0;
}
