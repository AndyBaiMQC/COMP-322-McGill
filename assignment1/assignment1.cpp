/*************************************
	COMP 322 - Intro to C++
	Assignment 1
	Student Name: Yifan(Andy) Bai
	ID: 260562421
**************************************/

#include <iostream>
#include <string>
#include <cctype>
#include<bits/stdc++.h>
#include <limits>

using namespace std;

// Question 1 - countLetter
void countLetter()
{
    // Get user inputs
    string s;
    cout << "Please enter a sentence: ";
    cin.ignore(0, '\n');
    getline(cin, s);

    string c;
    while(true)
    {
        // Get user inputs (letter)
        cout << "Please enter a letter: ";
        cin.ignore(0, '\n'); /Ignore spaces/numbers
        getline(cin, c);

        // Check if input is letter. Invalid if length bigger than 1, or not alphabet
        if (!isalpha(c[0]) or c.length() > 1)   cout << "Invalid input. Please try again." << endl;
        else break;
    }

    int count = 0; // Initialize counter
    for (unsigned int i = 0; i < s.length(); i++)
    {
        if (tolower(s[i]) == tolower(c[0]))   count++; // Check character in string
    }

    string t;
    if (count == 0 || count == 1)   t = "time";
    else    t = "times";

    cout << "The letter " << c << " is repeated " << count << " " << t << " in your sentence\n";
};

// Question 2 - convertPhonetic
void convertPhonetic()
{
    // Get user inputs
    string w;
    cout << "Please enter a word: ";
    cin.ignore(0, '\n'); //Ignore spaces/numbers
    getline(cin, w);

    // Phonetics, using array of strings and access elements like a 2-D array later
    string phonetics[26] = {"Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima", "Mike", 
    "November", "Oscar", "Papa", "Quebec", "Romeo", "Sierra", "Tango", "Uniform", "Victor", "Whiskey", "X-ray", "Yankee", "Zulu"};

    string str;
    for (unsigned int i = 0; i < w.length(); i++) // Loop through each letter in the word
    {      
        for (unsigned int j = 0; j < 26; j++) // Look through each word in the phonetics
        {
            if (tolower(w[i]) == tolower(phonetics[j][0]))
            {
                str.append(phonetics[j]);
                str += ' '; // Add space between words
            }
        }
    }
    str.pop_back(); // Remove the last space character in the sentence

    cout << str << endl; // Print out the final result
};

/*
	Question 3

	a) A recursive function is tail recursive when recursive call is the last thing executed by the function. 
  It is considered better than non tail recursive functions as it can be optimized by compiler. The idea used 
  by compilers to optimize tail-recursive functions is simple: since the recursive call is the last statement, 
  there is nothing left to do in the current function, so no need to save current function’s stack frame. 
  
  For example below is a tail-recursion implemented for calculating factorial:
  int sum = 0;
  int sum(x, sum)  
  {
    if (x==0) return sum;
    else return sum(x-1, sum+x);
  }
    sum(5,0)
  = sum(4,5)
  = sum(3,9)
  = sum(2,12)
  = sum(1,14)
  = sum(0,15)
  = 15

  Had it not been tail-recursive, it would re-call the returned value every single time:
  int sum(x) 
  {
    if (x==1) return x;
    else return (x + sum(x-1));
  }
    sum(5)
  = 5 + sum(4)
  = 5 + 4 + sum(3)
  = 5 + 4 + 3 + sum(2)
  = 5 + 4 + 3 + 2 + sum(1)
  = 5 + 4 + 3 + 2 + 1
  = 15

  b) Consider the function to calculate factorial of n. It is non-tail-recursive. By code inspection, we can see 
  the value returned by fact(n-1) is used in fact(n), so the call to fact(n-1) is not the last thing done by fact(n)

  #include<iostream>
  using namespace std; 

  // A NON-tail-recursive function. The function is not tail 
  // recursive because the value returned by fact(n-1) is used in 
  // fact(n) and call to fact(n-1) is not the last thing done by fact(n) 
  
  unsigned int fact(unsigned int n) 
  { 
    if (n == 0) return 1; 
    return n*fact(n-1); 
  } 
  // Driver program to test above function 
  int main() 
  { 
    cout << fact(5); 
    return 0; 
  } 

  The above function can be written as a tail recursive function. The idea is to use one more argument and 
  accumulate the factorial value in second argument. When n reaches 0, return the accumulated value.

  However, if the number of substeps produced at each step is more than 1 (substantially recursive), tail 
  recursion cannot be done. To implement such an algorithm tail-recursively, additional storage would be 
  required to store pending sub-problems. An example of this is tree traversal, whereby each parent might 
  have 2 or more children. Such a recursive algorithm would not be able to be implemented tail recursively. 
*/

// Question 4
unsigned long int factorialTR(unsigned long int n, unsigned long int a)
{
    if (n == 0)   return a;
    return factorialTR(n - 1, n * a);
}

void factorial()
{
    // Get user inputs
    unsigned long int n;
    while(true)
    {
        cout << "Please enter a number: ";    // 21! is larger than long int data type can store
        cin >> num;
        if (cin.fail() or num < 0 or num > 20)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please try again. Make sure you enter a positive integer that is smaller than 21." << endl;
        }
        else break;
    }

    cout << "The factorial of " << m << " is " << factorialTR(m, 1) << endl;
};

// Question 5
unsigned enhancedFactorialTR(unsigned int n, unsigned int a)
{
    if (n == 0)   return a; // Base case
    if (n == 6)   return 720 * a; // Stop when reached 6 (use pre-calculated value)
    else   return enhancedFactorialTR(n - 1, n * a);
}

void enhancedFactorial()
{
    // Input handling
    string x;
    cout << "Please enter a number: ";
    getline(cin, x);
    unsigned int m = stoi(x);

    int foo[6] = {1, 2, 6, 24, 120, 720};

    // If the number is within the range of 1 to 6, no need to recursively compute; else, call Tail Recursion
    if (m > 0 && m < 7)   cout << "The factorial of " << m << " is " << foo[m - 1] << endl;
    else   cout << "The factorial of " << m << " is " << enhancedFactorialTR(m, 1) << endl;
};

// Main Function
int main()
{
    countLetter();
    convertPhonetic();
    factorial();
    enhancedFactorial();

    return 0;
};