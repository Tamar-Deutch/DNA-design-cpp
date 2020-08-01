
#ifndef __CIL_H__
#define __CIL_H__
#include <vector>
#include "general.h"


//===================command-line==========================

class CLI : public IView
{
public:
	void execCommand (commandCollection &allCommands);
private:
	std::string getInput ();
	Icommand *m_command;	
	std::vector <std::string> split (std::string s);
	
};


#endif
