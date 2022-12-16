
#include <iostream>
#include <string>
#include "roster.h"
using namespace std;


//Add function to populate classRosterArray
void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string degreeprogram) {

	int NumOfDaysToComplete[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
		classRosterArray[++index] = new Student(studentID, firstName, lastName,
			emailAddress, age, NumOfDaysToComplete, degreeprogram);
}
                  

                  // Class Roster functions

    // Prints All stundents data
	void Roster::printAll(){
		for (int i = 0; i <numStudents; i++) {
			if (classRosterArray[i] != nullptr) {
				classRosterArray[i]->print();
			}
	    }
	}

	//prints average of days in course
	void Roster::printAverageDaysInCourse( string studentID) {
		for (int i = 0; i < 5; i++) {
			int sum = classRosterArray[i]->getNumDays()[0] + classRosterArray[i]->getNumDays()[1]
					   + classRosterArray[i]->getNumDays()[2];
			int Avg = sum / 3;
			cout << "student ID:\ " << classRosterArray[i]->getID() << "," << "\ averages\ " << Avg <<
				"\ days in a course." << endl;	
		}
	}

	//Prints invalid emails 
	void Roster::printInvalidEmails() {
		for (int i = 0; i < 5; i++) {
			if ((classRosterArray[i]->getEmail()).find("@") == string::npos) {
				cout << classRosterArray[i]->getEmail() << "\ -" << "\ missing an @ symbol." << endl;
			}
			else if ((classRosterArray[i]->getEmail()).find(".") == string::npos) {
				cout << classRosterArray[i]->getEmail() << "\ -" << "\ missing a period." << endl;
			}
			else if ((classRosterArray[i]->getEmail()).find(" ") != string::npos) {
				cout << classRosterArray[i]->getEmail() << "\ -" << "\ no spaces allowed." << endl;
			}
		}
	}

	//Print Degree Program
    void Roster::printByDegreeProgram(string degreeProgram){
		for (int i = 0; i < 5; i++) {
			if (classRosterArray[i]->getDegreeProg() == degreeProgram) {
				classRosterArray[i]->print();
			};
		}	
	}
	
	//Remove function
	void Roster::remove(string studentID) {
		for (int i = 0; i < 5; ++i) {
			if (classRosterArray[i] != nullptr && classRosterArray[i]->getID() == studentID) {
				classRosterArray[i] = nullptr;
				break;
				}
			if (classRosterArray[i] == nullptr) {
				cout << "the student with the ID:\ " << studentID << "\ was not found." << endl;
			}
		}
	}


	//Destructor
	Roster::~Roster() {
		for (int i = 0; i < numStudents; i++) {
			if (classRosterArray[i] != nullptr) {
				delete classRosterArray[i];
			}

		}
		
	}



	//PARSER
	void Roster::parse(string info) {
		size_t rhs = info.find(",");
		string studentID = info.substr(0,rhs);

		size_t lhs = rhs + 1;
		rhs = info.find(",",lhs);
		string firstName = info.substr(lhs,rhs - lhs);

		lhs = rhs + 1;
		rhs = info.find(",",lhs);
		string lastName = info.substr(lhs,rhs - lhs);

		lhs = rhs + 1;
		rhs = info.find(",", lhs);
		string emailAddress = info.substr(lhs,rhs - lhs);

		lhs = rhs + 1;
		rhs = info.find(",",lhs);
		int age = stoi(info.substr(lhs,rhs - lhs));
		
		lhs = rhs + 1;
		rhs = info.find(",", lhs);
		int daysInCourse1 = stoi(info.substr(lhs,rhs - lhs));

		lhs = rhs + 1;
		rhs = info.find(",",lhs);
		int daysInCourse2 = stoi(info.substr(lhs,rhs - lhs));

		lhs = rhs + 1;
		rhs = info.find(",",lhs);
		int daysInCourse3 = stoi(info.substr(lhs,rhs - lhs));

		lhs = rhs + 1;
		rhs = info.find(",",lhs);
		string strProg = info.substr(lhs,rhs - lhs);
		DegreeProgram DegreeProg = DegreeProgram::SOFTWARE;
		if (strProg == "SECURITY") {
			DegreeProg = DegreeProgram::SECURITY;
		}
		else if (strProg == "NETWORK") {
			DegreeProg = DegreeProgram::NETWORK;
		}
		else if (strProg == "SOFTWARE") {
			DegreeProg = DegreeProgram::SOFTWARE;
		}

	add(studentID,firstName,lastName,emailAddress,age,daysInCourse1,daysInCourse2,daysInCourse3,strProg);
		

	}
	 