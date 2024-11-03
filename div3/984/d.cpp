#include <bits/stdc++.h>
using namespace std;

int main(){
    #define fastio ios_base::sync_with_stdio(0); cin.tie(0)
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<string> grid(n);
        for(int i = 0; i < n; i++) cin >> grid[i]; 

        int t = 0, l = 0, r = m-1, b = n - 1;
        vector<vector<int>> ans;
        while((t <= b) && (l <= r)){
            vector<int> aux;
            for(int i = l; i <= r; i++) aux.push_back(grid[t][i]-'0');
        
            for(int i = t+1; i <= b; i++) aux.push_back(grid[i][r] - '0');

            if(t < b){
                for(int i = r-1; i >= l; i--) aux.push_back(grid[b][i] - '0');
            }

            if(l < r){
                for(int i = b - 1; i > t; i--){
                    aux.push_back(grid[i][l] - '0');
                }
            }

            ans.push_back(aux);
            l++, r--, b--, t++;
            aux.clear();
        }

        int cnt = 0;
        for(int i = 0; i < ans.size(); i++){
            vector<int> final = {1, 5, 4, 3};
            vector<int> arr = ans[i];
            vector<int> c;
            for(int k = 0; k < arr.size(); k++){
                for(int j = 0; j < 4; j++){
                    c.push_back(arr[(k+j)%arr.size()]);
                }
                if(c == final) cnt++;
                c.clear();
            }
        }
        cout << cnt << endl;
    }
}