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

int main() {

// For SmartPointer class
cout << "Testing SmartPointer class" << endl;

// Testing Constructors
cout << "Creating a SmartPointer of type int with value 11" << endl;
SmartPointer<int> SmartIntPointer1(11);
cout << "SmartIntPointer1 = " << SmartIntPointer1.getValue() << endl;

cout << "Creating a SmartPointer of type int with value -1" << endl;
SmartPointer<int> SmartIntPointer(-1);

cout << "Creating a SmartPointer of type int with no value provided" << endl;
SmartPointer<int> SmartIntPointer2;
cout << "SmartIntPointer2 = " << SmartIntPointer2.getValue() << endl;

// Testing Setter & Getter
cout << "Setting value of SmartIntPointer2 to 5" << endl;
SmartIntPointer2.setValue(5);
cout << "SmartIntPointer2 = " << SmartIntPointer2.getValue() << endl;

cout << "Creating a SmartPointer of type float with no value provided" << endl;
SmartPointer<float> SmartFloatPointer1;
cout << "SmartFloatPointer1 = " << SmartFloatPointer1.getValue() << endl;

cout << "Setting value of SmartFloatPointer1 to 1.5" << endl;
SmartFloatPointer1.setValue(1.5);
cout << "SmartFloatPointer1 = " << SmartFloatPointer1.getValue() << endl;

cout << "Creating a SmartPointer of type float with no value provided" << endl;
SmartPointer<float> SmartFloatPointer2;
cout << "SmartFloatPointer2 = " << SmartFloatPointer2.getValue() << endl;

cout << "Setting value of SmartFloatPointer2 to 2.5" << endl;
SmartFloatPointer2.setValue(2.5);
cout << "SmartFloatPointer2 = " << SmartFloatPointer2.getValue() << endl;

SmartPointer<float> SmartFloatPointer3 = SmartFloatPointer1 + SmartFloatPointer2;
cout << "SmartFloatPointer1 + SmartFloatPointer2 = " << SmartFloatPointer3.getValue() << endl;

SmartPointer<float> SmartFloatPointer4 = SmartFloatPointer2 - SmartFloatPointer1;
cout << "SmartFloatPointer2 - SmartFloatPointer1 = " << SmartFloatPointer4.getValue() << endl;

SmartPointer<float> SmartFloatPointer5 = SmartFloatPointer1 * SmartFloatPointer2;
cout << "SmartFloatPointer1 * SmartFloatPointer2 = " << SmartFloatPointer5.getValue() << endl;

// For handling arrays
cout << "Testing arrays" << endl;

// 
// add the needed code that shows how you use your class to create an array of multiple elements of a certain type.
// provide all the necessary test code that shows the different use cases of your code
}
