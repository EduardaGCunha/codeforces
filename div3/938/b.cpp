#include <bits/stdc++.h>
using namespace std;

int n, c, d; 

void solve(){
    cin >> n >> c >> d;
    int arr[n*n];
    int low = INT_MAX;
    for(int i = 0; i < (n*n); i++){
        cin >> arr[i];
        low = min(low, arr[i]);
    }
    int grid[n][n];
    grid[0][0] = low;
    for (int i = 0; i < n; i++){
        if (i > 0) grid[i][0] = grid[i-1][0] + d; 
        for (int j = 1; j < n; j++){
            grid[i][j] = grid[i][j-1] + c;
        }
    }

    vector<int> v;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            v.push_back(grid[i][j]);
        }
    }

    sort(v.begin(), v.end());
    sort(arr, arr+(n*n));
    for(int i = 0; i < v.size(); i++){
        if(arr[i] != v[i]){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}