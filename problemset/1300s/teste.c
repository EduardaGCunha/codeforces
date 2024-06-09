#include <stdio.h>
#include <string.h>
#include <ctype.h>

void lermat(char mat[][100]){
    
    int i=0;
    
    while(scanf("%[^\n]%*c", mat[i]) && strcmp(mat[i], "fim") != 0){
        i++;
    }

    for(int j = 0; j < i; j++){
        printf("%s\n", mat[j]);
    }
        
}
    


int main()
{
    
    char mat[100][100];
    int i;
    
    lermat(mat);
        
 
    return 0;
}
