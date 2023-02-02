#include "ComplexNumber.h"
#include "ComplexNumber.cpp"
#include "UserInterface.h"

#include <iostream>
#include <regex>
using namespace std;

ComplexNumber UserInterface::enterComplexNumberPrompt() {
    cout << "A complex number can be entered in the following formats:" << endl;
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
            input.pop_back();

            CartesianCoordinate cartesian = {};
            cartesian.realPart = stod(input.substr(0, input.find('+')));
            cartesian.imaginaryPart = stod(input.substr(input.find('+') + 1));

            ComplexNumber c;
            c.setCartesianValues(cartesian.realPart, cartesian.imaginaryPart);
            return c;
        }

        cout << "Invalid input, try again." << endl;
    }

    string s;
    cin >> s;
    cout << s;
}
