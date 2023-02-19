#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

#include "Matrix.h"


// ----------------------------------------------------------------------------

Matrix33 Matrix33::zeros()
{
    return Matrix33(0,0,0  ,0,0,0  ,0,0,0);
}


// ----------------------------------------------------------------------------

Matrix33 Matrix33::ones()
{
    return Matrix33(1,1,1  ,1,1,1  ,1,1,1);
}


// ----------------------------------------------------------------------------

Matrix33::Matrix33( double m11, double m12, double m13, double m21, double m22, double m23, double m31, double m32, double m33 )
{
    m_matrix[0][0] = m11;
    m_matrix[0][1] = m12;
    m_matrix[0][2] = m13;
    m_matrix[1][0] = m21; m_matrix[1][1] = m22; m_matrix[1][2] = m23;
    m_matrix[2][0] = m31; m_matrix[2][1] = m32; m_matrix[2][2] = m33;
}


// ----------------------------------------------------------------------------

std::string Matrix33::toString() const
{
    std::stringstream s;
    s << "----------------------------\n";
    s << "| "  <<std::setw(6) << m_matrix[0][0];
    s << " | " <<std::setw(6) << m_matrix[0][1];
    s << " | " <<std::setw(6) << m_matrix[0][2] << " |";
    s << "\n----------------------------\n";
    s << "| "  <<std::setw(6) << m_matrix[1][0];
    s << " | " <<std::setw(6) << m_matrix[1][1];
    s << " | " <<std::setw(6) << m_matrix[1][2] << " |";
    s << "\n----------------------------\n";
    s << "| "  <<std::setw(6) << m_matrix[2][0];
    s << " | " <<std::setw(6) << m_matrix[2][1];
    s << " | " <<std::setw(6) << m_matrix[2][2] << " |";
    s << "\n----------------------------\n";

    return s.str();
}


// ----------------------------------------------------------------------------


Matrix33 Matrix33::operator+(const Matrix33 other) const{
    Matrix33 result = Matrix33::zeros();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.m_matrix[i][j] = this->m_matrix[i][j] + other.m_matrix[i][j];
        }
    }
    return result;
}

Matrix33 Matrix33::operator*(const Matrix33 other) const {
    Matrix33 result = Matrix33::zeros();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int sum_i = 0; sum_i < 3; sum_i++) {
                result.m_matrix[i][j] += this->m_matrix[i][sum_i] * other.m_matrix[sum_i][j];
            }
        }
    }
    return result;
}

Matrix33 Matrix33::operator*(const int scalar) const {
    Matrix33 result = Matrix33::zeros();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.m_matrix[i][j] += this->m_matrix[i][j] * scalar;
        }
    }
    return result;
}

Matrix33& Matrix33::operator+=(const Matrix33 other) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->m_matrix[i][j] += other.m_matrix[i][j];
        }
    }
    return *this;
}

Matrix33& Matrix33::operator=(const Matrix33 other) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->m_matrix[i][j] = other.m_matrix[i][j];
        }
    }
    return *this;
}

Matrix33 operator*(const int scalar, const Matrix33 matrix) {
    Matrix33 result = matrix;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.m_matrix[i][j] *= scalar;
        }
    }
    return result;
}

// Determinant algorithm based on the Rule of Sarrus
Matrix33::operator double() const {
    double result = 0;
    double positive_diagonal, negative_diagonal;
    for (int column = 0; column < 3; column++) {
        positive_diagonal = negative_diagonal = 1;
        for (int diagonal_stepper = 0; diagonal_stepper < 3; diagonal_stepper++) {
            positive_diagonal *= this->m_matrix[diagonal_stepper][(column + diagonal_stepper) % 3];
            negative_diagonal *= this->m_matrix[2 - diagonal_stepper][(column + diagonal_stepper) % 3];
        }
        result += positive_diagonal - negative_diagonal;
    }
    return result;
}

double& Matrix33::get(const int row, const int column) {
    if (row < 0 || row < 0 || column > 2 || column > 2 ) {
        throw new IndexOutOfBoundsException();
    }
    return this->m_matrix[row][column];
}
