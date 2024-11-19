#include <iostream>
#include <memory>
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
    smptr() : person(nullptr), ref_count(new int(0)) {}

    // Constructor with raw pointer
    explicit smptr(T* p) : person(p), ref_count(new int(1)) {}

    // Copy constructor
    smptr(const smptr& other) 
        : person(other.person), ref_count(other.ref_count) {
        if (person) {
            ++(*ref_count); // Increment reference count
        }
    }

    // Move constructor
    smptr(smptr&& other) noexcept
        : person(other.person), ref_count(other.ref_count) {
        other.person = nullptr;
        other.ref_count = nullptr;
    }

    // Copy assignment operator
    smptr& operator=(const smptr& other) {
        if (this != &other) {
            cleanup(); // Release current resource if needed
            person = other.person;
            ref_count = other.ref_count;
            if (person) {
                ++(*ref_count); // Increment reference count
            }
        }
        return *this;
    }

    // Move assignment operator
    smptr& operator=(smptr&& other) noexcept {
        if (this != &other) {
            cleanup(); // Release current resource if needed
            person = other.person;
            ref_count = other.ref_count;
            other.person = nullptr;
            other.ref_count = nullptr;
        }
        return *this;
    }

    // Destructor
    ~smptr() {
        cleanup();
    }

    // Overload operator-> to access object members
    T* operator->() const {
        return person;
    }

    // Get the reference count (for debugging purposes)
    int use_count() const {
        return ref_count ? *ref_count : 0;
    }

private:
    T* person;       // Pointer to the managed object
    int* ref_count;  // Pointer to the reference count

    void cleanup() {
        if (ref_count) {
            --(*ref_count);
            if (*ref_count == 0) { // Last reference
                delete person;
                delete ref_count;
                cout << "Resource deleted!\n";
            }
        }
    }
};

int main() {
    {
        smptr<Person> ptr1(new Person("Alice", 25));
        cout << "Ref count: " << ptr1.use_count() << "\n";
        
        {
            smptr<Person> ptr2 = ptr1; // Shared ownership
            cout << "Ref count after copy: " << ptr1.use_count() << "\n";
            ptr2->display();
        } // ptr2 goes out of scope, ref count decrements

        cout << "Ref count after ptr2 out of scope: " << ptr1.use_count() << "\n";
    } // ptr1 goes out of scope, resource is deallocated

    return 0;
}
