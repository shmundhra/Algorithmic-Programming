// https://www.interviewbit.com/problems/insertion-sort-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    
    ListNode *tmp1 , *tmp , *prev , *curr ; 
    
    tmp1 = A ; 
    while( tmp1 )
    {
        tmp = tmp1 ; 
        tmp1 = tmp->next ; 
        
        prev = NULL ; 
        curr = A ; 
           
        while( curr != tmp )
        {
            if ( curr->val > tmp->val )
            {
                if(prev == NULL ) A = tmp ; 
                else prev->next = tmp ; 
                
                tmp->next = curr ; 
                
                while ( curr->next != tmp ) curr = curr->next ; 
                break ; 
            }
            else
            {
                prev = curr ; 
                curr = curr->next ; 
            }
        }
        curr->next = tmp1 ; 
    }
 
    return A ; 
    
}
