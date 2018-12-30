// https://www.interviewbit.com/problems/symmetric-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*

This is actualy wrong in the case where the keys are repeated. An unsymmetric tree with
all 1 perse will pass in this as well 

int Inorder ( TreeNode* A , vector<int> &v ) 
{
    if ( !A ) return 0 ; 
    
    Inorder ( A->left , v ) ; 
    v.push_back(A->val) ; 
    Inorder ( A->right , v ) ; 
}
 
 
int Solution::isSymmetric(TreeNode* A) {
    
    vector < int > v ; 
    Inorder ( A , v ) ; 
    
    return equal(v.begin() , v.begin() + v.size()/2 , v.rbegin() ) ; 
}
*/

int Check ( TreeNode* L , TreeNode* R )
{
    if ( !L or !R ) return ( L == R ) ; 
    
    int leftS  = Check ( L->left , R->right ) ; 
    int currS  = ( L->val == R->val ) ; 
    int rightS = Check ( L->right , R->left ) ;
    
    return (leftS*currS*rightS) ; 
}

int Solution::isSymmetric(TreeNode* A) {

    if (!A ) return 1 ; 
    
    int ans = Check ( A->left , A->right ) ; 
    
    return ans ; 
}