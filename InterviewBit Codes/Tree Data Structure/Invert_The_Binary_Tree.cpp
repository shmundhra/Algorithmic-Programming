// https://www.interviewbit.com/problems/invert-the-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int Invert(TreeNode* &A)
{
    if (!A) return 0 ; 
    
    Invert(A->left ) ; 
    Invert(A->right) ; 
    
    TreeNode* tmp1 = A->left ;
    TreeNode* tmp2 = A->right ;
    
    A->left  = tmp2 ; 
    A->right = tmp1 ; 
}


TreeNode* Solution::invertTree(TreeNode* A) {

    Invert(A) ; 
    return A ; 
}
