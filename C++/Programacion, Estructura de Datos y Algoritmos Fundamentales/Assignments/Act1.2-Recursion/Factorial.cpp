# include <iostream>
using namespace std;

int factorial(int n) {
    if (n > 0) {
        return n * factorial(n-1);   
    } else {
        return 1;
    }
}

int factorialI(int n) {
    if (n > 1) {
    int fact = 1;
    for(int i = 1; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
    } else {
        return 1;
    } 

}

// Suma iterativa

int sumIterative(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum = sum + i;
    }

    return sum;

}

// Suma recursive

int sumRecursive(int n) {
    if (n > 1) {
        return n + sumRecursive(n-1);
    } else {
        return 1;
    }
}

// Suma Directa

int sumFormula (int n) {
    return n * (n+1) / 2;
}

int main() {
    int n = 4;
    int n1 = 5;

    cout << "El factorial de " << n << " es: "<<factorial(n)<<endl;
    cout << "El factorial de " << n << " es: "<<factorialI(n)<<endl;
    cout << "La suma de 1 hasta " << n1 << " es: "<<sumIterative(n1)<<endl;
    cout << "La suma de 1 hasta " << n1 << " es: "<<sumRecursive(n1)<<endl;
    cout << "La suma de 1 hasta " << n1 << " es: "<<sumFormula(n1)<<endl;

    return 0;
}

