// https://www.interviewbit.com/problems/inorder-traversal/

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
vector<int> Solution::inorderTraversal(TreeNode* A) {
    
    vector<int> v ;
    
    stack < TreeNode* > s ; 
    
    if ( !A ) return v ; 
    
    s.push(A) ;
    
    while ( !s.empty() )
    {
        TreeNode *tmp = s.top() ; 
        
        if ( tmp->left ) 
        {
            s.push(tmp->left) ; 
        }
        else
        {
            v.push_back(tmp->val) ; 
            s.pop() ; 
            
            if ( !s.empty() )
            {
                TreeNode *tmp1 = s.top() ;
                tmp1->left = NULL ; 
            }
            
            if ( tmp->right)
            {
                s.push(tmp->right) ; 
            }
        }
    }
    return v ;
    
}
*/

vector<int> Solution::inorderTraversal(TreeNode* A) {
    
    vector < int > ans ; 
    
    stack< TreeNode* > s ; 
    
    TreeNode* root = A ; 
    
    while (1)
    {
        while(root)
        {
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
            ans.push_back(curr->val) ; 
            s.pop() ; 
            
            root = curr->right ; 
        }
    }
    return ans ; 
}