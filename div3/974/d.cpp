#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, d, k; cin >> n >> d >> k;
        vector<int> pref(n+2, 0);
        for(int i = 0; i < k; i++){
            int a, b; cin >> a >> b;
            pref[max(1, a-d+1)]++;
            pref[b+1]--;
        }

        for(int i = 1; i <= n - d + 1; i++){
            pref[i] += pref[i-1];
            //cout << pref[i] << " ";
        }
        //out << endl;

        int mn = INT_MAX, mx = 0, b = 0, m = 0;
        for(int i = 1; i <= n-d+1; i++){
            if(pref[i] > mx) mx = pref[i], b = i;
            if(pref[i] < mn) mn = pref[i], m = i;
        }

        cout << b << " " << m << endl;
    }
}