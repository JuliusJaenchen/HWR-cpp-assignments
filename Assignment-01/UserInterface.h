#pragma once
#ifndef USERINTERFACE
#define USERINTERFACE

#include "ComplexNumber.h"

class UserInterface {
private:
    ComplexNumber currentComplexNumber;
    ComplexNumber enterComplexNumberPrompt();
public:
    void runApplication();
};

#endif //USERINTERFACE
