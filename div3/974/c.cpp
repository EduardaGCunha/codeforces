#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        double sum = 0;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            sum += arr[i];
        }

        if(n == 1 || n == 2){
            cout << -1 << endl;
            continue;
        }
        sort(arr, arr+n);
        int l = 0, r = 1e16;
        while(l < r){
            int mid = (l+r)/2;
            double res = (sum+mid)/(n*2); 
            int x = lower_bound(arr, arr+n, res)-arr;
            //cout << res << " " << x << endl;
            if(x > n/2) r = mid;
            else l = mid+1;
        }

        cout << l << endl;
    }
}