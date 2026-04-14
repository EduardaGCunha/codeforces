#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        string s;
        cin >> n >> s;

        int ones = 0;
        int first = -1, last = -1;

        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                ones++;
                if(first == -1) first = i;
                last = i;
            }
        }

        int mx = ones;
        if(ones >= 2)
            mx = last - first + 1;

        int mn = 0;

        for(int i = 0; i < n; ){
            if(s[i] == '1'){
                int j = i;
                while(j < n && s[j] == '1') j++;

                int len = j - i;
                mn += (len + 1) / 2;

                i = j;
            } else {
                i++;
            }
        }

        cout << mn << " " << mx << "\n";
    }
}