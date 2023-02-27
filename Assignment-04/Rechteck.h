#ifndef RECHTECK_H
#define RECHTECK_H

#include "ZeichenElement.h"
using namespace std;

class Rechteck: public ZeichenElement
{
private:
    double m_length, m_width;
public:
    Rechteck(const double x, const double y, const double length, const double width);
    double area() const;
    double circumference() const;
    string toString() const;
};

#endif // RECHTECK_H
