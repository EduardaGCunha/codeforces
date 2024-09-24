#include <bits/stdc++.h>
using namespace std;

int res(int a, int b, int c, int i){
    if(i == 5) return a*b*c;
    return max({res(a+1, b, c, i+1), res(a, b+1, c, i+1), res(a, b, c+1, i+1)});
}

int main(){
    int t; cin >> t;
    while(t--){
        int a, b, c; cin >> a >> b >> c;
        cout << res(a, b, c, 0) << endl;
    }
}