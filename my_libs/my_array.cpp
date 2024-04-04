#include<iostream>
#include<array>

template<typename T, size_t S>
class Array
{
public:
	constexpr size_t Size()const { return S; }
	T& operator[](size_t index) { return m_Data[index]; }
	const T& operator[](size_t index)const{ return m_Data[index]; }

	T* Data() { return m_Data; }
	const T* Data()const { return m_Data; }
private:
	T m_Data[S];
};
int main()
{
	Array<int, 5>data;
	//const auto& arrRef = data;
	memset(&data[0], 0, data.Size() * sizeof(int));
	for (auto i = 0; i < data.Size(); ++i)
	{
		//data[i] = 2;
		std::cout << data[i] << "\n";
	}
}
