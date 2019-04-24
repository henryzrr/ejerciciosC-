#include<cstdio>
#include<vector>
#include<ctime>

using namespace std;

clock_t ti,tf;
vector<vector<int>> ls;
int monto,tipoprenda,k,auxk;
int tamanhols;

int getMaximo(int pos,int max,int monto){
    int tam = (ls[pos]).size();
    int saldo,resp;
    //printf("%i\n",tam);
    for(int i=0;i<tam;i++){
        saldo = monto-ls[pos][i];
        if(pos!=tamanhols)resp = getMaximo(pos+1,max,saldo); 
        else resp = saldo;
        resp = resp>=0&&resp<max?resp:max;
        max=resp;
    }
    return resp;
}
int main(){
    scanf("%i %i",&monto,&tipoprenda);
    ls.reserve(tipoprenda);
    tamanhols = tipoprenda-1;
    for(int i=0;i<tipoprenda;i++){
        scanf("%i",&k);
        vector<int> aux(k);
        for(int j=0;j<k;j++){
            scanf("%i",&aux[j]);
        }
        ls[i]=aux;
        
    }
    
    ti = clock();
    int res = getMaximo(0,monto,monto);
    tf = clock();
    //puts("");
    printf("%i\n",monto-res);
    puts("tiempo de ejecucion:");
    printf("%f\n",(double)(tf-ti)/CLOCKS_PER_SEC);
    return 0;
}