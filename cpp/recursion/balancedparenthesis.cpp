#include<iostream>
using namespace std ;

bool ismatch(char a, char b){
    if(a == '(' && b == ')') return true ;
    if(a == '{' && b == '}') return true ;
    if(a == '[' && b == ']') return true ;
    return false ;
}

bool isBalanced(string s, int i, int j){
    if(i>j){
        return true;
    }
    if(s[i] == ')' || s[i] == '}' || s[i] == ']' || s[j] == '(' || s[j] == '{' || s[j] == '['){
        return false ;
    }
    if(s[i] == '('){
        if(s[j] == ')' && s[j]!='}' && s[j]!=']'){
            return isBalanced(s,i+1,j-1);
        }
        if(s[j]!='}' && s[j]!=']'){
            return isBalanced(s,i,j-1);
        }
        return false ;
    }
    if(s[i] == '{'){
        if(s[j] == '}' && s[j]!=')' && s[j]!=']'){
            return isBalanced(s,i+1,j-1);
        }
        if(s[j]!=')' && s[j]!=']'){
            return isBalanced(s,i,j-1);
        }
        return false ;
    }
    if(s[i] == '['){
        if(s[j] == ']' && s[j]!=')' && s[j]!='}'){
            return isBalanced(s,i+1,j-1);
        }
        if(s[j]!=')' && s[j]!='}'){
            return isBalanced(s,i,j-1);
        }
        return false ;
    }
    return isBalanced(s,i+1,j-1) ;
}

int main(){
    string s ;
    cin >> s; 
    (isBalanced(s,0,s.length()-1))?cout << "true":cout << "false" ;
}