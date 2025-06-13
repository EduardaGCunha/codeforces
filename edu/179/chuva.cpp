#include <bits/stdc++.h>
using namespace std;

const int MAXN = 501;
char grid[MAXN][MAXN];
int n, m;


//pintar os aux daquela linha com o
void aux(int x, int y){
    //cout << x << " " << y << endl;
    for(int i = y; i < m; i++){
        if(grid[x][i] == '#') break;
        if(x+1 < n && grid[x+1][i] == '#'){
            grid[x][i] = 'o'; 
        }else if(x+1 < n && grid[x+1][i] == '.'){
            grid[x][i] = 'o'; 
            break;
        }
    }
    for(int i = y; i >= 0; i--){
        if(grid[x][i] == '#') break;
        if(x+1 < n && grid[x+1][i] == '#'){
            grid[x][i] = 'o'; 
        }else if(x+1 < n && grid[x+1][i] == '.'){
            grid[x][i] = 'o'; 
            break;
        }
    }
}

int main(){
    cin >> n >> m;
    int x = 0, y = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'o') x = i, y = j;
        }
    }

    
    aux(x, y);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '#') continue;
            if(i == n-1 && grid[i-1][j] == 'o'){
                grid[i][j] = 'o';
            }else if(grid[i-1][j] == 'o'){
                aux(i, j);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
}