#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
toda vez q um valor a for maior q x, ent eu sei q qualquer subarray q eu pegar
dali pra tras o maior valor vai ser a, ent eu posso so remove ele do arr
do contrario quero saber quantos subarrays tem q sao daquele tamanho 
eh garantido q o maximo naquele subarray vai ser no maximo x 
ent a resposta vai ser ser a qtd de somas q o valor maximo eh x - 
qtd somas q o valor maximo eh x-1
*/

int res(vector<int> arr, int n, int s, int x){
    map<int, int> pref;
    int ans = 0, sum = 0;
    pref[0]++;
    for(int i = 0; i < n; i++) {
        if(arr[i] > x){
            pref.clear(); 
            pref[0]++;
            sum = 0;
        }else{
            sum += arr[i];
            ans += pref[sum - s];
            pref[sum]++;
        }
    }
    return ans;
}

void solve(){
    int n, s, x; cin >> n >> s >> x;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
   
    cout << res(arr, n, s, x) - res(arr, n, s, x-1) << endl;
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
}
