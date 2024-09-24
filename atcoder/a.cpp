#include <bits/stdc++.h>
using namespace std;


int main(){
    char ab, ac, bc; cin >> ab >> bc >> ac;
    if(ab == '<'){
        //a eh o mais novo
        if(ac == '<'){
            if(bc == '>') cout << "C" << endl;
            else cout << "B" << endl;
        }else{
            if(bc == '>') cout << "C" << endl;
            else cout << "B" << endl;
        }
    }else{
        if(ac == '<'){
            if(bc == '>') cout << "A" << endl;
            else cout << "B" << endl;
        }else{
            if(bc == '>') cout << "C" << endl;
            else cout << "B" << endl;
        }
    }
}