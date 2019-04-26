#include<cstdio>
#include<vector>
#include<ctime>
using namespace std;

typedef struct barra{
    int precio;
    int corte;
}barra;
vector<barra>ls;
int tamf,lsPrecios,tamBarra;
clock_t ti,tf;
int getMaximo(int tam,int pos,int sumant,int max){
    int i=0,corte=0,tamrestante,res;
 
    while(corte<=tam){
   
        tamrestante = tam-corte;
        if(pos+1<tamf) res = getMaximo(tamrestante,pos+1,(i*ls[pos].precio)+sumant,0);
        else /*if(tamrestante%ls[pos+1].corte==0) */res=(tamrestante * ls[pos+1].precio)+sumant+(i*ls[pos].precio);
        //else res=0;
        
        max = res>max?res:max;

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
    ti = clock();
    int res = getMaximo(tamBarra,0,0,0);
    tf = clock();
    printf("%i\n",res);
    printf("%f\n",(double)(tf-ti)/CLOCKS_PER_SEC);
    return 0;
}