/******************************************************************************

             Code belongs to Aboli A Mane

*******************************************************************************/
#include <iostream>

class Stack 
{
    public:
        Stack()=default;
        void push(int val)
        {
            if(m_size >= 10)
                return;
            arr[m_size++]=val;
        }
        
        int pop()
        {
            if(m_size<=0)
                return -1;
            --m_size;
        }
        
        int top(){
            return arr[m_size];
        } 
        
        bool isEmpty(){
            if(m_size<=0)
                return true;
            return false;
        }
        
        void print_stack(){
            for(int i=0;i<m_size;++i)
            {
                std::cout<<arr[i]<<' ';
            }
            std::cout<<"\n";
        }
    private:
        int m_size {0};
        int arr[10];
};

int main() {
  
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.print_stack();
    s.pop();
    s.print_stack();
    std::cout<<s.top()<<"\n";
    return 0;
}
