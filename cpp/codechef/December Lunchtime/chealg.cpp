#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t ;
	cin >> t ;
	while(t--){
	    string s, ans ="" ;
	    cin >> s ;
	    int c = 1 ;
	    for(int i=0; i<s.length()-1; i++){
	        if(s[i] == s[i+1]){
	            c++ ;
	        }
	        else {
	            ans += s[i]+to_string(c) ;
	            c = 1 ;
	        }
	    }
        cout << ans << endl ;
	}
	return 0;
}
