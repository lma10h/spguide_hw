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

    int ans_a = 0, ans_b = 0;
    int n = 0;
    cin >> n;

    Point A;
    cin >> A.x >> A.y;

    vector<Point> v(n - 1, {0, 0, 0, 0});
    for (int i = 0; i < n - 1; ++i) {
        long long x = 0, y = 0;
        cin >> x >> y;

        v[i] = {x - A.x, y - A.y, 0, 2 + i};
    }

    const double PI = 3.14159265;

    for (int i = 0; i < n - 1; ++i) {
        long double dd = atan2(v[i].y * 1.0, v[i].x * 1.0) - atan2(0.0, 1.0); // radians
        long double dd2 = dd * 180;
        long double dd3 = dd2 / PI; // degrees
        v[i].angle = dd3 < 0 ? dd3 + 360.0 : dd3;
    }

    sort(v.begin(), v.end(), [](const Point &p1, const Point &p2) { return p1.angle < p2.angle; });

    // точка А зафиксировали
    // точка B это v[b]
    // точка С это v[c]
    // прямая АB делит плоскость на две части
    // точка С это первая точка во второй плоскости

    int c = 0;
    for (int b = 0; b < n - 1; ++b) {
        int from = c;
        while (v[c].angle - v[b].angle < 180.0) {
            c = (c + 1) % (n - 1);
            if (from == c) {
                break;
            }
        }

        int count = (c - b - 1 + (n - 1)) % (n - 1);
        if (count == (n - 2) - count) {
            ans_a = 1;
            ans_b = v[b].num;
            break;
        }
    }

    cout << ans_a << " " << ans_b << endl;

    return 0;
}

