#include<iostream>
using namespace std ;

int countpermutation(string s, string ans){
    if(s.length() == 0){
        cout << ans << " " ;
        return 1 ;
    }
    
    int count = 0 ;
    
    for(int i=0; i<s.length(); i++){
        char c = s[i] ;
        string restStr = s ;
        restStr.erase(restStr.begin()+i) ;
        count += countpermutation(restStr,ans+c) ;
    }
    return count ;
}

int main(){
    string s ;
    cin >> s ;
    cout << countpermutation(s,"");
}