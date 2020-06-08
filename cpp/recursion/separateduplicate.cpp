#include<iostream>
using namespace std ;

string separate(string s, int idx, string ans){
    if(idx == s.length()-1){
        ans += s[idx] ;
        return ans ;
    }
    if(s[idx]==s[idx+1]){
        ans += s[idx] ;
        ans += "*" ;
    }
    else {
        ans += s[idx] ;
    }
    return separate(s,idx+1,ans);
}

void print(string s, int idx, int i){
    if(idx == i) {
        cout << s[idx] << endl;
        return ;
    }
    print(s,idx+1,i) ;
}

int main(){
    string s ;
    int i ;
    cin >> s >> i ;
    string ans = "" ;
    ans = separate(s,0,ans) ;
    print(s,0,i) ;
    cout << ans ;
}