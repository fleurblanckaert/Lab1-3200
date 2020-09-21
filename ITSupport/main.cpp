/* Name: Fleur Blackaert, Gabriel Dietrich
   Date: 19th September, 2020
   Program: Lab1_Classes - OOP 3200
   Description: This is an application that creates a class called WorkTicket, which represents a
                a client request for support.
*/

#include <iostream>     // for cin and cout
#include <iomanip> 		// for output formatting
#include <stdexcept>	// for invalid_argument
#include <sstream> 		// stringstream
#include <string>		// for getline
#include "MyConsoleInput.h" // Provided by Tom Tsiliopoulous (For ConsoleInput::ReadInteger())


using namespace std;

// Class declaration
class WorkTicket 
{
public:

	//Default Constructor
	WorkTicket() : ticketNumber(0), clientId(""), ticketDay(1), ticketMonth(1), ticketYear(2000), issueDescription("") {}

	//Parameterized Constructor
	WorkTicket(int number, string id, int day, int month, int year, string description);

	//Accessors;
	int GetTicketNumber() const { return ticketNumber; }
	string GetClientId() const { return clientId; }  
	int GetTicketDate() const { return ticketDay, ticketMonth, ticketYear; }
	string GetIssueDescription() const { return issueDescription; }
	
	string ShowWorkTicket() const; //Accessor Method

	// Mutators
	void SetTicketNumber(int number) {ticketNumber = Validate(number);}
	void SetClientID(string id) {clientId = id;}
	void SetTicketDate(int day, int month, int year) {ticketDay = day; ticketMonth = month;	ticketYear = year;}
	void SetIssueDescription(string description) {issueDescription = description;} 

	bool SetWorkTicket(int number, string id, int day, int month, int year, string description); // Mutator Method

	

//Members will only be accessible inside the class
private:  
	int ticketNumber;  
	string clientId;
	int ticketDay;	  
	int ticketMonth;
	int ticketYear;   
	string issueDescription;

	int Validate(int toNumber) const; // Double representing the validated value

};


int main()
{
	//Declarations
	WorkTicket ticket[3];
	int ticketInput;
	string clientInput;
	int dayInput;
	int monthInput;
	int yearInput;
	string issueDescription;

try
	{

		//Output Header
		cout << "IT Support Tracking Application" << endl
			<< "===============================" << endl << endl;
		for (int i = 0; i < 3; i++)
		{
			//Prompts user to enter Work Ticket Number
			cout << "The Ticket Number is: ";
			ticketInput = ConsoleInput::ReadInteger(0);

			//Prompts user for client id number
			cout << "The Client ID is: ";
			getline(cin, clientInput);

			//Prompts user for work ticket date
			cout << "The Work Ticket Date is: \nDay: ";
			dayInput = ConsoleInput::ReadInteger(1,31);
			cout << "Month: ";
			monthInput = ConsoleInput::ReadInteger(1,12);
			cout << "Year: ";
			yearInput = ConsoleInput::ReadInteger(2000,2099);

			//Prompts user for issue description
			cout << "The Issue Description is: ";
			getline(cin, issueDescription);

			ticket[i].SetWorkTicket(ticketInput, clientInput, dayInput, monthInput, yearInput, issueDescription);

			cout << endl;
		}
	}
	catch (invalid_argument& ia)
	{
		cerr << ia.what() << "Invalid argument" << endl;
	}

		//Displays output
		cout << endl << "Ticket Number\t" << "Client ID\t" << "Work Ticket Date\t" << "Issue Description\t" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << ticket[i].ShowWorkTicket() << endl;
		}

	return 0;

}

//Parameterized Constructor for WorkTicket Class
WorkTicket::WorkTicket(int number, string id, int day, int month, int year, string description)
{
	ticketNumber = number;
	clientId = id;
	ticketDay = day;
	ticketMonth = month;
	ticketYear = year;
	issueDescription = description;
}

//Method to display user's Work Ticket Number
string WorkTicket::ShowWorkTicket() const
{
	stringstream string;
		
	string  << (ticketNumber) << "\t\t" << (clientId) << "\t\t" << (ticketDay)<< "/" << (ticketMonth) << "/" << (ticketYear) << "\t\t"
			<< (issueDescription);

	return string.str();
}

//
bool WorkTicket::SetWorkTicket(int number, string id, int day, int month, int year, string description)
{
	SetTicketNumber(number);
	SetClientID(id);
	SetTicketDate(day, month, year);
	SetIssueDescription(description);

	return true;
}

int WorkTicket::Validate(int toNumber) const
{
	const int LIMIT = 0;
	
	if (toNumber < LIMIT)
		throw invalid_argument("Value must be a positive, whole number");
	else
		return toNumber;
}

