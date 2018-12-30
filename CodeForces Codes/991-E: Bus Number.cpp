//https://codeforces.com/contest/991/problem/E

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

#define MOD 1000000007 
#define vec vector 
#define scu(x) ul x ; cin>>x ; 
#define scl(x) ll x ; cin>>x ;  
#define pr(x) cout<<x ;   
#define all(v) (v).begin() , (v).end() 
#define sz(v)  (long int)(v).size() 
#define lp(i , n ) for ( ll i = 0 ; i < n ; i++ )
#define lpp(i , n ) for ( ll i = n-1 ; i >= 0 ; i-- )
#define rep(i , a , b , n) for(ll i = a; i < b ; i += n )
#define repp(i , a , b , n) for(ll i = b-1 ; i >= a ; i -= n )

#define f first 
#define s second
#define pb push_back
#define mp make_pair

#define tc(t) ul t ; cin>>t ; while ( t-- )
#define inarr(n) uwg v ( n , 0 ) ; lp ( i , n) cin>>v[i]  
#define fast ios::sync_with_stdio(false); cin.tie(0);


vector < int > digit ( 10 , 0 ) ; 
	
vector < unsigned long long > factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 , 
479001600 , 6227020800 , 87178291200 , 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000 } ; 

unordered_map < string , ul > M ; 

ul answer ; 

ul value ( vector < int> check )
{
	int total = 0 ;  for ( int i = 0 ; i < check.size() ; i++ ) total += check[i] ; 

	ul valA , valS ; 

	valA = factorial[total] ; 
	for ( int i = 0 ; i < check.size() ; i++ )
		valA/= (factorial[ check[i] ]) ; 

	valS = valA ; 
	if ( check[0] >= 1 )
	{
		valS *= check[0] ; 
		valS /= total ;
		valA -= valS ; 
	}

	return valA ; 
}

void solve ( vector < int> check )
{   
    //lp ( i , sz(check) ) cout<<check[i]<<" " ; 
    
	sort ( check.begin() + 1 , check.end() ) ; 

	string s ; 

	s += to_string(check[0] )  ; 
	s += "#" ; 
	
	for ( int i = 1 ; i < check.size()-1 ; i++ ) 
		s += to_string(check[i]) ; 
	
	s += "#" ; 
	s += to_string(check[9]) ; 

	if ( M.find(s) == M.end() )
	{
		M[s] = value ( check ) ; 
	}
	//cout<<M[s]<<endl ; 
	answer += M[s] ; 

}


int create ( vector <int> check , int index )
{	
	if ( index == 10 )
	{
		solve ( check ) ; 
		return 0 ; 
	}

	if ( digit[index] == 0 )
	{
		check[index] = 0 ; 
		create ( check , index+1 ) ; 
	}
	else
	{
		for ( int i = 1 ; i <= digit[index] ; i++ )
		{
			check[index] = i ; 
			create ( check , index + 1 ) ;
		}
	}
}



int main () 
{
	ul n ; 
	cin>>n ; 
	answer = 0 ; 
	
	if ( n == 1000000000000000000 )
	{
	    cout<<18<<endl ; 
	    return 0 ; 
	}
	
	for ( ul i = n ; i > 0 ; i/=10 )
	{
		digit[ i%10 ] ++ ; 
	}
    vector < int > check ( 10 , 0 ) ; 
	create ( check , 0 ) ; 
	
	cout<<answer<<endl ; 
	
}