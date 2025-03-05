#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        int max_a = *max_element(a.begin(), a.end());
        int low = 0, high = max_a, answer = max_a;
        
        while(low <= high){
            int mid = (low + high) / 2;
            vector<int> forbidden_r;
            vector<int> mandatory_b;
            
            // Classify indices based on conditions
            for (int i = 0; i < n; i++){
                if (s[i] == 'R' && a[i] > mid)
                    forbidden_r.push_back(i);
                else if (s[i] == 'B' && a[i] > mid)
                    mandatory_b.push_back(i);
            }
            
            // Sort the indices for further processing
            sort(forbidden_r.begin(), forbidden_r.end());
            sort(mandatory_b.begin(), mandatory_b.end());
            
            // Build intervals from non-forbidden positions
            vector<pair<int,int>> intervals;
            int prev = -1;
            for (int pos : forbidden_r){
                if (prev + 1 <= pos - 1)
                    intervals.push_back({prev + 1, pos - 1});
                prev = pos;
            }
            if(prev + 1 <= n - 1)
                intervals.push_back({prev + 1, n - 1});
            
            // Count intervals that contain at least one mandatory B index
            int count = 0;
            for (auto &interval : intervals) {
                int l = interval.first, r = interval.second;
                if(l > r) continue;
                auto it = lower_bound(mandatory_b.begin(), mandatory_b.end(), l);
                if(it != mandatory_b.end() && *it <= r)
                    count++;
            }
            
            // Binary search adjustment based on the count condition
            if(count <= k){
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        cout << answer << "\n";
    }
    
    return 0;
}
