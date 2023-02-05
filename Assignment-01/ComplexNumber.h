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
    void setCartesianValues(CartesianCoordinate);
    void setCartesianRealPart(double);
    void setCartesianImaginaryPart(double);
    void setPolarValues(PolarCoordinate);
    void setPolarLength(double);
    void setPolarAngleInDegrees(double);
    CartesianCoordinate getCartesianCoordinate();
    PolarCoordinate getPolarCoordinate();
};


#endif //COMPLEXNUMBER_H
