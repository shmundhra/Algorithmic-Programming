// https://www.interviewbit.com/problems/search-for-a-range/

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    long long low , high , mid  ; 
    
    low = 0 ; 
    high = A.size()-1;
    
    while ( low <= high )
    {
        mid = low + ( high - low  ) / 2 ; 
        
        if ( A[ mid ] >= B )
        {
            high = mid - 1  ; 
        }
        else
        {
            low = mid ; 
        }
    }
    
    int LEFT = high ; 
    
    
    
    low = LEFT + 1 ; 
    high =  A.size()-1 ;
    
    while ( low < high )
    {
        mid = low + ( high - low  ) / 2 ;
        
        if ( A[mid) == B && A[mid-1] < B 

    break ; 
    
else
{
    if ( A[mid) < B 
 low = mid + 1 ; 
    else high = mid - 1 ;
}
        
        
        if ( A[ mid ] <= B )
        {
            low = mid + 1  ; 
        }
        else
        {
            high = mid ; 
        }
    }
    
    int RIGHT = low ; 
    
    int ans = RIGHT - LEFT + 1 ; 
    
    
    
    /*
    int L ; 
    if ( A[0] == B )
        L = 0 ; 
    else
    {
        low = 1 ; 
        high = A.size()-1;
        
        while ( low <= high )
        {
            mid = low + ( high - low  ) / 2 ;
            
            if ( A[mid] == B && A[mid-1] < B )
            {   
                L = mid ; 
                break ; 
            }    
            else
            {
                if ( A[mid] < B ) low = mid + 1 ; 
                else high = mid - 1 ;
            }
        }
        if ( high < low ) 
        {
            vector < int > v = { -1 , -1 } ; 
            return v ; 
        }
    }
    
    int R ; 
    if ( A[A.size()-1] == B )
        R = A.size()-1 ; 
    else
    {
        low = L ; 
        high = A.size()-2;
        
        while ( low <= high )
        {
            mid = low + ( high - low  ) / 2 ;
            
            if ( A[mid] == B && A[mid+1] > B )
            {   
                R = mid ; 
                break ; 
            }    
            else
            {
                if ( A[mid] > B ) high = mid - 1 ; 
                else low = mid + 1 ;
            }
        }
    }
    vector < int > v = { L , R } ; 
    return v ; 
    */
    
}
