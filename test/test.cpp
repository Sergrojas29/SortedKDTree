#include <iostream>
#include <span>
#include <vector>
#include <array>
#include <algorithm>
#include "sorted_kd_tree/sorted_kdtree.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    // std::vector<std::array<float, 2>> myVector = {
    //     {12, 63}, // A
    //     {88, 80}, // B
    //     {40, 60}, // C
    //     {60, 36}, // D
    //     {51, 45}, // E
    //     {53, 91}  // F
    // };

    std::vector<std::array<float, 2>> myVector = {
        {12, 63},
        {88, 80},
        {40, 60},
        {60, 36},
        {51, 45},
        {53, 91},
        {72, 15},
        {43, 75},
        {41, 11},
        {12, 36},
        {23, 36},
        {83, 65},
        {61, 45},
        {41, 53},
        {93, 28},
    };

    // https://www.desmos.com/calculator/nvhspvobkg
    sortedkdtree::sortedKDTree tree(2);

    tree.insertSort(myVector);

    sortedkdtree::PointVec sortedVector;

    sortedkdtree::Point searchPoint = {16, 59}; 
    for (auto &i : myVector)
    {        
        searchPoint = tree.findNearestNeighbor(searchPoint);
        sortedVector.push_back(searchPoint);
    }

    for (auto &&i : sortedVector)
    {
        std::cout << "(" << i[0] << ", " << i[1] << ")\n";
    }

    return 0;
}
