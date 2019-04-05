#include<stdio.h>
#include<unordered_map>
#include<unordered_set>
#include<sstream>
#include<stdlib.h>
using namespace std;

main(){
    int cases,nroC;
    scanf("%i",&cases);
    unordered_map<int,unordered_set<int>> elem_conj;
    unordered_map<int,int>elem;
    unordered_map<int,unordered_set<int>> conj_elem;
    while(cases){
        scanf("%i",&nroC);
        char cad[100];
        fgets(cad,99,stdin);
        for(int i=1;i<=nroC;i++){
            fgets(cad,99,stdin);
            stringstream str(cad);
            string res;
            unordered_set<int> elementos;
            while(getline(str,res,' ')){
                int num =stoi(res);
                elem[num] +=1;
                elementos.insert(num);
                elem_conj[num].insert(i);
            
            }
            conj_elem[i]=elementos;
        }
        int res = 0;
        unordered_map<int,int>::iterator it = elem.find(1);
        while(it !=elem.end()){
            unordered_set<int> x =elem_conj[it->first];
            for(auto &y: x){
                conj_elem.erase(it->first);
                elem.erase(it);
            }
            res ++;
            it++;
        }
        printf("%i %i",conj_elem.size(),elem.size());
        cases--;
    }
    return 0;
}