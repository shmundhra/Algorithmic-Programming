// https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* Flatten ( TreeNode* &A)
{
    if(!A) return NULL ; 
    
    if ( !(A->left) and !(A->right) )
    {
        return A ; 
    }
    TreeNode *L , *R ; 
    L = R = NULL ; 
    
    if ( A->left  )
    {
        L = Flatten ( A->left  ) ; 
    }
    if ( A->right )
    {
        R = Flatten ( A->right ) ; 
    }
    /*if (!L) return R ; 
    if (!R)
    {
        A->right = A->left  ;
        A->left = NULL ;
        return L ; 
    }
    
    L->right = A->right ; 
    A->right = A->left  ;
    A->left = NULL ;    
  
    return R ; */
    
    if(L)
    {
        L->right = A->right ; 
        A->right = A->left ; 
        A->left = NULL ; 
        
        if(!R) return L ; 
    }
    return R ; 
    
}
 
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    Flatten(A) ; 
    return A ; 
}
