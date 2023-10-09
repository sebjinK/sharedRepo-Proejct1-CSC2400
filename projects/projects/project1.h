#ifndef project_H
#define project_H
#include <iostream>
#include <vector>
/*
    File:           project1.h
    Author:         Sebjin Kennedy
    Date:           October 8th, 2023
    Description:    This script holds functions for all three ways of checking GCD
*/

using namespace std;

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
    if (m == 0)
        *y = xStorage - (m / n) * yStorage;
    else
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
    if (m == 0 || n == 0) //if statements to check if m and n fail any 0 checks
    {
        if (n == 0 && m == 0) //if m and n are both 0 they automatically fail
            return 0;
        else if (n == 0) //if m OR n are 0, they automatically return the n OR m respectively
            return m;
        else
            return n;
    }
    int t = min(m, n);//save the minimum of m and n
    while (t > 0) // while loop that checks through t's integer's that lesser than it to see what is its GCD
    {
        if (m % t == 0 && n % t == 0) // use modulo to check if t divides evenly among both of the two inputs m and n
        {
            return t; //finish the while loop
        }
        t--; // iterate through the size of the smaller integer
    }

    return 1; //if no common factor is found
}


/*
use seive of eratosthenes to calculate prime numbers
put those numbers in an array
Args:
    a number input
returns:
    vector array of prime numbers lesser than input
*/
vector<bool> sieveOfEratosthenes(int input)
{
    vector<bool> PrimeCheck(input + 1, true); // vector will check true so as to not go out of bounds
    PrimeCheck[0] = PrimeCheck[1] = false;


    for (int p = 2; p * p <= input; p++) //p is the starting number; we go until p^2 <= input so we don't have collision problems.  
    {                                   //ex. if p = 4 and input = 5, p^2 would be 16 and the process would keep going until p = 5;
        if (PrimeCheck[p]) //primecheck at p is already set to true at creation
        {
            for (int i = p * p; i <= input; i += p) // ex. p = 4 so i = 16; i > input (= 5); so the inner for loop will stop there
            {                                       // i += p due to how some numbers divide evenly but some others don't like 
                                                    // like how 8 divides evenly into 24 but 8 does not.
                PrimeCheck[i] = false; //this will make any NON-prime numbers 
            }
        }
    }
    return PrimeCheck; //return the resulting vector with prime numbers being true and non-primes being false
}
/*
Calculates GCD from m and n and returns GCD
interpreted through middle school procedure
use seive of eratosthenes to calculate prime numbers
put those numbers in an array
match prime numbers
calculate GCD 

Args:
    two number inputs m and n
returns:
    integer containing GCD
*/
int middleSchool(int m, int n)
{
    m = abs(m);
    n = abs(n);
    if (m == 0 || n == 0) //if statements to check if m and n fail any 0 checks
    {
        if (n == 0 && m == 0) //if m and n are both 0 they automatically fail
            return 0;
        else if (n == 0) //if m OR n are 0, they automatically return the n OR m respectively
            return m;
        else
            return n;
    }
    vector<bool> mArray = sieveOfEratosthenes(m);
    vector<bool> nArray = sieveOfEratosthenes(n);
    vector<bool> matching(min(m, n) + 1, true);
    matching[0] = matching[1] = false;
    int GCD = 1;

    for (int i = 2; i <= min(m, n); i++) //run through the smaller of the two arrays
    {
        if (!(mArray[i]) && !(nArray[i])) //check if both are true
            matching[i] = false;
    }
    int j = 2;
    for (int i = 2; i < min(m, n); i++)
    {
        if (matching[i] && m % i == 0 && n % i == 0)
        {
            GCD *= i;
        }
    }
    return GCD; //will return the largest of the two
}
#endif
