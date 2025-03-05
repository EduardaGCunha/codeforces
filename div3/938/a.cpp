#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, a, b; cin >> n >> a >> b;
        int ans = 0;
        while(n > 0){
            if(n%2 == 0){
                n-=2; 
                if(a+a > b){
                    ans += b;
                }else{
                    ans += a+a;
                }
            }else{
                n--;
                ans += a;
            }
        }
        cout << ans << endl;
    }
}