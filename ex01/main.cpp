#include "iter.hpp"
#include <iostream>
#include <string>

void maj(std::string &str)
{
	for(int i = 0; i < str.length(); ++i)
	{
		if(str[i] > 'a' && str[i] < 'z')
			str[i] -= 32;
	}
}


int main(void)
{
// Test avec un tableau de strings (pour prouver que c'est générique)
    std::string tabStrings[] = {"Bonjour", "le", "monde"};
    size_t tailleStrings = 3;

    std::cout << "--- Test avec des strings ---" << std::endl;
    // Ici, on ne peut pas utiliser 'incrementer' car ça n'a pas de sens sur des strings,
    // mais on peut utiliser notre template d'affichage instancié pour des strings !
    ::iter(tabStrings, tailleStrings, maj);
	std::cout << tabStrings[0] << " " << tabStrings[1] << " " << tabStrings[2];
    std::cout << std::endl;
}
