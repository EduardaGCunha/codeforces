#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;
int arr[MAXN][2];

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a;
        char b;
        cin >> a >> b;
        int c = (b == 'M'? 0 : 1);
        if(!arr[a-1][c] && !c){
            cout << "Yes" << endl;
        }else cout << "No" << endl;
        arr[a-1][c]++;

    }
}