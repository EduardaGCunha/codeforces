#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

int n; 
int check(int l, int r){
    int sp = 0, sa = 0;
    cout << "1 " << l << " " << r << endl;
    cin >> sp;
    cout << "2 " << l << " " << r << endl;
    cin >> sa;
    return abs(sp - sa);
}


/*
so preciso achar o cara mais a direita pq dai eu descubro o l baseado no tamanho do intervalo
*/

void solve(){
    cin >> n;
    int sp = 0, sa = 0;
    cout << "1 1 " << n << endl;
    cin >> sp;
    cout << "2 1 " << n << endl;
    cin >> sa;
    int l = 1, r = n, ans = 0;
    int tot = abs(sp - sa);
    while(l <= r){
        int mid = l + (r-l)/2;
        //cout << mid << endl;
        //int val = check(1, mid);
        //cout << val << endl;
        if(check(1, mid) == tot){
            ans = mid;
            r = mid-1;
        }else{
            //cout << "entrei no l\n";
            l = mid + 1;
        }
    } 

    //cout << r-diff+1 << endl;
    cout << "! " << ans - tot + 1 << " " << ans << endl;
}

signed main(){
	//fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}