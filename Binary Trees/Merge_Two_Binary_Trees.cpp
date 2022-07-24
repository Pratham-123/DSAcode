Link - 
  
  Given two binary trees node0 and node1, return a merge of the two trees where each value is equal to the sum of the values of the corresponding nodes of the input trees. If only one input tree has a node in a given position, the corresponding node in the new tree should match that input node.

Constraints

n ≤ 100,000 where n is the number of nodes in node0
m ≤ 100,000 where m is the number of nodes in node1
Example 1
Input
Visualize
node0 = [0, [3, null, null], [2, [3, null, null], null]]
node1 = [7, [5, null, null], [1, null, null]]
Output
Visualize
[7, [8, null, null], [3, [3, null, null], null]]
Example 2
Input
Visualize
node0 = [1, [2, [3, null, null], null], null]
node1 = [4, null, [5, null, [6, null, null]]]
Output
Visualize
[5, [2, [3, null, null], null], [5, null, [6, null, null]]]


********************************************************SOLUTION***************************************************

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
Tree* solve(Tree* node0, Tree* node1) {
    if (!node0 && !node1) return NULL;
  if (!node0) return node1;
  if (!node1) return node0;

  node0 -> val = node0 -> val + node1 -> val;

  node0 -> left = solve(node0 -> left, node1 -> left);
  node0 -> right = solve(node0 -> right, node1 -> right);

  return node0;
}
