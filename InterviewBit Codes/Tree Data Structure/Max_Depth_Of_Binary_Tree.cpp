// https://www.interviewbit.com/problems/max-depth-of-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int Height ( TreeNode* A)
{
    if ( A == NULL ) return 0 ; 
    
    int left = Height ( A->left ) ; 
    int right = Height ( A->right ) ; 
    
    return ( 1 + max(left,right) ) ; 
}
 
int Solution::maxDepth(TreeNode* A) {
    
    return Height(A) ; 
}
