#include <iostream>
#include <climits>
using namespace std;

int main() {
	// your code goes here
	int t ;
	cin >> t ;
	while(t--){
	    int n, mini = INT_MAX ;
	    cin >> n ;
	    int a[n] ;
	    for(int i=0; i<n; i++){
	        cin >> a[i] ;
	    }
	    for(int i=0; i<n; i++){
	        if(a[i]<mini){
	            mini = a[i] ;
	        }
	    }
	    cout << mini << endl ;
	}
	return 0;
}
