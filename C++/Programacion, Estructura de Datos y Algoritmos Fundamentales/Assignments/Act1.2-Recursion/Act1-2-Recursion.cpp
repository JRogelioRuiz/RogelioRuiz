# include <iostream>
using namespace std;

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


// Suma con Formula 

int sumFormula (int n) {
    return n * (n+1) / 2;
}

// Fibonacci iterative

int fibonacciIterative (int n) {
    if (n == 1 || n == 2) {
        return 1;
    } else {
        int a = 1;
        int b = 1;
        int fib = 0;
        for (int i = 0; i < (n-2); i++) {
            fib = a + b;
            a = b;
            b = fib;
        }
        return fib;
    }
}

// Fibonacci con recursividad

int fibonacciRecursive (int n) {
    
    if (n == 1 || n == 2) {  
        return 1;
    } else {
        return fibonacciRecursive(n-2) + fibonacciRecursive(n-1);
    }
}

// Bacterias iterative

int bacteriasIterative (int n) {
    int bact = 1;
    float rate = 3.78-2.34;

    for (int i = 0; i < n; i++) {
        bact = bact + bact*rate;
    }
    return bact;
}

// Bacterias con recursividad

int bacteriasRecursive (int n) {    
    if (n > 0) {
        return bacteriasRecursive(n-1) * (1+1.44);
    } else {
        return 1;
    }
}

// Investment Iterative

int investmentIterative(int balance, int months) {
    float rate = 18.75;
    for (int i = 1; i <= months; i++) {
        balance = balance * (1+ rate/100);
    }
    return balance;
}

// Investment Recursive

int investmentRecursive(int balance, int months) {
    float rate = 18.75;
    if (months > 0) {
        return investmentRecursive(balance, months-1) * (1 + rate/100);
    } else {
        return balance;
    }
    
}

// power iterative

int powIterative(int n, int y) {
    int num = 1;
    for (int i = 0; i < y; i++) {
        num = num *n;
    }
    return num;
} 

// power recursive

int powRecursive(int n, int y) {
    if (y == 1) {
        return n;
    }  else {
       return powRecursive(n,y-1)*n; 
    }
} 


int main() {

    int n1 = 10;
    int n2 = 5;

    cout << "La suma de 1 hasta " << n1 << " es: "<<sumIterative(n1)<< " [iterativa]"<<endl;
    cout << "La suma de 1 hasta " << n1 << " es: "<<sumRecursive(n1)<< " [recursiva]"<<endl;
    cout << "La suma de 1 hasta " << n1 << " es: "<<sumFormula(n1)<< " [formula]"<<endl;
    cout << "El numero de fibonacci en la posicion " << n1 << " es: "<<fibonacciIterative(n1)<< " [iterativa]"<<endl;
    cout << "El numero de fibonacci en la posicion " << n1 << " es: "<<fibonacciRecursive(n1)<< " [recursiva]"<<endl;
    cout << "El numero de bacterias en el dia " << n1 << " es: "<<bacteriasIterative(n1)<< " [iterativa]"<<endl;
    cout << "El numero de bacterias en el dia " << n1 << " es: "<<bacteriasRecursive(n1)<< " [recursiva]"<<endl;
    cout << "El dinero en el mes " << n1 << " es: "<<investmentIterative(1000,10)<< " [iterativa]"<<endl;
    cout << "El dinero en el mes " << n1 << " es: "<<investmentRecursive(1000,10)<< " [recursiva]"<<endl;
    cout << "El número " << n1 << " elevado a la potencia " << n2 << " es: "<<powIterative(n1,n2)<< " [iterativa]"<<endl;
    cout << "El número " << n1 << " elevado a la potencia " << n2 << " es: "<<powRecursive(n1,n2)<< " [recursiva]"<<endl;
    
    return 0;
}

