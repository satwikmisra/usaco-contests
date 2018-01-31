#include <bits/stdc++.h>

using namespace std;

bool a[2002][2002];

struct point{
    int x;
    int y;
};

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

bool inbounds(int x, int y){
    return (x>=0 && y>=0 && x<2002 && y<2002);
}

int main()
{
    ifstream cin("gates.in"); ofstream cout("gates.out");
    int n; string s; cin>>n>>s;
    int curx=1000; int cury=1000;
    for(int i=0;i<n;i++){
        int dx=0; int dy=0;
        char c=s[i];
        if(c=='N') dy++;
        if(c=='S') dy--;
        if(c=='E') dx++;
        if(c=='W') dx--;
        for(int i=0;i<2;i++){
            curx+=dx; cury+=dy;
            a[curx][cury]=true;
        }
    }
    int ans=0;
    for(int i=0;i<2002;i++){
        for(int j=0;j<2002;j++){
            if(a[i][j]) continue;
            ans++;
            queue<pair<int, int>>q;
            q.push(make_pair(i,j));
            a[i][j]=true;
            while(!q.empty()){
                pair<int,int>p=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nx=p.first+dx[k];
                    int ny=p.second+dy[k];
                    if(inbounds(nx, ny) && !a[nx][ny]){
                        a[nx][ny]=true;
                        q.push(make_pair(nx, ny));
                    }
                }
            }

        }
    }
    cout<<ans-1;
}
