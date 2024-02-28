//Version 1.0 ; WIP CARTER HOLLMAN
#include <iostream>
#include <string>
#include <random>
#include <math.h>
#include "Login.h"
#include <vector>
#include <fstream>
using namespace std;

//TODO
//-Save/load info to local machine 'Bank.txt'
//-Create caeser cypher for data stored
//Read encrpyted data and then store into data structure (vector)
//-Continue refining user terminal experience 
//Add ability to search for specific login for account !!!!!!!! <-
//After saving and loading to txt file on machine, work on SQL server integration 

//Globals
vector<Login> logins;
int numLogins;

//USE TO SET MASTER PIN!!!!!!!!!!!!!
constexpr auto masterPin = 0000;  //CHANGE THIS FROM INT TO STRING NEED CHANGE IN VERIFYUSER FUNCTION


//Main menu terminal
void mainMenu() {
	cout << "*****************************************\n";
	cout << "*-------Login bank!---------------------*\n";
	cout << "*-------Created by: Carter Hollman------*\n";
	cout << "*****************************************\n\n";
	cout << "Select a function: \n";
	cout << "1. Verify User\n";
	cout << "2. Exit\n";

}

//User validation
bool userValid(int inV) {
	if (masterPin == inV) {
		return true;
	}
	return false;
}

//menu where user enters pin
void innerMenu() {
	int toBeValidated;
	bool validationResult;
	char screenHolder;   //to hold the non-verified user on their failed attempt, requiring action to exit program 


	cout << "Enter Your Master Pin :)\n\n";
	cin >> toBeValidated;

	validationResult = userValid(toBeValidated);
	if (validationResult) {
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; //give some new space to the meat of the bank 
	}
	else {
		cout << "Not your space bro, beat it. (Type anything to get outta my sight)\n";
		cin >> screenHolder;
		exit(1);
	}
}

//function to display logins
void displayLogins() {
	cout << "\n\n";
	for (int i = 0; i < numLogins; i++) {
		cout << logins[i].getAffiliation() << " account" << "\n";
		cout << "Username: " << logins[i].getUserName() << "\n";
		cout << "Password: " << logins[i].getPassword() << "\n\n\n";
	}
}

//function to add to login vector
void addLogin() {
	std::string affiliationIn, userIn, passIn;
	cout << "What account is this login affiliated with? (Ex. Github, Amazon etc.)\n";
	cin >> affiliationIn;
	cout << "What is the username for this account?\n";
	cin >> userIn;
	cout << "What is the password associated with this account?\n";
	cin >> passIn;

	Login temp = Login(affiliationIn, userIn, passIn);
	logins.push_back(temp);

	numLogins++;
	cout << "Congrats, your login has been added to the vault!\n\n";
}

//function to remove specified login from vector
void removeLogin() {

}

void findLogin() {

}

//final menu where user can choose to view find, add or remove logins
void innerMostMenu() {
	int innerInput;
	char continueQuery;
	cout << "Welcome back bro\n";
	cout << "Select an option:\n\n";
	cout << "1. View Logins\n" << "2. Add Login\n" << "3. Remove Login\n" << "4. Find specific login in vault\n" << "5. Exit\n";
	
	cin >> innerInput;

	switch (innerInput) {
	case 1:
		displayLogins();
		break;
	case 2:
		addLogin();
		break;
	case 3:
		removeLogin();
		break;
	case 4:
		findLogin();

	case 5:
		exit(1);
	default:
		cout << "Error: Please pick one of the valid options!\n";
	}

	cout << "Would you like to go back to the previous screen? (y/n)\n";
	cin >> continueQuery;

	if (continueQuery == 'y') {
		innerMostMenu();
	}
	else {
		exit(1);
	}
}




//Basic ceaser cypher to encrypt password data
void encrypt(vector<Login> input) { //TODO


}

//basic caeser cypher to decrypt password data for loading
void decrypt(vector<Login> input) { //TODO


}

//saving login vector to external text document
void save() {
	ofstream file("bank.txt");
	//TODO

	file.close();
}//TODO //TODO

void load() {
	ifstream file("bank.txt");
	//TODO

	file.close();
} //TODO

int main() {
	load();   //Loading previous data

	int userIn;
	mainMenu();      //Main menu prinout + intake of the users selection 
	cin >> userIn;

	switch (userIn) {    //switch based on what user chose
	case 1:
		innerMenu();
		innerMostMenu();
		break;

	case 2:
		return 2;

	default:
		cout << "Error: Please pick one of the valid options!\n";
	}


	save();   //Saving data to bank file
	return 1;

}



