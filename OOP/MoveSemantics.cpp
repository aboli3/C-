#include <iostream>
#include <cstring>
#include <utility> // For std::move

class String {
public:
    // Default constructor
    String() : m_data(nullptr), m_size(0) {}

    // Parameterized constructor
    String(const char* _data) {
        m_size = strlen(_data);
        m_data = new char[m_size + 1]; // Allocate space for null-terminator
        strcpy(m_data, _data);
    }

    // Copy constructor (deep copy)
    String(const String& other) 
        : m_size(other.m_size), m_data(new char[other.m_size + 1]) {
        strcpy(m_data, other.m_data);
    }

    // Move constructor
    String(String&& other) noexcept 
        : m_data(other.m_data), m_size(other.m_size) {
        other.m_data = nullptr; // Transfer ownership
        other.m_size = 0;
    }

    // Copy assignment operator
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] m_data; // Free existing memory
            m_size = other.m_size;
            m_data = new char[m_size + 1]; // Allocate new memory
            strcpy(m_data, other.m_data);
        }
        return *this;
    }

    // Move assignment operator
    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] m_data; // Free existing memory
            m_data = other.m_data; // Transfer ownership
            m_size = other.m_size;
            other.m_data = nullptr;
            other.m_size = 0;
        }
        return *this;
    }

    // Display function
    void display() const {
        if (m_data)
            std::cout << m_data << '\n';
    }

    // Destructor
    ~String() {
        delete[] m_data;
    }

private:
    char* m_data;
    size_t m_size;
};

class Entity {
public:
    // Default constructor
    Entity() = default;

    // Constructor with lvalue reference
    Entity(const String& string) 
        : m_string(string) {}

    // Constructor with rvalue reference
    Entity(String&& string) 
        : m_string(std::move(string)) {}

    // Print function
    void printString() const {
        m_string.display();
    }

private:
    String m_string;
};

int main() {
    Entity e(String("Aboli")); // Using move constructor
    e.printString(); // Output: Aboli
    return 0;
}
