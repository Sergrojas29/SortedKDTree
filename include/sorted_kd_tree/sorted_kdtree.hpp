#include "node.hpp"

namespace sortedkdtree
{

    class sorted_kdtree
    {
    private:
        NodePtr Root;
        int Dimension_;
        int depth_;

    public:
        sorted_kdtree(int dimension): Root(nullptr), Dimension_(dimension), depth_(0){};

        ~sorted_kdtree() {};

        void insert();
    };

}// kdtree