#include "Q2_Sort_By_Distance.h"
#include <algorithm>

void sort_points_by_distance(std::vector<std::array<double, 3>>& points) {
    if (points.empty()) {
        return;
    }

    auto squared_distance = [](const std::array<double, 3>& point) {
        return point[0]*point[0] + point[1]*point[1] + point[2]*point[2];
    };

    std::sort(points.begin(), points.end(),
        [&squared_distance](const auto& a, const auto& b) {
            return squared_distance(a) < squared_distance(b);
        });
}