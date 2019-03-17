// C++ program to demonstrate 
// accessing of data members 

#include<iostream> 
#include<String>

using namespace std; 

/*

	Question 1

	Smart Pointer 
		Using smart pointers, we can make pointers to work in way that we don’t need to explicitly call delete. Smart pointer is a wrapper 
	class over a pointer with operator like * and -> overloaded. The objects of smart pointer class look like pointer, but can do many 
	things that a normal pointer can’t like automatic destruction (yes, we don’t have to explicitly use delete), reference counting and more.
    	The idea is to make a class with a pointer, destructor and overloaded operators like * and ->. Since destructor is automatically called 
    when an object goes out of scope, the dynamically allocated memory would automatically deleted (or reference count can be decremented). 
    Consider the following simple smartPtr class.

*/

// Question 2
class SmartPointer
	int *ptr;
public:
{
    void getValue(){
        cout << sPointer.getValue(); 
    }

    ~SmartPoiner { delete(ptr) };

}; 

int main() {
    SmartPointer sPointer(11);
} 
