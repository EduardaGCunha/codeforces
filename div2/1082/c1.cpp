#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    stack<int> st;
    for(int i = n-1; i >= 0; i--){
        if(st.empty()){
            st.push(arr[i]);
            continue;
        }
        //cout << arr[i] << " " << st.top()+1 << endl;
        while(!st.empty() && arr[i]+1 == st.top()) st.pop();
        st.push(arr[i]);
    }

    cout << st.size() << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}