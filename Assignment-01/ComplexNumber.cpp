#include "ComplexNumber.h"
#include "CoordinateConverter.cpp"
#include <cmath>
using namespace std;

void ComplexNumber::setPolarValues(PolarCoordinate polarInput) {
    PolarCoordinate pc = {};
    double reducedAngle = fmod(polarInput.angleInDegrees, 360);
    if (reducedAngle < 0) {
        reducedAngle = 360 - abs(reducedAngle);
    }
    pc.angleInDegrees = reducedAngle;
    pc.length = polarInput.length;
    this->polarCoordinate = pc;
    this->cartesianCoordinate = CoordinateConverter::polarToCartesian(pc);
}

void ComplexNumber::setPolarLength(double newLength) {
    PolarCoordinate newPolar = {};
    newPolar.length = newLength;
    newPolar.angleInDegrees = this->polarCoordinate.angleInDegrees;
    this->setPolarValues(newPolar);
}

void ComplexNumber::setPolarAngleInDegrees(double newAngleInDegrees) {
    PolarCoordinate newPolar = {};
    newPolar.length = this->polarCoordinate.length;
    newPolar.angleInDegrees = newAngleInDegrees;
    this->setPolarValues(newPolar);
}

void ComplexNumber::setCartesianValues(CartesianCoordinate cartesian) {
    this->cartesianCoordinate = cartesian;
    this->polarCoordinate = CoordinateConverter::cartesianToPolar(cartesian);
}

void ComplexNumber::setCartesianRealPart(double newRealPart) {
    CartesianCoordinate newCartesian = {};
    newCartesian.realPart = newRealPart;
    newCartesian.imaginaryPart = this->cartesianCoordinate.imaginaryPart;
    this->setCartesianValues(newCartesian);
}

void ComplexNumber::setCartesianImaginaryPart(double newImaginaryPart) {
    CartesianCoordinate newCartesian = {};
    newCartesian.realPart = this->cartesianCoordinate.realPart;
    newCartesian.imaginaryPart = newImaginaryPart;
    this->setCartesianValues(newCartesian);
}

CartesianCoordinate ComplexNumber::getCartesianCoordinate() {
    return this->cartesianCoordinate;
}

PolarCoordinate ComplexNumber::getPolarCoordinate() {
    return this->polarCoordinate;
}
