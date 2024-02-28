#pragma once
#include <string>
class Login
{
private:
	std::string userName, password, affiliation;

public:
	Login();
	Login(std::string affilIn, std::string userIn, std::string passIn);
	std::string getUserName();
	std::string getPassword();
	std::string getAffiliation();
	void setUserName(std::string in);
	void setPassword(std::string in);
	void setAffiliation(std::string in);


};

