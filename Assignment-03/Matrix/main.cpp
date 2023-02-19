#include <iostream>
#include "Matrix.h"
#include "IndexOutOfBoundsException.h"

/*
Bearbeiten Sie die Aufgaben der Reihe nach direkt im Quellcode.
Sie koennen die Beschreibungen zur Aufgabenstellung loeschen, aber bitte
lassen Sie die Markierungen, wo welche Aufgabe beginnt im Quellcode!

Hinweis: Bitte geben Sie nur die Quelldateien ohne das Visual Studio Projekt ab!
*/

int main()
{
    
	
    // ------------------------------------------------------------------------
    // 1. Aufgabe (Referenzen)
    // ------------------------------------------------------------------------
    
    std::cout<<"\n\nAufgabe 1\n=========\n" <<std::endl;
    
	// Wo steckt der eigentliche Konstruktoraufruf bei der folgenden Anweisung?
    // Innerhalb der implimentierung von Matrix33::ones().

	// Wieso kann die Funktion ones() mit dem Scope-Operator, ohne Objekt aufgerunfen werden?
    // Weil die Funktion statisch ist.
	Matrix33 mat1 = Matrix33::ones();
	
    // Ueber die Funktion Matrix33::get koennen sie einen Wert in der Matrix abfragen:
    std::cout<<"Wert in Matrix(2,2): " << mat1.get(1, 1) <<std::endl;

    // veraendern Sie die Funktion Matrix33::get so, 
    // dass Sie ueber diese Funktion auch Werte verändern koennen:
	// Hinweis: Rueckgabewert als Referenz
    mat1.get(1, 1) = 5;

    std::cout<<mat1.toString() <<std::endl; 

	
    // ------------------------------------------------------------------------
    // 2. Aufgabe (Operatoren)
    // ------------------------------------------------------------------------
    
    std::cout<<"\n\nAufgabe 2\n=========\n" <<std::endl;
    
    Matrix33 matA(-1,0,3,  2,-2.5,1,  -4,1.5,-1);
    Matrix33 matB(1,0,1,  1.5,0,0,  2.5,-1.5,-2);
    
    // Implementieren Sie die noetigen Operatoren in der Klasse, damit folgende
    // Ausdruecke richtig funktionieren und geben Sie nach jeder Rechnung die Ergebnisse aus:
    
    Matrix33 matResult1 = matA + matB;
    // std::cout << "Matrix33 matResult1 = matA + matB;" << std::endl;
    // std::cout << matResult1.toString() << std::endl;
    Matrix33 matResult2 = matA * matB;
    // std::cout << "Matrix33 matResult2 = matA * matB;" << std::endl;
    // std::cout << matResult2.toString() << std::endl;
    Matrix33 matResult3 = matA * 5;
    // std::cout << "Matrix33 matResult3 = matA * 5;" << std::endl;
    // std::cout << matResult3.toString() << std::endl;
    matResult1 += matB;
    // std::cout << "matResult1 += matB;" << std::endl;
    // std::cout << matResult1.toString() << std::endl;
    Matrix33 matC = matResult2 += matB;
    // std::cout << "Matrix33 matC = matResult2 += matB;" << std::endl;
    // std::cout << matC.toString() << std::endl;


    
    // ------------------------------------------------------------------------
    // 3. Aufgabe (Operatoren)
    // ------------------------------------------------------------------------
    
    std::cout<<"\n\nAufgabe 3\n=========\n" <<std::endl;
    
    // Testen Sie folgende Anweisung:
    Matrix33 matResult4 = 5 * matA;
    // std::cout << "Matrix33 matResult4 = 5 * matA;" << std::endl;
    // std::cout << matResult4.toString() << std::endl;

    // Warum funktioniert die Anweisung nicht? L�sen Sie das Problem!
    

    // ------------------------------------------------------------------------
    // 4. Aufgabe (Konvertierungsoperator)
    // ------------------------------------------------------------------------
    
    std::cout<<"\n\nAufgabe 4\n=========\n" <<std::endl;
    
    Matrix33 matZ(1,3,5,  1,-2,1, 1.5, 3.5, -4);
    // Erzeugen Sie einen Konvertierungsoperator, so dass folgender Ausdruck klappt.
    double det = matZ;
    // std::cout << "double det = matZ;" << std::endl;
    // std::cout << det << std::endl;

    // Der Konvertierungsoperator soll die Determinante der Matrix zurueckgeben.
    // Hinweis: http://de.wikipedia.org/wiki/Determinante#Berechnung
    
    // ------------------------------------------------------------------------
    // 5. Aufgabe (Exception)
    // ------------------------------------------------------------------------
    
    std::cout<<"\n\nAufgabe 5\n=========\n" <<std::endl;
    
    Matrix33 matX(1,3,5,  1,-2,1, 1.5, 3.5, -4);
    // Implementieren Sie ein Exceptionhandling mit einer extra definierten
	// Exceptionklasse. Ein Objekt dieser Klasse soll geworfen werden, wenn 
    // bei der Verwendung der get-Funktion fehlerhafte Indizes eingegeben werden
	// z.B.
	
    try {
        double y = matX.get(3,3);
    } catch (IndexOutOfBoundsException*) {
        std::cout << "Phew, that was close. Almost crashed the program." << std::endl;
        std::cout << "I should probably fix that..." << std::endl;
    }
    
    return 0;
}
