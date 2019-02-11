#include<iostream>
#include<string>
#include<cctype>
#include<bits/stdc++.h>

using namespace std;

unsigned factorialTR(unsigned int n, unsigned int a) 

{ 
    if (n == 0){
        return a;
    else {
        if(n > 6){
            return factorialTR(n-1, n*a);
        } else {
            return factorialTR(720, n*a);
        }
    }
} 

void factorial()
{
    // Input handling
    string x;
    cout << "Please enter a number: ";
    getline(cin, x);

    unsigned int m = stoi(x);
    int foo[6] = {1, 2, 6, 24, 120, 720};

    if(m > 0 && m < 7){
        // Handle base case
        cout << "The factorial of " << m << " is " << foo[n-1];
    } else  {
        cout << "The factorial of " << m << " is " << factorialTR(m, 1);
    }
};

int main()
{
    factorial();
}