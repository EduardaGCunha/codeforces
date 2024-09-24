#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];

        //qualquer coisa vou de 2 em 2
        int mx = 0, mn = INT_MAX;
        for(int i = 0; i <= n-1; i++){
            if(arr[i] > arr[i+1]){
                int x = arr[i] - arr[i+1];
                x /= 2;
                arr[i] -= x;
                arr[i+1] += x;
            }
            mx = max(mx, arr[i]);
            mn = min(mn, arr[i]);
        }

        for(int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;

        cout << mx - mn << endl;
    }
}