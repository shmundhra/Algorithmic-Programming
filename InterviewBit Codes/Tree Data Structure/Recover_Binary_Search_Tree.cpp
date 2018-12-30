// https://www.interviewbit.com/problems/recover-binary-search-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void pushALL ( TreeNode* A , stack < TreeNode* > &s )
{
    while ( A )  
    {
        s.push(A) ; 
        A = A->left ; 
    }
}
 
vector<int> Solution::recoverTree(TreeNode* A) {
    
    stack < TreeNode* > s ; 
    vector < int > ans(2) ; 
    
    pushALL ( A , s ) ; 
    
    TreeNode *prev , *curr ;
    prev = curr = NULL ; 
    
    prev = s.top() ; 
    s.pop() ; 
    pushALL(prev->right , s ) ; 
    
    int flag = 0 ; 
    while ( !s.empty() )
    {
        curr = s.top() ; 
        s.pop() ; 
        pushALL(curr->right , s) ; 
        
        //cout<<prev->val<<"$"<<curr->val<<"   " ; 
        
        if ( flag == 0 and curr->val < prev->val )
        {
            ans[0] = prev->val ; 
            ans[1] = curr->val ;
            flag = 1 ; 
        }
        else if ( flag == 1 and curr->val < prev->val )
        {
            ans[1] = curr->val ; 
            break ; 
        }
        
        prev = curr ; 
    }
    
    sort ( ans.begin() , ans.end() ) ; 
    return ans ; 
}
