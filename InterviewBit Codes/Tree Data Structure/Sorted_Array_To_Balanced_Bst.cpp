// https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/

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
TreeNode* Create ( const vector < int > &A , int start , int end )
{   
    if ( end < start ) return NULL ; 
    
    int index = start + (end-start)/2 ; 
    
    TreeNode* T = new TreeNode( A[ index ] )  ; 
    
    T->left  = Create ( A , start , index-1 ) ; 
    T->right = Create ( A , index + 1 , end ); 
    
    return T ; 
}
 
 
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return  Create ( A , 0 , (int)A.size()-1 ) ;   
}
*/
TreeNode* Create ( const vector < int > &A , int start , int len )
{   
    if ( len < 1 ) return NULL ; 
    
    int index = start + (len-1)/2 ; 
    
    TreeNode* T = new TreeNode( A[ index ] )  ; 
    
    T->left  = Create ( A , start , index - start ) ; 
    T->right = Create ( A , index + 1 , len - ( index-start ) - 1 ); 
    
    return T ; 
}
 
 
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return  Create ( A , 0 , A.size() ) ;   
}
