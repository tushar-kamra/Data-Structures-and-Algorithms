#include<iostream>
using namespace std ;

/*
string move(string s, char ch, int l, int r){
    if(l >= r) return s ;
    if(s[l] == ch){
        swap(s[l], s[r]);
        return move(s,ch,l+1,r-1);
    }
    return move(s,ch,l+1,r) ;
}
*/

string move(string s, char ch, int l, int r){
    if(l >= r) return s ;
    if(s[l] == ch){
        s += s[l] ;
        s.erase(s.begin()+l);
        l-- ;
        return move(s,ch,l+1,r-1);
    }
    return move(s,ch,l+1,r) ;
}

int main(){
    string s ;
    char ch ;
    int i ;
    cin >> s >> ch >> i ;
    string ans = move(s,ch,0,s.length()-1);
    cout << ans[i] << endl;
    cout << ans ;
}