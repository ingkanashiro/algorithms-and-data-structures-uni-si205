/*
    Diseñe un algoritmo que reciba “n” (n<=50) números enteros (de 2 y 3 cifras) y los almacene en un arreglo 
    (entre los “n” números deben existir números primos). Luego calcule el promedio de los elementos del arreglo. 
    
    Luego proceda a eliminar los números pares menores al promedio y a duplicar (es decir, hacer que aparezcan 2 veces) 
    los números primos mayores al promedio anteriormente calculado.
    
    Al terminar el proceso debe mostrar el arreglo resultante. Sólo debe utilizar una variable arreglo para realizar 
    todas las operaciones mencionadas. No debe utilizar funciones.

*/

#include <iostream>

int main() {

    int n;
    std::cin >> n;

    int array[2*n - 1]; // array <> ptr
    double avg = 0;

    bool includesPrime = false;

    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
        avg += array[i];

        if (!includesPrime) {
            bool isPrime = true;
            for (int k = 2; k < array[i]; k++) {
                if (array[i] % k == 0) {
                    isPrime = false;
                    break;
                }
            }

            includesPrime = isPrime;
        }
    }

    for (int i = n; i < 2*n - 1; i++) {
        array[i] = 0;
    }

    if (!includesPrime) {
        throw std::runtime_error("no primes? :(");
    }

    avg /= n;

    /*
        Luego proceda a eliminar los números pares menores al promedio y a duplicar (es decir, hacer que aparezcan 2 veces) 
        los números primos mayores al promedio anteriormente calculado.
    */

    int len = n;
    for (int i = 0; i < 2*n - 1; i++) {

        if (array[i] == 0) break;

        bool isPrime = true;
        for (int k = 2; k < array[i]; k++) {
            if (array[i] % k == 0) {
                isPrime = false;
                break;
            }
        }

        if (array[i] % 2 == 0 && array[i] < avg) {
            len--;
            
            for (int j = i; j < 2*n - 1; j++) {
                array[j] = array[j+1];
            }

            array[2*n - 2] = 0;
            
            i--;
            continue;
        }

        if (isPrime && array[i] > avg) {
            for (int j = 2*n - 1; j > i; j--) {
                array[j] = array[j-1];
            }

            len++;
            i++;
            continue;
        }
    }

    for (int i = 0; i < len; i++) {
        std::cout << array[i] << " ";
    }


    return 0;
}