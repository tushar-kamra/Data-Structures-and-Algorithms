#include<iostream>
#include<vector>
using namespace std ;

void nokiakeypad(vector<string> keypad, string num, int idx, string ans){
    if(idx == num.length()){
        cout << ans << endl ;
        return ;
    }
    string res = keypad[num[idx]-'0'] ;
    for(int i=0; i<res.length(); i++){
        char ch = res[i] ;
        nokiakeypad(keypad,num,idx+1,ans+ch);
    }
}

int main(){
    string num ;
    cin >> num ;
    vector<string> keypad = {"+","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz","#"} ;
    nokiakeypad(keypad,num,0,"");
}