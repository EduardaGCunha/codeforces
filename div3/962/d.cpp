#include <bits/stdc++.h>
using namespace std;

int check(int a, int b, int c, int n, int x){
    if((a + b + c) > n) return 0;
    if((a*b + a*c + b*c) > x) return 0;
    return 1;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; i*j <= n; j++){
                int k = min(x - i - j, (n-(i*j))/(i+j));
                if(k >= 1) cnt+=k;
            }
        }

        cout << cnt << "\n";
    }
}