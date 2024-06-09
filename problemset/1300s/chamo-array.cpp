#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n+1];
        for(int i = 0; i < n; i++) cin >> arr[i];
        sort (arr, arr+n);
        if(n == 2){
            cout << arr[0] << endl;
        }else{
            for(int i = 0; i < n - 2; i++){
                
            }
        }
    }
}