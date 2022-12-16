#pragma once
#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
using namespace std;
        



class Roster {
public:
	int index = -1;
	Student* classRosterArray[5]; //Student class now a user-defined type
	const static int numStudents = 5;

	// Add function to populate classRosterArray
	void add(string studentID, string firstName, string lastName, string emailAddress,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string degreeprogram);

	//Destructor
	~Roster();

	//Roster functions
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(string degreeProgram);
	void parse(string info);
};
#endif