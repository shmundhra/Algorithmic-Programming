// https://www.interviewbit.com/problems/populate-next-right-pointers-tree/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    /*
    if (A)
    {   
        TreeLinkNode* sentinel = new TreeLinkNode(0) ; 
        
        queue < TreeLinkNode* > q ; 
        q.push(A) ; 
        q.push(sentinel) ; 
        
        while ( (int)q.size() != 1  )
        {
            TreeLinkNode* tmp = q.front() ; 
            q.pop() ; 
            
            if ( tmp->left )  q.push(tmp->left  ) ; 
            if ( tmp->right ) q.push(tmp->right ) ; 
            
            if ( q.front() == sentinel ) 
            {
                tmp->next = NULL ; 
                q.pop() ; 
                q.push(sentinel) ; 
            }
            else
            {
                tmp->next = q.front() ; 
            }
        }
    }*/
    /*
    while(A)
     {
         TreeLinkNode* tmp = new TreeLinkNode(0);
         TreeLinkNode* curr = tmp ;
         
         while(A)
         {
             if(A->left)
             {
                 curr->next = A->left;
                 curr = curr->next;
             }
             if(A->right)
             {
                 curr->next = A->right;
                 curr = curr -> next;
             }
             A = A->next;
         }
         A = tmp->next;
         
     }
    */
    A->next = NULL ; 
    
    TreeLinkNode *start , *prev , *curr ; 
    start = A ; 
   
    while ( 1 )
    {
        prev = start ; 
        
        while ( prev and !prev->left and !prev->right ) prev = prev->next ; 
        
        if ( !prev ) break ; 
        
        if ( prev->left ) curr = prev->left ; 
        else curr = prev->right ; 
        
        start = curr ; 
        
        while ( prev )
        {   
            //cout<<prev->val<<"-"<<curr->val<<"  " ; 
            
            if ( prev->left and prev->left!=curr )
            {
                curr->next = prev->left ; 
                curr = curr->next ; 
            }
            if ( prev->right )
            {
                curr->next = prev->right ; 
                curr = curr->next ; 
            }
            prev = prev->next ; 
        }
        //cout<<endl ; 
        curr->next = NULL ; 
    }
    
}
