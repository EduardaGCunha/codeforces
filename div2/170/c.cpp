#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];

        sort(arr, arr+n);
        int l = 0, r = 0;
        //respostas e quantidade de cartas distintas
        int ans = 0, cnt = 1;
        while(l < n && r < n){
            while(r < n && cnt <= k){
                ans = max(ans, r - l + 1);
                r++;
                if(arr[r] == arr[r-1]) continue;
                else if(arr[r] == arr[r-1]+1) cnt++;
                else{
                    l = r;
                    cnt = 1;
                }
            }
            while(l < n && cnt > k){
                l++;
                if(arr[l] > arr[l-1]) cnt--;
            }

        }

        cout << ans << endl;
    }
}