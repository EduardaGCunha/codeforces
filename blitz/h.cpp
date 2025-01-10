#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'A') cnt++;
        }
        if(cnt >= 3) cout << "A" << endl;
        else cout << "B" << endl;
    }
}