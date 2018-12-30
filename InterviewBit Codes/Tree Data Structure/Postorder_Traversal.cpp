// https://www.interviewbit.com/problems/postorder-traversal/

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
vector<int> Solution::postorderTraversal(TreeNode* A) {
    
    vector < int > v ; 
    
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
            if ( tmp->right )
            {
                s.push(tmp->right) ; 
            }
            else
            {
                v.push_back(tmp->val) ; 
                s.pop() ; 
                
                if ( !s.empty() )
                {
                    TreeNode *tmp1 = s.top() ; 
                    
                    if ( tmp1->left == tmp ) tmp1->left = NULL ; 
                    else tmp1->right = NULL ; 
                }
                
            }
        }
    }
    
    return v ; 
    
}
*/

vector<int> Solution::postorderTraversal(TreeNode* A) {
    
    vector<int> v ; 
    
    stack < TreeNode*> s ; 
    
    TreeNode *root = A ; 
    TreeNode *prev = NULL ;
    TreeNode *curr = NULL ;
    
    while(1)
    {
        while(root)
        {
            s.push(root) ; 
            root = root->left ; 
        }
       
        while ( !s.empty() )
        {   
            curr = s.top() ;
            if (curr->right and curr->right != prev) break ; 
               
            v.push_back(curr->val) ;
            prev = curr ; 
            s.pop() ; 
        }
        
        if( s.empty() )
        {
            break ; 
        }
        else
        {
            root = curr->right ; 
        }
    }
    
    return v ; 
}