#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> arr(n+1);
        arr[0]= 0;
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }

        sort(arr.rbegin(), arr.rend());

        for(int i = 1; i <= n; i++){
            arr[i] += arr[i-1];
        }
        int i = 0;
        for(i = 0; i < n; i++){
            if(arr[i] > k) break;
        }
        cout << abs(k - arr[i-1]) << endl;

    }
}