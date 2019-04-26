#include<stdio.h>
#include<vector>
#include<ctime>
using namespace std;

typedef struct elem{
    int tam;
    int valor;
}elem;

vector<elem>ls;
int capacidad,nroElem,aux;
clock_t ti,tf;

int main(){
    scanf("%i %i",&capacidad,&nroElem);
    ls.reserve(nroElem);
    int res[nroElem][capacidad+1];
    for(int i=0;i<nroElem;i++){
        scanf("%i %i",&ls[i].tam,&ls[i].valor);
        res[i][0]=0;
    }
    ti = clock();
    for(int i=0;i<nroElem;i++){
        for(int j=1;j<=capacidad;j++){
            if(i==0) res[i][j] = (j/ls[i].tam)*ls[i].valor;
            else if(j>=ls[i].tam){
                aux = ((j/ls[i].tam)*ls[i].valor)+res[i][j%ls[i].tam];
                res[i][j]=aux>res[i-1][j]?aux:res[i-1][j]; 
            }else res[i][j]= res[i-1][j];
        }
    }
    tf = clock();
    printf("%i\n",res[nroElem-1][capacidad]);
    printf("%f",(double)(tf-ti)/CLOCKS_PER_SEC);
    return 0;
}