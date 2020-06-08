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

void connectRecur(Node* root){
    if(root == NULL){
        return ;
    }
    if(root->left){
        root->left->nextRight = root->right ;
    }
    if(root->right){
        root->right->nextRight = (root->nextRight)?root->nextRight->left : NULL ;
    }
    connectRecur(root->left) ;
    connectRecur(root->right) ;
}

void connectNodesAtSameLevel(Node* root){
    root->nextRight = NULL ;
    connectRecur(root) ;
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