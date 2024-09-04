#include <bits/stdc++.h>
using namespace std;

void solve(){
    int arr[3];
    int sum = 0;
    for(int i = 0; i < 3; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    if(arr[0] == arr[1] && arr[1] == arr[2]){
        cout << "YES" << endl;
        return;
    }
    if((sum%3) != 0){
        cout << "NO" << endl;
        return;
    }
    sum /= 3;
    for(int i = 0; i < 3; i++){
        if(arr[i] < sum){
            cout << "NO" << endl;
            return;
        }
    } 
    cout << "YES" << endl;
    return;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}