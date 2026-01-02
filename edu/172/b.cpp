#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


int solve(int a, int b){
    int x = a, y = b, tog = 0, ans = 0;
    for(int i = 0; i <= 20; i++){
        int amnt = (1<<i);
        if(tog) x -= amnt;
        else y -= amnt;
        //cout << amnt << " " << x << " " << y << endl;
        if(x < 0 || y < 0){
            ans = max(ans, i-1);
            break;
        }
        tog = !tog;
    }
    return ans;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
        int a, b; cin >> a >> b;
		int ans = max(solve(a, b), solve(b, a));
        cout << ans+1 << endl;
	}
}