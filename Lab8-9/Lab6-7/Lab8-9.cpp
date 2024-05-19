// Lab6-7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "RepositoryFile.h"
#include "Lista.h"
#include "Validator.h"
#include "Service.h"
#include "HTML_Cos.h"
#include "UI.h"
#include "Teste.h"

int main()
{
    std::cout << "-------------PRINTRI NECESARE PENTRU TESTE! IGNORATI------------\n";
    Teste teste;
    teste.start();
    std::cout << "-------------PRINTRI NECESARE PENTRU TESTE! IGNORATI------------\n\n\n";
    std::cout << "TESTE TRECUTE CU SUCCESS\n";
    RepositoryFile repository_file("input.txt", "output.txt");
    ActivitateValidator validator;
    Service service{ repository_file, validator };
    HTML_Cos lista = { repository_file };
    UI ui{ service , lista };
    ui.start();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
