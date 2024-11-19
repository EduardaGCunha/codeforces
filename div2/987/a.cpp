#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int i = 0, j = n-1;
    int cnt =0;
    while(i < j){
        if(arr[i] > arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j--;
            cnt++;
        }
        i++;
    }
    cout << cnt << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}