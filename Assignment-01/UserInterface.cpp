#include "UserInterface.h"

#include <iostream>
#include <regex>
using namespace std;

void UserInterface::runApplication() {
    this->currentComplexNumber = this->enterComplexNumberPrompt();
    this->printCartesianForm();
    this->printPolarForm();
}

ComplexNumber UserInterface::enterComplexNumberPrompt() {
    cout << "A complex number can be entered in the following formats:" << endl;
    cout << "WARNING: only positive input values are supported at the moment." << endl;
    cout << "x+yi  (cartesian)" << endl;
    cout << "example: 2+5i" << endl;
    cout << "P(r,φ)  (polar)(φ in degrees, not radians)" << endl;
    cout << "example: P(3,180)" << endl << endl;

    while (true) {
        string input;
        cout << "Please enter a complex number: ";
        cin >> input;

        regex cartesianRegex("^\\d+\\+\\d+i$");
        if (regex_match(input, cartesianRegex)) {
            cout << endl;

            input.pop_back();

            CartesianCoordinate cartesian = {};
            cartesian.realPart = stod(input.substr(0, input.find('+')));
            cartesian.imaginaryPart = stod(input.substr(input.find('+') + 1));

            ComplexNumber c;
            c.setCartesianCoordinate(cartesian);
            return c;
        }

        regex polarRegex("^P\\(\\d+,\\d+\\)$");
        if (regex_match(input, polarRegex)) {
            cout << endl;

            string trimmedInput = input.substr(2, input.size()-3);

            PolarCoordinate polar = {};
            polar.length = stod(trimmedInput.substr(0, trimmedInput.find(',')));
            polar.angleInDegrees = stod(trimmedInput.substr(trimmedInput.find(',') + 1));

            ComplexNumber c;
            c.setPolarCoordinate(polar);
            return c;
        }

        cout << "Invalid input, try again." << endl;
    }
}

void UserInterface::printCartesianForm() {
    cout<< "cartesian form: "
        << this->currentComplexNumber.getCartesianCoordinate().realPart
        << " + "
        << this->currentComplexNumber.getCartesianCoordinate().imaginaryPart
        << 'i'
        << endl;
}

void UserInterface::printPolarForm() {
    cout<< "polar form: P("
        << this->currentComplexNumber.getPolarCoordinate().length
        << ", "
        << this->currentComplexNumber.getPolarCoordinate().angleInDegrees
        << ')'
        << endl;
}