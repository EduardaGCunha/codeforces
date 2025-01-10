#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define int long long

void solve(){
    string s;
    cin >> s;
    int sum = 0;
    int two = 0, three = 0;
    for(auto u : s){
        if(u == '2') two++;
        else if(u == '3') three++;
        sum += u-'0';
    }
    if(sum%9 == 0){
        cout << "YES" << endl;
        return;
    }
    for(int i = 0; i <= two; ++i){
        int new_s = sum + 2*i;

        for(int j = 0; j <= three; ++j){
            int cnt = new_s + 6*j;
            if(cnt%9 == 0){
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

signed main() {_
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
} 