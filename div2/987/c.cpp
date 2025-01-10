#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    if(n&1 & n >= 27){
        cout << "1 2 2 3 3 4 4 5 5 1 6 6 7 7 8 8 9 9 10 10 11 11 12 13 13 1 12 ";
        int a = 14;
        for(int i = 27; i < n; i+= 2){
            cout << a << " " << a << " ";
            a++;
        }
        cout << endl;
    }else if(!(n&1)){
        int a = 1;
        for(int i = 0; i < n; i+=2){
            cout << a << " " << a  << " ";
            a++;
        }
        cout << endl;
    }else cout << -1 << endl;

}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}