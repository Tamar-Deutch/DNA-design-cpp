#ifndef __COM_H__
#define __COM_H__

#include "DNA.h"
#include <vector>

//=====================Interface-for-commands=======================
class Icommand
{
public:
	virtual void exec (std::vector <std::string> params) = 0;
};

//=============================new==================================
class New:public Icommand
{
public:
	void exec (std::vector <std::string> params);
private:
	static size_t m_seq ;
};

inline void New::exec (std::vector <std::string> params) 
{

	if (params.size()!=3)
	{
		char buffer[20];
		sprintf(buffer, "seq%ld", m_seq++);
		DNAdata DNA(params[1],buffer);
	}

	else if (DNAcollection::findName(params[2]))
	{
		std::cout << "!!--this name is used, try again--!!" << std::endl;
	}
	

	else
	{	
		DNAdata DNA(params[1],params[2]);
	}
}


//===============================load=============================
class Load:public Icommand
{
public:
	void exec (std::vector <std::string> params) {std::cout << "in function load" << std::endl;}
};


//===============================save=============================
class Save:public Icommand
{
public:
	void exec (std::vector <std::string> params) {}
};
#endif
