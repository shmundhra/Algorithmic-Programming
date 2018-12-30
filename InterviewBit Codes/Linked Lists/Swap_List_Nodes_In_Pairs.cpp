// https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    
    if(A == NULL ) return A ; 
    
    ListNode *tmp1 , *tmp2 ; 
    ListNode *prev , *end ; 
    
    tmp1 = A ;
    prev = NULL ; 
    
    while ( tmp1 )
    {   
        tmp2 = tmp1->next ;
        if ( tmp2 == NULL ) break  ; 
        
        end = tmp2->next ;
        
        tmp2->next = tmp1 ; 
        tmp1->next = end ; 
        
        if ( prev ) prev->next = tmp2 ; 
        else A = tmp2 ;  
        
        prev = tmp1 ; 
        tmp1 = end ; 
    }
    return A ; 
}
