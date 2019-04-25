#include<cstdio>

using namespace std;
typedef struct barra{
    int corte;
    int precio;
}barra;
int nroCortes,tamBarra;
int main(){
    scanf("%i %i",&nroCortes,&tamBarra);
    barra ls[nroCortes];
    int res [nroCortes][tamBarra+1];
    for(int i=0;i<nroCortes;i++){
        scanf("%i %i",&ls[i].corte,&ls[i].precio);
        res[i][0]=0;
    }
    for(int i=1;i<nroCortes;i++){
        for(int j=1;j<=tamBarra;j++){
            if(i==0){
                res[i][j]=ls[i].
            }else{

            }
        }
    }
    return 0;
}