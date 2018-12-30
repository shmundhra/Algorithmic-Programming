// https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* Create ( vector<int > &A , vector<int > &B , int start , int end )
{   
    //for ( int i = start ; i <=end ; i++ ) cout<<A[i]<<" " ; cout<<endl ; 
    //for ( int i = start ; i <=end ; i++ ) cout<<B[i]<<" " ; cout<<endl ; cout<<endl ; 
    
    if ( end < start ) return NULL ; 
        
    int value = B[end] ; 
    
    int ind ; 
    for (  ind = start ; ind <= end ; ind++ )
    {
        if ( A[ind] == value ) break ; 
    }
    for ( int i = ind ; i < end ; i++ )
    {
        A[i] = A[i+1] ; 
    }
    TreeNode *T = new TreeNode(value) ; 
    
    T->left  = Create ( A , B , start , ind - 1 ) ;
    T->right = Create ( A , B , ind , end - 1 ) ;

    return T ; 
}
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    
    return Create( A , B , 0 , (int)A.size()-1 ) ; 
}
