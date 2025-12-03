#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
a moral eh q toda vez q a gente adicionar um novo valor q seja menor q o anterior
a gente vai aumentar todas as LDS em 1

por exemplo
1 2 3
6 1 5
as LDS ate o momento (sem considerar as de tam 1) tem tamanho max
[1, 3] = 2, pois 6-1, ou 6-5, mas o tamanho maximo em si nesse subarray eh 2
[1, 2] = 2, pois 6-1
[2, 3] = 1, pois 1-5 nn eh um subarray valido
ent o best ate esse momento eh 5
lembrando q best representa a soma das LDS dos subarrays

quando adicionarmos o 2, teremos
1 2 3 4
6 1 5 2
2 < 5, entao adicionaremos 4 na resposta, pq?
veja as LDS q tinhamos
6-1, 6-5, 6-1
agr temos
6-1-2, 6-5-2, 6-1-2
e tambem, do intervalo [2,5]
temos 
1-5-2, o tamanho da LDS desse subarray agr eh 2 por conta da 5-2
veja q no total adicionamos 4

quando adicionarmos o 4, teremos:
1 2 3 4 5
6 1 5 2 4
apenas adicionamos 1 nova LDS, q seria do intervalo [1, 5]
pois as de todos os outros intervalos se mantem o mesmo
*/

void solve(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int ans = 0, best = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] < arr[i-1]) best += i+1;
        else best++;
        ans += best;
    }
    ans += n;
    cout << ans << endl;
}

signed main(){
	//fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}