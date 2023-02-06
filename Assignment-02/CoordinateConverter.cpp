#include "Coordinates.h"
#include "CoordinateConverter.h"
#include <cmath>
using namespace std;

PolarCoordinate CoordinateConverter::cartesianToPolar(CartesianCoordinate cartesian) {
    PolarCoordinate polar = {};
    polar.length = sqrt((cartesian.realPart * cartesian.realPart) + (cartesian.imaginaryPart * cartesian.imaginaryPart));
    if (polar.length == 0) {
        polar.angleInDegrees = 0;
        return polar;
    }
    double angleRadian = atan2(cartesian.imaginaryPart, cartesian.realPart);
    polar.angleInDegrees = angleRadian * 180/M_PI;
    return polar;
}

CartesianCoordinate CoordinateConverter::polarToCartesian(PolarCoordinate polar) {
    CartesianCoordinate cartesian = {};
    double angleRadian = polar.angleInDegrees * M_PI/180;
    cartesian.realPart = polar.length * cos(angleRadian);
    cartesian.imaginaryPart = polar.length * sin(angleRadian);
    return cartesian;
}
