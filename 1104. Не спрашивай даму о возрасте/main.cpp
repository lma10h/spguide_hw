/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int main()
{
    string s; // digit of the current year
    cin >> s;
    
    long long sum=0;
    long long maxv = 0;
    
    for (int i=0; i<s.size(); ++i) {
        char c = s[i];
        long long value=0;
        if (isdigit(c)) {
            value = c-'0';
        } else {
            value = c-'A'+10;
        }
        
        sum += value;
        maxv = max(maxv, value);
    }
    
    
    int ans=-1;
    for (int k=max(2ll, maxv+1); k<37; ++k) {
        if (sum % (k-1) == 0) {
            ans = k;
            break;
        }
    }
    
    if (ans == -1) {
        cout << "No solution." << endl;
    } else {
        cout << ans << endl;
    }
    
    return 0;
}
