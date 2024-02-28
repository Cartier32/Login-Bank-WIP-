#include "Login.h"
Login::Login() {
	this->userName = "null";
	this->password = "null";
	this->affiliation = "null";
}

Login::Login(std::string affilIn, std::string userIn, std::string passIn) {
	this->userName = userIn;
	this->affiliation = affilIn;
	this->password = passIn;
}


std::string Login::getUserName() {
	return this->userName;
}

std::string Login::getPassword() {
	return this->password;
}

std::string Login::getAffiliation() {
	return this->affiliation;
}

void Login::setUserName(std::string in) {
	this->userName = in;
}

void Login::setPassword(std::string in) {
	this->password = in;
}

void Login::setAffiliation(std::string in) {
	this->affiliation = in;
}