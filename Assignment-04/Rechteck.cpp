#include "Rechteck.h"
#include <sstream>
using namespace std;

double Rechteck::area() const {
    return this->m_length * this->m_width;
}

double Rechteck::circumference() const {
    return 2 * (this->m_length + this->m_width);
}

string Rechteck::toString() const {
    stringstream ss;
    ss << "Rechteck an der Stelle (" << this->m_koordinate->getX() << ',' << this->m_koordinate->getY() << ")";
    ss << " hat die Länge " << this->m_length;
    ss << " und die Breite " << this->m_width;
    ss << " und die Fläche " << this->area();
    ss << " und den Umfang " << this->circumference();
    return ss.str();
}
