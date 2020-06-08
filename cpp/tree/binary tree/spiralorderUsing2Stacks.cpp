#include<iostream>
#include<queue>
#include<stack>

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

void spiralorder(Node* root){
    stack<Node*> s1,s2 ;
    s1.push(root) ;
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            Node* curr = s1.top() ;
            s1.pop() ;
            cout << curr->data <<" " ;
            if(curr->left) s2.push(curr->left) ;
            if(curr->right) s2.push(curr->right) ;
        }
        cout << endl ;
        while(!s2.empty()){
            Node* curr = s2.top();
            s2.pop();
            cout << curr->data << " " ;
            if(curr->right) s1.push(curr->right);
            if(curr->left) s1.push(curr->left) ;
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
    root = insertNode(root,11);
    root = insertNode(root,9);
    root = insertNode(root,3);
    spiralorder(root) ;
}