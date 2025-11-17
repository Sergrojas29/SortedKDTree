#include <iostream>
#include <span>
#include <vector>
#include <array>
#include <algorithm>
#include "sorted_kd_tree/sorted_kdtree.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    std::vector<std::array<float, 2>> myVector = {
        {12, 63}, // A 
        {88, 80}, // B
        {40, 60}, // C
        {60, 36}, // D
        {51, 45}, // E
        {53, 91}  // F
    };

    sortedkdtree::sortedKDTree tree(2);

    
    
    tree.insertSort(myVector);
    
    
    std::optional<sortedkdtree::Point> nearestPoint1 = tree.findNearestNeighbor({16,59});
    std::cout << nearestPoint1.value()[0] << ", " << nearestPoint1.value()[1] << "\n";
    std::optional<sortedkdtree::Point> nearestPoint2 = tree.findNearestNeighbor({76,85});
    std::cout << nearestPoint2.value()[0] << ", " << nearestPoint2.value()[1] << "\n";
    std::optional<sortedkdtree::Point> nearestPoint3 = tree.findNearestNeighbor({45,66});
    std::cout << nearestPoint3.value()[0] << ", " << nearestPoint3.value()[1] << "\n";
    std::optional<sortedkdtree::Point> nearestPoint4 = tree.findNearestNeighbor({40,60});
    std::cout << nearestPoint4.value()[0] << ", " << nearestPoint4.value()[1] << "\n";




















    // typedef std::array<int, 2> Point;
    // typedef std::vector<Point> PointVec;
    // // PointVec myVector = {
    // //     {12, 63},
    // //     {88, 80},
    // //     {40, 60},
    // //     {60, 36},
    // //     {51, 45},
    // //     {53, 91},
    // //     {72, 15},
    // //     {43, 75},
    // //     {41, 11},
    // //     {12, 36},
    // //     {23, 36},
    // //     {83, 65},
    // //     {61, 45},
    // //     {41, 53},
    // //     {93, 28},
    // // };

    // std::span<Point> full_span(myVector); // Automatic deduction
    // int INDEX_MEDIAN = full_span.size() / 2;

    // std::span<Point> left = full_span.first(INDEX_MEDIAN);

    // cout << left[0][0] <<", " <<left[0][1] << endl;
    // std::span<Point> right = full_span.last(full_span.size() - INDEX_MEDIAN);

    // std::sort(right.begin() , right.end(), [] (Point a , Point b){
    //     return a[0] < b[0] ;
    // });

    return 0;
}
