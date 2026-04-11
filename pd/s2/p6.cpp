/*
Escriba un programa que permita ingresar las notas de n alumnos (n < 30) de la primera practica calificada de Física 
y devuelva lo siguiente:

    • Promedio de notas aprobadas (nota mayor o igual a 10).
    • Promedio de notas desaprobadas (nota menor a 10).
    • Mayor nota.
    • Menor nota.
*/

#include <iostream>

int main() {

    int n;
    std::cin >> n;

    double avgPass, avgFail, max = 0, min = 20;
    int numPass = 0, numFail = 0;

    while (n--) {

        double g;
        std::cin >> g;

        if (g >= 10) {
            avgPass += g;
            numPass++;
        }
        else {
            avgFail += g;
            numFail++;
        }

        if (g > max) {
            max = g;
        }

        if (g < min) {
            min = g;
        }
    }

    avgPass /= numPass;
    avgFail /= numFail;

    std::cout << "avg-p: " << avgPass << std::endl;
    std::cout << "avg-f: " << avgFail << std::endl;
    std::cout << "  max: " << max << std::endl;
    std::cout << "  min: " << min << std::endl;

    return 0;
}