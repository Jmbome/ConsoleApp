#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "degree.h"
using namespace std;



class Student {
private:
	const static int daysArray = 3;
	string studentID = "A1";
	string firstName = "John";
    string  lastName = "Dow";
	string  emailAddress = "wgu@gmail.com"; 
	int age = 45;
	int  NumOfDaysToComplete[daysArray];
	string degreeprogram = "SOFTWARE";


public:
	// Void constructor
	Student();

	//parametrized constructor
	Student( string id,string fName,string lName,string Email, int age, int DaysToComp[], string DegProg);

	//Student information setter
	void Set_Info( string id, string fName, string lName, string Email, int age, int DaysToComp[], string DegProg);

	//Getters
	string getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getNumDays();
	string getDegreeProg();
	void print();


};

#endif