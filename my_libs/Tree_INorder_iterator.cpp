#include <iostream>
#include <stack>

class Node{

public:
  int data;
  Node* left;
  Node* right;
Node(int val){
  data = val;
  left = nullptr;
  right = nullptr;
}
};

void inorder_tr(Node* root)
{
  std::stack<Node*> stack;
  Node* curr = root;

  while(curr!=nullptr || !stack.empty())
  {
    while(curr!=nullptr){
      stack.push(curr);
      curr = curr->left;
    }    
    curr = stack.top();
    stack.pop();
    std::cout<<curr->data<<"\n";
    curr=curr->right;
  }  
}
int main(){

  Node* root = new Node(25);
  root->left = new Node(15);
  root->right = new Node(50);
  root->left->left = new Node(10);
  root->left->right = new Node(22);
  root->right->left = new Node(35);
  root->right->left->left = new Node(37);

  inorder_tr(root);
}
