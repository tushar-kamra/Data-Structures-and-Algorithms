#include <iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int main() {
	// your code goes here
	int t ;
	cin >> t ;
	while(t--){
	    int n ;
	    cin >> n ;
	    string s ;
	    cin >> s ;
	    int lastOccurrence[26] ;
		int min = INT_MAX ;
		for(int i=0; i<26; i++){
			lastOccurrence[i] = -1 ;
		}
	    for(int i=0; i<n; i++){
			if(lastOccurrence[s[i]-'a'] == -1){
				lastOccurrence[s[i]-'a'] = i ;
			}
			else {
				int val = i - lastOccurrence[s[i]-'a'] ;
				lastOccurrence[s[i]-'a'] = i ;
				if(val < min){
					min = val ;
				}
			}
		}
		if(min == INT_MAX) cout << 0 << endl ;
		else {
			cout << n-min << endl ;
		}
	}
	return 0;
}
