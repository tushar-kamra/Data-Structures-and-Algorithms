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

void levelbylevel(Node* root){
    queue<Node*> q1, q2 ;
    q1.push(root) ;
    while(!q1.empty() || !q2.empty()){
        while(!q1.empty()){
            Node* temp = q1.front() ;
            cout << temp->data <<" " ;
            q1.pop() ;
            if(temp->left) q2.push(temp->left) ;
            if(temp->right) q2.push(temp->right) ;
        }
        cout << endl ;
        while(!q2.empty()){
            Node* temp = q2.front() ;
            cout << temp->data <<" " ;
            q2.pop() ;
            if(temp->left) q1.push(temp->left) ;
            if(temp->right) q1.push(temp->right) ;
        }
        cout << endl ;
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
    root = insertNode(root,16);
    root = insertNode(root,25);
    root = insertNode(root,27);
    root = insertNode(root,3);
    root = insertNode(root,17);

    levelbylevel(root) ;
}