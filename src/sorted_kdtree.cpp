#include "sorted_kd_tree/sorted_kdtree.hpp"

namespace sortedkdtree
{
    void sortedKDTree::recursiveInsertSort(NodePtr &current, std::span<Point> &PointSpan, int depth)
    {

        //*Create Unique Node Pointer
        if (!current)
            current = std::make_unique<Node>();

        int SIZE = PointSpan.size();
        //*Base Case for Leaf
        if (SIZE == 1)
        {
            current->point = PointSpan[0];
            return;
        }

        int AXIS = depth % Dimension_;
        int INDEX_MEDIAN = SIZE / 2;
        
        //*Sort by Axis
        std::sort(PointSpan.begin(), PointSpan.end(), [&AXIS](Point a, Point b)
        { return a[AXIS] < b[AXIS]; });
        
        //*Set Node Axis
        current->axis = PointSpan[INDEX_MEDIAN][AXIS];

        std::span<Point> leftSpan = PointSpan.first(INDEX_MEDIAN);
        std::span<Point> rightSpan = PointSpan.last(SIZE - INDEX_MEDIAN);

        //* RecursiveInsert
        recursiveInsertSort(current->left, leftSpan, depth + 1);
        recursiveInsertSort(current->right, rightSpan, depth + 1);
    }

} // namespace sortedkdtree