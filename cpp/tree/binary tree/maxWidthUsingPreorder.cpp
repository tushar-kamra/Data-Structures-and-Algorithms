#include<iostream>
#include<queue>
using namespace std ;

struct Node {
    int data ;
    Node* left ;
    Node* right ;
};

Node* createNode(int x){
    Node* temp = new Node() ;
    temp->data = x ;
    temp->left = NULL ;
    temp->right = NULL ;
    return temp ;
}

Node* insertNode(Node* root, int x){
    if(root == NULL){
        root = createNode(x) ;
        return root ;
    }
    queue<Node*> q ;
    q.push(root) ;
    while(!q.empty()){
        Node* temp = q.front() ;
        q.pop() ;
        if(!temp->left){
            temp->left = createNode(x) ;
            break ;
        }
        else {
            q.push(temp->left) ;
        }
        if(!temp->right){
            temp->right = createNode(x) ;
            break ;
        }
        else {
            q.push(temp->right) ;
        }
    }
    return root ;
}

int height(Node* root){
    if(root == NULL){
        return 0 ;
    }
    int lh = height(root->left) ;
    int rh = height(root->right) ;
    return max(lh,rh)+1 ;
}

int getMax(int count[], int h){
    int maxi = 0 ;
    for(int i=0; i<h; i++){
        if(count[i] > maxi){
            maxi = count[i] ;
        }
    }
    return maxi ;
}

void maxWidthRecur(Node* root, int level, int count[]){
    if(root){
        count[level]++ ;
        maxWidthRecur(root->left,level+1,count) ;
        maxWidthRecur(root->right,level+1,count) ;
    }
}

int maxWidth(Node* root){
    int h = height(root) ;
    int count[h] = {} ;
    maxWidthRecur(root,0,count) ;
    return getMax(count,h) ;
}

int main(){
    Node* root = NULL ;
    root = insertNode(root,2);
    root = insertNode(root,4);
    root = insertNode(root,1);
    root = insertNode(root,8);
    root = insertNode(root,6);
    root = insertNode(root,5);
    root = insertNode(root,7);
    root = insertNode(root,9);
    root = insertNode(root,11);
    root = insertNode(root,16);
    root = insertNode(root,25);
    root = insertNode(root,27);
    root = insertNode(root,3);
    root = insertNode(root,17);

    cout << "Max width : "<<maxWidth(root) ;
}