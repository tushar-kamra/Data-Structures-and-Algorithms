#include<iostream>
using namespace std ;

void asciisubs(string s, string ans){
    if(s.length() == 0){
        cout << ans << " " ;
        return ;
    }
    char ch = s[0] ;
    string str = s.substr(1) ;
    asciisubs(str,ans+ch);
    asciisubs(str,ans+to_string(ch-'a'+97));
    asciisubs(str,ans);
    return ;
}

int main(){
    string s ;
    cin >> s ;
    asciisubs(s,"");
}