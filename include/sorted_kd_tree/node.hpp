#pragma once
#include <vector>
#include <array>
#include <memory>
#include <cmath>

namespace sortedkdtree{

    
    using Point =  std::array<float,2>;
    
    struct Node
    {
        int axis;
        Point point;
        NodePtr left;
        NodePtr right;
        explicit Node():left(nullptr), right(nullptr){}
    };
    
    using NodePtr = std::unique_ptr<Node> ;
    
}



