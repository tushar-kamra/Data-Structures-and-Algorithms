#include <iostream>
#include <climits>
using namespace std;

int main() {
	// your code goes here
	int t ;
	cin >> t ;
	while(t--){
	    int n, minValue = INT_MAX, minIndex, ans = 0 ;
	    cin >> n ;
	    int c[n] ;
	    for(int i=0; i<n; i++){
	        cin >> c[i] ;
	    }
	    while(true){
	        if(n <= 0){
	            break ;
	        }
	        for(int i=0; i<n; i++){
	            if(c[i] <= minValue){
	                minValue = c[i] ;
	                minIndex = i ;
	            }
	        }
	        ans += n ;
	        if(minValue == 1){
	            n = minIndex ;
	        }
	        for(int i=0; i<n; i++){
	            c[i] -= 1 ;
	        }
	    }
	    cout << ans << endl ;
	}
	return 0;
}
