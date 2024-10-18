#include <bits/stdc++.h>
using namespace std;

const int MAXM = 5*1e3+1;
const int MAXN = 2*(1e6);
int pd[MAXM][MAXM];
int arr[MAXN];
int n, m;

int dp(int s, int iq, int idx){

}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            pd[i][j] = -1;
        }
    }
}