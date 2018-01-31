#include <bits/stdc++.h>

using namespace std;

bool a[101][101];
int x,y,k,m;

int main()
{
    ifstream cin("pails.in"); ofstream cout("pails.out");
    cin>>x>>y>>k>>m;
    a[0][0]=true;
    for(int s=0;s<k;s++){
        bool temp[101][101];
        for(int q=0;q<101;q++){
                for(int w=0;w<101;w++){
                    temp[q][w]=false;
                }
                }
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                if(!a[i][j]) continue;

                temp[i][0]=true;
                temp[0][j]=true;
                temp[x][j]=true;
                temp[i][y]=true;
                temp[i][j]=true;
                int a1=min(i,y-j);
                temp[i-a1][j+a1]=true;
                int b=min(x-i,j);
                temp[i+b][j-b]=true;
            }
        }
        for(int q=0;q<101;q++){
                for(int w=0;w<101;w++){
                    a[q][w]=temp[q][w];
                }
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            if(a[i][j]){
                ans=min(ans, abs(i+j-m));
            }
        }
    }
    cout<<ans;
    return 0;
}
