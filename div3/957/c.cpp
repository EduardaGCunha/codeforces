#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        int val = n;
        int arr[n];
        for(int i = 0, j = 1; i < n; i++){
            if(val <= m){
                arr[i] = j;
                j++;
            } 
            else arr[i] = val;
            val--;
        }

        for(int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }
}