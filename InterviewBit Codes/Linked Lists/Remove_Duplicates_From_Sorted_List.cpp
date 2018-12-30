// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    ListNode *prev , *curr , *forw  ; 
    
    prev = NULL ;
    curr = A ; 
    
    while ( A )
    {
        forw = curr->next ; 
        
        if ( forw == NULL ) break ; 
        
        if ( curr->val == forw->val )
        {
            if ( prev == NULL ) A = forw ; 
            else prev->next = forw ;
            
            curr = forw ; 
        }
        else
        {
            prev = curr ; 
            curr = forw ; 
        }
    }
    
    return A ; 
    
}
