#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int arr[n+1];
        arr[0] = 0;
        for(int i = 1; i <= n; i++){
            arr[i] = arr[i-1] + (s[i-1] == '1');
        }
    }
}