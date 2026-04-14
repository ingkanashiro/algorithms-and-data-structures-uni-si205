/*
    Desarrolle un programa C++, que reciba n (n<10) números enteros positivos y determine un
    nuevo número entero formado por el mínimo digito impar del primero, luego el máximo
    dígito par del segundo número, luego el mínimo dígito impar del tercero y así
    sucesivamente. Asuma que el dígito 0 es par. Si algún número no contiene el digito
    buscado, ignorarlo. 
    
    Ejemplo: si n = 5 y los números ingresados son 2134, 5063, 363, 59359
    y 92793, el resultado será 1633
*/

#include <iostream>

int main() {

    int n;
    std::cin >> n;

    int result = 0;

    for (int i = 0; i < n; i++) {

        int num;
        std::cin >> num;

        bool digitExists = false;   // flag
        int digit;

        if (i % 2 == 0) {

            // get minimum odd digit.
            digit = 11;
            while(num) {

                if (((num % 10) % 2 == 1) && ((num % 10) < digit)) {
                    digit = (num % 10);
                    digitExists = true;
                }

                num /= 10;
            }
        }
        else {

            // get maximum even digit.
            digit = -1;
            if (num == 0) {
                digit = 0;
                digitExists = true;
            }

            while(num) {

                if (((num % 10) % 2 == 0) && ((num % 10) > digit)) {
                    digit = (num % 10);
                    digitExists = true;
                }

                num /= 10;
            }
        }

        if (digitExists) {
            result *= 10;
            result += digit;
        }
    }

    std::cout << "val: " << result << std::endl;

    return 0;
}