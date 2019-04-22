#include<stdio.h>
#include<ctime>
using namespace std;

int main(){
    int monto,i,j,corte1,saldo,max1,max2,corte2,saldo2;
    clock_t ti,tf;
    while(true){
        scanf("%i",&monto);
        ti = clock();
        corte1=i=0;
        max1 = monto;
        while(corte1<=monto){
            saldo = monto-corte1;
            corte2=j=0;
            max2=saldo;

            while(corte2<=saldo){
                saldo2 = saldo - corte2;
                saldo2 +=j;
                max2 = saldo2<max2?saldo2:max2;
                j++;
                corte2 = j*30;
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