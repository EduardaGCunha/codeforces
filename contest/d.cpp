#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

signed main(){
    fastio;
    int n, k; cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int l = 0, r = 0;
    int ans = 0;
    int sum = 0, qtd_distintos = 0, qtd = 0;
    map<int, int> mp;
    while(l < n && r < n){
        while(sum <= k && r < n){
            sum += arr[r];
            qtd++;
            //checando se esse cara nn estava ali ainda
            if(!mp[arr[r]]) qtd_distintos++;
            mp[arr[r]]++;
            //calculando a quantidade de quartas iguais
            ans = max(ans, qtd - qtd_distintos);
            r++;
        }
        while(sum > k && l < n){
            sum -= arr[l];
            l++;
            qtd--;
            mp[arr[l]]--;
            if(!mp[arr[l]]) qtd_distintos--;
        }
    }
    cout << ans << endl;
} 