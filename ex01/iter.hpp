#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template<typename T, typename Func>
void iter(T *array, size_t length, Func fonction)
{
	if(!array)
		return;
	for (size_t i = 0; i < length; ++i)
		fonction(array[i]);

}




#endif

