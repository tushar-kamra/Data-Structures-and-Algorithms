#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int counthi(string s, int idx){
    if(idx>s.length()-2) return 0 ;
    if(s[idx]=='h' && s[idx+1]=='i'){
        return 1+counthi(s,idx+2);
    }
    return counthi(s,idx+1);
}

string removehi(string s, int idx){
    if(idx>s.length()-2) return s ;
    if(s[idx]=='h' && s[idx+1]=='i'){
        s.erase(s.begin()+idx) ;
        s.erase(s.begin()+idx) ;
        idx-- ;
    }
    return removehi(s,idx+1);
}

int main() {
    string s ;
    cin >> s ;
    int i ;
    cin >> i ;
    cout << counthi(s,0) << endl ;
    string ans = "" ;
    ans = removehi(s,0) ;
    cout << ans[i] << endl ;
    cout << ans ;
    return 0;
}
