#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main(){
	fastio;
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        arr[i] = x;
    }

    for(int i = 0; i < n; i++){
        if(arr[i] == 1){
            cout << "NO\n";
            continue;
        }
        int raiz = sqrt(arr[i]);
        //checar se a raiz nao for exata
        if(raiz*raiz != arr[i]){
            cout << "NO\n";
            continue;
        }
        //checo se essa raiz eh prima square root
        int x = sqrt(raiz);
        int achou = 0;
        for(int j = 2; j <= x; j++){
            if((raiz%j) == 0){
                achou = 1;
            }
        }

        if(achou) cout << "NO\n";
        else cout << "YES\n";
    }   

}