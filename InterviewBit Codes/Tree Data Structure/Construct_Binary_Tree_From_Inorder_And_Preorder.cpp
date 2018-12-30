// https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* Create ( vector<int> &A , vector<int> &B , int start , int end )
{
    if ( end < start ) return NULL ; 
    
    int value = B[start] ; 
    TreeNode* N = new TreeNode(value) ; 
    
    int ind ; 
    for ( ind = start ; ind <= end ; ind++ )
    {
        if ( A[ind] == value )
            break ; 
    }
    for ( int i = ind ; i > start ; i-- ) A[i] = A[i-1] ; 
    
    N->left  = Create(A , B, start + 1 , ind  );
    N->right = Create(A , B, ind + 1 , end   );

    return N ; 
}
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    
    TreeNode *T = Create(B,A,0,(int)A.size()-1 ) ; 
    return T ; 
}
