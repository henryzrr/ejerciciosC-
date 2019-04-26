#include<stdio.h>
#include<vector>
#include<ctime>

using namespace std;

typedef struct elem{
    int tam;
    int valor;
}elem;

vector<elem>ls;
int tamf,capacidad,nroElem;
clock_t ti,tf;

int getMax(int pos, int tam,int sumant,int max){
    int res;
    if(pos==tamf){
        res =  ((tam/ls[pos].tam)*ls[pos].valor)+sumant;
        return res>max?res:max;
    }
    int tamrestante,corte=0,i=0;

    while(corte<=tam){
        tamrestante = tam - corte;
        res = getMax(pos+1,tamrestante,(i*ls[pos].valor)+sumant,max);
        max = res>max?res:max;
        i++;
        corte = i*ls[pos].tam;
    }
    return max;
}
int main(){
    scanf("%i %i",&capacidad,&nroElem);
    ls.reserve(nroElem);
    tamf=nroElem-1;
    for(int i=0;i<nroElem;i++){
        scanf("%i %i",&ls[i].tam,&ls[i].valor);
    }
    ti = clock();
    int res = getMax(0,capacidad,0,0);
    tf = clock();
    printf("%i\n",res);
    printf("%f",(double)(tf-ti)/CLOCKS_PER_SEC);
    return 0;
}