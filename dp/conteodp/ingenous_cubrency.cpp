// UVa 11137 - Ingenuous Cubrency

#include <iostream>
#include <string.h>
#include<cstdio>
using namespace std;

#define datatype unsigned long long int

int main() {

	int cube[22];
	/*for (int j = 1; j <= 21; j++)
		cube[j] = j * j * j;
*/  cube[0]=0;
    cube[1]=1;
    cube[2]=2;
    cube[3]=3;
    cube[4]=4;
	datatype T[10000];
	memset(T, 0, sizeof(T));
	T[0] = 1;
    
	for (int j = 1; j <= 4; j++){
		for (int i = cube[j]; i < 11; i++){
			T[i] += T[i - cube[j]];
            printf("%i ",T[i]);
        }
        puts("");
    }
    puts("");
	int n;
	while (cin >> n) {
		cout << T[n] << endl;
    }
	return 0;
}
