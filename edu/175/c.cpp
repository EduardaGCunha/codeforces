#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

const int MAXN = 3*(1e5)+7;
int n, k;
string s;
int arr[MAXN];

bool check(int mid){
    vector<int> R;
    vector<int> b;
    for (int i = 0; i < n; i++){
        if (s[i] == 'R' && arr[i] > mid) R.push_back(i);
        else if (s[i] == 'B' && arr[i] > mid) b.push_back(i);
    }
    
    sort(R.begin(), R.end());
    sort(b.begin(), b.end());
    
    vector<pair<int,int>>  intervalos;
    int prev = -1;
    for (int pos : R){
        //cout << pos << " " << prev << endl;
        if (prev + 1 <= pos - 1)
        intervalos.push_back({prev + 1, pos - 1});
        prev = pos;
    }
    if(prev + 1 <= n - 1) intervalos.push_back({prev + 1, n - 1});
    int cnt = 0;
    for (auto &i : intervalos) {
        int l = i.first, r = i.second;
        //cout << l << " " << r << endl;
        if(l > r) continue;
        auto it = lower_bound(b.begin(), b.end(), l);
        if(it != b.end() && *it <= r) cnt++;
    }
    return cnt <= k;
}

signed main(){
    int t; cin >> t; 
    while(t--){
        cin >> n >> k;
        cin >> s;
        for(int i = 0; i <= n; i++){
            arr[i] = 0;
        }
        int mx = 0;
        for (int i = 0; i < n; i++){
            cin >> arr[i];
            mx = max(mx, arr[i]);
        }
        
        int l = 0, r = mx, ans = mx;
        
        while(l <= r){
            int mid = (l+r)/2;
            //cout << mid << " " << l << " " << r << endl;
            
            if(check(mid)){
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        cout << ans << endl;
    }
    
}
