#pragma once
#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

struct PolarCoordinate {
    double angleInDegrees, length;
};

struct CartesianCoordinate {
    double realPart, imaginaryPart;
};

class Converter {
public:
    static PolarCoordinate cartesianToPolar(CartesianCoordinate);
    static CartesianCoordinate polarToCartesian(PolarCoordinate);
};


class ComplexNumber {
private:
    PolarCoordinate polarCoordinate;
    CartesianCoordinate cartesianCoordinate;
public:
    void setCartesianValues(double realPart, double imaginaryPart);
    void setPolarValues(double polarLength, double polarAngleInDegrees);
    CartesianCoordinate getCartesianCoordinate();
    PolarCoordinate getPolarCoordinate();
};


#endif //COMPLEXNUMBER_H
