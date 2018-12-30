// https://www.interviewbit.com/problems/list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if ( A       == NULL ) return NULL ; 
    if ( A->next == NULL ) return NULL ; 
    
    int len = 0 ; 
    ListNode *prev , *curr , *forw ; 
  
    prev = NULL ; 
    curr = A ; 
    
    while( curr )
    {   
        len++ ; 
        forw = curr->next ;
        curr->next = prev ; 
        prev = curr ; 
        curr = forw ; 
    }
    
    if ( A->next == NULL ) return NULL ; 
    
    int i ; 
    for ( curr = A , i = 1 ; i < len/2 ; i++ )
    {
        curr = curr -> next ; 
    }
    
    int loop = 0 ; 
    prev = curr ; 
    
    do 
    {   
        if ( curr == NULL ) return NULL ; 
        loop++ ; 
        curr = curr->next ; 
    }while(prev!=curr) ; 
    
    loop-- ; 
    //cout<<len<<" "<<prev->val<<" "<<loop<<" " ; 
    
    for ( curr = A , i = 1 ; i < (len - loop)/2 ; i++ )
    {
        curr = curr -> next ; 
    }
    return curr ; 
    
}
