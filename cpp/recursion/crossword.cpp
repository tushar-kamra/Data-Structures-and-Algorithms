#include<iostream>
#include<vector>

using namespace std ;

bool canPlaceHorizontal(vector< vector<char> > board, string word, int r, int c){

    cout << "func1\n" ;

    if(c == 0 && word.length() != board[0].size()){
        if(board[r][c+word.length()] != '+'){
            return false ;
        }
    }
    else if( (c+word.length()) == board[0].size() && word.length()!=board[0].size() ){
        if( board[r][c-1] != '+'){
            return false ;
        }
    }
    else {
        if( board[r][c-1] != '+' || board[r][c+word.length()] != '+'){
            return false ;
        }
    }

    for(int i=0; i<word.length(); i++){
        if( !(board[r][c+i] == '-' || word[i] == board[r][c+i]) ){
            return false ;
        }
    }
    return true ;
}

vector<bool> placeHorizontal(vector< vector<char> > board, string word, int r, int c){

    cout << "func2\n" ;
    vector<bool> pos(word.length(),false) ;
    for(int i=0; i<word.length(); i++){
        if(board[r][c+i] == '-'){
            board[r][c+i] = word[i] ;
            pos[i] = true ;
        }
    }
    return pos ;
}

void unplaceHorizontal(vector< vector<char> > board, string word, int r, int c, vector<bool> pos){

    cout << "func3\n" ;
    for(int i=0; i<word.length(); i++){
        if(pos[i]){
            board[r][c+i] = '-' ;
        }
    }
}

bool canPlaceVertical(vector< vector<char> > board, string word, int r, int c){

    cout << "func4\n" ;
    
    if(r == 0 && word.length() != board.size()){
        if(board[r+word.length()][c] != '+'){
            return false ;
        }
    }
    else if( (r+word.length()) == board.size() && word.length()!=board.size() ){
        if( board[r-1][c] != '+'){
            return false ;
        }
    }
    else {
        if( board[r-1][c] != '+' || board[r+word.length()][c] != '+'){
            return false ;
        }
    }

    for(int i=0; i<word.length(); i++){
        if( !(board[r+i][c] == '-' || word[i] == board[r+i][c]) ){
            return false ;
        }
    }
    return true ;
}

vector<bool> placeVertical(vector< vector<char> > board, string word, int r, int c){

    cout << "func5\n" ;
    vector<bool> pos(word.length(),false) ;
    for(int i=0; i<word.length(); i++){
        if(board[r+i][c] == '-'){
            board[r+i][c] = word[i] ;
            pos[i] = true ;
        }
    }
    return pos ;
}

void unplaceVertical(vector< vector<char> > board, string word, int r, int c, vector<bool> pos){

    cout << "func6\n" ;
    for(int i=0; i<word.length(); i++){
        if(pos[i]){
            board[r+i][c] = '-' ;
        }
    }
}

int crossword(vector< vector<char> > board, vector<string> words, int idx){
    if(idx == words.size()){
        for(vector<char> ar : board){
            for(char ele : ar){
                cout << ele <<" " ;
            }
            cout << endl ;
        }
        return 1 ;
    }
    string word = words[idx] ;
    int count = 0 ;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(canPlaceHorizontal(board,word,i,j)){
                vector<bool> pos = placeHorizontal(board,word,i,j) ;
                count += crossword(board,words,idx+1) ;
                unplaceHorizontal(board,word,i,j,pos) ;
            }
            if(canPlaceVertical(board,word,i,j)){
                vector<bool> pos = placeVertical(board,word,i,j) ;
                count += crossword(board,words,idx+1) ;
                unplaceVertical(board,word,i,j,pos) ;
            }
        }
    }
    return 0 ;
}

int main(){
    vector< vector<char> > board = {
        {'+','+','+','+','+','+'},
        {'+','+','-','-','-','+'},
        {'+','+','+','+','+','+'},
    };
    vector<string> words = {"bat"} ;
    cout << crossword(board,words,0) ;
}