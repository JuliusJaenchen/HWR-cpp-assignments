#ifndef ZEICHENELEMENT_H
#define ZEICHENELEMENT_H

#include "Koordinate.h"
#include <iostream>
using namespace std;

class ZeichenElement
{
protected:
    Koordinate* m_koordinate;
    // Der Konstruktor im Protected Bereicht hat zufolge, dass die Abstrakte Klasse ZeichenElement
    // nicht instanziiert werden kann. Trotzdem kann der Konstruktot von den Kindesklassen aufgerufen werden.
    ZeichenElement(const double x, const double y) {this->m_koordinate = new Koordinate(x, y);};
    virtual ~ZeichenElement() {delete this->m_koordinate;};

public:
    virtual string toString() const = 0;
    // Diese Funktionen müssen Polymorph implementiert werdnen, da die Berechnungsmethode für jede Kindesklasse
    // anders ist.
    virtual double area() const = 0;
    virtual double circumference() const = 0;
};

#endif // ZEICHENELEMENT_H
