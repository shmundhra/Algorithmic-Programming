// https://www.interviewbit.com/problems/palindrome-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    
    ListNode *tmp ; 
    int len = 0 ; 
    int i ; 
    
    tmp = A ; 
    while (tmp)
    {
        len++ ; 
        tmp = tmp->next ; 
    }
    
    for ( tmp = A , i = 0 ; i < len/2 ; i++ )
    {
        tmp = tmp->next ; 
    }
    
    ListNode *prev , *curr , *forw ; 
    
    prev = tmp ; 
    curr = tmp->next ;
    
    while ( curr )
    {
        forw = curr -> next ;
        curr->next = prev ; 
        prev = curr ; 
        curr = forw ; 
    }
    
    for ( tmp = A , i = 0 ; i < len/2 ; i++, tmp = tmp->next, prev = prev ->next )
    {
        if ( tmp -> val != prev->val ) return 0 ; 
    }
    
    return 1 ; 
    
    
    
}

