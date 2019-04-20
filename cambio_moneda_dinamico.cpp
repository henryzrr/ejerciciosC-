#include<cstdio>
#include<ctime>
#include<unordered_map>

using namespace std;
unordered_map<int,int> ls;
clock_t ti,tf;
int monto,corte1,i,j,corte2,intaux;
unordered_map<int,int>::iterator aux;
int main(){
    while(true){
        scanf("%i",&monto);
        ti = clock();
        corte1=i=0;
        while(corte1<=monto){
            saldo = monto-corte1;
            corte2=j=0;
            while(corte2<=saldo){
                saldo2 = saldo - corte2;
                saldo2 +=j;
                aux = ls.find(saldo2);
                if(aux!=ls.end()){
                    if(saldo2<(*aux).second))ls[saldo]=saldo2;
                }else{
                    ls[saldo]=saldo2;
                }
                j++;
                corte2 = j*30;
            }
            aux = ls.find(saldo);
            if(aux!=ls.end()){
                if(saldo2<(*aux).second))ls[saldo]=saldo2;
            }else{
                ls[saldo]=saldo2;
            }
            max2 +=i;
            max1 = max2<max1?max2:max1;
            i++;
            corte1 = 50*i;
        }
        printf("%i\n",max1);
        tf = clock();
        puts("tiempo ejecucion:");
        printf("%f ms\n",(double)(tf-ti)/CLOCKS_PER_SEC);
    }
    return 0;
}