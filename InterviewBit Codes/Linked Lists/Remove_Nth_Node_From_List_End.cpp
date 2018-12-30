// https://www.interviewbit.com/problems/remove-nth-node-from-list-end/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    
    /*if ( B == 0 ) return A ;
    
    ListNode *tmp = A ; 
    
    int len = 0 ; 
    while(tmp)
    {   
        len++ ; 
        tmp = tmp->next ;
    }
    
    int num = len - B ;
    
    if ( num < 1 ) return ( A->next) ; 
    
    int i ; 
    for ( i = 1 , tmp = A ; i < num ; i++ )
    {
        tmp = tmp->next ; 
    }
    tmp->next = (tmp->next)->next ; 
    
    return A ; */
    
    if ( !A or !B ) return A ; 
    
    ListNode *prev , *temp ; 
    
    temp = A ; prev = NULL ; 
    
    for ( int i = 1 ; i < B and temp->next ; i++ , temp = temp->next ) ; 
    
    while ( temp->next )
    {
        temp = temp->next ; 
        prev = prev ? (prev->next) : A ; 
    }
    
    if ( prev ) 
    {
        if ( prev->next )
        {
            prev->next = (prev->next)->next ; 
        }
    }
    else
    {
        if ( A )
        {
            A = A -> next ; 
        }
    }
    return A ; 
    
}
