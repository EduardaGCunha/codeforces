#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int cnt = 0;
        int x = n/4;
        int y = (n - x*4)/2; 
        cout << x + y << endl;
    }
}