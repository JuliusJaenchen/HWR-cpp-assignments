#pragma once
#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include "Coordinates.hpp"

// 1. a) Anstatt die Werte einzelnd zu übergeben, haben wir uns entschieden einen Constructor mit dem
//       CartesianCoordinate struct zu bauen und einen mit dem PolarCoordinate struct. So kommen sie
//       sich nicht in die Quere.
// 1. b) Der Compiler wirft einen Fehler: "no matching constructor for initialization of 'ComplexNumber'".
// 2. Man kann nur einem der beiden Konstruktoren einen default parameter geben. Sonst kommt der folgende Fehler:
//    "./UserInterface.h:7:7: error: call to constructor of 'ComplexNumber' is ambiguous"
// 4. Hierfür benutzen wir unsere Structs CartesianCoordinate und PolarCoordinate.
// 5. Lokal funktionierte die implizierte float zu double Konvertierung beim aufrufen des Constructors.
//    Hätte es nicht funktioniert, hätte man explizites type-casting hinzugefügt


class ComplexNumber {
private:
    PolarCoordinate polarCoordinate;
    CartesianCoordinate cartesianCoordinate;
public:
    ComplexNumber(double polarLength);
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
