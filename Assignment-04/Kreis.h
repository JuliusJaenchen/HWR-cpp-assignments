#ifndef KREIS_H
#define KREIS_H

#include "ZeichenElement.h"
using namespace std;

class Kreis: public ZeichenElement
{
private:
    double m_radius;
public:
    Kreis(const double x, const double y, const double radius);
    double area() const;
    double circumference() const;
    string toString() const;
};

#endif // KREIS_H
