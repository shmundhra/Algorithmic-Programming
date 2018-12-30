// https://www.interviewbit.com/problems/balanced-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

long abso ( long x ){ if ( x < 0 ) return (-x) ; return x ; }

long maxim ( long x , long y ){  if ( x < y ) return y ; return x ; }

pair < long , bool > Height ( TreeNode *A )
{
    if ( A == NULL ) return make_pair(0,true) ; 
    
    pair <long , bool > left   = Height (A->left ) ; 
    pair <long , bool > right  = Height (A->right) ;
    
    pair <long , bool> ans ; 
    
    if ( !left.second or !right.second or abso(left.first-right.first) > 1 )  ans.second = false ; 
    else ans.second = true ;
    
    ans.first = 1 + maxim(left.first , right.first ) ; 
    
    return ans ; 
}
 
 
int Solution::isBalanced(TreeNode* A) {
    
    pair <long , bool> ans  = Height( A ) ; 
    
    return ans.second ; 
    
}
