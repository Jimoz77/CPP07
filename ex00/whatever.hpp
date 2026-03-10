#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
const T& max(T& a, T& b)
{
	if(a > b)
		return a;
	return b;
}

template<typename T>
const T& min(T& a, T& b)
{
	if(a < b)
		return a;
	return b;
}

template<typename T>
void swap(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}


#endif
