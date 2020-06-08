#include<iostream>
using namespace std ;

void insertNode(char bt[], int idx, char key){
    if(bt[idx] == '\0'){
        bt[idx] = key ;
        return ;
    }
    if(bt[2*idx+1]=='\0'){
        return insertNode(bt,2*idx+1,key);
    }
    if(bt[2*idx+2]=='\0'){
        return insertNode(bt,2*idx+2,key);
    }
    return insertNode(bt,idx+1,key);
}

int main(){
    char bt[10]={} ;
    insertNode(bt,0,'A');
    insertNode(bt,0,'F');
    insertNode(bt,0,'G');
    insertNode(bt,0,'B');
    insertNode(bt,0,'K');
    for(int i=0; bt[i]!='\0'; i++){
        cout << bt[i] <<" " ;
    }
}