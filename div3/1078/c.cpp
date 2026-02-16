#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
parece dp
dp[i][v] seria o min os primeiro i se v for o iesimo valor do cubo
p/ cada i = 0 ate 7
    se i != valor atual && i + valor atual != 7
        dp[i][v] = min(pegar o anterior com esse u + 1)
*/

const int MAXN = 3e5+7;

void solve(){
    int n; cin >> n;
    int arr[n];
    vector<vector<int>> dp(n, vector<int>(7, 1e18));
    for(int i = 0; i < n; i++) cin >> arr[i];


    for(int i = 1; i<= 6; i++){
        dp[0][i] = (arr[0] == i ? 0 : 1);
    }

    for(int i = 1; i < n; i++){
        //p cada valor de dado q eu posso transformar esse cara
        for(int j = 1; j <= 6; j++){
            int val = (arr[i] == j ? 0 : 1);
            for(int k = 1; k <= 6; k++){
                //se eu pegar o caso anterior?
                if(j != k && k + j != 7){
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + val); 
                }
            }
        }
    }

    int ans = 1e18;
    for(int i = 1; i <= 6; i++){
        ans = min(ans, dp[n-1][i]);
    }
    cout << ans << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}