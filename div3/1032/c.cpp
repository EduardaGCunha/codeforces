#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
I want to minimize the maximum value in this grid
The operations that I'm allowed to do is choose some int i, j and decrease by 1 each 
valeu in the ith line and jth column 
maybe I can just find the maximum and get all of their positions
if all of them share some side i or j, then we can decrease them by 1 
otherwise its their value
im testing for the first value if they other coordinates match
*/

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<pair<int, int>> freq;
    int mx = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] > mx){
                mx = grid[i][j];
                freq.clear();
                freq.push_back({i, j});
            }else if(grid[i][j] == mx){
                freq.push_back({i, j});
            }
        }
    }

    int i = freq[0].first; 
    int j = freq[0].second; 
    int c = -1, pos = 1;
    //cout << i << " " << j << endl;
    for(auto [a, b] : freq){
        if(a == i) continue;
        if(c == -1) c = b;
        else if(c != b){
            pos = 0;
            break;
        }
    }
    if(pos){
        cout << mx-1 << endl;
        return;
    }

    int l = -1;
    pos = 1;
    for(auto [a, b] : freq){
        if(b == j) continue;
        if(l == -1) l = a;
        else if(l != a){
            pos = 0;
            break;
        }
    }

    if(pos) cout << mx-1 << endl;
    else  cout << mx << endl;
    
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
