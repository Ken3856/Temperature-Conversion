// Title: Temperature conversion
// Author: Kenneth Johnnson
// Version 1
// Date: 02-Feb-22

#include <iostream>

//Declaration of class celsius, kelvin, fahrenheirt
using namespace std;
class celsius;
class kelvin;
//class fahrenheit


class fahrenheit {
private:
	double degrees;
	friend ostream& operator<< (ostream&, const fahrenheit&);
	friend istream& operator>> (istream&, fahrenheit&);


public:
	fahrenheit();
	fahrenheit(double);
	fahrenheit(const celsius&);
	fahrenheit(const kelvin&);
	double getDegrees() const;
};


class celsius {
private:
	double degrees;

public:
	friend ostream& operator<<(ostream& os, const celsius& cel);
	friend istream& operator>>(istream& is, celsius& cel);
	friend celsius operator+ (celsius&, celsius&);

	celsius();
	celsius(double);
	celsius(const fahrenheit&);
	celsius(const kelvin&);
	double getDegrees() const;
};



class kelvin {
private:
	double degrees;

public:
	friend ostream& operator<<(ostream& os, const kelvin& cel);
	friend istream& operator>>(istream& is, kelvin& cel);


	kelvin();
	kelvin(double);
	kelvin(const celsius&);
	kelvin(const fahrenheit&);
	double getDegrees() const;
};


//Function Definations of class celsius
ostream& operator<<(ostream& os, const celsius& cel) {
	os << " " << cel.degrees << " degrees C ";
	return os;
}

istream& operator>>(istream& is, celsius& cel) {
	is >> cel.degrees;
	return is;
}

celsius operator+ (celsius& t1, celsius& t2) {

	celsius sum = t1.getDegrees() + t2.getDegrees();
	return sum;
}

celsius::celsius(double val) { // Default constructor
	degrees = val;
}

celsius::celsius() { // Regular contructor
	degrees = 0.0;
}

celsius::celsius(const fahrenheit& val) { // Conversion constructor
	degrees = ((val.getDegrees()) - 32.0) * 5.0 / 9.0; // conversion for fahernheit to celsius
}

celsius::celsius(const kelvin& val) { // Conversion constructor
	degrees = ((val.getDegrees()) - 273.15); // conversion for kelvin to celsius
}

double celsius::getDegrees() const { // get accessor
	return degrees; // returns degrees celsius
}





//Function Definations of class fahrenheit
fahrenheit::fahrenheit(double val) { // Default constructor
	degrees = val;
}

fahrenheit::fahrenheit() { // Regular constructor 
	degrees = 0.0;
}

fahrenheit::fahrenheit(const celsius& val) { // Conversion constructor
	degrees = (val.getDegrees()) * 9.0 / 5.0 + 32; //  coversion for Celsius to Fahernheit
}

fahrenheit::fahrenheit(const kelvin& val) { // Conversion constructor
	degrees = ((val.getDegrees() - 273.15) * 9.0 / 5.0 + 32); // conversion for Kelvin to Fahernheit
}

double fahrenheit::getDegrees()	const {
	return degrees;  // returns degrees fahrenheit
}

ostream& operator<<(ostream& os, const fahrenheit& farh) {  // output stream operator
	os << " " << farh.degrees << " degrees F ";
	return os;
}

istream& operator>> (istream& is, fahrenheit& farh) {  // input stream operator
	is >> farh.degrees;
	return is;
}





//Function Definition of class kelvin
kelvin::kelvin(double val) { // Default constructor
	degrees = val;
}

kelvin::kelvin() { // Regular constructor
	degrees = 0.0;
}

kelvin::kelvin(const celsius& val) { // Conversion constructor
	degrees = (val.getDegrees() + 273.15); //conversion for Celsius to Kelvin
}

kelvin::kelvin(const fahrenheit& val) { // Conversion constructor
	degrees = ((val.getDegrees() - 32) * 5.0 / 9.0) + 273.15; // conversion for Fahernheit to Kelvin
}

double kelvin::getDegrees()	const {
	return degrees; // returns degrees kelvin
}

ostream& operator<<(ostream& os, const kelvin& kel) {
	os << " " << kel.degrees << " degrees K ";
	return os;
}

istream& operator>> (istream& is, kelvin& kel) {
	is >> kel.degrees;
	return is;
}



