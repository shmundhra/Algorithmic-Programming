// https://www.interviewbit.com/problems/path-sum/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int Check ( TreeNode* A , int B )
{   
    if ( A == NULL )
    {
        return 0 ; 
    }
    
    if ( A->left == NULL and A->right == NULL )
    {
        if ( B == A->val ) return 1 ; 
        else return 0 ; 
    }
    
    int left  = Check ( A->left  , B - A->val ) ; 
    int right = Check ( A->right , B - A->val ) ;
    
    return ( left + right ) ; 
}
 
 
int Solution::hasPathSum(TreeNode* A, int B) {
    
    return !(!Check( A , B )) ; 
}
