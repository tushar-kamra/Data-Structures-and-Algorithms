#include<iostream>
#include<vector>
using namespace std ;

vector<string> permutation(string s, vector<string> ans){
    if(s.length() == 0){
        ans.push_back("");
        return ans ;
    }

    char ch = s[0] ;
    string restStr = s.substr(1) ;

    vector<string> recAns = permutation(restStr,ans);

    for(int i=0; i<recAns.size(); i++){
        for(int j=0; j<=recAns[i].length(); j++){
            string one = recAns[i].substr(0,j);
            string two = recAns[i].substr(j);
            string res = one+ch+two ;
            ans.push_back(res) ;
        }
    }

    return ans ;
}

int main(){
    string s ;
    cin >> s ;
    vector<string> v ;
    v = permutation(s,v) ;
    for(int i=0; i<v.size(); i++){
        cout << v[i] <<" " ;
    }
}