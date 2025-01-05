	#include <iostream>
	#include <memory>
	using namespace std;
	
	class Person {
	public:
		Person(){}
		Person(const char* n, int a)
			:name(n),age(a){}
		void display() {
			cout << "age : " << age << " name : " << name << "\n";
		}
	private:
		const char* name;
		int age;
	};
	template<typename T>
	class smptr {
	public:
		smptr() {

		}
		smptr(T* p)
		{
			person = p;
		}
		T* operator->()
		{
			return person;
		}
		~smptr() {
			cout << "smptr desctor !\n";
		}
	private:
		T* person;
	};
	int main()
	{
		{
			smptr<Person> ptr(new Person("boli",12));
			ptr->display();
		}
	}
