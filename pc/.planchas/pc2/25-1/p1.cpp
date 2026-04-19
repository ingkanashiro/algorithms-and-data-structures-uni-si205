/*
    Dado un arreglo cuadrado de orden K de enteros de dos cifras, escriba un programa en C++ que solicite al usuario 
    las coordenadas (a, b) de una celda del arreglo y solicite un valor L donde L ≤ K.   
    
    Asuma que las coordenadas (a,b) son la esquina superior izquierda de un subarreglo cuadrado de orden L, y calcule 
    y muestre el producto de los elementos que se encuentran en la diagonal secundaria de este subarreglo. 
    
    Valide que el subarreglo definido sea válido dentro del arreglo original


    [][][][][][][]
    [][][][][][][]
    [][]{}{}{}[][]
    [][]{}{}{}[][]
    [][]{}{}{}[][]
    [][][][][][][]


*/

#include <iostream>
#include <ctime>
#include <random>

int main() {

    // Assuming random generator
    std::random_device rd;
    std::mt19937 g(rd());

    std::uniform_int_distribution randint(0, 99);

    int K;
    std::cin >> K;

    int matrix[K][K];
    for (int i = 0; i < K; i++) for (int j = 0; j < K; j++) {
        matrix[i][j] = randint(g);
    }

    int a, b, L;
    std::cin >> a >> b >> L; 

    if (a > K - 1 || b > K - 1 || a < 0 || b < 0 || a + L >= K || b + L >= K) {
        throw std::runtime_error("could not resolve matrix.");
    }
    
    a--; b--;

    std::cout << std::endl;
    for (int i = 0; i < K; i++) for (int j = 0; j < K; j++) {
        std::cout << (matrix[i][j] < 10 ? " " : "") << matrix[i][j] << (j == K - 1 ? '\n' : ' ');
    }

    std::cout << std::endl << std::endl;
    for (int i = a; i < a + L; i++) for (int j = b; j < b + L; j++) {
        std::cout << (matrix[i][j] < 10 ? " " : "") << matrix[i][j] << (j == b + L - 1 ? '\n' : ' ');
    }

}