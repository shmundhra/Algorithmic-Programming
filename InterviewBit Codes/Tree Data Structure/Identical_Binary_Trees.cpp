// https://www.interviewbit.com/problems/identical-binary-trees/

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
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    
    if ( !A or !B ) return ( A == B ) ; 
    
    stack < TreeNode* > sa ; 
    stack < TreeNode* > sb ;
    
    sa.push(A) ; 
    sb.push(B) ; 
    
    while ( !sa.empty() and !sb.empty() )
    {
        TreeNode* tmpa = sa.top() ; 
        TreeNode* tmpb = sb.top() ; 
        
        if ( !( tmpa->left ) )
        {
            if ( tmpb->left ) return 0 ; 
        }
        if ( !( tmpb->left ) )
        {
            if ( tmpa->left ) return 0 ; 
        }
        
        if ( tmpa->left and tmpb->left)
        {
            sa.push(tmpa->left) ; 
            sb.push(tmpb->left) ; 
        }
        else
        {
            if ( tmpa->val != tmpb->val ) return 0 ; 
            
            sa.pop() ; sb.pop() ; 
            
            if ( !sa.empty() and !sb.empty() )
            {
                TreeNode* tmpa1 = sa.top() ; 
                TreeNode* tmpb1 = sb.top() ;
                
                tmpa1->left = NULL ; 
                tmpb1->left = NULL ; 
            }
            
            if ( !( tmpa->right ) )
            {
                if ( tmpb->right ) return 0 ; 
            }
            if ( !( tmpb->right ) )
            {
                if ( tmpa->right ) return 0 ; 
            }
            if ( tmpa->right and tmpb->right )
            {
                sa.push(tmpa->right) ; 
                sb.push(tmpb->right) ; 
            }
        }
        
    }
    return 1 ; 
}*/
#include <stdint.h>

int Inorder ( TreeNode* A , TreeNode* B )
{   
    // if ( !A or !B ) return ( A == B ) ; 
    
    if ( (!A) * (!B) ) return 1 ;
    
    if ( !(!A) ^ !(!B)  ) return 0 ; 
    
    int left  = Inorder ( A->left , B->left ) ;// cout<<"("<<A->val<<B->val<<")"<<left ;  
    int curr  = (A->val == B->val ) ;// cout<<"("<<A->val<<B->val<<")"<<curr;
    int right = Inorder ( A->right , B->right ) ;// cout<<"("<<A->val<<B->val<<")"<<right ;  
    
    return ( left*curr*right ) ; 
}

int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    
    int ans = Inorder( A , B ) ; 
    
    return ans ; 
}

