#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        double a, b, c;
        cin >> a >> b >> c;
        int mid = (a+b)/2;
        int maxi = max(a, b);
        int res = ceil((maxi - mid)/c);
        cout << res << endl;
    }
}