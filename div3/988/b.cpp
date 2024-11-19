#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        set<int> val;
        int g = k-2;
        pair<int, int> ans;
        int n = k-2;
        for(int i = 0; i < k; i++){
            int a; cin >> a;
            if(a != 0 && n % a == 0){
                int b = n/a;
                if(val.count(b)){
                    ans = {a, b};
                }
            }
            val.insert(a);
        }
        cout << ans.first << " " << ans.second << endl;
    }
}