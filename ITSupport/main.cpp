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
	void SetTicketNumber(int number) {ticketNumber = number;}
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
};


int main()
{
	//Declarations
	WorkTicket ticket[3];
	int ticketInput = 0;
	string clientInput = "";
	int ticketDay;
	int ticketMonth;
	int ticketYear;
	string issueDescription;

	//Output Header
	cout << "IT Support Tracking Application" << endl
		<< "===============================" << endl << endl;
	for (int i = 0; i < 3; i++)
	{
		//Prompts user to enter Work Ticket Number
		cout << "The Ticket Number is: ";
		ticketInput = ConsoleInput::ReadInteger(); 
		ticket[i].SetTicketNumber(ticketInput);

		//Prrompts user for client id number
		cout << "The Client ID is: ";
		cin >> clientInput;
		ticket[i].SetClientID(clientInput);

		//Prompts user for work ticket date
		cout << "The Work Ticket Date is: ";
		cin >> ticketDay >> ticketMonth >> ticketYear;
		ticket[i].SetTicketDate(ticketDay, ticketMonth, ticketYear);

		//Prompts user for issue description
		cout << "The Issue Description is: ";
		cin >> issueDescription;
		ticket[i].SetIssueDescription(issueDescription);

		cout << endl;
	}
	
	cout << endl << "Ticket Number\t" << "Client ID\t" << "Work Ticket Date\t" << "Issue Description\t" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << ticket[i].ShowWorkTicket() << endl;
	}
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
	return true;
}
