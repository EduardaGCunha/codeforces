#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'



void solve(){
	int n; cin >> n;
    deque<int> d;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        d.push_back(x);
    }

    //1 2 3 4 5 6 7 
    int tog = 0;
    string s ="";
    while(!d.empty()){
        if(tog){
            if(d.front() > d.back()){
                s += "L";
                //cout << d.front() << " ";
                d.pop_front();
            }else{
                s += "R";
                //cout << d.back() << " ";
                d.pop_back();
            }
        }else{
            if(d.front() > d.back()){
                s += "R";
                //cout << d.back() << " ";
                d.pop_back();
            }else{
                s += "L";
                //cout << d.front() << " ";
                d.pop_front();
            }
        }
        tog = !tog;
    }
    cout << s << endl;
    
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}