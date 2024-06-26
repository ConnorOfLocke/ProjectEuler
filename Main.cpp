// ProjectEuler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "EulerProjects.h"

int main()
{
    std::cout << "Euler Projcts!\n";
    
    Euler28_NumberSpiralDiagonals* project = new Euler28_NumberSpiralDiagonals();
    
    std::cout << "Running " + project->Name() << std::endl << "---------" << std::endl;
    project->Run();
    std::cout << std::endl << "---------" << std::endl;

    delete project;

    return 1;
}
