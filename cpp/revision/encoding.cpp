#include<iostream>
using namespace std ;

void encoding(string num, string ans){
    if(num.length() == 0){
        cout << ans << endl ;
        return ;
    }
    int num1 = num[0]-48 ;
    if(num1 != 0){
        encoding(num.substr(1),ans+char('a'+num1-1));
    }
    else {
        encoding(num.substr(1),ans) ;
    }
    if(num.length() > 1){
        int num2 = num1*10 + num[1] - 48 ;
        if(num2 <= 26){
            encoding(num.substr(2),ans+char('a'+num2-1)) ;
        }
    }
}

int main(){
    string num ;
    cin >> num ;
    encoding(num,"") ;
}