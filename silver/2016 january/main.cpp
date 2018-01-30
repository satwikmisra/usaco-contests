#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<int>pos;

int main()
{
    ifstream cin("angry.in"); ofstream cout("angry.out");
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int t; cin>>t;
        pos.push_back(t);
    }
    int lo=0;
    int hi=1000000000;
    while(lo<hi){
        //cout<<1;
        int mid=(lo+hi)/2;
        int cur=0;
        int c=0;
        sort(pos.begin(), pos.end());
        while(cur<n){
            //cout<<1;
            c++;
            int next=cur+1;
            while(next<n && pos[next]-pos[cur]<=2*mid){
                next++;
            }
            cur=next;
        }

        if(c<=k){
            hi=mid;
        }
        else
            lo=mid+1;
    }
    cout<<lo;
    return 0;
}
