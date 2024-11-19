//////////////////////////////////////////////////////////
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
///////////////////>>>> ADVANCE VERSION

#include <iostream>
#include <memory>
#include <utility>
using namespace std;

class Person {
public:
    Person() : name(""), age(0) {} // Default constructor
    Person(const char* n, int a) : name(n), age(a) {}
    void display() const {
        cout << "Age: " << age << ", Name: " << name << "\n";
    }
private:
    const char* name;
    int age;
};

template<typename T>
class smptr {
public:
    // Default constructor
    smptr() : person(nullptr) {}

    // Constructor with raw pointer
    explicit smptr(T* p) : person(p) {}

    // Destructor
    ~smptr() {
        delete person;
        cout << "smptr destructor called!\n";
    }

    // Disable copy constructor and copy assignment operator
    smptr(const smptr&) = delete;
    smptr& operator=(const smptr&) = delete;

    // Move constructor
    smptr(smptr&& other) noexcept : person(other.person) {
        other.person = nullptr;
    }

    // Move assignment operator
    smptr& operator=(smptr&& other) noexcept {
        if (this != &other) {
            delete person;        // Free existing resource
            person = other.person; // Take ownership
            other.person = nullptr;
        }
        return *this;
    }

    // Overload operator-> to access object members
    T* operator->() const {
        return person;
    }

private:
    T* person;
};

int main() {
    {
        smptr<Person> ptr(new Person("Boli", 12));
        ptr->display(); // Access Person's members via smptr
    } // smptr goes out of scope, and the destructor is called

    return 0;
}
///////>>>>>>>>>>>>>>
smptr<Person> createPerson() {
    return smptr<Person>(new Person("John", 30));
}

int main() {
    smptr<Person> person = createPerson();
    person->display();
}
///////////////>>>>>>>>>>>>>this code is for move semantic
smptr<Person> ptr1(new Person("Charlie", 35));
smptr<Person> ptr2 = std::move(ptr1); // Transfers ownership
ptr2->display();

/////////////////>>>>>>>>>>>>scope cleanup
{
    smptr<Person> scopedPtr(new Person("Scoped", 40));
    scopedPtr->display();
} // Destructor called, memory released
///////////////>>>>>>>>>>>
Advantages of the Improved Code
RAII: Resource management tied to the smptr's lifetime ensures no memory leaks.
Safe Ownership Transfer: Move semantics enable flexibility in transferring ownership.
Robustness: Prevents copying and accidental double-deletes.
Modern C++ Practices: Aligns with the principles of smart pointers like std::unique_ptr.
