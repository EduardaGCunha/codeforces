#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(!(n&1)){
            cout << -1 << endl;
            continue;
        }
        int arr[n];
        for(int i = 0, j = 1; i < n; i+= 2, j++){
            arr[i] = j;
        }
        for(int i = n-2, j = (n+1)/2; i > 0; i -= 2, j++){
            arr[i] = j;
        }

        for(int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }
}