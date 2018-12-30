// https://www.interviewbit.com/problems/min-stack/

stack < int > elementStack ; 
stack < int > minimumStack ; 

MinStack::MinStack() {
    
    while ( !elementStack.empty() ) elementStack.pop() ; 
    while ( !minimumStack.empty() ) minimumStack.pop() ; 
}

void MinStack::push(int x) {
    
    elementStack.push(x) ; 
    //cout<<"\n"<<top()<<" " ; 
    
    if (  minimumStack.empty() or x <  minimumStack.top() )  
    {
        minimumStack.push(x) ; 
        //cout<<getMin()<<endl ;    
    }
}

void MinStack::pop() {
    
    if ( !elementStack.empty() )
    {
        if ( elementStack.top() ==  minimumStack.top() )  
        {   
            //cout<<"\n"<<getMin()<<" ";
            minimumStack.pop() ; 
        }
        //cout<<top()<<" "<<endl;
        elementStack.pop() ; 
    }
}

int MinStack::top() {
    
    if ( elementStack.empty() ) return -1 ; 
    return elementStack.top() ; 
}

int MinStack::getMin() {
    
    if ( minimumStack.empty() ) return -1 ; 
    return  minimumStack.top() ; 
}