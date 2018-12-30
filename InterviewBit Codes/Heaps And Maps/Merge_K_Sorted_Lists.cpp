// https://www.interviewbit.com/problems/merge-k-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef pair <int , int> pii ; 

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    
    priority_queue < pii , vector< pii > , greater< pii >  > pq ; 
   
    for ( int i = 0 ; i < A.size() ; i++ )
    {
        pq.push(  make_pair( A[i]->val , i )  ) ; 
        A[i] = A[i]->next ; 
    }
    
    ListNode *R , *prev ; 
    R = NULL ; prev = NULL ; 
    
    while ( !pq.empty() )
    {   
        pii p = pq.top() ; 
        pq.pop() ; 
        
        ListNode *N = new ListNode( p.first ) ; 
        
        if ( prev == NULL )
        {
            R = N ; 
        }
        else
        {
            prev -> next = N ; 
        }
        prev = N ; 
        
        int i = p.second ; 
        if ( A[i] )
        {   
            pq.push(  make_pair( A[i]->val , i )  ) ; 
            A[i] = A[i]->next ; 
        }
       
    }
    return R ; 
    
}
