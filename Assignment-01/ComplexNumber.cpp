#include "ComplexNumber.h"
#include <cmath>
using namespace std;

PolarCoordinate Converter::cartesianToPolar(CartesianCoordinate cartesian) {
    PolarCoordinate polar = {};
    polar.length = sqrt((cartesian.realPart * cartesian.realPart) + (cartesian.imaginaryPart + cartesian.imaginaryPart));
    if (polar.length == 0) {
        polar.angleInDegrees = 0;
        return polar;
    }
    double angleRadian = atan2(cartesian.realPart, cartesian.imaginaryPart);
    polar.angleInDegrees = angleRadian * 180/M_1_PI;
    return polar;
}

CartesianCoordinate Converter::polarToCartesian(PolarCoordinate polar) {
    CartesianCoordinate cartesian = {};
    double angleRadian = polar.angleInDegrees * M_1_PI/180;
    cartesian.realPart = polar.length * cos(angleRadian);
    cartesian.imaginaryPart = polar.length * sin(angleRadian);
    return cartesian;
}

void ComplexNumber::setPolarValues(double polarLength, double polarAngleInDegrees) {
    PolarCoordinate pc = {};
    double reducedAngle = fmod(polarAngleInDegrees, 360);
    if (reducedAngle < 0) {
        reducedAngle = 360 - abs(reducedAngle);
    }
    pc.angleInDegrees = reducedAngle;
    pc.length = polarLength;
    this->polarCoordinate = pc;
    this->cartesianCoordinate = Converter::polarToCartesian(pc);
}

void ComplexNumber::setCartesianValues(double realPart, double imaginaryPart) {
    CartesianCoordinate cartesian = {};
    cartesian.realPart = realPart;
    cartesian.imaginaryPart = imaginaryPart;
    this->cartesianCoordinate = cartesian;
    this->polarCoordinate = Converter::cartesianToPolar(cartesian);
}

CartesianCoordinate ComplexNumber::getCartesianCoordinate() {
    return this->cartesianCoordinate;
}

PolarCoordinate ComplexNumber::getPolarCoordinate() {
    return this->polarCoordinate;
}
