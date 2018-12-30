// https://www.interviewbit.com/problems/merge-two-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Merge(ListNode* A, ListNode* B)
{ 
    if ( !A ) return B ; 
    if ( !B ) return A ; 
    
    ListNode *C ; 
    
    if ( A->val < B->val )
    {
        C = A ; 
        C->next = Merge(A->next , B ) ; 
    }
    else
    {
        C = B ; 
        C->next = Merge(B->next , A ) ; 
    }
    return C ; 
}
 
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    
    /*ListNode *tmp1 , *tmp2 , *tmp , *C ; 
    
    if ( A->val < B->val ) C = A ; 
    else C = B ; 
    
    tmp1 = A->next ; tmp2 = B->next ; 
    tmp = C ; 
    
    while ( tmp1 != NULL and tmp2 != NULL )
    {
        if ( (tmp1-> val) < (tmp2->val) )
        {
            tmp->next = tmp1 ; 
            tmp1 = tmp1->next;
        }
        
        else
        {
            tmp->next = tmp2 ; 
            tmp2 = tmp2->next;
        }
        tmp = tmp->next ;
        
    }
    
    if ( tmp1 != NULL ) tmp->next = tmp1 ; 
    else tmp->next = tmp2 ; 
    
    return C ; */
    
    ListNode* C = Merge ( A , B ) ; 
    
    return C ; 
    
}
