#include "eveniment.h";
#include <string>
#include <iostream>
using namespace std;

eveniment::eveniment() : idEv(0) {  //constructor implicit//
	tipEv = nullptr;
	dataEv = "";
	oraEv = "";
	locatieEv = "";
}

eveniment::eveniment(const char* tipEv, string dataEv, string oraEv, string locatieEv) : idEv(idEv)  //constructor cu parametrii//
{
	if (tipEv != nullptr)
	{
		this->tipEv = new char[strlen(tipEv) + 1];
		strcpy_s(this->tipEv, strlen(tipEv) + 1, tipEv);
	}
	else
	{
		this->tipEv = nullptr;
	}
	this->dataEv = dataEv;
	this->oraEv = oraEv;
	this->locatieEv = locatieEv;

}
eveniment::eveniment(const eveniment& e) : idEv(e.idEv)   //constructor de copiere//
{
	if (e.tipEv != nullptr)
	{
		this->tipEv = new char[strlen(e.tipEv) + 1];
		strcpy_s(this->tipEv, strlen(e.tipEv) + 1, e.tipEv);
	}
	else
	{
		this->tipEv = nullptr;
	}
	this->dataEv = e.dataEv;
	this->oraEv = e.oraEv;
	this->locatieEv = e.locatieEv;

}
eveniment::~eveniment()    //destructor//
{
	if (this->tipEv != nullptr)
	{
		delete[] this->tipEv;
	}
}

eveniment& eveniment::operator=(const eveniment& e)
{
	if (this != &e)
	{
		if (e.tipEv != nullptr)
		{
			if (tipEv != nullptr)
			{
				delete[] tipEv;
			}

			this->tipEv = new char[strlen(e.tipEv) + 1];
			strcpy_s(this->tipEv, strlen(e.tipEv) + 1, e.tipEv);
		}
		this->dataEv = e.dataEv;
		this->oraEv = e.oraEv;
		this->locatieEv = e.locatieEv;
	}
	return *this;
}

string eveniment::getOraEv()
{
	return this->oraEv;
}

string eveniment::getDataEv()
{
	return this->dataEv;
}

string eveniment::getLocatieEv()
{
	return this->locatieEv;
}

void eveniment::setTipEv(const char* tipEv)
{
	if (tipEv != nullptr)
	{
		if (this->tipEv != nullptr)
		{
			delete[] this->tipEv;
		}
		this->tipEv = new char[strlen(tipEv) + 1];
		strcpy_s(this->tipEv, strlen(tipEv) + 1, tipEv);
	}
}

char* eveniment::getTipEv() {
	if (tipEv != nullptr)
	{
		char* copy = new char[strlen(tipEv) + 1];
		strcpy_s(copy, strlen(tipEv) + 1, tipEv);
		return copy;
	}
	return nullptr;
}

string eveniment::getTipEvAsString()
{
	string copie = tipEv;
	return copie;
}

char& eveniment::operator[](int index)
{
	if (tipEv != nullptr && index >= 0 && index < strlen(tipEv))
	{
		return tipEv[index];
	}
	else
		return charInvalid;
}


istream& operator>>(istream& in, eveniment& e)
{
	cout << "Nume eveniment: (alegeti dintre 'MECIFOTBAL' , 'FILM' , TEATRU' )" << endl;
	string buffer;
	in >> buffer;
	e.setTipEv(buffer.c_str());

	cout << "Data la care doriti sa participati la eveniment";
	in >> e.dataEv;
	cout << "Ora la care doriti sa participati la eveniment ";
	in >> e.oraEv;
	cout << "Locatia unde doriti sa participati la eveniment";
	in >> e.locatieEv;
	return in;
}

ostream& operator<<(ostream& out, eveniment e)
{
	out << "Eveniment: ";
	if (e.tipEv != nullptr)
	{
		out << e.tipEv;
	}
	out << endl;
	out << "Data la care doriti sa participati la eveniment" << e.dataEv << endl;
	out << "Ora la care doriti sa participati la eveniment " << e.oraEv << endl;
	out << "Locatia unde doriti sa participati la eveniment" << e.locatieEv << endl;
	return out;
}
string eveniment::taraEv = "Romania";
char eveniment::charInvalid = -1;





