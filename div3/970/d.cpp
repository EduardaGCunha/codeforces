#include <bits/stdc++.h>
using namespace std;

string s;
const int MAXN = 2*(1e5);
int arr[MAXN], visited[MAXN], res[MAXN];

int dfs(int v, int cnt){
    //cout << v << " " << cnt << endl;
    if(visited[v]){
        return cnt;
    }
    visited[v] = 1;
    return res[v] = dfs(arr[v], (s[v] == '0') + cnt);
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            arr[i] = 0;
            visited[i] = 0;
            res[i] = 0;
        }
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            a--;
            arr[i] = a;
        }
        cin >> s;

        for(int i = 0; i < n; i++){
            if(!visited[i]) dfs(i, 0);
            cout << res[i] << " ";
        }
        cout << endl;
    }
}