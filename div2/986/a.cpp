#include <bits/stdc++.h>
using namespace std;

int d1[] = {0, 1, 0, -1};
int d2[] = {1, 0, -1, 0};

void solve(){
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    pair<int, int> cur;
    cur = {0, 0};
    int pos = 0, j = 0;
    for(int i = 0; i < 10000; i++){
        if(cur.first == a && cur.second == b){
            cout << "YES" << endl;
            return;
        }
        if(s[pos] == 'N') cur.second++;
        else if(s[pos] == 'E') cur.first++;
        else if(s[pos] == 'S') cur.second--;
        else cur.first--;
        pos = (pos+1)%n;
    }
    cout << "NO" << endl;
}


int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}