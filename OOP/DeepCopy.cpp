#include <iostream>
#include <cstring>

class Shallow 
{
public:
    Shallow() : str(nullptr) {}

    Shallow(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Deep copy constructor
    Shallow(const Shallow& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    // Copy assignment operator (for deep copy assignment)
    Shallow& operator=(const Shallow& other) {
        if (this != &other) {
            delete[] str;
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    // Destructor to clean up the memory
    ~Shallow() {
        delete[] str;
    }

    void display() const {
        std::cout << str << "\n";
    }

    void modify() {
        if (str) str[0] = 's';
    }

private:
    char* str;
};

int main()
{
   Shallow s1("vector"), s2(s1);
   s2.modify();
   s1.display();
   return 0;
}
