//https://codeforces.com/contest/907/problem/C

#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
using namespace std; 

typedef unsigned long long ul ;
typedef long long ll ;

typedef pair<ll, ll>  pll ;
typedef pair< ll , pll > edge ; 
typedef vector < ll > uwg ;
typedef vector < pll > wg ;

#define scu(x) ul x ; scanf("%llu", &x)  
#define scl(x) ll x ; scanf("%lld", &x)  
#define pr(x) printf("%llu", x)  
#define rep(i , a , b , n) for(ll i = a; i < b ; i += n )
#define f first 
#define s second
#define pb push_back
#define mp make_pair
#define tc(t) ul t ; cin>>t ; while ( t-- )

void print ( int arr[26] )
{
    rep ( k , 0 , 25 , 1 )
        cout<<arr[k] ;
    cout<<endl;
    rep ( k , 0 , 25 , 1 )
        cout<<(char)(k+'a') ;
    cout<<endl;
    
}

int main() {
   
    scl(n) ; 
    int a[26] = {0} ; 
    int b[26] ; 
    char c ; 
    string s ;
    int len = 26 ;
    ll flag ; 
    ll pos ; 
    rep ( i , 0 , n-1 , 1)
    {
        cin>>c;cin>>s;
        if ( c == '.' || c == '?')
        {
            rep ( j , 0 , s.size() , 1 )
            {
                if ( a[ s[j]-'a' ] == 0 ) 
                    len -- ; 
                
                a[ s[j]-'a' ] =  1 ;        
            }
        }
        else
        {
            rep ( j , 0 , 26 , 1)
                b[j] =  1 ; 
                
            flag = 0 ; 
            rep ( j , 0 , s.size() , 1 )
            {
                if ( a[ s[j]-'a' ] !=  1 && b[ s[j]-'a' ] != 0  )
                {
                    b[ s[j]-'a' ] = 0 ; 
                    flag ++ ; 
                }
            }
            len = flag ; 
            rep ( j , 0 , 26 , 1 )
                a[j] = b[j] ; 
        }
        
        pos = i ; 
        if ( len < 2 ) break ; 
    }
    
    
    ll count = 0 ; 
    rep ( j , pos+1 , n-1 , 1 )
    {
        cin>>c;
        cin>>s;
        if ( c != '.') count++ ;
    }
    
    cout<<count ; 
	return 0;
}
















