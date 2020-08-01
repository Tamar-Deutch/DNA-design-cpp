#include "CIL.h"


//-----------------execute-commands----------------------------

inline void CLI::execCommand (commandCollection &allCommands)
{
	std::string cmd = getInput ();
	std::vector <std::string> inputSplit = split (cmd);
	while (cmd!="quit")
	{

		allCommands.getCommand(inputSplit[0])->exec(inputSplit);
		cmd = getInput ();
		inputSplit = split (cmd);
		//print (); ??
	}	
}

//-----------------Auxiliary-functions-to-execCommand---------------
inline std::string CLI::getInput ()
{
	std::string input;
	std::cout << ">>";
	getline(std::cin,input);
	
	return input;
}


inline std::vector <std::string> CLI::split(std::string s)
{
	std::vector <std::string> vec;
	char* str = (char*)s.c_str();
	char* token = strtok (str," ");
	while (token != NULL)
	{
		vec.push_back (token);
		token = strtok (NULL," ");
	}
	return vec;
}
 
