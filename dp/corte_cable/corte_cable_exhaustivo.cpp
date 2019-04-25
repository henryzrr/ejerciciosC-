#include<cstdio>
#include<vector>
using namespace std;

typedef struct barra{
    int precio;
    int corte;
}barra;
vector<barra>ls;
int tamf,lsPrecios,tamBarra;

int getMaximo(int tam,int pos,int sumant,int max){
    int i=0,corte=0,tamrestante,res;
    //printf("%i ",pos);
    //puts("asd");
    while(corte<=tam){
        //res =0;
        tamrestante = tam-corte;
        if(pos+1<tamf) res = getMaximo(tamrestante,pos+1,(i*ls[pos].precio)+sumant,0);
        else /*if(tamrestante%ls[pos+1].corte==0) */res=(tamrestante * ls[pos+1].precio)+sumant+(i*ls[pos].precio);
        //else res=0;
        //printf("r%i i%i p%i m%i corte%i tam%i\n",res,i,ls[pos].corte,max,corte,tamrestante);
        max = res>max?res:max;
        //printf("max%i pos%i sa%i i%i\n",max,pos,sumant,i);
        i++;
        corte = i*ls[pos].corte;
        
    }
    return max;
}

int main(){
    scanf("%i %i",&lsPrecios,&tamBarra);
    ls.reserve(lsPrecios);
    tamf=lsPrecios-1;
    for(int i=0;i<lsPrecios;i++){
        scanf("%i %i",&ls[i].corte,&ls[i].precio);
    }
    /*for(int i=0;i<lsPrecios;i++){
        printf("%i %i\n",ls[i].corte,ls[i].precio);
    }*/
    //puts("asd");
    int res = getMaximo(tamBarra,0,0,0);
    printf("%i\n",res);
    return 0;
}