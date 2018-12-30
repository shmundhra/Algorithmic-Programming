// https://www.interviewbit.com/problems/copy-list/

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
typedef RandomListNode RLN ; 

RandomListNode* Solution::copyRandomList(RandomListNode* A) {
        
    RandomListNode *B , *prev ;
    prev = NULL ; 
    
    RandomListNode *tmp , *tmp1 ; 
    tmp = A ;
    
    while(tmp)
    {
        RandomListNode *N = new RandomListNode(tmp->label) ; 
        N->random = tmp->random ; 
        
        tmp1 = tmp->next ; 
        tmp->next = N ; 
        tmp = tmp1 ; 
        
        if ( prev == NULL ) 
        {   
            B = N ; 
        }
        else 
        {
            prev->next = N ; 
        }
        prev = N ;
        //cout<<N->label<<" -> "<<( (N->random)?((N->random)->label) : NULL) << "  " ; 
    }
    
    tmp1 = B ; 
    while(tmp1)
    {   
        if (tmp1->random) tmp1->random = (tmp1->random)->next ; 
        tmp1 = tmp1->next ; 
    }
    
    return B ; 
    
}
