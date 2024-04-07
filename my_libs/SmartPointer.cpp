
#include <stdio.h>
#include <iostream>


//smart pointer : object that behave like pointer
template<typename T1, typename T2>
class Person
{
    public:
        Person() = default;
        Person(T1 a, const T2* n)
            :age(a),name(n){}
        void details(){
            std::cout<<"age : "<<age<<" name is : "<<name<<"\n";
        }
    private:
        T1 age;
        const T2* name;
};

template<typename T>

class SmartPointer
{
    public:
        SmartPointer() = default;
        SmartPointer(T* p)
            :ptr(p){}
        
        T* operator->(){
            return ptr;
        }
        
        ~SmartPointer(){
            delete ptr;
        }
    private:
        T* ptr;
};

int main()
{
    SmartPointer<Person<int, char>> ptr(new Person<int, char>(10, "dabu"));
    ptr->details();
    return 0;
}
