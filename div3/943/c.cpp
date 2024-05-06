#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int m = 10000;
        cout << m << " ";
        for(int i = 2; i <= n; i++){
            int x; cin >> x;
            m += x;
            cout << m << " ";
        }
        cout << "\n";
    }
}