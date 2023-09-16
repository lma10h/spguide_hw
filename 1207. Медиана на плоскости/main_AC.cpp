#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    long double x;
    long double y;
    long double angle;
    long long num;
};

int main()
{
#if 0
    freopen("input.txt", "r", stdin);
#endif

    int n = 0;
    cin >> n;

    vector<Point> v1(n, {0, 0, 0, 0});
    for (int i = 0; i < n; ++i) {
        long double x = 0, y = 0;
        cin >> x >> y;

        v1[i] = {x, y, 0, 1 + i};
    }

    auto it = min_element(v1.begin(), v1.end(),
                          [](const Point &p, const Point &smallest) { return p.y < smallest.y; });
    int minIndex = std::distance(v1.begin(), it);

    vector<Point> v2(n - 1, {0, 0, 0, 0});
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (i == minIndex) {
            continue;
        }

        v2[j].angle = (v1[i].x - v1[minIndex].x)
            / sqrt(pow(v1[i].x - v1[minIndex].x, 2) + pow(v1[i].y - v1[minIndex].y, 2));
        v2[j].num = i + 1;
        ++j;
    }

    sort(v2.begin(), v2.end(),
         [](const Point &p1, const Point &p2) { return p1.angle > p2.angle; });

    cout << minIndex + 1 << " " << v2[(n - 1) / 2].num << endl;

    return 0;
}

