#include "node.hpp"
#include "distance.hpp"

namespace sortedkdtree
{

    class sortedKDTree
    {
    private:
        NodePtr Root;
        int Dimension_;
        int depth_;

    public:
        sortedKDTree(int dimension) : Root(nullptr), Dimension_(dimension), depth_(0) {};
        ~sortedKDTree() {};

        void insertSort(PointVec PointVec)
        {
            std::span<Point> pointSpan(PointVec);
            recursiveInsertSort(Root, pointSpan, 0);
        };

        Point findNearestNeighbor(const Point& target)
        {
            std::optional<double> bestDistance = std::nullopt;
            std::optional<Point> bestPoint = std::nullopt;

            recursiveFindNearestNeighbor(target, Root , bestDistance, 0, bestPoint);
            
            return bestPoint.value();
            
        };

    private:
        void recursiveFindNearestNeighbor(const Point &target, NodePtr &current, std::optional<double> &bestDistanceSqrd, int Depth, std::optional<Point>& bestPoint)
        {
            if (current->isLeaf)
            {

                double newDistance = squaredEuclideanDistance(target, current->point);
                if (!bestDistanceSqrd || newDistance < bestDistanceSqrd)
                {
                    bestDistanceSqrd = newDistance;
                    bestPoint = current->point;
                }
                return;
            }

            int AXIS = Depth % Dimension_;
            bool go_left = (target[AXIS] < current->axis);
            NodePtr &firstNode = go_left ? current->left : current->right;
            NodePtr &otherNode = go_left ? current->right : current->left;

            recursiveFindNearestNeighbor(target, firstNode, bestDistanceSqrd, Depth + 1 , bestPoint);

            // r' = (target[axis]-current[axis]) ** 2
            double primeRadius = (target[AXIS] - current->axis);
            double primeRadiusSqrd = primeRadius * primeRadius;

            if (primeRadiusSqrd < bestDistanceSqrd)
            {
                recursiveFindNearestNeighbor(target, otherNode, bestDistanceSqrd, Depth+1,  bestPoint);
            }
        };

        void recursiveInsertSort(NodePtr &current, std::span<Point> &PointSpan, int depth);
    };

} // namespace sortedkdtree