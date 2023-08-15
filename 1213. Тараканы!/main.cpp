/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
    unordered_set<string> s;
    string gw;
    cin>>gw;
    s.insert(gw);
    
    string edge;
    while(cin>>edge && edge != "#") {
        auto pos = edge.find("-");
        s.insert(edge.substr(0,pos));
        s.insert(edge.substr(pos+1));
    }
    
    if (s.size() == 0) {
        cout << 0 << "\n";
    } else {
        cout << s.size()-1 << "\n";
    }

    return 0;
}
