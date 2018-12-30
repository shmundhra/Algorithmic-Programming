// https://www.interviewbit.com/problems/2sum-binary-tree/

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
int inorder ( TreeNode* A , vector < int > &v )
{
    if ( !A ) return 0 ; 
    
    inorder ( A->left , v ) ; 
    v.push_back(A->val) ; 
    inorder ( A->right , v ) ; 
}
 
 
int Solution::t2Sum(TreeNode* A, int B) {
    
    vector < int > v ; 
    inorder ( A , v ) ; 
    
    for ( int i = 0 , j = (int)v.size()-1 ; i < j ; )
    {
        if ( v[i] + v[j] == B ) return 1 ; 
        
        if ( v[i] + v[j] > B ) j-- ; 
        else i++ ; 
    }
    
    return 0 ; 
    
}
*/

TreeNode* Smallest ( TreeNode* A , stack < TreeNode* > &s )
{
    while ( A and A->left )
    {
        s.push(A) ; 
        A = A->left ; 
    }
    return A ;
}

TreeNode* Largest ( TreeNode* A , stack < TreeNode* > &p )
{
    while ( A and A->right )
    {
        p.push(A) ; 
        A = A->right ; 
    }
    return A ;
}

TreeNode* Successor ( TreeNode* A , stack < TreeNode* > &s )
{
    if ( A->right )
    {
        s.push(A) ; 
        return Smallest ( A->right , s ) ;
    }
    else
    {
        while ( !s.empty() )
        {
            TreeNode* par = s.top() ; 
            s.pop() ; 
            
            if ( !par or par->left == A ) return par ; 
            
            A = par ; 
        }
    }
}

TreeNode* Predecessor ( TreeNode* A , stack < TreeNode* > &p )
{
    if ( A->left )
    {
        p.push(A) ; 
        return Largest ( A->left , p ) ;
    }
    else
    {
        while ( !p.empty() )
        {
            TreeNode* par = p.top() ; 
            p.pop() ; 
            
            if ( !par or par->right == A ) return par ; 
            
            A = par ; 
        }
    }
}

int Solution::t2Sum(TreeNode* A, int B) {
    
    stack < TreeNode* > s , p ; 
    
    TreeNode* Small = Smallest ( A , s ) ; 
    TreeNode* Large = Largest  ( A , p ) ; 
    
    
    while ( Small != Large )
    {    
        if ( Small->val + Large->val == B ) return 1 ; 
        else
        {
            if ( Small->val + Large->val > B )
            {
                Large = Predecessor( Large , p ) ; 
            }
            else
            {
                Small = Successor ( Small , s ) ; 
            }
        }
    }
    
    return 0 ; 
}









