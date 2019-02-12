/*************************************
	COMP 322 - Intro to C++
	Assignment 1
	Student Name: Yifan(Andy) Bai
	ID: 260562421
**************************************/

#include <iostream>
#include <string>
#include <cctype>
//#include<bits/stdc++.h>
#include <limits>

using namespace std;

// Question 1 - countLetter
void countLetter()
{
    // Get user inputs
    string s;
    cout << "Please enter a sentence: ";
    getline(cin, s);

    string c;
    cout << "Please enter a letter: ";
    getline(cin, c);

    int count = 0; // Initialize counter
    for (unsigned int i = 0; i < s.length(); i++)
    {
        // Check character in string
        if (tolower(s[i]) == tolower(c[0]))
        {
            count++;
        }
    }

    cout << "The letter " << c << " is repeated " << count << " times in your sentence\n";
};

// char letterCheck(string s)
// {
// 	int i = 0;
//   	if(s.length() == 1){
//   	    if(isalpha(s[0]) == false){
//   	        cout << "ERROR: Invalid input. Please retype.\n";
//   	        cout << "Please enter a letter: ";
//   	        cin >> s;
//   	        letterCheck(s);
//   	    }
//   	} else if (s.length() > 1){
//   	    //redo this
//   	    while(c[i]){
//   	        if(isalpha(c[i])){
//   	            cout << "WARNING: Improper Input. Will proceed with first letter taken as default.\n";
//   	            c[0] = c[i];
//   	            break; //take first strip all
//   	        } else {
//   	            cout << "ERROR: Invalid input. Please retype. Make sure there is at least an alphabet.\n"; //print only once
//   	        }
//   	        i++;
//   	    }
//   	}

// };

// Question 2 - convertPhonetic
void convertPhonetic()
{
    // Get user inputs
    string w;
    cout << "Please enter a word: ";
    getline(cin, w);
    //letterCheck(w);

    // Phonetics, using array of strings and access elements like a 2-D array later
    string phonetics[26] = {"Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel",
                            "India", "Juliett", "Kilo", "Lima", "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo", "Sierra",
                            "Tango", "Uniform", "Victor", "Whiskey", "X-ray", "Yankee", "Zulu"};

    string str;
    // Loop through each letter in the word
    for (unsigned int i = 0; i < w.length(); i++)
    {
        // Look through each word in the phonetics
        for (unsigned int j = 0; j < 26; j++)
        {
            if (tolower(w[i]) == tolower(phonetics[j][0]))
            {
                str.append(phonetics[j]);
                str += ' '; // Add space between words
            }
        }
    }
    str.pop_back(); // Remove the last space character in the sentence

    cout << str << endl;
};

// int wordCheck(string s)
// {
// 	int count=0;
// 	for(int i = 0; i<s.length(); i++){
// 		if(isalpha(s[i]) == true){
// 			//
// 			count += 1;
// 		} else {
// 			//
// 			count += 0;
// 		}
// 	};
// 	if(count == 0){
// 		cout << "No alphabet detected. \n"
// 		string t;
// 		cout << "Please enter a word: "
// 		getline(cin, t);
// 		s = t;
// 	} else if(count <= s.length()){
// 		cout << "WARNING: Non-alphabets detected and will be ignored."
// 	}
// 	return s;
// };

/*
	Question 3

	a) A recursive function is tail recursive when recursive call is the last thing executed by the function. 
  It is considered better than non tail recursive functions as it can be optimized by compiler. The idea used 
  by compilers to optimize tail-recursive functions is simple: since the recursive call is the last statement, 
  there is nothing left to do in the current function, so no need to save current function’s stack frame

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
*/

// Question 4
unsigned factorialTR(unsigned int n, unsigned int a)
{
    if (n == 0)
        return a;

    return factorialTR(n - 1, n * a);
}

void factorial()
{
    string x;
    cout << "Please enter a number: ";
    getline(cin, x);
    unsigned int m = stoi(x);
    cout << "The factorial of " << m << " is " << factorialTR(m, 1) << "\n";
};

// Question 5
unsigned enhancedFactorialTR(unsigned int n, unsigned int a)

{
    if (n == 0)
        return a;
    if (n == 6)
        return 720 * a;
    else
    {
        return factorialTR(n - 1, n * a);
    };
}

void enhancedFactorial()
{
    // Input handling
    string x;
    cout << "Please enter a number: ";
    getline(cin, x);
    unsigned int m = stoi(x);

    int foo[6] = {1, 2, 6, 24, 120, 720};

    if (m > 0 && m < 7)
    {
        // If the number is within the range of 1 to 6, no need to recursively compute
        cout << "The factorial of " << m << " is " << foo[m - 1] << "\n";
    }
    else
    {
        cout << "The factorial of " << m << " is " << factorialTR(m, 1) << "\n";
    }
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