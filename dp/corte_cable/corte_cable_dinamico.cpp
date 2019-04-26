#include<cstdio>
#include<ctime>
using namespace std;

typedef struct barra{
    int corte;
    int precio;
}barra;

int nroCortes,tamBarra,aux;
clock_t ti,tf;
int main(){
    scanf("%i %i",&nroCortes,&tamBarra);
    barra ls[nroCortes];
    int res [nroCortes][tamBarra+1];
    for(int i=0;i<nroCortes;i++){
        res[i][0]=0;
        scanf("%i %i",&ls[i].corte,&ls[i].precio);
       
    }
    ti = clock();
    for(int i=0;i<nroCortes;i++){
        for(int j=1;j<=tamBarra;j++){
            
            if(i==0){
                res[i][j]= (j/ls[i].corte)*ls[i].precio;
            }else if(j>=ls[i].corte){
                aux = ((j/ls[i].corte)*ls[i].precio)+(res[i][j%ls[i].corte]);
                res[i][j]=aux>res[i-1][j]?aux:res[i-1][j];
            }else{
                res[i][j]=res[i-1][j];
            }
            
        }
    }
    tf = clock();
    printf("%i\n",res[nroCortes-1][tamBarra]);
    printf("%f\n",(double)(tf-ti)/CLOCKS_PER_SEC);
    return 0;
}