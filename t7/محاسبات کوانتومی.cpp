#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

struct Point {
    long long x;
    long long y;
};

double calculateDistance(const Point& p1, const Point& p2) {
    long long dx = p2.x - p1.x;
    long long dy = p2.y - p1.y;
    return std::sqrt(dx*dx + dy*dy);
}

int main() {
    long long n;
    std::cin >> n;

    std::vector<Point> points(n);

    for (long long i = 0; i < n; i++) {
        std::cin >> points[i].x >> points[i].y;
    }

    double minDistance = std::numeric_limits<double>::max();
    Point closestPoint1, closestPoint2;

    for (long long i = 0; i < n - 1; i++) {
        for (long long j = i + 1; j < n; j++) {
            double distance = calculateDistance(points[i], points[j]);
            if (distance < minDistance) {
                minDistance = distance;
                closestPoint1 = points[i];
                closestPoint2 = points[j];
            }
        }
    }

    std::cout << closestPoint1.x << " " << closestPoint1.y << std::endl;
    std::cout << closestPoint2.x << " " << closestPoint2.y << std::endl;

    return 0;
}
