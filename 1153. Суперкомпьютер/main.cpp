https://acm.timus.ru/problem.aspx?space=1&num=1153

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // calculation
    D = 500;

    // sqrt(D) by BS
    N = D+1;
    
    x=-1
    l=0, r=N; // [l, r]
    // K[l] <= D && D < K[r]
    while (l != r - 1) {
        m = (l+r)/2
        Km = m*m
        
        if (Km == D) {
          x=m
          break;
        }
        
        if (D < Km) {
            r=m
        } else {
            l=m
        }
    }
    
    // x*x == D
    n = (-b + x)/(2*a)
    // SUM(1...n) == S

    return 0;
}
