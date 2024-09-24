#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

int main(){
    fastio;
    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q;
        vector<vector<int>> pre1(n + 1, vector<int>(26, 0));
        vector<vector<int>> pre2(n + 1, vector<int>(26, 0));

        for (int i = 1; i <= n; i++){
            char c;
            cin >> c;
            pre1[i][c - 'a']++;

            for (int j = 0; j < 26; j++)
                pre1[i][j] += pre1[i - 1][j];
        }
        for (int i = 1; i <= n; i++){
            char c;
            cin >> c;
           pre2[i][c - 'a']++;

            for (int j = 0; j < 26; j++)
               pre2[i][j] +=pre2[i - 1][j];
        }
        while(q--){
            int x, y; cin >> x >> y;
            int dif = 0;
            for(int c = 0; c < 26; c++){
                int v1 = pre1[y][c] - pre1[x-1][c];
                int v2 = pre2[y][c] - pre2[x-1][c];

                dif += abs(v1 - v2);
            }
            cout << dif/2 << endl;
        
        }
    }
}