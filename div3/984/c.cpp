#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

string s;
bool check(int i){
    if(i >= 0 && i + 3 < s.size()){
        return s[i] == '1' && s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0';
    }
    else return false;
}
int main(){
    fastio;
    int t; cin >> t;
    while(t--){
        int q;
        cin >> s >> q;
        set<int> p;
        for(int i = 0; i< s.size()-3; i++){
            if(check(i)) p.insert(i);
        }

        while(q--){
            int a, b; 
            cin >> a >> b;
            a--;
            if(s[a] - '0' != b){
                for(int i = max(0, a-3); i <= min((int)s.size() - 4, a + 3); i++){
                    if(check(i)) p.erase(i);
                }

                s[a] = '0' + b;
                for (int i = max(0, a - 3); i <= min((int)s.size() - 4, a + 3); i++) {
                    if (check(i)) p.insert(i);
                }
            }

            if(!p.empty()) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}