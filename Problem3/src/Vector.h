#pragma once
#include <iostream>

const int default_size = 0;
const int default_capacity = 0;
template <typename T>
class Vector
{
public:
	Vector(int sz = default_size);
	~Vector();

	// useful function
	const T* begin() const;
	const T* end() const;
	void push_back(const T& element);
	const int& get_size() const;
	const int& get_capacity() const;
	void resize(const int& sz);
	void expand(const int& sz);

	// operator
	T& operator [] (const int& n) const;
	void operator += (const T& element);

private:
	void AllocateMemory(const int& cap);
	int CalculateCapacity(const int& sz) const;
	int Pow(const int& num, int n) const;

	T* self;	// the space of array
	int capacity;
	int size;
};

template <typename T>
Vector<T>::Vector(int sz)
	: self(nullptr), capacity(default_capacity)
{
	AllocateMemory(CalculateCapacity(sz));
	size = sz;
}

template <typename T>
Vector<T>::~Vector()
{
	delete[] self;
	//std::cout << "delete" << std::endl;
}

template <typename T>
const T* Vector<T>::begin() const
{
	return self;
}

template <typename T>
const T* Vector<T>::end() const
{
	return self + size;
}

template <typename T>
void Vector<T>::push_back(const T& element)
{
	if (size + 1 > capacity)
	{
		expand(size + 1);
	}
	else
	{
		size += 1;
	}
	self[size - 1] = element;
}

template <typename T>
const int& Vector<T>::get_size() const
{
	return size;
}

template <typename T>
const int& Vector<T>::get_capacity() const
{
	return capacity;
}

template <typename T>
void Vector<T>::resize(const int& sz)
{
	AllocateMemory(CalculateCapacity(sz));
	size = sz;
}

template <typename T>
void Vector<T>::expand(const int& sz)
{
	if (sz < size)
	{
		std::cerr << "[Error]: Failed to expand, don't less than size" << std::endl;
		exit(EXIT_FAILURE);
	}
	else if (capacity >= sz)
	{
		size = sz;
	}
	else
	{
		T* temp;
		temp = new T[size]();
		for (int i = 0; i < size; i++)
		{
			temp[i] = self[i];
		}
		AllocateMemory(CalculateCapacity(sz));
		for (int i = 0; i < size; i++)
		{
			self[i] = temp[i];
		}
		delete[] temp;
		size = sz;
	}
}

template <typename T>
T& Vector<T>::operator [] (const int& n) const
{
	if (n >= size)
	{
		std::cerr << "[Error]: Index out of range" << std::endl;
		exit(EXIT_FAILURE);
	}
	return self[n];
}

template <typename T>
void Vector<T>::operator += (const T& element)
{
	push_back(element);
}

template <typename T>
void Vector<T>::AllocateMemory(const int& cap)
{
	if (cap < 0)
	{
		std::cerr << "[Error]: Failed to allocate memory" << std::endl;
		exit(EXIT_FAILURE);
	}
	else if (self != nullptr)
	{
		delete[] self;
	}
	capacity = cap;
	self = new T[cap]();
}

template <typename T>
int Vector<T>::CalculateCapacity(const int& sz) const
{
	if (sz < 0)
	{
		std::cerr << "[Error]: Invalid Size" << std::endl;
		exit(EXIT_FAILURE);
	}
	int cap = 1;
	while (cap < sz)
	{
		cap *= 2;
	}
	return cap;
}

template <typename T>
int Vector<T>::Pow(const int& num, int n) const
{
	int temp = 1;
	while (n-- > 0)
	{
		temp *= num;
	}
	return temp;
}