#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll ;

ll countDivisors(ll n) 
{ 
    ll cnt = 0; 
    for (ll i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            // If divisors are equal, 
            // count only one 
            if (n / i == i) 
                cnt++; 
  
            else // Otherwise count both 
                cnt = cnt + 2; 
        } 
    } 
    return cnt; 
} 

int main() {
	// your code goes here
	int t ;
	cin >> t ;
	while(t--){
	    ll a,b, c  ;
	    cin >> a >> b ;
	    int r = abs(a-b) ;
	    c = countDivisors(r) ;
	    cout << c << endl ;
	}
	return 0;
}