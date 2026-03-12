#include <iostream>
#include <string>
#include "Array.hpp"

// Petite macro pour rendre l'affichage des tests plus joli
#define PRINT_TEST(name) std::cout << "\n--- " << name << " ---" << std::endl;

int main()
{
    try
    {
        PRINT_TEST("1. Constructeur par defaut (Tableau vide)");
        Array<int> emptyArray;
        std::cout << "Taille de emptyArray : " << emptyArray.size() << std::endl;


        PRINT_TEST("2. Constructeur avec taille n (Initialisation par defaut)");
        Array<int> intArray(5);
        std::cout << "Taille de intArray : " << intArray.size() << std::endl;
        std::cout << "Valeurs initiales (doivent etre 0) : ";
        for (unsigned int i = 0; i < intArray.size(); i++)
            std::cout << intArray[i] << " ";
        std::cout << std::endl;


        PRINT_TEST("3. Assignation de valeurs via operator[]");
        for (unsigned int i = 0; i < intArray.size(); i++)
            intArray[i] = i * 10; // 0, 10, 20, 30, 40
        
        std::cout << "Nouvelles valeurs : ";
        for (unsigned int i = 0; i < intArray.size(); i++)
            std::cout << intArray[i] << " ";
        std::cout << std::endl;


        PRINT_TEST("4. Constructeur par copie (Deep copy test)");
        Array<int> copyArray(intArray);
        std::cout << "Modification de la copie (index 0 mis a 999)..." << std::endl;
        copyArray[0] = 999;
        
        std::cout << "Original intArray[0] : " << intArray[0] << " (doit rester 0)" << std::endl;
        std::cout << "Copie    copyArray[0] : " << copyArray[0] << " (doit etre 999)" << std::endl;


        PRINT_TEST("5. Operateur d'affectation '=' (Deep copy test)");
        Array<int> assignedArray;
        assignedArray = intArray; // Test de l'opérateur =
        std::cout << "Modification du tableau assigne (index 1 mis a 888)..." << std::endl;
        assignedArray[1] = 888;

        std::cout << "Original intArray[1] : " << intArray[1] << " (doit rester 10)" << std::endl;
        std::cout << "Assigne  assignedArray[1] : " << assignedArray[1] << " (doit etre 888)" << std::endl;


        PRINT_TEST("6. Test des exceptions (Index hors limites)");
        try {
            std::cout << "Tentative d'acces a l'index 5 sur un tableau de taille 5..." << std::endl;
            std::cout << intArray[5] << std::endl; // Doit throw !
            std::cout << "Ceci ne doit pas s'afficher." << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Exception attrapee avec succes : " << e.what() << std::endl;
        }


        PRINT_TEST("7. Test avec un type complexe (std::string)");
        Array<std::string> stringArray(3);
        stringArray[0] = "Hello";
        stringArray[1] = "42";
        stringArray[2] = "World";

        for (unsigned int i = 0; i < stringArray.size(); i++)
            std::cout << stringArray[i] << " ";
        std::cout << std::endl;

    }
    catch (const std::exception& e)
    {
        // Catch global au cas où une exception inattendue s'échappe
        std::cerr << "Erreur inattendue : " << e.what() << std::endl;
    }

    PRINT_TEST("FIN DES TESTS (Verification des leaks a faire)");
    return 0;
}
