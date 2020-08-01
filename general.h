#ifndef __GEN_H__
#define __GEN_H__

#include "commands.h"


//---------------commands-Collection--------------------------
class commandCollection
{
private:
	std::map <std::string, Icommand*> commands;
public:
	commandCollection ();
	~commandCollection ();
	Icommand* getCommand (std::string command);
};

inline commandCollection::commandCollection ()
{
	commands = {
	{"new",new New()},
	{"load",new Load()},
	{"save",new Save()}
	};
}
inline commandCollection ::~commandCollection ()
{
	std::map <std::string, Icommand*>::iterator it;
	for (it = commands.begin(); it!=commands.end(); it++)
	{
		delete it->second;
	}
}

//-------------interface-of-the-view--(like-GUI\CLI...)---------
class IView
{
public:
	//virtual char* seperate
	virtual void execCommand (commandCollection &allCommands) = 0;
	
};


inline Icommand* commandCollection::getCommand (std::string command)
{
	return commands[command];
}

#endif
