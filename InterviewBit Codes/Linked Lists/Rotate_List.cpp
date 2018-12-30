// https://www.interviewbit.com/problems/rotate-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    
    if( A == NULL ) return NULL ; 
    
    ListNode *tmp , *end; 
    
    int len = 1 ;
    tmp = A ; 
    while ( tmp->next ) 
    {
        tmp = tmp->next ;
        len++ ; 
    }
    end = tmp ; 
    
    int num = len - (B%len) ; 
    
    int i ; 
    for ( tmp = A ,  i = 1 ; i < num ; i++ )
    {
        tmp = tmp->next ; 
    }
    
    end->next = A ; 
    A = tmp->next ; 
    tmp->next = NULL ; 
    
    return A ; 
}
