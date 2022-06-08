Link- https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Example 1:

Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9           
Output: 
4 2 1 5 6 3 8 7 9 
Explanation:

Example 2:

Input:
       1
    /    \
   2       3
 /    \      \
4      5      6
Output: 4 2 1 5 3 6
Your Task:
You don't need to read input or print anything. Your task is to complete the function verticalOrder() which takes the root node as input parameter and returns an array containing the vertical order traversal of the tree from the leftmost to the rightmost level. If 2 nodes lie in the same vertical level, they should be printed in the order they appear in the level order traversal of the tree.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= Number of nodes <= 3*10^4





*************************SOLUTION*******************************

 vector<int> verticalOrder(Node *root)
    {
        //Your code here
        map<int, map<int, vector<int> > > nodes;
        queue<pair<Node*, pair<int, int>> > q;
        vector<int> ans;
        
        if(root == NULL) return ans;
        
        //(0,0) because 0 is the distance of root fron center and 
        //0 is the level of root
        q.push(make_pair(root, make_pair(0,0)));
        
        while(!q.empty()){
            pair<Node*, pair<int, int>> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int distance = temp.second.first;
            int level = temp.second.second;
            
            nodes[distance][level].push_back(frontNode->data);
            
            //if we go to the left, our ditance on the scale becomes negative 
            if(frontNode->left){
                q.push(make_pair(frontNode->left, make_pair(distance-1, level+1) ));
            }
            //if we go to the right, our distance increases because root was at 0
             if(frontNode->right){
                q.push(make_pair(frontNode->right,make_pair(distance+1, level+1) ));
            }
        }
            for(auto i: nodes){
                for(auto j:i.second){
                    for(auto k:j.second){
                        ans.push_back(k);
                    }
                }
            }
        return ans;

        
    }
