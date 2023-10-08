#ifndef project_H
#define project_H
#include <iostream>
/*
    File:           project1.h
    Author:         Sebjin Kennedy
    Date:           October 8th, 2023
    Description:    This script holds functions for all three ways of checking GCD
*/

using namespace std;
/*
int euclidsAlgo(int m, int n)
{
    int remainder;
    do
    {
        remainder = m % n;
        cout << "\ngcd(" << m << ", " << n << ") = gcd (" << n << ", " << "(" << m << " % " << n << "))";
        m = n;
        n = remainder;
    } while (n != 0);
    cout << endl << m;
    return m;
}
*/

/*
Calculates GCD from m and n and returns m(x) + n(y)
Interpreted through the Extended Euclidean Algorithm
Args:
    two numbers m and n. Two null pointers x and y
returns:
    GCD
*/
int extendedEuclidsAlgo(int m, int n, int *x, int *y)
{
    if (n == 0) //base case
    {
        *x = 1;
        *y = 0;
        return m;
    }
    /*
    recursive call to find the GCD of two numbers
    and store their values in variables x and y.
    The value returned by this function is the greatest common divisor of a and b
    which can be found using the formula: g=gcd(a,b)=gcd(b%a,a).
    */
    int xStorage, yStorage; //stores the resulting coefficients

    int gcd = extendedEuclidsAlgo(n, m % n, &xStorage, &yStorage); // euclid's takes over--does this multiple times until it reaches the base case
    //recursive calls for calculating the new coefficients

    *x = yStorage;
    *y = xStorage - (n / m) * yStorage;
    return gcd;
}

/*
Calculates GCD from m and n and returns GCD
Interpreted through the consectutive integer checking algorithm

Args:
    two numbers m and n
returns:
    GCD
*/
int consecutiveIntCheckAlgorithm(int m, int n)
{
    m = abs(m);
    n = abs(n);
    if (m == 0 || n == 0)
    {
        if (n == 0 && m == 0)
            return 0;
        else if (n == 0)
            return m;
        else
            return n;
    }
    int smaller = min(m, n);
    while (smaller > 0)
    {
        if (m % smaller == 0 && n % smaller == 0)
        {
            return smaller;
        }
        smaller--;
    }

    return 1; //if no common factor is found
}


/*
Calculates GCD from m and n and returns GCD
interpreted through middle school procedure
(use seive of eratosthenes to calculate prime numbers)
(put those numbers in an array)
(compare array m and array n and find matching vlaues)
(put those into seperate array and multiply all elements of final array together)
Args:
    two numbers m and n
returns:
    GCD
*/
/*
int sieveOfEratosthenes(int m, int n)
{
    //Implements sieve of Eratosthenes
    //Input:    A positive integer n > 1
    //Output:   Array L of all prime numbers less than or equal to n

    int * A;
    int j;
    int p;
    int * L;
    A = new int[m * n];

    for (int i = 2; i < m; i++)
    {
        A[i] = i;
    }

    for (int i = 2; i < sqrt(m); i++)
    {
        if (A[i] != 0)
        {
            j = i * i;

            while (j <= m)
            {
                A[j] = 0;
                j += i;
            }
        }
        
    }
    p = 0;
    for (int i = 2; i < m; i++)
    {
        if (A[i] != 0)
        {
            L[i] = A[i];
        }
    }

    return -1; //return L;
}

*/
/*
use function to implement sieve twice
use a varaible (ans = 1) and multiply the common primes by it 
return the primes and output the GCD
*/
#endif
