#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"


//pode ter um problema com o cara do meio
signed main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        deque<int> dq(n);
        for(int i = 0; i < n; i++){
            cin >> dq[i];
        }

        int ans = 0;
        while(dq.size() > 1 && k){
            int low = min(dq.front(), dq.back());
            if(k >= 2*low){
                dq.front() -= low;
                dq.back() -= low;
                k -= 2*low;
            }else{
                dq.back() -= k/2;
                dq.front() -= k/2 + k%2;
                k = 0;
            }
            if(!dq.front()){
                dq.pop_front();
            }
            if(!dq.back()){
                dq.pop_back();
            }
        }
        ans = n - dq.size();
        cout << ans + (dq.size() && dq.front() <= k) << endl;
    }
}