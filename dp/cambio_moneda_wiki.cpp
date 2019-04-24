#include<cstdio>
#include<vector>
#include<ctime>
using namespace std;

int main(){
    clock_t ti,tf;
    int monedas[]={1,20,30,50};
    int monto,aux;

    scanf("%i",&monto);
    ti = clock();
    int tamM = 4;
    vector<vector<int>> arr;
    arr.reserve(tamM);
    for(int i=0;i<tamM;i++){
        vector<int> v;
        v.assign(monto+1,0);
        arr.push_back(v);
    }
    for(int i=0;i<tamM;i++){
        for(int j=1;j<=monto;j++){
           if(i!=0){
               if(monedas[i]<=j){
                    aux = (j/monedas[i])+arr[i][j%monedas[i]];
                    arr[i][j] = aux<arr[i-1][j]?aux:arr[i-1][j];
               }else arr[i][j] = arr[i-1][j];
               
           }else arr[i][j]=j;
            
        }
    }
    tf = clock();
    printf("%i\n",arr[tamM-1][monto]);
    puts("tiempo de ejecucion");
    printf("%f",(double)(tf-ti)/CLOCKS_PER_SEC);
}