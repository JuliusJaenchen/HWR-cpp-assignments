#include "Kreis.h"
#include "Rechteck.h"
#include <iostream>
using namespace std;

int main() {
    Kreis foo(4, 5, 3);
    cout << foo.toString() << endl;

    ZeichenElement* elements[10];
    int cursor = 0;

    while (true) {
        string input;
        cout << "Bitte wählen Sie ein Element (Rechteck/Kreis): ";
        cin >> input;
        if (input == "Kreis") {
            string xCoordInput, yCordInput, radiusInput;
            cout << "Bitte geben Sie eine X Koordinate an: "; cin >> xCoordInput;
            cout << "Bitte geben Sie eine Y Koordinate an: "; cin >> yCordInput;
            cout << "Bitte geben Sie ein Radius an: "; cin >> radiusInput;
            elements[cursor] = new Kreis(stod(xCoordInput), stod(yCordInput), stod(radiusInput));
        } else if (input == "Rechteck") {
            string xCoordInput, yCordInput, lengthInput, widthInput;
            cout << "Bitte geben Sie eine X Koordinate an: "; cin >> xCoordInput;
            cout << "Bitte geben Sie eine Y Koordinate an: "; cin >> yCordInput;
            cout << "Bitte geben Sie eine Länge an: "; cin >> lengthInput;
            cout << "Bitte geben Sie eine Breite an: "; cin >> widthInput;
            elements[cursor] = new Rechteck(stod(xCoordInput), stod(yCordInput), stod(lengthInput), stod(widthInput));
        } else {
            cout << "Ungültige Eingabe, bitte versuchen Sie es erneuert." << endl;
            continue;
        }


        if (cursor == 9) {
            cout << "Maximale Anzahl an Grafiken (10) erreicht." << endl;
            break;
        }
        string wantsToContinue;
        cout << "Möchten Sie ein weiteres Element hinzufügen? (y/n): ";
        cin >> wantsToContinue;
        if (wantsToContinue == "y") {
            cursor++;
            continue;
        }
        break;
    }

    cout << endl;
    cout << "Ihre eingegebenen Grafiken: " << endl;
    double rectangleArea = 0.0;
    double circleArea = 0.0;
    for (int i = 0; i <= cursor; i++) {
        cout << elements[i]->toString() << endl;
        if (dynamic_cast<Rechteck*>(elements[i]) != nullptr) {
            rectangleArea += elements[i]->area();
        } else if (dynamic_cast<Kreis*>(elements[i]) != nullptr) {
            circleArea += elements[i]->area();
        }
    }
    cout << endl;
    cout << "Die Gesamtfläche Ihrer " << cursor + 1 << " Grafiken beträgt " << rectangleArea + circleArea;
    cout << endl;
    cout << "Die Gesamtfläche Ihrer Kreise beträgt " << circleArea << endl;
    cout << "Die Gesamtfläche Ihrer Rechtecke beträgt " << rectangleArea << endl;
}
