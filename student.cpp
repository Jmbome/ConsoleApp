#include <iostream>
using namespace std;
#include "student.h"

//Void constructor
Student::Student() {
	studentID = "";
	firstName =  "";
	lastName = "";
	emailAddress = "none";
	age = 0; 
	NumOfDaysToComplete[daysArray];
	degreeprogram = "SOFTWARE";
};

//Parametrized constructor
Student::Student(string id, string fName, string lName, string Email, int age, int DaysToComp[], string DegProg) {
	 studentID = id;
	 firstName = fName;
	 lastName = lName;
	 emailAddress = Email;
	this-> age = age;
	 for (int i = 0; i < 3 ; i++) {
		 NumOfDaysToComplete[i] = DaysToComp[i];
	    };
	 degreeprogram = DegProg;
};

//Setter
void Student::Set_Info(string id, string fName, string lName, string Email, int age, int DaysToComp[], string DegProg) {
	studentID = id;
	firstName = fName;
	lastName = lName;
	emailAddress = Email;
	this->age = age;
	for (int i = 0; i < 3; i++) {
		NumOfDaysToComplete[i] = DaysToComp[i];
	};
	degreeprogram = DegProg;
};

//Getters
string Student::getID() {
	return studentID;
};
string Student::getFirstName() {
	return firstName;
};
string Student::getLastName() {
	return lastName;
};
string Student::getEmail() {
	return emailAddress;
};
int Student::getAge() {
	return age;
};
int* Student::getNumDays() {
	return NumOfDaysToComplete;
};
string Student::getDegreeProg() {
	return degreeprogram;
};

void Student::print() {
	string program;
	if (degreeprogram == "NETWORK") {
		program = "NETWORK";
	}
	else if (degreeprogram == "SECURITY") {
		program = "SECURITY";
	}
	else if (degreeprogram == "SOFTWARE") {
		program = "SOFTWARE";
	}

	

	cout << studentID   << "\   First Name:\ " << firstName << "\   Last Name:\ "<< lastName;
	cout << "\   Age:\ " <<age << "\   daysInCourse:\ "<<"{" << NumOfDaysToComplete[0] << ","
		<< NumOfDaysToComplete[1] << "," << NumOfDaysToComplete[2] << "}" << "\   Degree Program:\ " << degreeprogram << endl;
};
