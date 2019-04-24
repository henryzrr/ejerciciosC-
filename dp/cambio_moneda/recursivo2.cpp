#include<stdio.h>
#include<ctime>
#include<unordered_map>

using namespace std;
int ls[]={50,30,20,1};
int posf=3;
unordered_map<int,int>ls30;
unordered_map<int,int>ls10;
unordered_map<int,int>::iterator i30;
unordered_map<int,int>::iterator i10;
int fraccionarMonto(int monto, int pos){
    int i=0;
    int corte = 0;
    int saldo,resp,aux,menor = monto;
    while(corte<=monto){
       
        saldo = monto-corte;
        if(pos+1==posf) resp = saldo;
        else{
            aux=pos+1;
            if(ls[aux]==30){
                i30 = ls30.find(saldo);
                if(i30!=ls30.end()) resp = i30->second;
                else{
                    resp = fraccionarMonto(saldo,aux);
                    ls30[saldo]=resp;
                }
            } 
            else if(ls[aux]==20){
                i10 = ls10.find(saldo);
                if(i10!=ls10.end()) resp = i10->second;
                else{
                    resp = fraccionarMonto(saldo,aux);
                    ls10[saldo]=resp;
                }
            } 
            
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
    while(true){
        scanf("%i",&monto);
        ti = clock();
        res = fraccionarMonto(monto,0);
        tf = clock();
        printf("%i\n",res);
        printf("%f\n",(double)(tf-ti)/CLOCKS_PER_SEC);
    }
    
    return 0;
}