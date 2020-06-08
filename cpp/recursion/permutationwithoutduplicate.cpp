#include<iostream>
#include<algorithm>
#include<vector>
using namespace std ;

vector<string> v ;
void permutation(string s, string ans){
    if(s.length() == 0){
        v.push_back(ans) ;
        return ;
    }
    int a[256] = {0} ;
    for(int i=0; i<s.length(); i++){
        char ch = s[i] ;
        if(a[ch-'\0']==0){
            a[ch-'\0'] = 1 ;
        }
        else {
            continue ;
        }
        string one = s.substr(0,i);
        string two = s.substr(i+1);

        permutation(one+two,ans+ch) ;
    }
    return  ;
}

int main(){
    string s ;
    cin >> s ;
    sort(s.begin(), s.end()) ;
    permutation(s,"") ;
    cout << v.size() << endl ;
    for(int i=0; i<v.size(); i++){
        cout << v[i] << endl ;
    }
}