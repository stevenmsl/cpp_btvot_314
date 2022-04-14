#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <queue>
using namespace sol314;
using namespace std;

/*takeaways
  - given a node its left child will be in the previous column while its
    right child will be in the next column
  - use DFS to find how many columns we need with leftmost node having
    the smallest column index rightmost node the largest.
  - use BFS to make sure inside each column the nodes are listed
    from top to bottom

*/
void Solution::getRange(Node *node, vector<int> &range, int colIdx)
{
  if (node == nullptr)
    return;
  range[0] = min(range[0], colIdx);
  range[1] = max(range[1], colIdx);
  /* previous column */
  getRange(node->left, range, colIdx - 1);
  /* next column */
  getRange(node->right, range, colIdx + 1);
}

vector<vector<int>> Solution::traverse(Node *root)
{
  if (root == nullptr)
    return {};

  /* find out what the smallest and the largest col indexes are */
  auto range = vector<int>(2);
  getRange(root, range, 0);

  /* we have that many columns: range[1] - range[0] + 1 */
  auto result = vector<vector<int>>(range[1] - range[0] + 1);

  /* node and its col index
    - the range looks like [-2,-1,0,1,2]
    - adjust the col index of the root node so that the leftmost
      node has the col index of 0
      [-2,-1,0,1,2] -> [0,1,2,3,4]
  */
  auto q = queue<pair<Node *, int>>{{{root, 0 + abs(range[0])}}};

  /*BFS
    - you need to list the nodes from top to bottom,
      column by column
  */

  while (!q.empty())
  {
    const auto &[node, col] = q.front();
    q.pop();
    result[col].push_back(node->val);
    if (node->left != nullptr)
      q.push({node->left, col - 1});
    if (node->right != nullptr)
      q.push({node->right, col + 1});
  }

  return result;
}