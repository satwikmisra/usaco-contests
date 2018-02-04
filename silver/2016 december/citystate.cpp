#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream cin("citystate.in");
    ofstream cout("citystate.out");
    int n; cin>>n;
    multiset<string>ss1;
    multiset<string>ss2;
    set<string>cont;
    for(int i=0;i<n;i++){
        string s1,s2; cin>>s1>>s2;
        string t1=s1.substr(0,2)+s2;
        string t2=s2+s1.substr(0,2);
        if(t1!=t2){
            ss1.insert(t1); ss2.insert(t2);
            cont.insert(t1);
        }
    }
    int ans=0;
    for(auto it=cont.begin();it!=cont.end();it++){
        string temp=*it;
        ans+= (ss1.count(temp))*(ss2.count(temp));
    }
    ans/=2;
    cout<<ans;
}
