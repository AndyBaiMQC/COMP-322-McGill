/*************************************
	COMP 322 - Intro to C++
	Assignment 1
	Student Name: Yifan(Andy) Bai
	ID: 260562421
**************************************/

#include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;

// Question 1 - countLetter
void countLetter(){
	// Get user inputs
	string s;
	cout << "Please enter a sentence: ";
	cin >> s;

  	string c;
	cout << "Please enter a letter: ";
  	cin >> c;

  	int count = 0;		// Initialize counter
  	for(unsigned int i = 0; i < s.length(); i++){
		// Check character in string
		if(tolower(s[i]) == tolower(c[0])){ 
			count++;
		}
	}

  	cout << "The letter " << c << " is repeated " << count << " times in your sentence\n";
};

// Question 2 - convertPhonetic
void convertPhonetic(){
	// Get user inputs
	string w;
	cout << "Please enter a word: ";
	cin >> w;

	// Phonetics, using array of strings and access elements like a 2-D array later
	string phonetics[26] = {"Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel",
	"India", "Juliett", "Kilo", "Lima", "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo", "Sierra", 
	"Tango", "Uniform", "Victor", "Whiskey", "X-ray", "Yankee", "Zulu"};

    string str;
    // Loop through each letter in the word
    for(unsigned int i=0; i<w.length(); i++){
    	// Look through each word in the phonetics
        for(unsigned int j=0; j<26; j++){
            if(tolower(w[i]) == tolower(phonetics[j][0])){
                str.append(phonetics[j]);
                str += ' '; // Add space between words
            }
        }
    }
    str.pop_back(); // Remove the last space character in the sentence

    cout << str << endl;
};


/*
	Question 3
	a) Tail recurisivity refers to recursion in a recursive function whereby the 
	   recursive	
*/

// Question 4
void factorial(){
    string x;
    cout << "Please enter a number: ";
    cin >> x;
    unsigned int m = stoi(x);
    cout << "The factorial of " << m << " is " << fact(m);
};

unsigned int fact(unsigned int n) 
{ 
	if (n == 0) return 1; 

	return n*fact(n-1); 
};

// Question 5
// void enhancedFactorial(){
// 	//todo
	
// };

// Main Function
int main(){

	countLetter();
	convertPhonetic();
	factorial();
	// enhancedFactorial();

	return 0;
};