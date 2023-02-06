#pragma once
#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include "Coordinates.h"
#include "CoordinateConverter.h"

class ComplexNumber {
private:
    PolarCoordinate polarCoordinate;
    CartesianCoordinate cartesianCoordinate;
public:
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
