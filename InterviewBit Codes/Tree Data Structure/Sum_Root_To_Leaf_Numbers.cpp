// https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
#define modu 1003 

int Add ( TreeNode* A , long val , long &ans )
{
    if ( !A )
    {
        return 0 ;      
    }
    
    val = ( (val*10)%modu + A->val ) %modu ; 
    
    if ( !(A->left) and !(A->right) )
    {
        ans = ( ans + val ) % modu ; 
        return 1 ; 
    }
    
    Add ( A->left  , val , ans) ; 
    Add ( A->right , val , ans) ; 
}

int Solution::sumNumbers(TreeNode* A) {
    
    long ans = 0 ; 
    Add ( A , 0 , ans ) ; 
    return ans ; 
}
