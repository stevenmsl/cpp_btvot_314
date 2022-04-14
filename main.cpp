#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol314;

/*
Input: [3,9,20,null,null,15,7]

   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7

Output:

[
  [9],
  [3,15],
  [20],
  [7]
]
*/

tuple<Node *, vector<vector<int>>> testFixture1()
{
  auto root = new Node(3);
  root->left = new Node(9);
  root->right = new Node(20);
  root->right->left = new Node(15);
  root->right->right = new Node(7);
  auto const output = vector<vector<int>>{
      {9},
      {3, 15},
      {20},
      {7}};

  return make_tuple(root, output);
}

/*
Input: [3,9,8,4,0,1,7]

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7

Output:

[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]

*/

tuple<Node *, vector<vector<int>>> testFixture2()
{
  auto root = new Node(3);
  root->left = new Node(9);
  root->left->left = new Node(4);
  root->left->right = new Node(0);
  root->right = new Node(8);
  root->right->left = new Node(1);
  root->right->right = new Node(7);
  auto const output = vector<vector<int>>{
      {4},
      {9},
      {3, 0, 1},
      {8},
      {7}};

  return make_tuple(root, output);
}

/*
Input: [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5)

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2

Output:

[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]
*/

tuple<Node *, vector<vector<int>>> testFixture3()
{
  auto root = new Node(3);
  root->left = new Node(9);
  root->left->left = new Node(4);
  root->left->right = new Node(0);
  root->left->right->left = new Node(5);
  root->left->right->right = new Node(2);
  root->right = new Node(8);
  root->right->left = new Node(1);
  root->right->right = new Node(7);
  auto const output = vector<vector<int>>{
      {4},
      {9, 5},
      {3, 0, 1},
      {8, 2},
      {7}};

  return make_tuple(root, output);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - expect to see " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << "result: " << Util::toString(sol.traverse(get<0>(f))) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - expect to see " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << "result: " << Util::toString(sol.traverse(get<0>(f))) << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Test 3 - expect to see " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << "result: " << Util::toString(sol.traverse(get<0>(f))) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}