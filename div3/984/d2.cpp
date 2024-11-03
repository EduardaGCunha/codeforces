#include <bits/stdc++.h>
using namespace std;

void solve(){
    int h, w; cin >> h >> w;
    vector<string> v(h);
    for(int i = 0; i < h; i++){
        cin >> v[i];
    }
    int u = 0, b = h-1, l = 0, r = w-1;
    vector<string> str;
    while(u <= b && l <= r){
        string t;
        for(int i = l; i <= r; i++){
            t += v[u][i];
        }
        for(int i = u+1; i < b; i++){
            t += v[i][r];
        }
        for(int i = r; i > l; i--){
            t+= v[b][i];
        }
        for(int i = b; i > u; i--){
            t+= v[i][l];
        }
        //cout << t << endl;
        str.push_back(t);
        u++, b--, l++, r--;
    }
    int ans = 0;
    for(auto u : str){
        u += u.substr(0, 3);
        for(int i = 0; i <= (int)(u.size() - 4); i++){
            if(u.substr(i, 4) == "1543") ans++;
        }
    }
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }   
}