#include <iostream>
#include <vector>

template<typename T>
class Vector
{
public:
	Vector() {
		Realloc(2);
	}
	~Vector(){
		delete[] m_Data;
	}
	void Push_Back(const T& data) {
		if (m_Size >= m_Capacity) {
			Realloc(m_Capacity + m_Capacity / 2);
		}
		m_Data[m_Size++] = data;
	}

	void Push_Back(T&& data) {
		if (m_Size >= m_Capacity) {
			Realloc(m_Capacity + m_Capacity / 2);
		}
		m_Data[m_Size++] = std::move(data);
	}

	void Pop_Back() {
		if (m_Size > 0) {
			--m_Size;
		}
	}
	template<typename... Args>
	T& EmplaceBack(Args&&... args)
	{
		if (m_Size >= m_Capacity) {
			Realloc(m_Capacity + m_Capacity / 2);
		}
		m_Data[m_Size++] = T(std::forward<Args>(args)...);
		return m_Data[m_Size];
	}

	size_t Size()const {
		return m_Size;
	}

	T& operator[](size_t index) {
		return m_Data[index];
	}

	const T& operator[](size_t index)const {
		return m_Data[index];
	}

	
private:
	void Realloc(size_t newCapacity) {
		//create new arr
		//assin old one to it
		//dele new old array

		T* newarr = new T[newCapacity];
		for (size_t i = 0; i < m_Size; ++i)
		{
			newarr[i] = std::move(m_Data[i]);
		}
		delete[] m_Data;
		m_Data = newarr;
		m_Capacity = newCapacity;
	}
private:
	T* m_Data;
	size_t m_Capacity = 0;
	size_t m_Size = 0;
};
template<typename T1>
void Print_Vector(const Vector<T1>& vector)
{
	for (size_t i = 0; i < vector.Size(); ++i)
		std::cout << vector[i] << "\n";
}
int main()
{
	Vector<std::string> vector;
	vector.Push_Back("aboli");
	vector.Push_Back("avinash");
	vector.Push_Back("mane");
	Print_Vector(vector);
	
}
