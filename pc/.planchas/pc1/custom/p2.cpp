/*
    Diseñe un programa que solicite al usuario tres números enteros que representan el Día, Mes y Año de una fecha. 
    El programa debe hacer dos cosas: primero, validar si la fecha ingresada existe realmente en el calendario; 
    segundo, si la fecha es válida, calcular e imprimir exactamente la fecha del día siguiente.

    Regla de oro (año bisiesto): un año es bisiesto (febrero tiene 29 días) si es divisible por 4. 
    Sin embargo, si termina en dos ceros (como 1900 o 2100), no es bisiesto, a menos que también sea 
    divisible por 400 (como el 2000, que sí fue bisiesto).

    Restricciones: está prohibido usar arreglos para guardar los días de los meses 
    (por ejemplo, int dias[] = {31, 28, 31...}). También está prohibido usar la librería <ctime>. Todo debe hacerse 
    usando if, else if o switch.

    Ejemplos para tu prueba de escritorio:
    
        Entrada: 28 2 2024 → Análisis: 2024 es bisiesto, febrero tiene 29. 
        → Salida: Fecha válida. El día siguiente es: 29 / 2 / 2024.
        
        Entrada: 28 2 2023 → Análisis: 2023 NO es bisiesto, febrero llega hasta 28. 
        → Salida: Fecha válida. El día siguiente es: 1 / 3 / 2023.
        
        Entrada: 31 12 2026 → Análisis: Fin de año. 
        → Salida: Fecha válida. El día siguiente es: 1 / 1 / 2027.
        
        Entrada: 31 4 2026 → Análisis: Abril solo tiene 30 días. 
        → Salida: Error: Fecha inválida.
*/

#include <iostream>

int main() {

    int dd, mm, yy;

    std::cin >> dd >> mm >> yy;
    
    int maxDayCount;
    switch (mm) {
        case 1:     maxDayCount = 31; break;
        case 2:     maxDayCount = (((yy % 4 == 0) && (!(yy % 100 == 0) || (yy % 400 == 0))) ? 29 : 28); break;
        case 3:     maxDayCount = 31; break;
        case 4:     maxDayCount = 30; break;
        case 5:     maxDayCount = 31; break;
        case 6:     maxDayCount = 30; break;
        case 7:     maxDayCount = 31; break;
        case 8:     maxDayCount = 30; break;
        case 9:     maxDayCount = 30; break;
        case 10:    maxDayCount = 31; break;
        case 11:    maxDayCount = 30; break;
        case 12:    maxDayCount = 31; break;
        
        default:    maxDayCount = 0; break;
    }
    
    // Check if valid

    bool validDay = (dd > 0 && dd <= maxDayCount); 
    bool validMonth = (mm > 0 && mm <= 12);

    if (!validDay || !validMonth) {
        std::cout << "input not valid." << std::endl;
        return 0;
    }

    // Find next day
    dd++;

    if (dd > maxDayCount) {
        dd = 1;
        mm++;

        if (mm > 12) {
            mm = 1;
            yy++;
        }
    }

    std::cout << "tomorrow: " << dd << "/" << mm << "/" << yy << std::endl;
    return 0;
}