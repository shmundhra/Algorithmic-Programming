// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    ListNode *prev , *curr , *forw ; 
    
    prev = NULL ; 
    curr = A ; 
    int flag = 0 ;
    
    while ( A )
    {
        forw = curr->next ; 
        
        if ( forw == NULL ) break ; 
        
        if ( (curr->val) == (forw->val) )
        {   
            flag = 1 ; 
            if ( prev == NULL ) A = forw ; 
            else prev->next = forw ; 
            
            curr = forw ;  
        }
        else
        {
            if ( flag == 1 )
            {
                if ( prev == NULL ) A = forw ; 
                else prev->next = forw ; 
            
                curr = forw ;  
                flag = 0 ; 
            }
            else
            {   
                prev = curr ; 
                curr = forw ; 
            }
        }
    }
    
    if ( flag == 1 )
    {
        if ( prev == NULL ) A = NULL ; 
        else prev->next = NULL ; 
    }
    
    
    return A ; 
}
