#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    while(t--){
       int n; cin >> n;
       string s; cin >> s;
       int a = sqrt(n);
        if(sqrt(n) != a){
            cout << "NO" << endl;
            continue;
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) cnt += (s[i] - '0');
        if(cnt == 4 * (a-1)) cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }

}