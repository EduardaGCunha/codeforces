#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string s(n, '0');

    cout << s << endl;
    for(int i = n-1; i >= 0; i--){
        s[i] = '1';
        cout << s << endl;
    }

    for(int i = n-1; i > 0; i--){
        s[i] = '0'; 
        cout << s << endl;
    }
}