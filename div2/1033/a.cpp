#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

bool possible(int l1, int b1, int l2, int b2, int l3, int b3){
    long long S = l1*b1 + l2*b2 + l3*b3;
    int s = floor(sqrt((long double)S));
    if(s*s != S) return false;
    if(b1==s && b2==s && b3==s && l1+l2+l3==s) return true;
    if(l1==s && l2==s && l3==s && b1+b2+b3==s) return true;
    if(b1==s){
        int w = s - l1;
        if(w>0 && l2==w && l3==w && b2+b3==s) return true;
    }
    if(l1==s){
        int h = s - b1;
        if(h>0 && b2==h && b3==h && l2+l3==s) return true;
    }
    return false;
}

void solve(){
    int l1,b1,l2,b2,l3,b3;
    cin>>l1>>b1>>l2>>b2>>l3>>b3;
    string ans="NO";
    if(possible(l1,b1,l2,b2,l3,b3)) ans="YES";
    if(possible(l2,b2,l1,b1,l3,b3)) ans="YES";
    if(possible(l3,b3,l1,b1,l2,b2)) ans="YES";
    if(possible(l1,b1,l3,b3,l2,b2)) ans="YES";
    if(possible(l2,b2,l3,b3,l1,b1)) ans="YES";
    if(possible(l3,b3,l2,b2,l1,b1)) ans="YES";
    cout<<ans<<endl;
}

signed main(){
    fastio;
    int t;
    cin>>t;
    while(t--) solve();
}
