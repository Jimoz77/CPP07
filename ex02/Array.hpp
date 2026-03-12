#ifndef ARRAY_HPP
#define ARRAY_HPP


#include <exception>
#include <stdexcept>
template<typename T>
class Array
{
	private:
		unsigned int	_size;
		T				*_array;
	public:

	unsigned int					size() const;
	Array								&operator=(const Array &other);
	T									&operator[](unsigned int index);
	const T								&operator[](unsigned int index) const;
										Array();
										Array(const Array &other);
										Array(unsigned int n);
										~Array();
	class Out_of_range : public std::exception
	{
		public:
		 virtual const char* what() const throw()
		{
			return ("Index is out of range.");
		}
	};

};

template<typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	_array = new T[_size]();
}

template<typename T>
Array<T>::Array() :  _size(0)
{
	_array = new T[0]();
}

template<typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if(index >= _size)
		throw Array<T>::Out_of_range();
	return _array[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if(index >= _size)
		throw Array<T>::Out_of_range();
	return _array[index];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array &other)
{
	if(this != &other)
	{
		_size = other._size;
		delete[] _array;
		_array = new T[_size]();
		for(unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return *this;
}
template<typename T>
Array<T>::Array(const Array &other) : _size(other._size)
{
	_array = new T[_size]();
	for(unsigned int i = 0; i < _size; i++)
		_array[i] = other._array[i];
}


#endif
