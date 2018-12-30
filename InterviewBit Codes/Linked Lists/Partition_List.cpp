// https://www.interviewbit.com/problems/partition-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int x) {
    
    ListNode  *B , *tmp ,  *currL , *currR ;  
    
    currL = currR = NULL ; 
    
    B = NULL ; 
    
    for ( tmp = A ; tmp ; tmp = tmp->next )
    {
        int num = tmp ->val ; 
        
        if ( num < x )
        {
            if ( currL == NULL )
            {
                currL = tmp ; 
                A = currL ; 
            }
            else
            {
                currL->next = tmp ; 
                currL = currL->next ; 
            }
        }
        else
        {
            if ( currR == NULL )
            {
                currR = tmp ; 
                B = currR ; 
            }
            else
            {
                currR->next = tmp ; 
                currR = currR->next ;
            }
        }
    }
    
    if ( currR ) (currR->next) = NULL ; 
    
    if ( currL ) (currL->next) = B ; 
    
    return A ; 
}
