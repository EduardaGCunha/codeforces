
#include <bits/stdc++.h>
using namespace std;
int main() {   
   int n;cin>>n;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < n; i++) {
        string str, t;
        getline(cin, str);
        char del = ' ';
        stringstream ss(str);
        while(getline(ss, t, del)){
            if (t[0] >= 'a' && t[0] <= 'z') {
                t[0] = t[0] - 32;
            }
            cout << t[0];
        }
        cout << endl;
    
    }
 
    return 0;
}