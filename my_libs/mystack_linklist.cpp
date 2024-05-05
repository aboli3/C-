#include <iostream>

class Node
{
    public:
        Node()
            :next(nullptr){}
        Node(int val)
            :data(val),next(nullptr){}
            
        int data;
        Node* next;
};
class Stack 
{
    public:
        Stack()=default;
        void push(int val)
        {
            Node* newNode = new Node(val);
            if(top == nullptr)
            {
                top = newNode;
                return;
            }
            newNode->next = top;
            top = newNode;
        }
        
        void pop()
        {
            if(top==nullptr)
                return;
            Node* tmp = top;
            top = top->next;
            free(tmp);
        }
        void print()
        {
            Node* tmp = top;
            while(tmp)
            {
                std::cout<<tmp->data<<' ';
                tmp = tmp->next;
            }
            std::cout<<"\n";
        }
        
        bool isEmpty()
        {
            return top==nullptr;
        }
        
        int top_val()
        {
            if(top == nullptr)
            {
                return -1;
            }
            return top->data;
        }
    private:
       //int m_size {0};
       Node* top{nullptr};
       
};

int main() {
   Stack s;
   s.push(10);
   s.push(20);
   s.push(30);
   s.print();
   std::cout<<"============================\n";
   s.pop();
   s.print();
    return 0;
}
