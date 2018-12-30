// https://www.interviewbit.com/problems/reorder-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    
    int len = 0 ; 
    ListNode *tmp ; 
    
    for ( tmp = A ; tmp != NULL ; tmp = tmp->next , len++ ) ; 
    
    ListNode *prev , *curr , *forw ;
    
    prev = NULL ; 
    curr = A ; 
    for ( int i = 1 ; i <= len/2 ; i++ )
    {
        prev = curr ; 
        curr = curr->next ; 
    }
    
    while ( curr )
    {
        forw = curr->next ; 
        curr->next = prev ; 
        
        prev = curr ; 
        curr = forw ; 
    }
    
    ListNode *rev = prev ; 
    ListNode *revprev = NULL ; 
   
    curr = A ; 
    
    while ( curr != rev and curr != rev->next  )
    {
        revprev = rev ; 
        rev = rev->next ; 
        
        revprev->next = curr->next ; 
        curr->next = revprev ; 
        curr = revprev ->next ; 
    }
    if ( rev != NULL ) rev->next = NULL ; 
    
    return A ; 
    
}
