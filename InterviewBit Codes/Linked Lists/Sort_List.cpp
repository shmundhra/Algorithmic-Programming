// https://www.interviewbit.com/problems/sort-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Merge ( ListNode *A , ListNode *B )
{
    ListNode *C , *tmp , *currA , *prevA , *currB , *prevB ; 
    
    prevA = NULL ; currA = A ; 
    prevB = NULL ; currB = B ; 
    
    tmp = C = NULL ; 
    
    while ( currA && currB )
    {
        if ( currA->val < currB->val )
        {
            if ( tmp == NULL )
            {
                C = currA ; 
            }
            else
            {
                tmp->next = currA ; 
            }
            tmp = currA ; 
            currA = currA->next ; 
        }
        else
        {
            if ( tmp == NULL )
            {
                C = currB ; 
            }
            else
            {
                tmp->next = currB ; 
            }
            tmp = currB ; 
            currB = currB->next ; 
        }
    }
    if ( currA ) tmp->next = currA ; 
    else tmp->next = currB ; 
    
    return C ; 
}

ListNode* MergeSort ( ListNode* A )
{   
    if ( A->next == NULL ) return A ;       // BASE CASE 
        
    ListNode *tmp ; 
    
    int len = 0 ; 
    for ( tmp = A ; tmp ; tmp = tmp->next , len++ ) ; 

    int i ; 
    for ( tmp = A , i = 1 ; i < len/2 ; i++ , tmp = tmp->next ) ; 
    
    ListNode *left = MergeSort ( tmp->next ) ; 
    
    tmp->next = NULL ; 
    ListNode *right = MergeSort( A ) ; 
    
    return Merge( left , right ) ; 
}

 
ListNode* Solution::sortList(ListNode* A) {
    
    return MergeSort(A) ; 
}
