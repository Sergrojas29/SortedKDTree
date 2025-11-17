#pragma once
#include <vector>
#include <array>
#include <memory>
#include <cmath>
#include <span>
#include <iostream>
#include <algorithm>
namespace sortedkdtree{

    
    using Point =  std::array<float,2>;
    using PointVec = std::vector<Point>;
    
    struct Node
    {
        int axis;
        Point point;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
        explicit Node():left(nullptr), right(nullptr){}
    };
    
    using NodePtr = std::unique_ptr<Node> ;
    
}



