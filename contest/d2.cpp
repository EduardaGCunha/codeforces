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
    int sum = arr[0], curr = 0, qtd = 0;
    map<int, int> mp;
    while(l < n && r < n){
        while(sum <= k && r < n){
            //somo primeiro e dps checo
            mp[arr[r]]++;
            curr += (mp[arr[r]]%2 == 0);
            //calculando a quantidade de quartas iguais
            ans = max(ans, curr);
            r++;
            sum += arr[r];
        }while(sum > k && l < n){
            sum -= arr[l];
            l++;
            qtd--;
            mp[arr[l]]--;
            curr -= (mp[arr[l]]&1);
        }
    }
    cout << ans << endl;
} 