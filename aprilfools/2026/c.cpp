#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n ;//tam vet
    vector<long long> entrada(n);
    vector<string> saida(n);

    for(int i=0;i<n;i++){//le nmrs
        cin >> entrada[i];
    }

    for(int i=0;i<n;i++){//inic. impressao
        saida[i]="YES\n";
    }

    for (int i=0;i<n;i++){
        double raiz = (double)sqrt(entrada[i]);
        if (ceil(raiz)==floor(raiz) and raiz!=1){
            for(int j=2;j<raiz;j++){
                if((int)raiz%j==0){
                    saida[i]="NO\n";
                }
            }
        }else{
            saida[i]="NO\n";
        }
    }

    for(int i=0;i<n;i++){
        cout << saida[i];
    }

    return 0;
}