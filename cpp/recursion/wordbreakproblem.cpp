#include<iostream>
#include<vector>
using namespace std ;

bool ispresent(string str, vector<string> dict){
    for(string s : dict){
        if(s == str) return true ;
    }
    return false ;
}

int wordbreakcount(vector<string> dict, string statement, string ans){
    if(statement.length() == 0){
        cout << ans <<"\n" ;
        return 1 ;
    }
    int count = 0 ;
    for(int i=1; i<=statement.length(); i++){
        string str = statement.substr(0,i) ;
        if(ispresent(str,dict)){
            count += wordbreakcount(dict, statement.substr(i,statement.length()-i), ans+str+" ");
        }
    }
    return count ;
}

int main(){
    string statement ;
    vector<string> dict = {"mobile","samsung","sam","sung", "man","mango", "icecream","and", "go","i","love","ice","cream","like","likes"} ;
    cin >> statement ;
    cout << wordbreakcount(dict,statement,"") << endl ;
}