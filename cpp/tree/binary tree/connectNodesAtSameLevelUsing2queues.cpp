#include<iostream>
#include<stack>
#include<queue>
#include<map>
using namespace std ;

struct Node {
    int data ;
    Node* left ;
    Node* right ;
    Node* nextRight ;
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

void printStack(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " " ;
        s.pop() ;
    }
}

void connectNodesAtSameLevel(Node* root){
    queue<Node*> q1,q2 ;
    q1.push(root) ;
    while(!q1.empty() || !q2.empty()){
        while(!q1.empty()){
            Node* temp = q1.front() ;
            q1.pop() ;
            if(q1.empty()){
                temp->nextRight = NULL ;
            }
            else {
                temp->nextRight = q1.front() ;
            }
            if(temp->left) q2.push(temp->left) ;
            if(temp->right) q2.push(temp->right) ;
        }
        while(!q2.empty()){
            Node* temp = q2.front() ;
            q2.pop();
            if(q2.empty()){
                temp->nextRight = NULL ;
            }
            else {
                temp->nextRight = q2.front() ;
            }
            if(temp->left) q1.push(temp->left) ;
            if(temp->right) q1.push(temp->right) ;
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

    connectNodesAtSameLevel(root) ;
    cout <<root->left->nextRight->data << endl ;
    cout <<root->left->left->nextRight->data << endl ;
    cout <<root->right->left->nextRight->data << endl ;
}