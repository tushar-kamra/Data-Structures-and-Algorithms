#include<iostream>
#include<vector>
using namespace std ;

vector<string> subsequence(string s, vector<string> ans){
    // base condition
    if(s.length()==0){
        ans.push_back("");
        return ans ;
    }
    
    char ch = s[0] ;
    string restStr = s.substr(1) ;
    vector<string> recAns = subsequence(restStr,ans) ;
    
    for(int i=0; i<recAns.size(); i++){
        ans.push_back(recAns[i]);
        //ans.push_back(ch+recAns[i]);
    }
    
    for(int i=0; i<recAns.size(); i++){
        //ans.push_back(recAns[i]);
        ans.push_back(ch+recAns[i]);
    }
    
    return ans ;

}

int main(){
    string s ;
    cin >> s ;
    vector<string> v ;
    v = subsequence(s,v) ;

    for(int i=0; i<v.size(); i++){
        cout << v[i] << endl ;
    }
}