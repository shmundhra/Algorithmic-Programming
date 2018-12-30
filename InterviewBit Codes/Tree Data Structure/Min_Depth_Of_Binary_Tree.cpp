// https://www.interviewbit.com/problems/min-depth-of-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int Check ( TreeNode *A )
{
    if (!A )
    {
        return INT_MAX/4 ;     
    }
    if ( !(A->left) and !(A->right) )
    {
        return 1 ; 
    }
    
    int left  = Check(A->left  ) ; 
    int right = Check(A->right ) ;
    
    return ( 1 + min( left , right ) ) ; 
}
 
int Solution::minDepth(TreeNode* A) {

    return Check ( A ); 
    
}
