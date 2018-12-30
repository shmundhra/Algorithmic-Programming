// https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int WidthL ( TreeNode* A , int x )
{   
    if ( A == NULL ) return x ; 
    
    int left  = WidthL ( A->left  , x+1 ) ; 
    int right = WidthL ( A->right , x-1 ) ; 
    
    return max ( left , right ) ; 
}
 
int WidthR ( TreeNode* A , int x )
{   
    if ( A == NULL ) return x ; 
    
    int left  = WidthR ( A->left  , x-1 ) ; 
    int right = WidthR ( A->right , x+1 ) ; 
    
    return max ( left , right ) ; 
}
 
 
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
   
    if ( !A )
    {
        vector < vector<int> > ans ; 
        return ans ; 
    }
    
    int wl = WidthL ( A , -1 ) ; 
    int wr = WidthR ( A , -1 ) ; 

    vector<vector<int> > ans ( wl+wr+1 , vector<int>() ) ; 
    
    queue < TreeNode* > q ; 
    q.push( A ) ;
   
    map < TreeNode* , int > m ; 
    m[A] = wl ; 
    
    while ( !q.empty() )
    {
        TreeNode *tmp = q.front() ; 
        q.pop() ; 
        
        int index = m[tmp] ; 
       
        ans [ index ].push_back( tmp->val ) ; 
        
        if ( tmp->left )
        {
            q.push( tmp->left ) ; 
            m[ tmp->left ] = index - 1 ; 
        }
        
        if ( tmp->right )
        {
            q.push( tmp->right ) ; 
            m[ tmp->right ] = index + 1 ; 
        }
    }
    return ans ; 
   
}
