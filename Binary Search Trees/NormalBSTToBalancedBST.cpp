Link- https://www.codingninjas.com/codestudio/problems/normal-bst-to-balanced-bst_920472?leftPanelTab=0

void inorder(TreeNode<int>* root, vector<int>&in){
    if(root==NULL) return ;
    
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
TreeNode<int>* inBST(int s, int e, vector<int>&in){
    if(s>e) return NULL;
    
    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(in[mid]);
    root->left = inBST(s,mid-1, in);
    root->right = inBST(mid+1, e, in);
    return root;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int> in;
    inorder(root, in);
    
    return inBST(0,in.size()-1,in);
}
