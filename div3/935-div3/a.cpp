#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int a, b, c; cin >> a >> b >> c;
        int d = (3 - b%3)%3;
        if(b > 0 && d > c){
            cout << -1 << endl;
            continue;
        }
        cout << a + (b+d)/3 + abs(c - d + 2)/3 << endl;
    }
}