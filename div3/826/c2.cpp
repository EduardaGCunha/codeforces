#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2*(1e3);
int arr[MAXN];
int n;

int solve(int sum, int x){
    int cur = 0;
    for(int j = x+1; j <= n; j++){
        if(sum == arr[j] - arr[x]){
            //cout << sum << " " << cur << endl;
            cur = max(cur, j - x);
            x = j;
        }else if(sum < arr[j] - arr[x]) return INT_MIN;
    }
    //cout << cur << endl;
    if(cur == 0) return INT_MIN;
    else return cur;
}


int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) arr[i] = 0;
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
            arr[i] = arr[i] + arr[i-1];
        }

        int res = INT_MAX, ans;
        for(int i = 1; i <= n; i++){
        
            ans = max(solve(arr[i], i), ans);
            cout << ans << endl;
            res = min(res, ans);
        }

        cout << res << endl;
    }
}