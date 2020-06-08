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

void postorder(Node* root){
    if(root == NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right) ;
    cout << root->data << " " ;
}

void iterpostorder(Node* root){
    Node* curr = root ;
    stack<Node*> s ;
    while(curr || !s.empty()){
        if(curr){
            s.push(curr) ;
            curr = curr->left ;
        }
        else {
            Node* temp = s.top()->right ;
            if(temp == NULL){
                temp = s.top() ;
                s.pop() ;
                cout << temp->data <<" " ;
                while(!s.empty() && temp == s.top()->right){
                    temp = s.top();
                    cout << temp->data <<" " ;
                    s.pop() ;
                }
            }
            else {
                curr = temp ;
            }
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
    cout << "Postorder recursive : " ;
    postorder(root) ;
    cout << endl ;
    cout << "Postorder iterative : " ;
    iterpostorder(root) ;
    cout << endl ;
}