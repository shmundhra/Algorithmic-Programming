// https://www.interviewbit.com/problems/bst-iterator/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int counter  ; 
stack < TreeNode* > s ; 
TreeNode *Small , *Large ;
TreeNode* A ; 

BSTIterator::BSTIterator(TreeNode *root) {
    
    A = root ; 
    counter = 0 ; 
    
    while ( !s.empty() ) s.pop() ; 
    
    Small = Large = NULL ; 
}

TreeNode* Smallest ( TreeNode* A )
{
    while ( A and A->left )
    {
        s.push(A) ; 
        A = A->left ; 
    }
    return A ; 
}

TreeNode* Successor ( TreeNode* A )
{
    if ( !A ) return NULL ; 
    
    if ( A->right)
    {
        s.push(A) ; 
        return Smallest(A->right) ;
    }
    else
    {
        while ( !s.empty() )
        {
            TreeNode* par = s.top(); 
            s.pop() ; 
            if ( !par or par->left == A ) return par ; 
            
            A = par ;
        }
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    
    if ( counter == 0 )
    {
        if ( A == NULL ) return false  ; 
        else return true ; 
    }
    
    if ( Small == Large ) return false ; 
    else return true ;  
    
}

/** @return the next smallest number */
int BSTIterator::next() {
    
    if ( counter == 0 )
    {
        counter++ ; 
        Small = Smallest ( A ) ; 
        
        TreeNode* tmp ; 
        for ( tmp = A ; tmp and tmp->right ; tmp = tmp->right ) ; Large = tmp ; 
        
        return Small->val ; 
    }
    else
    {
        Small = Successor ( Small ) ; 
        return Small->val ; 
    }
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
