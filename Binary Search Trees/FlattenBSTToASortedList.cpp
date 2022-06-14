Link- https://www.codingninjas.com/codestudio/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=0

Problem Statement
You have been given a Binary Search Tree (BST). Your task is to flatten the given BST to a sorted list. More formally, you have to make a right-skewed BST from the given BST, i.e., the left child of all the nodes must be NULL, and the value at the right child must be greater than the current node.
A binary search tree (BST), also called an ordered or sorted binary tree, is a rooted binary tree whose internal nodes each store a value greater than all the values in the node's left subtree and less than those in its right subtree.
Follow Up :
Can you solve this in O(N) time and O(H)  space complexity?
Input Format :
The first line of input contains a single integer T, representing the number of test cases or queries to be run. 

Then the T test cases follow. 

The first line of each test case contains elements in the level order form. The line consists of values of nodes separated by a single space. In case a node is null, we take -1 in its place.

For example, the input for the tree depicted in the below image would be :

4
2 6
1 3 5 7
-1 -1 -1 -1 -1 -1 -1 -1
Explanation :
Level 1 :
The root node of the tree is 4

Level 2 :
Left child of 4 = 2
Right child of 4 = 6

Level 3 :
Left child of 2 = 1
Right child of 2 = 3
Left child of 6 = 5
Right child of 6 = 7

Level 4 :
Left child of 1 = null (-1)
Right child of 1 = null (-1)
Left child of 3 = null (-1)
Right child of 3 = null (-1)
Left child of 5 = null (-1)
Right child of 5 = null (-1)
Left child of 7 = null (-1)
Right child of 7 = null (-1)

The first not-null node (of the previous level) is treated as the parent of the first two nodes of the current level. The second not-null node (of the previous level) is treated as the parent node for the next two nodes of the current level and so on.
The input ends when all nodes at the last level are null (-1).
Note :
The above format was just to provide clarity on how the input is formed for a given tree. 
The sequence will be put together in a single line separated by a single space. Hence, for the above-depicted tree, the input will be given as:

4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
Output Format :
For each test case, flatten the BST and print the values of the nodes in the level order form.

Print the output of each test case in a separate line.
Note :
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 100
1 <= N <= 5000
0 <= node.data <= 10^9, (where node data != -1)

Where 'N' denotes the number of nodes in the given tree.

Time Limit: 1 second
Sample Input 1
2
10 6 12 2 8 11 15 -1 -1 -1 -1 -1 -1 -1 -1
5 -5 8 -1 -1 -1 -1
Sample Output 1
2 -1 6 -1 8 -1 10 -1 11 -1 12 -1 15 -1 -1
-5 -1 5 -1 8 -1 -1
Explanation For Sample Input 1
For the first test case, the given BST is depicted below.

So, after flattening, the BST is transposed as the below figure.


For the second test case, the given BST is depicted below.

So, after flattening, the BST is transposed as the below figure.


Sample Input 2
2
5 3 7 -1 -1 6 8 -1 -1 -1 -1
2 1 -1 -1 -1
Sample Output 2
3 -1 5 -1 6 -1 7 -1 8 -1 -1
1 -1 2 -1 -1

  
  *************************************************************SOLUTION*********************************************************
  
   void inorder(TreeNode<int>* root, vector<int> & ans){
        if(root== NULL) return;
        
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<int> ans;
    inorder(root, ans);
        
    int n = ans.size();
    TreeNode<int>* newRoot = new TreeNode<int>(ans[0]);
    TreeNode<int>* curr = newRoot;
    for(int i=1;i<n;i++){
        TreeNode<int>* temp = new TreeNode<int>(ans[i]);
        
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    curr->left = NULL;
    curr->right = NULL;
    
    return newRoot;
}

  
