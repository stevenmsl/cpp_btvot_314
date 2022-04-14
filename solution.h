
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;
namespace sol314
{
    class Solution
    {
    private:
        void getRange(Node *, vector<int> &range, int colIdx);

    public:
        vector<vector<int>> traverse(Node *root);
    };
}
#endif