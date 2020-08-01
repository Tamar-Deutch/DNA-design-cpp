#ifndef __DNA_H__
#define __DNA_H__


#include <map>
#include <cstdio>
#include <iostream>
#include <cstring>

//==============================Nucleotide===========================================
//enable operator[] (assigment) in class DNAseq
class Nucleotide
{
public:
	Nucleotide () {}
	Nucleotide& operator = (const char &other);
	char m_nocleotide;
};

inline Nucleotide& Nucleotide::operator = (const char &other)
{
	m_nocleotide = other;
	return *this;
}
//===================================DNAseq=======================================
//------------------DNA-sequence-and-its-methodes---------------------------------
class DNAseq
{
public:
	DNAseq () {}
	DNAseq (const char* ch);
	DNAseq (const std::string& dna);
	void load () {std::cout << "------in function load-------" << std::endl;}
	void save () {std::cout << "------in function save-------" << std::endl;}
private:
	Nucleotide* m_dna;
};

inline DNAseq::DNAseq (const char* dna)
{
	size_t len = strlen(dna);
	try
	{
		m_dna = new Nucleotide [len];
	}
	catch(std::bad_alloc& e)
	{
		std::cout << "-------------";
	}
	for (size_t i = 0; i < len; i++)
	{
		m_dna[i] = dna[i];
	}
}

inline DNAseq::DNAseq (const std::string& dna)
{
	size_t len = strlen(dna.c_str());
	m_dna = new Nucleotide [len];

	for(size_t i = 0; i < len; i++)
	{
		m_dna[i] = dna.c_str()[i];
	}
}

//----------------------------------DNAdata------------------------------------------
class DNAdata
{
public:
	DNAdata (std::string dna, std::string name);
//private:
	std::string m_name;
	size_t m_id;
	static size_t m_count;
	DNAseq m_dnaSeq;
};



//------------------DNAcollection-------------------------

class DNAcollection
{

public:
	DNAseq getById (size_t id);
	DNAseq getByName (std::string name);
	static void insert (const DNAdata &dna);
	static bool findName (std::string s);

private:
	static std::map <size_t,std::string> idName;
	static std::map <std::string,DNAseq> nameDNA;

};
inline void DNAcollection::insert (const DNAdata &dna)
{
	idName [dna.m_id] = dna.m_name;
	nameDNA [dna.m_name] = dna.m_dnaSeq;
}

inline bool DNAcollection::findName (std::string s)
{
	return nameDNA.find(s) != nameDNA.end();
}
inline DNAdata::DNAdata (std::string dna, std::string name) : m_dnaSeq(dna), m_name(name), m_id(m_count++)
{
	DNAcollection::insert (*this);
}
#endif






