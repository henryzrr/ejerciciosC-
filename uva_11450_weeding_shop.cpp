#include<stdio.h>
#include<set>
#include<ctime>

using namespace std;

set<int>res;
set<int>sum;
set<int>::iterator it;
int cases,monto,tiposprenda,k,auxk;
clock_t ti,tf;
bool ini=true;
int main(){
    scanf("%i",&cases);
    while(cases--){
        res.insert(0);
        scanf("%i %i",&monto,&tiposprenda);
        ti = clock();
        while(tiposprenda--){
            scanf("%i",&k);
            while(k--){
                scanf("%i",&auxk);
                it = res.begin();
                while(it!=res.end()){
                    sum.insert(*it+auxk);
                    it++;
                }
            }
            res = sum;
            sum.clear();
        }
        int resp = 0;
        for(auto&x:res){
            resp = x>resp && x<=monto ? x:resp;
        }
        if(resp!=0)printf("%i\n",resp);
        else puts("no solution");
        tf = clock();
        printf("%f\n",(double)(tf-ti)/CLOCKS_PER_SEC);
        res.clear();       
    }
}