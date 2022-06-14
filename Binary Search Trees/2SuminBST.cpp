Link- https://www.codingninjas.com/codestudio/problems/two-sum-in-a-bst_1062631?leftPanelTab=0

Problem Statement
You have been given a Binary Search Tree and a target value. You need to find out whether there exists a pair of node values in the BST, such that their sum is equal to the target value.
A binary search tree (BST), also called an ordered or sorted binary tree, is a rooted binary tree whose internal nodes each store a value greater than all the values keys in the node's left subtree and less than those in its right subtree.
Follow Up:
Can you solve this in O(N) time, and O(H) space complexity?
Input Format:
The first line of input contains a single integer T, representing the number of test cases or queries to be run. 

Then the T test cases follow. 

The first line of each test case contains elements in the level order form. The line consists of values of nodes separated by a single space. In case a node is null, we take -1 in its place. 

The second line of each test case contains a single integer representing the target value.

For example, the input for the tree depicted in the below image would be :

4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
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
Output Format:
For each test case, print True or False in a separate line.
Note:
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 100
1 <= N <= 3000
-10^9 <= node data <= 10^9, (where node data != -1)
-10^9 <= target value <= 10^9

Where N denotes is the number of nodes in the given tree.

Time Limit: 1 second
Sample Input 1:
1
10 6 12 2 8 11 15 -1 -1 -1 -1 -1 -1 -1 -1
14
Sample Output 1:
True
Explanation For Sample 1:
For the first test case, the sum of the nodes with values 2 and 12 equals the target value.

Sample Input 2:
1
5 3 7 -1 -1 6 8 -1 -1 -1 -1
20
Sample Output 2:
False
Explanation For Sample 2:
For the first test case, there is no such pair of nodes, the sum of which equals the target value.

  
  
  
  ******************************************************SOLUTION**********************************************************
  
  void inorder(BinaryTreeNode<int>* root, vector<int> &in){
        if(root==NULL) return;
        
        inorder(root->left, in);
        in.push_back(root->data);
        inorder(root->right, in);
    }
bool twoSumInBST(BinaryTreeNode<int>* root, int k) {
	//Write your code here
    vector<int> in;
        inorder(root, in);
        int i=0, j = in.size()-1;
        
        while(i<j){
            int sum = in[i]+in[j];
            
            if(sum==k) return true;
            else if (sum>k) j--;
            else i++;
        }
        return false;
}
  
