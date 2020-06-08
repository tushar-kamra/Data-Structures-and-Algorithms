#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long long ll ;

int main() {
	int t ;
	cin >> t ;
	while(t--){
	    int n ; 
	    cin >> n ;
	    ll a,b,c,d,e,s=1,z=1 ;
		for(int i=1; i<=n; i++){
			s *= 10 ;
		}
		z = s*2 ;
	    int res ;
	    cin >> a ;
	    cout << z+a << "\n" ;
	    fflush(stdout) ;
	    cin >> b ;
	    cout << s-b << "\n" ;
	    fflush(stdout) ;
	    cin >> d ;
	    cout << s-d << "\n" ;
	    fflush(stdout) ;
	    cin >> res ;
	    if(res == -1){
	        break ;
	    }
	    cout << endl ;
	    fflush(stdout) ;
	}
	return 0;
}
