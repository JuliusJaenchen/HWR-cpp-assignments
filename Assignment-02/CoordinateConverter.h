#pragma once
#ifndef COORDINATECONVERTER_H
#define COORDINATECONVERTER_H

#include "Coordinates.hpp"

class CoordinateConverter {
public:
    static PolarCoordinate cartesianToPolar(CartesianCoordinate);
    static CartesianCoordinate polarToCartesian(PolarCoordinate);
};


#endif //COORDINATECONVERTER_H
