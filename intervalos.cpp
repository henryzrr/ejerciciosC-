#include<stdio.h>
#include<stdlib.h>
#include<list>
using namespace std;
typedef struct intervalo{
    int a;
    int b;
}intervalo;
int main(){
    int cases,puntos,linf,lsup;
    scanf("%i",&cases);
    while(cases){
        scanf("%i %i %i",&puntos,&linf,&lsup);
        list<intervalo> ls; 
        for(int i=0;i<puntos;i++){
            intervalo aux;
            scanf("%i %i",&aux.a,&aux.b);
            if(aux.b>linf || aux.a<lsup) ls.push_front(aux);
        }
        int dist = linf;
        int res=0;
        int size = ls.size();
        while(!ls.empty()&&linf<lsup){
            for(auto x = ls.begin();x!=ls.end();x++){

                if((*x).b>dist && (*x).a<=linf){
                    dist = (*x).b;
                    ls.erase(x);
                    x--;
                }
    
            }
            if(size==ls.size()){
                res =0;
                break;
            }else size =ls.size();
            linf=dist;
            res++;
        }
        printf("%i %i %i\n",res,linf,ls.size());
    
        cases--;
    }
    return 0;
}
