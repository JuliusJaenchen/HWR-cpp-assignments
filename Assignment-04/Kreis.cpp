#include "Kreis.h"
#include <math.h>
#include <sstream>
using namespace std;

double Kreis::area() const {
    return M_PI * pow(this->m_radius, 2);
}

double Kreis::circumference() const {
    return 2 * M_PI * this->m_radius;
}

string Kreis::toString() const {
    stringstream ss;
    ss << "Kreis an der Stelle (" << this->m_koordinate->getX() << ',' << this->m_koordinate->getY() << ")";
    ss << " hat den Radius " << this->m_radius;
    ss << " und die Fläche " << this->area();
    ss << " und den Umfang " << this->circumference();
    return ss.str();
}
