#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n+1];
        for(int i = 0; i < n; i++) cin >> arr[i];
        int inv = 0;
        for(int i = 0; i < n-1; i++){
            if(arr[i] > arr[i+1]) inv++;
        }
        if(arr[n-1] > arr[0]) inv++;
        cout << (inv <= 1 ? "YES" : "NO") << endl;
        
    }
}