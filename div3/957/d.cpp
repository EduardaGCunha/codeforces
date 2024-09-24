#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2*(1e5);
int dp[MAXN];
int n;
string s;

int solve(int i, int a, int b){
    if(i >= n || s[i] == 'C') return 0;
    if(i == n-1 && a >= 0 && b >= 0) return 1;

    if(dp[i] != -1) return dp[i];

    if(s[i] == 'W') return dp[i] = max(dp[i], solve(i+1, a-1, b));
    else if(s[i] == 'L'){
        for(int j = 1; j <= b; j++){
            return dp[i] = max(dp[i], solve(i+j, a, b-j));
        }
    }

    return dp[i];
}


int main(){
    int t; cin >> t;
    while(t--){
        int m, k; cin >> n >> m >> k;
        cin >> s;
        for(int i = 0; i < n; i++) dp[i] = -1;
        if(s[0] == 'C' || s[0] == 'L'){
            for(int i = 1; i <= m; i++) solve(i, k, m-i);
        }
        else solve(0, m, k);
        if(dp[n-1] == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}