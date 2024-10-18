#include <bits/stdc++.h>
using namespace std;

#define int long long


signed main() {
    int t;
    cin >> t;
    while(t--){
        int b, c, d; cin >> b >> c >> d;
        int a = 0;
        bool possible = true;
        for (int i = 0; i < 62; ++i) {
            int bb = (b >> i) & 1;
            int bc = (c >> i) & 1;
            int bd = (d >> i) & 1;

            if(bd){
                if((!bc && !bb) || (bb && !bc)){
                    a |= (1LL << i);
                }else if(!bb && bc){
                    possible = false;
                    break;
                }
            }else{
                if(bb && !bc){
                    possible = false;
                    break;
                }else if(bc && bb){
                    a |= (1LL << i);
                }
            }
        }

        if (possible && a <= (1LL << 61)) cout << a << endl;
        else cout << -1 << endl;
    }

}

