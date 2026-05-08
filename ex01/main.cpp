#include "iter.hpp"
#include <iostream>
#include <ostream>
#include <string>

void maj(std::string &str)
{
	for(size_t i = 0; i < str.length(); ++i)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
}

template<typename T>
void print(const T& x)
{
	std::cout << x << std::endl;
}


int main(void)
{
    std::string tabStrings[] = {"bonjour", "le", "monde"};
    size_t tailleStrings = 3;

    std::cout << "--- Test avec modification (non-const) ---" << std::endl;
    ::iter(tabStrings, tailleStrings, maj);
    ::iter(tabStrings, tailleStrings, print<std::string>);

    std::cout << "\n--- Test avec tableau constant (const) ---" << std::endl;
    const int tabInt[] = {1, 2, 3, 4, 5};
    ::iter(tabInt, 5, print<int>);

    return 0;
}
