#include <iostream>
#include <list>
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

void bfs(int v)
{
    struct Node {
        int v = 0;
        int color = 0; // requested color
    };

    list<Node> q;
    q.push_back({v, 0});

    while (!q.empty()) {
        Node node = q.front();
        q.pop_front();

        if (used[node.v]) {
            if (node.color != colors[node.v]) {
                isImpossible = true;
            }

            continue;
        }

        used[node.v] = 1;
        colors[node.v] = node.color;

        for (int vi : g[node.v]) {
            if (used[vi]) {
                continue;
            }

            q.push_back({vi, !node.color});
        }
    }
}

int main()
{
    readInput();

    // dfs(0, 0);
    bfs(0);

    if (isImpossible) {
        cout << -1 << "\n";
    } else {
        for (int c : colors) {
            cout << c;
        }
    }
}
