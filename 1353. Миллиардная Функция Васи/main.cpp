/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> dp(10, vector<int>(82, 0));
    // dp[length of string][sum of string] = count of numbers
    
    int s=0; cin>>s;
    for (int j=0; j<10; ++j) {
        dp[1][j]=1;
    }
    
    for (int i=2; i<10; ++i) {
        for (int j=0; j<=9*i; ++j) {
            for (int k=0; k<10; ++k) {
                if (j-k < 0) break;
                dp[i][j] += dp[i-1][j-k];
            }
        }
    }
    
    if (s == 1) {
        cout << dp[9][s]+1 << '\n';
    } else {
        cout << dp[9][s] << '\n';
    }
    
    return 0;
}
