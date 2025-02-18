#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)


void solve(){
    int n, m, k; cin >> n >> m >> k;
    string s = "L";
    string t; cin >> t;
    s += t;
    s += "L";

    vector<int> logs;
    for(int i = 0; i < n+2; i++){
        if(s[i] == 'L' && i != 0) logs.push_back(i);
    }

    int cur = 0, i = 0;
    while(i < n+1){
        if(s[i] == 'L'){
            if(logs[cur] - i <= m && cur < logs.size()){
                //cout << logs[cur] << " " << i << endl;
                i = logs[cur];
                cur++;
            }
            else i+=m;
        }else{
            if(s[i] == 'W' && k > 0){
                i++;
                k--;
            }else{
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;

}

int main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
}