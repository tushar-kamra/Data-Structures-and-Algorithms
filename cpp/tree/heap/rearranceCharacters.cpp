#include<iostream>
#include<queue>
#include<utility>

using namespace std ;

int main(){
    string s, ans = "" ;
    cin >> s ;
    int count[26] = {} ;
    for(int i=0; i<s.length(); i++){
        count[s[i]-'a']++ ;
    }
    priority_queue< pair<int,char> > pq ;
    for(int i=0; i<26; i++){
        if(count[i]){
            pq.push({count[i],'a'+i}) ;
        }
    }
    pair<int,char> prev = {-1,'#'} ;
    while (!pq.empty())
    {
        pair<int,char> p = pq.top() ;
        pq.pop() ;
        (p.first)-- ;
        ans += p.second ;

        if(prev.first > 0){
            pq.push(prev) ;
        }

        prev = p ;
    }

    if(ans.length() != s.length()){
        cout << "Not valid" ;
    }
    else {
        cout << ans ;
    }
}