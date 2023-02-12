#pragma once
#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include "Coordinates.h"

// 1. a) Anstatt die Werte einzelnd zu übergeben, haben wir uns entschieden einen Constructer mit dem
//       CartesianCoordinate struct zu bauen und einen mit dem PolarCoordinate struct. So kommen sie
//       sich nicht in die Quere.
// 1. b) Der Compiler wirft einen Fehler: "no matching constructor for initialization of 'ComplexNumber'".
// 2.

class ComplexNumber {
private:
    PolarCoordinate polarCoordinate;
    CartesianCoordinate cartesianCoordinate;
public:
    ComplexNumber(CartesianCoordinate = CartesianCoordinate());
    ComplexNumber(PolarCoordinate);
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
