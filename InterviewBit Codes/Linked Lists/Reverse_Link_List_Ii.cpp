// https://www.interviewbit.com/problems/reverse-link-list-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    
    
    ListNode  *startR , *startL , *prev , *curr , *forw , *endR , *endL; 
    
    int i ; 
    
    prev = NULL ; 
    for ( i = 1 , curr = A ; i < B and curr ; i++ )
    {
        prev = curr ; 
        curr = curr->next ; 
    }
    
    startL = prev ; 
    startR = curr ; 
    
    for ( ; i <= C and curr ; i++ )
    {
        forw = curr->next ; 
        curr->next = prev ; 
        prev = curr ; 
        curr = forw ; 
    }
    
    endL = prev ; 
    endR = curr ; 
    
    
    if(startL != NULL ) 
        startL->next = endL ; 
    else
        A = endL ; 
        
    startR->next = endR ; 
    
    return A ; 
    
}
