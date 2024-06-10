#include <vector>

template <typename T>
struct Point {
    Point(T _x, T _y) : x(_x), y(_y) {};
    T x;
    T y;
};

template <typename T>
int ccw(const Point<T>& O, const Point<T>& A, const Point<T>& B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

template <typename T>
bool check_collinear(std::vector<Point<T>>& points) {
    for (int i = 0; i < points.size() - 2; i ++) 
        if (ccw(points[i], points[i+1], points[i+2]) != 0)
            return false;
    return true;
}

template <typename T>
std::vector<Point<T>> convex_hull_standard(std::vector<Point<T>>& points) {
    std::sort(points.begin(), points.end());

    if (check_collinear(points))
        return points;

    std::vector<Point<T>> hull;
    for (auto& point : points) { // constructing the lower hull
        while (hull.size() >= 2 && ccw(hull[hull.size()-2], hull[hull.size()-1], point) > 0)
                    hull.pop_back();
        hull.emplace_back(point); 
    }

    int k = hull.size();
    for (int i = points.size() - 1; i > 0; i --) { // constructing the upper hull
        while (hull.size() >= k + 1 && 
                ccw(hull[hull.size()-2], hull[hull.size()-1], points[i]) > 0)
                    hull.pop_back();
        hull.emplace_back(points[i]); 
    }
    hull.pop_back(); // the first point will be added twice

    return hull;
}
