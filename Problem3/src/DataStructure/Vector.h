#pragma once

#include <iostream>

const int default_size = 0;
const int default_capacity = 0;
template <typename T>
class Vector
{
public:
	Vector(const int sz = default_size);
	~Vector() { delete[] self; }

	// useful function
	const T* begin() const { return self; }
	const T* end() const { return self + size; }
	const int& GetSize() const { return size; }
	const int& GetCapacity() const { return capacity; }
	void PushBack(const T& element);
	void Resize(const int& sz);
	void Expand(const int& sz);

	// operator
	T& operator [] (const int& n) const;
	void operator += (const T& element) { PushBack(element); }
	void operator = (const Vector<T>& arr);

private:
	void AllocateMemory(const int& cap);
	int CalculateCapacity(const int& sz) const;

	T* self = nullptr;	// the space of array
	int capacity = default_capacity;
	int size = default_size;
};

template <typename T>
Vector<T>::Vector(const int sz)
{
	AllocateMemory(CalculateCapacity(sz));
	size = sz;
}

template <typename T>
void Vector<T>::PushBack(const T& element)
{
	if (size + 1 > capacity)
	{
		Expand(size + 1);
	}
	else
	{
		size += 1;
	}
	self[size - 1] = element;
}

template <typename T>
void Vector<T>::Resize(const int& sz)
{
	AllocateMemory(CalculateCapacity(sz));
	size = sz;
}

template <typename T>
void Vector<T>::Expand(const int& sz)
{
	if (sz < size)
	{
		std::cerr << "[Error]: Failed to Expand, don't less than size" << std::endl;
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
void Vector<T>::operator = (const Vector<T>& arr)
{
	this->Resize(0);
	for (T element : arr)
	{
		this->PushBack(element);
	}
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