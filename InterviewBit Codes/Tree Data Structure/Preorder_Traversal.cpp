// https://www.interviewbit.com/problems/preorder-traversal/

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
vector<int> Solution::preorderTraversal(TreeNode* A) {
    
    
    vector < int > v ; 
    
    if ( !A ) return v ; 
    
    stack < TreeNode* > s ; 
    
    s.push(A) ; 
    v.push_back(A->val) ; 
     
    while ( !s.empty() )
    {
        TreeNode *tmp = s.top () ; 
        
        if ( tmp->left)
        {
            s.push(tmp->left) ; 
            v.push_back( (tmp->left)->val ) ; 
        }
        else
        {
            s.pop() ; 
            
            if ( !s.empty() )
            {
                TreeNode *tmp1 = s.top() ; 
                tmp1->left = NULL ;
            }
            
            if ( tmp->right )
            {
                s.push(tmp->right) ; 
                v.push_back( (tmp->right)->val ) ;
            }
        }
    }
    return v  ;
}
*/

vector<int> Solution::preorderTraversal(TreeNode* A) {
    
    vector <int> v ; 
    
    stack <TreeNode*> s ; 
    
    TreeNode *root = A ; 
    
    while(1)
    {
        while(root)
        {
            v.push_back(root->val) ; 
            s.push(root) ; 
            
            root = root->left ; 
        }
        if ( s.empty() )
        {
            break ; 
        }
        else
        {
            TreeNode *curr = s.top() ; 
            s.pop() ; 
            
            root = curr->right ; 
        }
    }
    
    return v ; 
}
