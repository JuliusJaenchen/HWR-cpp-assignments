#include "ComplexNumber.hpp"
#include "CoordinateConverter.hpp"
#include <cmath>
using namespace std;

ComplexNumber::ComplexNumber(CartesianCoordinate cartesian): cartesianCoordinate(cartesian) {
    this->polarCoordinate = CoordinateConverter::cartesianToPolar(cartesian);
}

ComplexNumber::ComplexNumber(PolarCoordinate polar): polarCoordinate(polar) {
    this->cartesianCoordinate = CoordinateConverter::polarToCartesian(polar);
}

ComplexNumber::ComplexNumber(double polarLength) {
    PolarCoordinate polar = {0, polarLength};
    if (polarLength < 0) {
       polar.angleInDegrees = -45;
    }
    if (polarLength > 0) {
        polar.angleInDegrees = 45;
    }
    this->setPolarCoordinate(polar);
}

void ComplexNumber::setPolarCoordinate(PolarCoordinate polarInput) {
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
    this->setPolarCoordinate(newPolar);
}

void ComplexNumber::setPolarAngleInDegrees(double newAngleInDegrees) {
    PolarCoordinate newPolar = {};
    newPolar.length = this->polarCoordinate.length;
    newPolar.angleInDegrees = newAngleInDegrees;
    this->setPolarCoordinate(newPolar);
}

void ComplexNumber::setCartesianCoordinate(CartesianCoordinate cartesian) {
    this->cartesianCoordinate = cartesian;
    this->polarCoordinate = CoordinateConverter::cartesianToPolar(cartesian);
}

void ComplexNumber::setCartesianRealPart(double newRealPart) {
    CartesianCoordinate newCartesian = {};
    newCartesian.realPart = newRealPart;
    newCartesian.imaginaryPart = this->cartesianCoordinate.imaginaryPart;
    this->setCartesianCoordinate(newCartesian);
}

void ComplexNumber::setCartesianImaginaryPart(double newImaginaryPart) {
    CartesianCoordinate newCartesian = {};
    newCartesian.realPart = this->cartesianCoordinate.realPart;
    newCartesian.imaginaryPart = newImaginaryPart;
    this->setCartesianCoordinate(newCartesian);
}

CartesianCoordinate ComplexNumber::getCartesianCoordinate() {
    return this->cartesianCoordinate;
}

PolarCoordinate ComplexNumber::getPolarCoordinate() {
    return this->polarCoordinate;
}
