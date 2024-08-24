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

void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    stack<TreeNode*> s1, s2;

    // Push the root to the first stack
    s1.push(root);

    // Run while the first stack is not empty
    while (!s1.empty()) {
        // Pop an element from s1 and push it to s2
        TreeNode* node = s1.top();
        s1.pop();
        s2.push(node);

        // Push the left and right children of the popped node to s1
        if (node->left) {
            s1.push(node->left);
        }
        if (node->right) {
            s1.push(node->right);
        }
    }

    // Now, print all elements in s2 (they are in post-order)
    while (!s2.empty()) {
        TreeNode* node = s2.top();
        s2.pop();
        cout << node->val << " ";
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
