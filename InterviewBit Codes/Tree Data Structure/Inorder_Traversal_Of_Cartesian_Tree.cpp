// https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Insert ( vector <int> A )
{   
    if ( (int)A.size() <= 0 ) return NULL ; 
    
    int max = INT_MIN ; 
    int maxp = -1 ; 
    
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        if ( max < A[i] )
        {
            max = A[i] ; 
            maxp = i ; 
        }
    }
    
    TreeNode* N = new TreeNode(max) ; 
    
    N->left  = Insert( vector <int> ( A.begin() , A.begin() + maxp )   ) ; 
    N->right = Insert( vector <int> ( A.begin() + maxp + 1 , A.end() ) ) ; 
    
    return N ; 
}
 
 
TreeNode* Solution::buildTree(vector<int> &A) {
    
    TreeNode* T = Insert ( A ) ; 
    
    return T ; 
}
