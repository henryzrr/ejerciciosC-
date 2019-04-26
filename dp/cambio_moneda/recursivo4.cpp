#include<stdio.h>
#include<ctime>
#include<map>
#include<unordered_map>

using namespace std;
map<int,unordered_map<int,int>> um;
int ls[]={50,30,20,1};
int posf=3;
int fraccionarMonto(int monto, int pos){
    int i=0;
    int corte = 0;
    int saldo,resp,aux,menor = monto;
    while(corte<=monto){
       
        saldo = monto-corte;
        if(pos+1==posf) resp = saldo;
        else{
            aux=pos+1;
            //if(aux>=1&&aux<=posf-1){
               // auto it = um[aux];
                auto itmp = (um[aux]).find(saldo);
                if(itmp!=(um[aux]).end()){
                    resp = itmp->second;
                   // puts("encontrado");
                }else{
                    resp = fraccionarMonto(saldo,aux);
                    (um[aux])[saldo]=resp;
                }   
            //}
        }
        resp +=i;
        menor = resp<menor?resp:menor;
        i++;
        corte = i*ls[pos];
    }
    return menor;
}

int main(){
    clock_t ti,tf;
    int monto,res;
    scanf("%i",&monto);
    ti = clock();
    res = fraccionarMonto(monto,0);
    tf = clock();
    printf("%i\n",res);
    printf("%f\n",(double)(tf-ti)/CLOCKS_PER_SEC);
    return 0;
}