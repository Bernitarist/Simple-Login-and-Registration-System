#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void regist();
bool LoggedIn();


int main()
{
	int choice;

	//prompt user
	cout << "Hello and Welcome!!\n\nPlease select your option below: " << endl;
	cout << "\t1. Register\n\t2. Login " << endl;
	cin >> choice;

	//option select
	if (choice == 1) {
		cout << "\nOPENING REGISTRATION...\n " << endl;
		regist();
	}
	
	if (choice == 2) {
		bool status = LoggedIn();
		if (!status) {
			cout << "\033[2J\033[1;1H";
			cout << "\n\t\tInvalid Login. Try again\n\n" << endl;
			main();
		}
		else {
			cout << "\033[2J\033[1;1H";
			cout << "\t\tWelcome!!\n\n\n" << endl;
		}

	}

	return 0;
}

//login function
bool LoggedIn()
{
	string username, un;
	int  password, pw;

	cout << "Enter your Username: " << endl;
	cin.ignore();
	getline(cin, username);
	cout << "Enter your Password: " << endl;
	cin >> password;

	ifstream objRead(username + ".txt");
	objRead >> un >> pw;
	
	if (un == username && pw == password) {
		return true;	
	}
	objRead.close();
}

//registration function
void regist()
{
	cout << "\033[2J\033[1;1H";

	int press;
	string username, password;

	cout << "Input your Username: " << endl;
	cin.ignore();
	getline(cin, username);
	cout << "Provide your password: " << endl;
	cin >> password;

	ofstream objWrite("C:\\Users\\Bernito\\Desktop\\Bern\\" + username + ".txt");  //select your preferred folder
	objWrite << username << " " << password << endl;
	objWrite.close();

	cout << "\n\t\tThank you for registering!!\n " << endl;
	cout << "\t\tPress 0 to return..\n";
	cin >> press;
	if (press == 0) {
		cout << "\033[2J\033[1;1H";
		main();
	}
}

