// https://www.interviewbit.com/problems/add-two-numbers-as-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    
    ListNode *a , *b , *start ; 
    
    a = A ; 
    b = B ; 
    start = NULL ; 
    int carry = 0 ; 
    while ( a and b )
    {   
        int temp = ( a->val + b->val + carry ) ;
        carry  = temp/10 ; 
        a->val = temp%10 ; 
        
        start = a ; 
        
        a = a->next ; 
        b = b->next ; 
    }
    
    if ( b ) start->next = b ;
   
    while ( start -> next )
    {
        int temp = (start->next)->val + carry ; 
        carry = temp / 10 ; 
        (start->next) -> val = temp%10 ; 
        
        start = start->next ; 
    }
    
    if ( carry )
    {
        ListNode *N = new ListNode(carry) ;
        start->next = N ; 
    }
    
    return A ; 
    
}
