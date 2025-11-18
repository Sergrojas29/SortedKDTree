#include "node.hpp"
#include "distance.hpp"

namespace sortedkdtree

{

    struct NearestResult
    {
        Node *parentNode;
        Node *bestNode;
        double bestDistanceSqrd;
        bool goLeft;
        explicit NearestResult() : parentNode(nullptr), bestNode(nullptr), bestDistanceSqrd(std::numeric_limits<double>::max()), goLeft(false) {};
    };

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

        Point findNearestNeighbor(const Point &target)
        {

            NearestResult Results;
            recursiveFindNearestNeighbor(target, Root, 0, Results, Root , Results.goLeft);
            
            Point bestPoint = Results.bestNode->point;
            if(Results.goLeft){
                Results.parentNode->left.reset();
            }else{
                Results.parentNode->right.reset();
            }
            return bestPoint;
        };

    private:
        void recursiveFindNearestNeighbor(const Point &target, NodePtr &current, int depth, NearestResult &Results, NodePtr &parentNode, bool goLeft)
        {
            if (!current)
                return;

            if (current->isLeaf)
            {
                updateResults(target, current, Results, parentNode , goLeft);
            }

            int AXIS = depth % Dimension_;
            bool go_left = (target[AXIS] < current->axis);
            NodePtr &firstNode = go_left ? current->left : current->right;
            NodePtr &otherNode = go_left ? current->right : current->left;

            recursiveFindNearestNeighbor(target, firstNode, depth + 1, Results, current, go_left);

            // r' = (target[axis]-current[axis]) ** 2
            double primeRadius = (target[AXIS] - current->axis);
            double primeRadiusSqrd = primeRadius * primeRadius;

            if (primeRadiusSqrd < Results.bestDistanceSqrd)
            {
                recursiveFindNearestNeighbor(target, otherNode, depth + 1, Results, current, !go_left);
            }
        };

        void recursiveInsertSort(NodePtr &current, std::span<Point> &PointSpan, int depth);

        void updateResults(const Point &target, const NodePtr &current, NearestResult &Results, NodePtr &parentNode , bool goLeft)
        {

            double newDistance = squaredEuclideanDistance(target, current->point);
            if (newDistance < Results.bestDistanceSqrd)
            {
                Results.bestDistanceSqrd = newDistance;
                Results.bestNode = current.get();
                Results.parentNode = parentNode.get();
                Results.goLeft = goLeft;
            }
            return;
        }
    };

} // namespace sortedkdtree