#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


void solve(){
    int n; cin >> n;
    queue<int> d, t, r;
    for(int i = 1; i <= n; i++){
        if(!(i%2)) d.push(i);
        else if(!(i%3)) t.push(i);
        else r.push(i);
    }

    for(int i = 1; i <= n; i++){
        if((i%3)){
            if(!d.empty()){
                cout << d.front() << " ";
                d.pop();
            }
            else if(!t.empty()){
                cout << t.front() << " ";
                t.pop();
            }else{
                cout << r.front() << " ";
                r.pop();
            }
        }else{
            cout << r.front() << " ";
            r.pop();
        }
    }
    cout << endl;
}

signed main(){
	fastio;
    int t;
    //t = 1;
    cin >> t;
	while(t--){
		solve();
	}
}