#include<stdio.h>
#include<ctime>
#include<unordered_map>
using namespace std;
unordered_map<int,int>mp30;
unordered_map<int,int>::iterator it30;
unordered_map<int,int>mp20;
unordered_map<int,int>::iterator it20;

int main(){
    int monto,i,j,corte1,saldo,max1,max2,corte2,saldo2,max3,corte3,saldo3,k;
    clock_t ti,tf;
    //while(true){
        scanf("%i",&monto);
        ti = clock();
        corte1=i=0;
        max1 = monto;
        while(corte1<=monto){
            saldo = monto-corte1;
            max2=saldo;
            it30=mp30.find(saldo);
            if(it30!=mp30.end()){
                max2 = it30->second;
            }else{
                corte2=j=0;
                while(corte2<=saldo){
                    saldo2 = saldo - corte2;
                    max3 = saldo2;
                    it20 = mp20.find(saldo2);
                    if(it20!=mp20.end()) max3 = it20->second;
                    else{
                        corte3=k=0;
                        while(corte3<=saldo2){
                            saldo3 =saldo2-corte3;
                            saldo3 +=k;
                            max3 = saldo3<max3?saldo3:max3;
                            k++;
                            corte3 = k*20;
                        }
                        mp20[saldo2]=max3;
                    }
                    max3 +=j;
                    max2 = max3<max2?max3:max2;
                    j++;
                    corte2 = j*30;
                }
                mp30[saldo]=max2;
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

    //}
    return 0;
}