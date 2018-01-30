#include <bits/stdc++.h>

using namespace std;

int n;


int main()
{
    ifstream cin("highcard.in"); ofstream cout("highcard.out");
    cin>>n;
    bitset<2*50001>score;
    for(int i=0;i<n;i++){
        int t; cin>>t;
        score[t]=1;
    }
    vector<int>elsie;
    vector<int>bessie;
    for(int i=1;i<=2*n;i++){
        if(score.test(i)) elsie.push_back(i);
        else bessie.push_back(i);
    }
    int b=0;
    int e=0;
    int ans=0;

    while(b<n){
        if(bessie[b]>elsie[e]){
            ans++;
            b++;
            e++;
            //cout<<e<<" "<<b<<"\n";
        }
        if(bessie[b]<elsie[e]){
            b++;
        }
    }
    cout<<ans;

    return 0;
}
