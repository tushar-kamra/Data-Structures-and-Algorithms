#include<iostream>
#include<stack>
#include<queue>
#include<map>
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

void diagonal(Node* root){
    queue<Node*> q ;
    q.push(root) ;
    q.push(NULL) ;
    while(!q.empty()){
        Node* temp1 = q.front() ;
        q.pop() ;
        if(temp1 == NULL){
            cout << endl ;
            q.push(NULL) ;
            Node* temp2 = q.front() ;
            if(temp2 == NULL){
                break ;
            }
        }
        while(temp1 != NULL){
            cout << temp1->data <<" " ;
            if(temp1->left){
                q.push(temp1->left) ;
            }
            temp1 = temp1->right ;
        }
    }
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
    root = insertNode(root,15);
    root = insertNode(root,25);
    root = insertNode(root,27);
    root = insertNode(root,3);
    root = insertNode(root,17);

    diagonal(root) ;
}