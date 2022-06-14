Link- https://www.codingninjas.com/codestudio/problems/lca-in-a-bst_981280?leftPanelTab=0

Problem Statement
You are given a binary search tree of integers with N nodes. You are also given references to two nodes P and Q from this BST.
Your task is to find the lowest common ancestor(LCA) of these two given nodes.
The lowest common ancestor for two nodes P and Q is defined as the lowest node that has both P and Q as descendants (where we allow a node to be a descendant of itself)
A binary search tree (BST) is a binary tree data structure which has the following properties.
• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.
Input Format:
The first line contains an integer 'T' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case contains two space separated integers P and Q, the nodes whose LCA we have to find.

The second line of each test case contains the elements of the BST in the level order form separated by a single space.

If any node does not have a left or right child, take -1 in its place. Refer to the example below.

Example:

Elements are in the level order form. The input consists of values of nodes separated by a single space in a single line. In case a node is null, we take -1 in its place.

For example, the input for the tree depicted in the below image would be :

1
2 3
4 -1 5 6
-1 7 -1 -1 -1 -1
-1 -1

Explanation :
Level 1 :
The root node of the tree is 1

Level 2 :
Left child of 1 = 2
Right child of 1 = 3

Level 3 :
Left child of 2 = 4
Right child of 2 = null (-1)
Left child of 3 = 5
Right child of 3 = 6

Level 4 :
Left child of 4 = null (-1)
Right child of 4 = 7
Left child of 5 = null (-1)
Right child of 5 = null (-1)
Left child of 6 = null (-1)
Right child of 6 = null (-1)

Level 5 :
Left child of 7 = null (-1)
Right child of 7 = null (-1)

The first not-null node (of the previous level) is treated as the parent of the first two nodes of the current level. The second not-null node (of the previous level) is treated as the parent node for the next two nodes of the current level and so on.

The input ends when all nodes at the last level are null (-1).
Note :
The above format was just to provide clarity on how the input is formed for a given tree. 

The sequence will be put together in a single line separated by a single space. Hence, for the above-depicted tree, the input will be given as:

1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1
Output Format :
For each test case print the LCA of nodes P and Q.

Output for every test case will be printed in a separate line.
Constraints:
1 <= T <= 100
1 <= N <= 5000
0 <= Data <= 10^6 and Data != -1

Time Limit: 1sec
Sample Input 1 :
2
3 5
2 1 3 -1 -1 -1 5 -1 -1
1 3
2 1 4 -1 -1 3 -1 -1 -1
Sample Output 1:
3
2
Explanation for Sample 1:
The BST corresponding to the first test case will be-

Here, we can clearly see that LCA of node 3 and node 5 is 3.

The BST corresponding to the second test case will be- 

Here, we can clearly see that LCA of node 1 and node 3 is 2.
Sample Input 2 :
1
1 1
3 2 -1 1 -1 -1 -1
Sample Output 2:
1
  
  
  
  
  
  **************************************************SOLUTION***********************************************
  
  TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	// Write your code here
    if(root == NULL) return NULL;
    if(root->data > P->data && root->data> Q->data){
        return LCAinaBST(root->left, P, Q);
    }
    if(root->data < P->data && root->data< Q->data){
        return LCAinaBST(root->right, P, Q);
    }
    return root;
}
  
