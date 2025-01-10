#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        string arr[n];

        int cnt = 0, cursize = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            cursize += arr[i].size();
            if(cursize <= m){
                cnt++;
            }
        }
        cout << cnt << endl;

    }
}