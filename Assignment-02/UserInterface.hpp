#pragma once
#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "ComplexNumber.hpp"

class UserInterface {
private:
    ComplexNumber currentComplexNumber;
    ComplexNumber enterComplexNumberPrompt();
    void printCartesianForm();
    void printPolarForm();
public:
    void runApplication();
};

#endif //USERINTERFACE_H
