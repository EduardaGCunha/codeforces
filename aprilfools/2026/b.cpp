#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    long long n,i,j,nPrimo;
    double raiz;
    cin >> n;
    vector<long long> p(n);
    vector<string> impressao(n);

    if(n>pow(10,5)){
        return 0;
    }

    for(i=0 ; i<n ; i++){
        impressao[i]= "YES";
    }

    for(i = 0; i<n; i++) {//recebe dados
        cin >> p[i];
        if (p[i]>pow(10,12)){
            return 0;
        }
    }

    for (i=0; i<n; i++){
        raiz = sqrt(p[i]);
        if ((pow(ceil(raiz),2) == pow(floor(raiz),2)) and p[i]!=1){//confere se é quadrado perfeito
            //nPrimo = raiz;
            nPrimo = sqrt(raiz);
            for (j=2; j < nPrimo; j++){//confere se a raiz é prima
                if((int)raiz%j==0){
                    impressao[i] = "NO";
                    // break;
                }
                //cout << j << endl;
                // nPrimo/=j;
            }
        } else {
            impressao[i] = "NO";
        }
    }

    for (i = 0; i<n; i++){
        cout << impressao[i] << "\n";
    }


    return 0;

}
