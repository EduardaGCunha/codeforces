#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string a, b; cin >> a >> b;
        char res;
        if(a.back() == b.back()){
            if(a.size() == b.size()){
                res = '=';
            }else if(a.back() == 'L'){
                 (a.size() > b.size()) ? res = '>' : res = '<';
            }else (a.size() > b.size()) ? res = '<' : res = '>';
        }else{
            if(a.back() == 'L') res = '>';
            if(a.back() == 'S') res = '<';
            if(a.back() == 'M'){
                b.back() == 'S'? res = '>' : res = '<';
            }
        }
        cout << res << endl;
    }
}