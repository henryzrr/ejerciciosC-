#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
// dp[i][j] 表示i元最多用j個硬幣的方法數
long long dp[301][1001] = {0};

int main()
{
    // 建表
    dp[0][0] = 1;
    for (int i = 0; i <= 300; ++i)          // i元硬幣
        for (int j = 0; j + i <= 300; ++j)  // j+i元是由j元方法數而來
            for (int k = 1; k <= 1000; ++k) // 用了k個硬幣
                dp[j+i][k] += dp[j][k-1];   // 用了k個硬幣組成j+i元的方法數是由
                                            // 用了k-1個硬幣組成j元的方法數而來
    // Input & Output
    ios::sync_with_stdio(false);
    string line;
    int n[3];
    while (getline(cin, line)) {
        stringstream ss(line);
        int i = 0;
        while (ss >> n[i]) ++i;
        switch(i){
            case 1: printf("%lld\n", dp[n[0]][1000]); break;
            case 2: printf("%lld\n", dp[n[0]][n[1]]); break;
            case 3: // 因為當L1 == 0會越界 因此要多個if判斷
                if (n[1] == 0) printf("%lld\n", dp[n[0]][n[2]]);
                else printf("%lld\n", dp[n[0]][n[2]]-dp[n[0]][n[1]-1]);
                break;
        }
    }
}