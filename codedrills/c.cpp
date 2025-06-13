#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];

        int ans = 0, l = 0;
        deque<int> dq;
        map<int, int> freq;
        for(int r = 0; r < n; r++){
            freq[arr[r]]++;
            while(!dq.empty() && arr[dq.back()] <= arr[r]){
                dq.pop_back();
            }

            dq.push_back(r);
            while(1){
                while(!dq.empty() && dq.front() < l){
                    dq.pop_front();
                }
                if(dq.empty()) break;
                int m = arr[dq.front()];
                if(freq[m] > k){
                    freq[arr[l]]--;
                    l++;
                }else break;
            }
            ans = max(ans, r-l+1);
        }
        cout << ans << endl;
    }
}