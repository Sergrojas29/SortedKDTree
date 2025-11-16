#include <iostream>
#include <span>
#include <vector>
#include <array>
#include <algorithm>
// #include "include/sorted_kd_tree/sorted_kdtree.hpp"

using namespace std;



int main(int argc, char const *argv[])
{
    typedef std::array<int, 2> Point;
    typedef std::vector<Point> PointVec;
    // PointVec myVector = {
    //     {12, 63},
    //     {88, 80},
    //     {40, 60},
    //     {60, 36},
    //     {51, 45},
    //     {53, 91},
    //     {72, 15},
    //     {43, 75},
    //     {41, 11},
    //     {12, 36},
    //     {23, 36},
    //     {83, 65},
    //     {61, 45},
    //     {41, 53},
    //     {93, 28},
    // };

    std::vector<std::array<int, 2>> myVector = {
        // {12, 63},
        {88, 80},
        {40, 60},
        {60, 36},
        {51, 45},
        {53, 91}};

    std::span<Point> full_span(myVector); // Automatic deduction
    int INDEX_MEDIAN = full_span.size() / 2;

    std::span<Point> left = full_span.first(INDEX_MEDIAN);

    cout << left[0][0] <<", " <<left[0][1] << endl;
    std::span<Point> right = full_span.last(full_span.size() - INDEX_MEDIAN);

    
    std::sort(right.begin() , right.end(), [] (Point a , Point b){
        return a[0] < b[0] ;
    });

    return 0;
}
