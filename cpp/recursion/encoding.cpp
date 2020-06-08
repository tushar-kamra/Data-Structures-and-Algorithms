#include<iostream>
using namespace std ;


void encoding(string s, string ans){
    if(s.length()==0){
        cout << ans <<"\n" ;
        return ;
    }
    string s1 = s.substr(0,1) ;
    string s2 ;
    if(s1 == "0"){
        encoding(s.substr(1), ans) ;
    }
    else {
        encoding(s.substr(1), ans+char('a'+(stoi(s1)-1)));
    }
    if(s.length()>1){
        s2 = s.substr(0,2) ;
        if(stoi(s2) <= 26){
            encoding(s.substr(2), ans+char('a'+(stoi(s2)-1)));
        }
    }
    return ;
}


/*
int encoding(string s, string ans){
    if(s.length() == 0){
        cout << ans << " " ;
        return 1 ;
    }
    char ch1 = s[0] ;
    int count = 0 ;
    if(ch1 == '0'){
        count += encoding(s.substr(1),ans);
    }
    else {
        count += encoding(s.substr(1),ans+char('a'+(ch1-'0')-1));
    }
    if(s.length()>1){
        char ch2 = s[1] ;
        int num = (ch2-'0')*10 + (ch1-'0') ;
        if(num <= 26){
            count += encoding(s.substr(2),ans+char('a'+(num-1)));
        }
    }
    return count ;
}
*/

int main(){
    string s ;
    cin >> s ;
    encoding(s,"") ;
}