// ProjectEuler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "EulerProjects.h"

int main()
{
    std::cout << "Euler Projcts!\n";
    
    Euler27_QuadraticPrimes* project = new Euler27_QuadraticPrimes();
    
    std::cout << "Running " + project->Name() << std::endl << "---------" << std::endl;
    project->Run();
    std::cout << std::endl << "---------" << std::endl;

    delete project;

    return 1;
}
