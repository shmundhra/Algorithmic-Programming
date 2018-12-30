// https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/

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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    
    vector<vector<int> > ans ; 
    
    TreeNode *sentinel = new TreeNode(0) ; 
    
    queue < TreeNode* > q ; 
    
    q.push(A) ; 
    q.push(sentinel) ; 
    int level = 0 ; 
    
    while (  (int)q.size() != 1  )
    {
        TreeNode *curr = q.front() ; 
        q.pop() ; 
        
        if ( curr == sentinel ) 
        {
            level++ ;
            q.push(sentinel) ;
            
            continue ; 
        }
        
        if ( ans.size() == level ) ans.push_back( vector<int>() ) ; 
        
        ans[level].push_back(curr->val) ; 
        
        if ( curr->left  ) q.push( curr->left  ) ; 
        if ( curr->right ) q.push( curr->right ) ;
    }
    for ( int i = 0 ; i < ans.size() ; i++ )
    {
        if ( i%2 ) reverse ( ans[i].begin() , ans[i].end() ) ; 
    }
    
    return ans ; 
}
*/

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    
    stack < TreeNode* > so , se ; 
    vector<vector<int> > ans ;
    
    se.push(A) ; 
    
    while ( !se.empty() or !so.empty() )
    {
        ans.push_back( vector<int>() ) ; 
        if ( !se.empty() )
        {
            while(!se.empty() )
            {
                TreeNode *curr = se.top() ;
                se.pop() ; 
                
                ans[(int)ans.size()-1].push_back( curr->val ) ;
                
                if ( curr->left  ) so.push( curr->left  ) ; 
                if ( curr->right ) so.push( curr->right ) ;
                
            }
        }
        else
        {
            while(!so.empty() )
            {
                TreeNode *curr = so.top() ;
                so.pop() ; 
                
                ans[(int)ans.size()-1].push_back( curr->val ) ;
                
                if ( curr->right ) se.push( curr->right ) ;
                if ( curr->left  ) se.push( curr->left  ) ; 
            }
        }
    }
    return ans ; 
}
