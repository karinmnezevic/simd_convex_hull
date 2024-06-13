#include "monotone_chain_std.h"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Point<int>> load_points_from_txt(std::filesystem::path file_path) {
    std::ifstream file(file_path);
    std::string line;
    std::getline(file, line);
    std::stringstream ss(line);
    file.close();

    std::vector<Point<int>> points;
    char dummy;
    int x,y;
    while (ss >> dummy >> x >> dummy >> y >> dummy >> dummy)
        points.emplace_back(x, y);
    
    return points;
}

int main() {

    std::vector<Point<int>> pts = load_points_from_txt("tests/1_in.txt");
    //std::vector<Point<int>> pts = load_points_from_txt("tests/3_in.txt");
    std::vector<Point<int>> hull = convex_hull_standard<int>(pts);

    std::ofstream file("out.txt");
    for (auto& pt: hull)
        file << '[' << pt.x << ',' << pt.y << ']' << ',';

    file.close();
    return 0;
}