#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x = 0;
    int y = 0;
};

bool isInPolygon(int cx, int cy, vector<Point> polygon, int n)
{
    // polygon:
    // n == 5
    //
    //            *5
    // *1
    //         *A[cx,cy]
    //                  *4
    //    *2      *3
    //
    // пройдем по всем парам векторов [1A,12], 2A_23, ...
    // и определим знак векторного произведения
    // если знак у всех одинаковый, значит точка лежит внутри полигона

    polygon.push_back(polygon[0]);

    int i = 0;
    int vx = polygon[i + 1].x - polygon[i].x;
    int vy = polygon[i + 1].y - polygon[i].y;

    int vax = cx - polygon[i].x;
    int vay = cy - polygon[i].y;

    int sign = vx * vay - vax * vy;

    for (i = 1; i < n; ++i) {
        vx = polygon[i + 1].x - polygon[i].x;
        vy = polygon[i + 1].y - polygon[i].y;

        vax = cx - polygon[i].x;
        vay = cy - polygon[i].y;

        if (sign != (vx * vay - vax * vy)) {
            return false;
        }
    }

    return true;
}

double vLen(double x, double y)
{
    return sqrt(x * x + y * y);
}

double findMinDistance(int cx, int cy, vector<Point> polygon, int n)
{
    polygon.push_back(polygon[0]);

    // допустим, т.А это координаты попадания
    // т.C и т.D это две ближайшие точки полигона
    // т.H это проекция т.А на отрезок CD
    //
    //
    //          *A
    //          |
    //          |
    //          |
    //          |
    //  *C------*H---------------*D
    //
    //

    double ans = 10e9;
    const auto A = Point{cx, cy};

    // пройдемся по всем парам CD и выберем наименьшую дистанцию
    for (int i = 1; i < n; ++i) {
        const auto C = polygon[i];
        const double CAx = A.x - C.x;
        const double CAy = A.y - C.y;

        const auto D = polygon[i + 1];
        const double CDx = D.x - C.x;
        const double CDy = D.y - C.y;
        const double lCD = vLen(CDx, CDy);
        double cosA = (C.x * D.x + C.y * D.y) / vLen(CAx, CAy) * lCD;

        // 1) нашли длинну вектора CH
        const double lCH = vLen(CAx, CAy) * cosA;

        // 2) найшли точку H
        double nCDx = C.x / lCD; // нормированный CD
        double nCDy = C.y / lCD;

        double CHx = nCDx * lCH;
        double CHy = nCDy * lCH;

        double AHx = CAx - CHx;
        double AHy = CAy - CHy;
        double lAH = vLen(AHx, AHy);

        double Hx = AHx + A.x;
        double Hy = AHy + A.y;
        double HDx = D.x - Hx;
        double HDy = D.y - Hy;
        double lHD = vLen(HDx, HDy);

        // 3) проверили т.H
        if (lCH + lHD == lCD) {
            // т.H лежит на отрезке CD => это самое короткое расстояние
            ans = min(ans, lAH);
        } else {
            double lCA = vLen(A.x - C.x, A.y - C.y);
            double lDA = vLen(A.x - D.x, A.y - D.y);
            ans = min(ans, min(lCA, lDA));
        }
    }

    return 2 * ans;
}

int main()
{
    int cx = 0, cy = 0, n = 0;
    cin >> cx >> cy >> n;

    vector<Point> polygon(n);
    for (int i = 0; i < n; ++i) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    // solve
    double ans = 0;
    if (isInPolygon(cx, cy, polygon, n)) {
        ans = 0;
    } else {
        ans = findMinDistance(cx, cy, polygon, n);
    }

    printf("%.3f\n", ans);
}
