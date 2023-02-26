#ifndef KOORDINATE_H
#define KOORDINATE_H

// In der der Klasse "Koordinate" sind Defaultwerte nicht sinnvoll.
// Erst in dem Kontext eines Zeichenelements machen Defaultwerte Sinn, da diese beispielsweise einfach
// an der Koordinate (0,0) eingezeichnet werden können.
class Koordinate
{
private:
    int m_x, m_y;
public:
    Koordinate(const int x, const int y): m_x(x), m_y(y) {};
    Koordinate(): Koordinate(0, 0) {};
    int getX() const { return m_x; };
    int getY() const { return m_y; };
};

#endif
