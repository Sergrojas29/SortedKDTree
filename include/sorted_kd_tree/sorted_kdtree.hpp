#include "node.hpp"

namespace sortedkdtree
{

    class sortedKDTree
    {
    private:
        NodePtr Root;
        int Dimension_;
        int depth_;

    public:
        sortedKDTree(int dimension): Root(nullptr), Dimension_(dimension), depth_(0){};
        ~sortedKDTree() {};

        void insertSort(PointVec PointVec){
            std::span<Point> pointSpan(PointVec);
            recursiveInsertSort(Root, pointSpan, 0);
        };

    private:
        void recursiveInsertSort(NodePtr& current, std::span<Point>& PointSpan , int depth);
    };

}// namespace sortedkdtree