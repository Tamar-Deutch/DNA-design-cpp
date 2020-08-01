
#ifndef __MAN_H__
#define __MAN_H__

#include "CIL.h"


//===================manager-initializaion======================

class Manager
{

public:
	Manager (IView &view) {m_view = &view;};
	void run ();
	void shutDown ();	//???
private:
	IView *m_view;
};


//------------------start-the-program-----------------------------
inline void Manager::run()
{
	commandCollection allCommands;
	m_view -> execCommand (allCommands);
}




#endif
