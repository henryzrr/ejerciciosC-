#include<cstdio>
#include<ctime>
using namespace std;
int isSumOfConsecutive2(int n) {
    if(n<2) return 0;
    int res=n&1?1:0,j=3,aux2=(n/3)-(j/2),sum;
    
    while(aux2>0){
        sum =0;
    
        for(int i=1;i<=j;i++){
            sum+=aux2;
        
            aux2++;
            
        }
        if(sum==n) res++;
        j++;
        aux2 = (n/j)-(j/2);
        aux2 += j&1?0:1;
    }
    return res;
}
int sumaConcecutivos(int n){
    int suma;
    int res=0;
    for(int i=(n/2)+1;i>0;i--){
        suma=0;
        for(int j=i;j>0;j--){
            suma +=j;
            if(suma==n) res++;
            if(suma>n) break;
        }
    }
    return res;
}
int main(){
    double segundos;
    clock_t tiempo_inicio, tiempo_final;
    tiempo_inicio = clock();
    for(int i=1;i<=10000;i++){
        int b = sumaConcecutivos(i);
    }
    tiempo_final=clock();
    segundos = (double)( tiempo_final-tiempo_inicio ) / CLOCKS_PER_SEC;
    printf("%f\n",segundos);
    tiempo_inicio = clock();
    for(int i=1;i<=10000;i++){
        int a = isSumOfConsecutive2(i);
    }
    tiempo_final=clock();
    segundos = (double)(tiempo_final-tiempo_inicio ) / CLOCKS_PER_SEC;
    printf("%f\n",segundos);
    
    return 0;
}