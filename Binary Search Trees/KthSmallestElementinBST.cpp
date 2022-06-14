Link- https://www.codingninjas.com/codestudio/problems/find-k-th-smallest-element-in-bst_1069333?leftPanelTab=0

Problem Statement
Given a binary search tree and an integer ‘K’. Your task is to find the ‘K-th’ smallest element in the given BST( binary search tree).
BST ( binary search tree) -
If all the smallest nodes on the left side and all the greater nodes on the right side of the node current node.
Example -

Order of elements in increasing order in the given BST is - { 2, 3, 4, 5, 6, 7, 8, 10 }
Suppose given ‘K = 3’ then 3rd smallest element is ‘4’.
Suppose given ‘K = 8’ then 8th smallest element is ‘10’.
Note:
1. You are not required to print the output explicitly, it has already been taken care of. Just implement the function and return the ‘K-th’ smallest element of BST.
2. You don’t need to return ‘K-th’ smallest node, return just value of that node. 
3. If ‘K-th’ smallest element is not present in BST then return -1.
Input Format:
The first line of input contains an integer ‘T’ denoting the number of test cases.
The next ‘T’ lines represent the ‘T’ test cases.

The first line of input contains a single integer ‘K’.
The second line of input contains the elements of the tree in the level order form separated by a single space.   
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
Output Format:
For every test case, return the ‘K-th’ smallest element.
Constraint :
1 <= T <= 100
1 <= N, K <= 3000
-10^9 <= data <= 10^9

Where ‘T’ represents the number of test cases, ‘N’ is the number of nodes in the tree, ‘K’ denotes given integer and ‘data’ denotes data contained in the node of a binary tree.

Time Limit: 1 sec
Sample Input 1:
2
3
3 1 4 -1 -1 -1 5 -1 -1
4
5 2 -1 -1 4 3 -1 -1 -1
Sample Output 1:
4   
5
Explanation Of Sample Input 1:
Test case 1:

Order of elements in the increasing order in the given BST is - { 1, 3, 4, 5 }.
‘K = 3’, so the 3’rd smallest element is ‘4’, return ‘4’.

Test case 2:

Order of elements in increasing order in the given BST is - { 2, 3, 4, 5 }.
‘K=4’, so the 4’rd smallest element is ‘5’, return ‘5’.
Sample Input 2:
2
1
3 2 -1 1 -1 -1 -1
4
3 1 4 -1 -1 -1 -1
Sample Output 2:
1
-1
  
  
  
  
  *****************************************************SOLUTION*************************************************************
  
  
  int solve(BinaryTreeNode<int>* root, int &i, int k){
    if(root ==  NULL) return -1;
    
    int left = solve(root->left,i,k);
    if(left!=-1) return left;
    
    i++;
    if(i==k) return root->data;
    
    return solve(root->right, i, k);
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int i= 0;
    int ans = solve(root, i,k);
    return ans;
}
