/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

struct Node {
  Node *l=nullptr;
  Node *r=nullptr;
  int val=0;
};

int find_x(int l, int r) {
    int i=r;

    for (; i>=l; --i) {
        if (v[i] < v[r]) {
            return i;
        }
    }
    return -1;
}

void build(int l, int r, Node *&root) {
    if (l >= r) {
        return;
    }
    
    int x = find_x(l, r);
    
    if (x != -1) {
        root->l = new Node;
        root->l->val = v[x];
        
        build(l, x, root->l);
    }
    
    if (x != r-1) {
        root->r = new Node;
        root->r->val = v[r-1];
        
        if (x==-1) {
            build(l, r-1, root->r);
        } else {
            build(x+1, r-1, root->r);
        }
    }
}

void printBT(const std::string& prefix, const Node* node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "L--");
        // print the value of the node
        std::cout << node->val << std::endl;
        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "|   " : "    "), node->l, true);
        printBT(prefix + (isLeft ? "|   " : "    "), node->r, false);
    }
}

void printBT(const Node* node)
{
    printBT("", node, false);
}

void printAns(const Node* node) {
    if (!node) return;
    
    printAns(node->r);
    printAns(node->l);
    cout << node->val << "\n";
}

int main()
{
    int N=0; cin>>N;
    v.resize(N, 0);
    for (int i=0; i<N; ++i) {
        cin>>v[i];
    }
    
    Node *root=nullptr;
    if (N>=1) {
        root=new Node;
        root->val = v[N-1];
        build(0, N-1, root);
    }
    
    //printBT(root);
    
    printAns(root);
    
    return 0;
}
