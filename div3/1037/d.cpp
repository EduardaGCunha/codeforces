#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

struct casino{
    int a, b, c;
    bool operator<(const casino &y) { return a < y.a; }
};

void solve(){
	int n, k; cin >> n >> k;
    vector<casino> v;
    for(int i = 0; i < n; i++){
        int l, r, w; cin >> l >> r >> w;
        v.push_back({l, r, w});
    }

    // for(int i = 0; i < n; i++){
    //     cout << v[i].a << " " << v[i].b << " " << v[i].c << endl;
    // }

    sort(v.begin(), v.end());
    priority_queue<int> pq;
    int i = 0;
    while(true){
        //cout << k << endl;
        while(i < n && v[i].a <= k){
            pq.push(v[i].c);
            i++;
        }

        while(!pq.empty() && pq.top() <= k){
            //cout << pq.top().second << " " << pq.top().first << endl;
            pq.pop();
        }
        
        if(pq.empty()) break;
        //pegar sempre o maior 
        k = pq.top();
        pq.pop();
    }
    cout << k << endl; 
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}