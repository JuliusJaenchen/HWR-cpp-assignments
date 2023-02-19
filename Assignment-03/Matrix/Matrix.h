#ifndef Matrix3
#define Matrix3

#include <string>
#include "IndexOutOfBoundsException.h"

class Matrix33
{
public:

    // Static Class-Functions
    static Matrix33 zeros();
    static Matrix33 ones();

    // Construction
    Matrix33( double m11, double ml2, double m13, 
              double m21, double m22, double m23, 
              double m31, double m32, double m33 );
    
    double& get(const int row, const int col);

    std::string toString() const;

    Matrix33 operator+(const Matrix33) const;
    Matrix33 operator*(const Matrix33) const;
    Matrix33 operator*(const int) const;
    Matrix33& operator+=(const Matrix33 other);
    Matrix33& operator=(const Matrix33 other);

    friend Matrix33 operator*(const int scalar, const Matrix33 matrix);

    operator double() const;


private:
    double m_matrix[3][3];
};


#endif