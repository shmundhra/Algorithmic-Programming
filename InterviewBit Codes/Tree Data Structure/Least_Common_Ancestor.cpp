// https://www.interviewbit.com/problems/least-common-ancestor/

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
int LCA ( TreeNode* A , int B , int C  , int &flag )
{
    if (!A ) return 0 ; 
    
    if ( flag == 0 )
    {
        if ( A->val == B )
        {
            flag = 1 ; 
            if ( A->val == C )
            {
                flag = 2 ; 
                return A->val ; 
            }
            LCA ( A->left , B , C , flag ) ;
            LCA ( A->right , B , C , flag ) ;
            if( flag == 2 )
                return A->val ; 
        }
        else
        {
            int valueL = LCA ( A->left , B , C , flag ) ; 
            
            if ( flag == 0 ) 
            {
                int valueR = LCA ( A->right , B , C , flag ) ; 
                if ( flag == 2 )
                {
                    return valueR ; 
                }
            }
            else if ( flag == 1 )
            {
                LCA ( A->right , B , C , flag ) ; 
                if ( flag == 2 )
                {
                    return  A->val ; 
                }
            }
            else
            {
                return valueL ; 
            }
        }
    }
    
    else if ( flag == 1 )
    {
        if ( A->val == C )
        {
            flag = 2 ; 
        }
        else
        {
            LCA ( A->left  , B , C , flag ) ; 
            LCA ( A->right , B , C , flag ) ; 
        }      
    }
    
}
 
int Solution::lca(TreeNode* A, int B, int C) {
    
    int flag = 0 ; 
    int ans = LCA ( A , B , C , flag ) ; 
    if ( flag == 0 or flag == 1 ) return -1 ; 
    return ans ; 
}*/
/*
int LCA ( TreeNode* A, int B, int C , int &flag )
{
    if ( !A ) return 0 ;
    
    if ( flag == 0 )
    {
        if ( A->val == B )
        {
            flag = 1 ; 
            LCA ( A , B , C , flag ) ; 
            
            if ( flag == 2 )
            {
                return A->val ;     
            }
        }
        
        int valueL = LCA ( A->left , B , C , flag ) ;
        if ( flag == 2 )
        {
            return valueL ; 
        }
        if ( flag == 1 )
        {
            int valueR = LCA ( A->right , B , C , flag ) ;
            if ( flag == 2 )
            {
                return A->val ; 
            }
        }
    }
    if ( flag == 1 )
    {
        if ( A->val == C )
        {
            flag = 2 ; 
        }
        else
        {
            LCA ( A->left  , B , C , flag ) ; 
            LCA ( A->right , B , C , flag ) ; 
        }
    }
}

int Solution::lca(TreeNode* A, int B, int C) {
    
    int flag = 0 ; 
    int ans = LCA ( A , B , C , flag ) ; 
    
    if ( flag == 2 ) return ans ; 
    return -1 ; 
    
}*/



int Search ( TreeNode* A , int C )
{   
    if ( !A ) return 0 ; 
    if ( A->val == C ) return 1 ; 
    if ( Search(A->left , C ) ) return 1 ; 
    if ( Search(A->right , C) ) return 1 ; 
    return 0 ; 
}


int Solution::lca(TreeNode* A, int B, int C) {
    
    stack < TreeNode* > s ; 
    
    s.push(A) ; 
    int flag = 0 ; 
    
    TreeNode* prev = NULL  ; 
    while(!s.empty() )
    {
        TreeNode *tmp = s.top() ; 

        if ( tmp->val == B )
        {
            flag = 1 ; 
            break ; 
        }

        if ( tmp->right and tmp->right == prev ) // RIGHT CHILD PRESENT and PROCESSED ALREADY -> Move UP
        {
            prev = s.top() ; 
            s.pop() ; 

        }
        else if ( tmp->left ) // LEFT CHILD PRESENT 
        {
            if ( tmp->left == prev )    // LEFT CHILD ALREADY PROCESSED 
            {
                if ( tmp->right )         // IF RIGHT CHILD PRESENT PUSH
                {
                    s.push(tmp->right) ; 
                }            
                else                     // NODE FINISHED Move UP
                {
                    prev = s.top() ; 
                    s.pop() ; 
                }
            }
            else                        // LEFT CHILD NOT PROCESSED 
            {
                s.push(tmp->left) ; 
            }
        }
        else if ( tmp->right )  // ONLY RIGHT CHILD and Well NOT PROCESSED 
        {
            s.push( tmp->right ) ; 
        }
        else // LEAF NODE 
        {
            prev = s.top() ; 
            s.pop() ; 
        }
    }
    if ( flag == 0 ) return -1 ; 
    
    //cout<<flag<<endl ; return 0 ;
    
    prev = NULL ; 
    while ( !s.empty() )
    {
        TreeNode *tmp = s.top() ; 
        
        int l , r ; 
        l = r = 0 ; 
        
        if ( tmp->val == C ) return tmp->val ; 
        
        if ( tmp->left and tmp->left != prev )  l = Search ( tmp->left , C ) ; 
        
        if ( tmp->right and tmp->right != prev ) r = Search ( tmp->right , C ) ; 
        
        if ( l or r ) return tmp->val ; 
        
        prev = tmp ;
        
        s.pop() ; 
    }
    
    return -1 ; 
    
}





