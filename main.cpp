#include <iostream>
#include <cctype>
#include <string>
#include "roster.h"
using namespace std;





int main() {

	const string studentData[5] = {

	 "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	 "A5,Joseph,Mbome,jmbome1@yahoo.edu,32,56,34,40,SOFTWARE"
	};



	cout << "C867-Scripting & Programming:\  Applications" << endl;
	cout << "Language:\ C++" << endl;
	cout << "Name:\ Joeseph\ Mbome" << endl;
	cout << endl;
	cout << "Done." << endl;
	

	
	//instance of Class Roster
	 Roster classRoster;  


	for (int i = 0; i < 5; i++) {
		classRoster.parse(studentData[i]); //Parse studnetData to class Roster
		
	}
	
	cout << "Displaying all students:" << endl; // Prints all student data
		classRoster.printAll();
	
	cout << endl;
	cout << "Displaying invalid emails:" << endl;
	cout << endl;

	classRoster.printInvalidEmails(); // prints invalid emails

	cout << endl;


	for (int i = 0; i < 1; i++) {           // prints average of days in course
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getID());
	}
	  

	cout << endl;
	cout << "Showing students in degree program:" << "\ SOFTWARE" << endl;
	cout << endl;

		classRoster.printByDegreeProgram("SOFTWARE"); // prints "software" degree program


		cout << endl;
		cout << "Removing A3:" << endl;
		cout << endl;

			classRoster.remove("A3"); // Removes student with id "A3"

			classRoster.printAll();  // Prints all student data again with deleted data 
			                         // containing id "A3"

			cout << endl;

			cout << "Removing A3 again" << endl;

			classRoster.remove("A3"); // Attempting to delete student data with id "A3" again
			                          // which throws an error message.

			

			cout << "Done." << endl;
			
	
	return 0;
}
	