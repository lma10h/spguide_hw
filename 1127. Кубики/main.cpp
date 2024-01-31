#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void parse(const string &cubic, const vector<int> &indexes, string &x)
{
    // GYVABW
    // 4, 0, 5, 3

    // min_v = A
    char min_v
        = min(cubic[indexes[0]], min(cubic[indexes[1]], min(cubic[indexes[2]], cubic[indexes[3]])));
    // min_i = 3
    int min_i = cubic.find(min_v);
    auto it = find(indexes.begin(), indexes.end(), min_i);
    // xi_j = 3
    int xi_j = distance(indexes.begin(), it);

    auto inc = [](int &i) { return i = (i + 1) % 4; };

    x[0] = cubic[indexes[xi_j]];
    inc(xi_j);
    x[1] = cubic[indexes[xi_j]];
    inc(xi_j);
    x[2] = cubic[indexes[xi_j]];
    inc(xi_j);
    x[3] = cubic[indexes[xi_j]];
}

void getXYZ(const string &cubic, string &x, string &y, string &z)
{
    vector<int> xi({4, 0, 5, 3});
    parse(cubic, xi, x);

    vector<int> y_i({1, 4, 2, 5});
    parse(cubic, y_i, y);

    vector<int> z_i({0, 1, 3, 2});
    parse(cubic, z_i, z);
}

int main()
{
    int n = 0;
    cin >> n;
    cin.ignore();

    // передняя, правая, левая, задняя, верхняя, нижняя
    unordered_map<string, int> m;

    for (int i = 0; i < n; ++i) {
        string cubic;
        cin >> cubic;

        string x(4, 0), y(4, 0), z(4, 0);
        getXYZ(cubic, x, y, z);

        m[x] += 1;
        string rx(x.rbegin(), x.rend());
        rotate(rx.rbegin(), rx.rbegin() + 1, rx.rend());
        m[rx] += 1;

        m[y] += 1;
        string ry(y.rbegin(), y.rend());
        rotate(ry.rbegin(), ry.rbegin() + 1, ry.rend());
        m[ry] += 1;

        m[z] += 1;
        string rz(z.rbegin(), z.rend());
        rotate(rz.rbegin(), rz.rbegin() + 1, rz.rend());
        m[rz] += 1;
    }

    int ans = -1;
    for (auto [side, count] : m) {
        ans = max(ans, count);
    }

    cout << ans << "\n";
}
