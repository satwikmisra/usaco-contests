#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int> >v;

int main()
{
    ifstream cin("balancing.in"); ofstream cout("balancing.out");
    cin>>n;
    for(int i=0;i<n;i++){
        int t1,t2; cin>>t1>>t2;
        v.push_back(make_pair(t1,t2));
    }
    sort(v.begin(), v.end());
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int cuty=v[j].second;
            int left=0;
            int bleft=0;
            int right=0;
            int bright=0;
            for(int k=0;k<=i;k++){
                left++;
                if(v[k].second<cuty){
                    bleft++;
                }
            }
            for(int k=i+1;k<n;k++){
                right++;
                if(v[k].second<cuty){
                    bright++;
                }
            }
            int temp=max(bleft, bright);
            temp=max(temp, left-bleft);
            temp=max(temp, right-bright);
            ans=min(ans, temp);
        }
    }
    cout<<ans;
    return 0;
}