void main() {


	//*************************   TEST   *************************************
	// 
	//celsius C1(25);
	//cout << C1 << "  " << endl << endl;
	//cout << " Faherenheit Conversion " << endl;
	//cout << " Conversion by cast => ";
	//fahrenheit F1(3.0);
	//cout << F1 << " = " << (celsius)F1 << endl; //Fahrenheit conversion by cast

	//cout << " Conversion by explicit constructor call => ";
	//fahrenheit F2(C1);
	//cout << F2 << " = " << C1 << endl;  // F2 degrees changes to the fahrenheit equivalent of C1

	//cout << " Conversion by implicit constructor call => ";
	//fahrenheit F3;
	//F3 = C1;
	//cout << F3 << " = " << C1 << endl << endl; // F3 degrees changes to the fahrenheit equivalent of C1

	//*******************   TEST   ********************************************

	//cout << " Kelvin Conversion " << endl;
	//cout << " Conversion by cast => ";
	//kelvin K1(3.0);
	//cout << K1 << " = " << (celsius)K1 << endl; //Kelvin conversion by cast

	//cout << " Conversion by explicit constructor call => ";
	//kelvin K2(C1);
	//cout << K2 << " = " << C1 << endl;  // K2 degrees changes to the Kelvin equivalent of C1

	//cout << " Conversion by implicit constructor call => ";
	//kelvin K3;
	//K3 = C1;
	//cout << K3 << " = " << C1 << endl << endl; // K3 degrees changes to the Kelvin equivalent of C1

	//**********************   TEST   *******************************************

	cout << " Temperature Conversion Application v1 "
		<< "\n Author: Kenneth Johnson "
		<< "\n Date: 03/Feb/22 " << endl;

	//Switch case to allow user to select a conversion
	cout << "\n Enter <1> for Kelvin => Celsius & Fahrenheit " <<
		"\n Enter <2> for Celsius => Kelvin & Fahrenheit " <<
		"\n Enter <3> for fahrenheit => Celsius & Kelvin " << endl;
	int option;
	cout << " Please Enter an option: ";
	cin >> option;
	switch (option)
	{
	case 1: {
		kelvin k4;
		cout << "\n Kelvin => Celsius & Fahrenheit conversion" << endl;
		cout << " Enter a kelvin temperature: ";
		cin >> k4;

		cout << "\n Conversion by cast => ";
		cout << k4 << " = " << (celsius)k4 << endl; // Kelvin to Celsius
		cout << " Conversion by cast => ";
		cout << k4 << " = " << (fahrenheit)k4 << endl; //Kelvin to Fahrenheit


		cout << "\n Conversion by explicit constructor call => ";
		celsius c4(k4);
		cout << k4 << " = " << c4 << endl;  //  degrees changes to the Kelvin equivalent of C4

		cout << " Conversion by explicit constructor call => ";
		fahrenheit f4(k4);
		cout << k4 << " = " << f4 << endl;  //  degrees changes to the Kelvin equivalent of f4

		cout << "\n Conversion by implicit constructor call => ";
		celsius c5;
		c5 = k4;
		cout << k4 << " = " << c5 << endl; // degrees changes to the Kelvin equivalent of C5

		cout << " Conversion by implicit constructor call => ";
		fahrenheit f5;
		f5 = k4;
		cout << k4 << " = " << f5 << endl << endl; // degrees changes to the Kelvin equivalent of f5
		break;
	}


	case 2: {
		celsius c6, c7;
		cout << " Enter a celsius temperature: ";
		cin >> c6;

		cout << "\n Celsius => Kelvin & Fahrenheit conversion" << endl;
		cout << "\n Conversion by cast => ";
		cout << c6 << " = " << (kelvin)c6 << endl; // celsius to Kelvin
		cout << " Conversion by cast => ";
		cout << c6 << " = " << (fahrenheit)c6 << endl; //celsius to Fahrenheit 


		cout << "\n Conversion by explicit constructor call => ";
		kelvin k4(c6);
		cout << c6 << " = " << k4 << endl;  //  degrees changes to the Celsius equivalent of k4

		cout << " Conversion by explicit constructor call => ";
		fahrenheit f4(c6);
		cout << c6 << " = " << f4 << endl;  //  degrees changes to the Celsius equivalent of f4

		cout << "\n Conversion by implicit constructor call => ";
		kelvin k5;
		k5 = c6;
		cout << c6 << " = " << k5 << endl; // degrees changes to the Celsius equivalent of k5

		cout << " Conversion by implicit constructor call => ";
		fahrenheit f5;
		f5 = c6;
		cout << c6 << " = " << f5 << endl << endl; // degrees changes to the Celsius equivalent of f5
		break;
	}

	case 3: {
		fahrenheit f6, f7;
		cout << " Enter a fahrenheit temperature: ";
		cin >> f6;

		cout << "\n Fahrenheit => Celsius & Kelvin conversion" << endl;
		cout << "\n Conversion by cast => ";
		cout << f6 << " = " << (celsius)f6 << endl; //Fahrenheit to Celsius
		cout << " Conversion by cast => ";
		cout << f6 << " = " << (kelvin)f6 << endl; //Fahrenheit to Kelvin 


		cout << "\n Conversion by explicit constructor call => ";
		celsius c7(f6);
		cout << f6 << " = " << c7 << endl;  //  degrees changes to the Fahrenheit equivalent of C7

		cout << " Conversion by explicit constructor call => ";
		kelvin k4(f6);
		cout << f6 << " = " << k4 << endl;  //  degrees changes to the Fahrenheit equivalent of f6

		cout << "\n Conversion by implicit constructor call => ";
		celsius c8;
		c8 = f6;
		cout << f6 << " = " << c8 << endl; // degrees changes to the Fahrenheit equivalent of C8

		cout << " Conversion by implicit constructor call => ";
		kelvin k5;
		k5 = f6;
		cout << f6 << " = " << k5 << endl << endl; // degrees changes to the Fahrenheit equivalent of k5
		break;

		}
	}


	//	cout << " Calculations " << endl;
	//	celsius C4(22.0);
	//	celsius C5(18.0);
	//	celsius C6;
	//
	//	C6 = C4 + C5;
	//	cout << C4 << " + " << C5 << " = " << C6 << endl;
	system("pause");
};



