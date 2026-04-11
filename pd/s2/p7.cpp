/*
    El gobierno del Perú ha publicado los reportes de las temperaturas en grados Celsius de la ciudad de Chosica 
    de n meses (n>=12 y múltiplo de 12). Escriba un programa que elabore un reporte con las siguientes características:

        • La temperatura más alta.
        • La temperatura más baja.
        • La variación más alta de temperaturas entre meses consecutivos mencionando los meses de variación.

    En caso de haber variaciones altas iguales imprimir la última variación alta.
*/

#include <iostream>

int main() {

    int n;

    do {
        std::cin >> n;
    }
    while (!(n >= 12 && n % 12 == 0));

    double max = 0, min = 999999999, prev, maxDif = 0, maxDif_i = 0;
    for (int i = 0; i < n; i++) {
        
        double T;
        std::cin >> T;
        
        if (T > max) {
            max = T;
        }

        if (T < min) {
            min = T;
        }

        if (i > 0) {
            double dif = (T > prev ? (T - prev) : (prev - T));

            if (maxDif < dif) {
                maxDif = dif;
                maxDif_i = i;
            }
        }

        prev = T;
    }

    std::cout << "max: " << max << std::endl;
    std::cout << "min: " << min << std::endl;
    std::cout << " md: " << maxDif << "     @     " << maxDif_i << ", " << (maxDif_i + 1) << std::endl;

    return 0;
}