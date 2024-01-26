#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<int> used;
vector<int> colors;
bool isImpossible = false;

void readInput()
{
    int n = 0;
    cin >> n;
    cin.ignore();

    g.resize(n);
    used.resize(n);
    colors.resize(n);

    for (int i = 0; i < n; ++i) {
        string input;
        getline(cin, input);

        vector<int> v;
        stringstream ss(input);
        while (!ss.eof()) {
            int value = 0;
            ss >> value;

            v.push_back(value - 1);
        }
        v.pop_back(); // remove last 0

        for (int j : v) {
            g[i].push_back(j);
            g[j].push_back(i);
        }
    }
}

void dfs(int v, int color)
{
    if (used[v]) {
        if (colors[v] == !color) {
            isImpossible = true;
        }

        return;
    }

    used[v] = 1;
    colors[v] = color;

    for (int vi : g[v]) {
        dfs(vi, !color);
    }
}

int main()
{
    readInput();

    dfs(0, 0);

    if (isImpossible) {
        cout << -1 << "\n";
    } else {
        for (int c : colors) {
            cout << c;
        }
    }
}
