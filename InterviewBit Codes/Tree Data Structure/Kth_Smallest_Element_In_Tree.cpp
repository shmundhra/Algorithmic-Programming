// https://www.interviewbit.com/problems/kth-smallest-element-in-tree/

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
    O(B) time algorithm instead of normal O(n) 
   OUR Stack Invariant is aisa ki the stack will hold the path from [Root , CurrSmall ) 
   at each step 
*/

TreeNode* Smallest ( TreeNode* A  , stack < TreeNode* > &s  )
{   
    while ( A and A->left )     // A and is added for generalised case 
    {
        s.push(A) ; 
        A = A->left ; 
    }
    return A ; 
}

 
TreeNode* Successor ( TreeNode* A  , stack < TreeNode* > &s )
{
    if ( A->right )
    {   
        //s.push(A) ; // I missed this out here PITY PITY 
        return Smallest ( A->right , s ) ; 
    }
    else
    {   
        TreeNode *par ; 
        /*while ( !s.empty() ) 
        {
            par = s.top() ; 
            s.pop() ; 
            
            if ( !par or par->left == A ) return par ;  // !par is added for general case 
            
            A = par ; 
        }*/
        if ( !s.empty() ) 
        {
            par = s.top() ; 
            s.pop() ; 
        }
        return par ; 
    }
}
 
int Solution::kthsmallest(TreeNode* A, int B) {
    
    //if (!A ) cout<<B<<"th largest element not present in TREE " ; EXTRA if B > N
    
    stack < TreeNode* > s ; 
    
    TreeNode* Small = Smallest ( A , s ) ; 
    
    for ( int i = 1 ; i < B ; i++ )
    {   
        //cout<<Small->val<<" " ; 
        Small = Successor ( Small , s ) ; 
        //if ( !Small) cout<<B<<"th largest element not present in TREE " ; EXTRA if B > N
        
    }
     
    return Small->val ; 
    
}

/*
void pushALL ( TreeNode* A , stack< TreeNode* > &s )
{
    while ( A )
    {
        s.push(A) ; 
        A = A->left ; 
    }
}

int Solution::kthsmallest(TreeNode* A, int B) {
    
    stack < TreeNode* > s ; 
    pushALL( A , s ) ; 
    
    TreeNode* Small = NULL ; 
    
    for ( int i = 0 ; i < B and !s.empty() ; i++ )
    {
        Small =  s.top() ; 
        s.pop() ; 
        
        pushALL( Small->right , s ) ; 
    }
    
    if ( Small ) return Small->val ; 
}*/
