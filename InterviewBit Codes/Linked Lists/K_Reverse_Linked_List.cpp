// https://www.interviewbit.com/problems/k-reverse-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    
    /*
    ListNode *start , *end , *prev , *curr ; 
    
    int k = B ;                                 //Blockwise reversal 
    
    start = NULL ; 
    end = A ; 
    
    while(end)
    {
        for ( int i = 1 ; i < k  and end ; i++ , end = end->next ) ; 
        
        prev = start ; 
        curr = (prev)?prev->next : A ; 
        
        start = end ; 
        if(end) end = end->next ; 
        
        if(start) start->next = NULL ; 
        
        if(prev) prev->next = Reverse(curr) ; 
        else A = Reverse(curr) ; 
        
        curr->next = end ;
        start = curr ; 
    }
    
    return A ; */
}
