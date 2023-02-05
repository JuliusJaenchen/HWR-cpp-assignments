#pragma once
#ifndef COORDINATES_H
#define COORDINATES_H

struct PolarCoordinate {
    double angleInDegrees, length;
};

struct CartesianCoordinate {
    double realPart, imaginaryPart;
};

#endif //COORDINATES_H
