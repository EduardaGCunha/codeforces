#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


/*
maybe store all the restrictions instead of the smallest values
and then check if all the restrictions work for everyone;
*/

const int MAXN = 5e3+7;
int arr[3][MAXN];
int n;

vector<vector<int>> res(2);

void restrictions(int t, int mn){
    for(int i = 0; i < n; i++){
        if(arr[t][i] == mn){
            for(int j = 0; j < n; j++){
                if(arr[t-1][j] < mn){
                    //a diferenca entre os indices da sequencia tem q ser essas
                    res[t-1].push_back(j - i);
                }
            }    
        }
    }
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[0][i];
        int mnc = INT_MAX, mnb = INT_MAX;
        for(int i = 0; i < n; i++){
            cin >> arr[1][i];
            mnb = min(mnb, arr[1][i]);
        }
        for(int i = 0; i < n; i++){
            cin >> arr[2][i];
            mnc = min(mnc, arr[2][i]);
        }

        restrictions(2, mnc);
        restrictions(1, mnb);

        cout << "restricoes do 0\n";
        for(auto restricao : res[0]){
            cout << restricao << endl;
        }
         cout << "restricoes do 1\n";
         for(auto restricao : res[1]){
            cout << restricao << endl;
        }

        // vector<int> ans1, ans2;
        // //de quantas maneiras eu consigo escolher o 1 valor tal que a restricao sempre se mantenha?
        for(auto idx : res[0]){
            int pos = 1;
            for(int i = 0; i < n; i++){
                if(arr[0][(i+idx)%n] > arr[1][i]){
                    pos = 0;
                    break;
                }
            }
            
        }
	} 
}