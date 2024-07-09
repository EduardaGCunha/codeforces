#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3;
const int MAXM = 203;
int place[MAXN];
pair<int, int> arr[MAXN];
int n;

bool check(int k){
    for(int i = 0; i < n; i++){
        if(arr[i].second <= 2*(k-arr[i].first)) return false;
    }
    return true;
}


int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> arr[i].first >> arr[i].second;
        }

        int l = 0, r = 1e3;
        while(l < r){
            int mid = (l+r)/2;
            if(check(mid)) l = mid+1;
            else r = mid;
        }

        cout << l-1 << endl;
    }
}