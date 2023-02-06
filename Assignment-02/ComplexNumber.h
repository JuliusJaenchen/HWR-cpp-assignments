#pragma once
#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include "Coordinates.h"

// 1. a) Wir haben uns auf CartesianCoordinate entschieden, da es leichter verstädlich ist.
// 1. b) Der Compiler wirft einen Fehler: "no matching constructor for initialization of 'ComplexNumber'".
// 2.

class ComplexNumber {
private:
    PolarCoordinate polarCoordinate;
    CartesianCoordinate cartesianCoordinate;
public:
    ComplexNumber(CartesianCoordinate = CartesianCoordinate());
    void setCartesianCoordinate(CartesianCoordinate);
    void setCartesianRealPart(double);
    void setCartesianImaginaryPart(double);
    void setPolarCoordinate(PolarCoordinate);
    void setPolarLength(double);
    void setPolarAngleInDegrees(double);
    CartesianCoordinate getCartesianCoordinate();
    PolarCoordinate getPolarCoordinate();
};


#endif //COMPLEXNUMBER_H
