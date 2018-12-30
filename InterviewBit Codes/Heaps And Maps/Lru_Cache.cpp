// https://www.interviewbit.com/problems/lru-cache/

struct Node { 
 int val ; Node *next ; Node *prev ; Node(int x) : val(x) , next(NULL) , prev(NULL) {} ; 
} ; 

Node  *front , *rear ; 

bool isempty(  )
{
    if ( front == NULL ) return true ; return false ; 
}
 
Node* pusher ( int x )
{
    Node *N = new Node ( x ) ; 
    
    if ( isempty(front,rear ) )
    {
        front = N ; 
        rear =  N ; 
    }
    else
    {   
        rear->prev = N ; 
        N->next = rear ; 
        rear = N ; 
    }
    
    return N ; 
}
 
int last ( )
{
    return rear->val ; 
}
 
void popper (  )
{   
    Node *tmp = rear ; 
    
    if ( front == rear )
    {
        front = NULL ; 
        rear = NULL ; 
    }
    else
    {   
        rear = rear->next ; 
        rear->prev = NULL ; 
    }
    
    delete tmp ; 
}
 
int first ( ) 
{
    return front->val ; 
}
 
void puller (  ) 
{   
    Node *tmp = front ; 
    
    if ( front == rear )
    {
        front = NULL ; 
        rear = NULL ; 
    }
    else
    {
        front = front ->prev ;
        front -> next = NULL ;
    }
    
    delete tmp ; 
}
 
void display (  )
{
    for ( Node *tmp = rear ; tmp ; tmp = tmp->next )
    {
        cout<<tmp->val<<" " ; 
        
    }cout<<endl ; 
    
}


unordered_map < int , int   > MAIN ; 
unordered_map < int , Node* > AUX ; 

long LEN ; long HeapSize ; , int number ;  

LRUCache::LRUCache(int capacity) {
    MAIN.clear()  ;   AUX.clear() ; 
    front = NULL ; rear = NULL ; 
    LEN = capacity ; number = 0 ;   
}

int LRUCache::get(int key) {
    
    if ( MAIN.find(key) == MAIN.end() )
    {   
        return -1 ; 
    }
    else 
    {  
        Node *tmp1 , *tmp2 , *tmp3 ; 
        
        tmp1 = AUX[key] ; 
        tmp2 = tmp1->prev ; 
        tmp3 = tmp1->next ; 
        
        if ( tmp2 ) tmp2->next = tmp3 ; 
        else rear = tmp3 ; 
        
        if ( tmp3 ) tmp3->prev = tmp2 ; 
        else front = tmp2 ; 
        
        delete tmp1 ; 
        
        AUX[key] = pusher(key);
        
        return MAIN[key] ; 
    }
}

void LRUCache::set(int key, int value) {
    
    if ( MAIN.find(key) != MAIN.end() )     {   
        
        MAIN[key] = value ;
        
        Node *tmp1 , *tmp2 , *tmp3 ; 
        
        tmp1 = AUX[key] ; 
        tmp2 = tmp1->prev ; 
        tmp3 = tmp1->next ; 
        
        if ( tmp2 ) tmp2->next = tmp3 ; 
        else rear = tmp3 ; 
        
        if ( tmp3 ) tmp3->prev = tmp2 ; 
        else front = tmp2 ; 
        
        delete tmp1 ; 
        
        AUX[key] = pusher(key);
       
    }
    else 
    {   
        if ( number == LEN )
        {   
            number-- ; 
            
            int delKey = first() ;
            
            D.puller() ; 
            
            MAIN.erase(delKey) ; 
             AUX.erase(delKey) ; 
           
        }    
      
        MAIN[key] = value ; 
        
        AUX[key] = pusher(key);
       
        number ++ ; 
        
    }

}