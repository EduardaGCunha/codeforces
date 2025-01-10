#include <bits/stdc++.h>
using namespace std;


int low = INT_MAX;
int n, a;

bool check(int mid){
    int x = (mid*(2*a + mid - 1)/2);
    int y = (n-mid)*(2*a + (n-mid)-1)/2;

    cout << abs(x-y) << endl;
    if(abs(x-y) < low){
        low = abs(x-y);
        return true;
    }
    return false;
}

void solve(){
    cin >> n >> a;
    low = INT_MAX;
    int l = a, r = a+n-1;
    while(l < r){
        int mid = (l+r)/2;
        cout << mid << endl;
        if(check(mid)) l = mid+1;
        else r = mid;
    }
    cout << low << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}