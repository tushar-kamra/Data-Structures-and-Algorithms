#include<iostream>
#include<vector>
using namespace std ;

void nokiakeypad(int idx, string num, vector<string> codes, string ans){
    if(idx == num.length()){
        cout << ans <<" ";
        return ;
    }
    string letter = codes[num[idx]-'0'];
    for(int i=0; i<letter.length(); i++){
        nokiakeypad(idx+1,num,codes,ans+letter[i]);
    }
}

int main(){
    string num ;
    cin >> num ;
    vector<string> codes = {"+","abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz"} ;
    nokiakeypad(0,num, codes, "") ;
}