#include "locbil.h"
#include <string>
#include <iostream>
using namespace std;


locbil::locbil()
{
	zona = "";
	nrRand = 0;
	nrCol = 0;
	randScaun = nullptr;
	colScaun = nullptr;
}

locbil::locbil(string zona, int nrRand, int nrCol, int* randScaun, int* colScaun)
{
	this->zona = zona;
	if (randScaun != nullptr && nrRand > 0)
	{
		this->randScaun = new int[nrRand];
		for (int i = 0; i < nrRand; i++)
		{
			this->randScaun[i] = randScaun[i];
		}
		this->nrRand = nrRand;
	}
	else
	{
		this->randScaun = nullptr;
		this->nrRand = 0;
	}

	if (colScaun != nullptr && nrCol > 0)
	{
		this->colScaun = new int[nrCol];
		for (int i = 0; i < nrCol; i++)
		{
			this->colScaun[i] = colScaun[i];
		}
		this->nrCol = nrCol;
	}
	else
	{
		this->colScaun = nullptr;
		this->nrCol = 0;
	}

}

locbil::locbil(const locbil& l)
{
	this->zona = l.zona;
	if (l.randScaun != nullptr && l.nrRand > 0)
	{
		this->randScaun = new int[l.nrRand];
		for (int i = 0; i < l.nrRand; i++)
		{
			this->randScaun[i] = l.randScaun[i];
		}
		this->nrRand = l.nrRand;
	}
	else
	{
		this->randScaun = nullptr;
		this->nrRand = 0;
	}

	if (l.colScaun != nullptr && l.nrCol > 0)
	{
		this->colScaun = new int[l.nrCol];
		for (int i = 0; i < l.nrCol; i++)
		{
			this->colScaun[i] = l.colScaun[i];
		}
		this->nrCol = l.nrCol;
	}
	else
	{
		this->colScaun = nullptr;
		this->nrCol = 0;
	}
}

locbil::~locbil()
{
	if (this->randScaun != nullptr)
	{
		delete[] this->randScaun;
	}

	if (this->colScaun != nullptr)
	{
		delete[] this->colScaun;
	}
}

locbil& locbil::operator=(const locbil& l)
{
	if (this != &l)
	{
		if (this->randScaun != nullptr)
		{
			delete[] this->randScaun;

		}
		if (l.randScaun != nullptr && l.nrRand > 0)
		{
			this->randScaun = new int[l.nrRand];
			for (int i = 0; i < l.nrRand; i++)
			{
				this->randScaun[i] = l.randScaun[i];
			}
			this->nrRand = l.nrRand;
		}
		else
		{
			this->randScaun = nullptr;
			this->nrRand = 0;
		}

		if (this->colScaun != nullptr)
		{
			delete[] this->colScaun;

		}
		if (l.colScaun != nullptr && l.nrCol > 0)
		{
			this->colScaun = new int[l.nrCol];
			for (int i = 0; i < l.nrCol; i++)
			{
				this->colScaun[i] = l.colScaun[i];
			}
			this->nrCol = l.nrCol;
		}
		else
		{
			this->colScaun = nullptr;
			this->nrCol = 0;
		}

	}
	return *this;
}

int locbil::getNrRand() {
	return nrRand;
}

int* locbil::getRandScaun()
{
	if (randScaun != nullptr)
	{
		int* copy = new int[nrRand];
		for (int i = 0; i < nrRand; i++) {
			copy[i] = randScaun[i];
		}
		return copy;
	}
	else return nullptr;
}

int locbil::getRandScaun(int index) {
	if (index >= 0 && index < nrRand && randScaun != nullptr) {
		return randScaun[index];
	}
	else return -1;
}
/////////////////////////

int locbil::getNrCol() {
	return nrCol;
}

int* locbil::getColScaun()
{
	if (colScaun != nullptr)
	{
		int* copy = new int[nrCol];
		for (int i = 0; i < nrCol; i++) {
			copy[i] = colScaun[i];
		}
		return copy;
	}
	else return nullptr;
}

int locbil::getColScaun(int index) {
	if (index >= 0 && index < nrCol && colScaun != nullptr) {
		return colScaun[index];
	}
	else return -1;
}
////////////////////////

void locbil::setRandScaun(int* randScaun, int nrRand) {
	if (randScaun != nullptr && nrRand > 0) {
		delete[] this->randScaun;
		this->randScaun = new int[nrRand];
		for (int i = 0; i < nrRand; i++) {
			this->randScaun[i] = randScaun[i];
		}
		this->nrRand = nrRand;
	}
}

void locbil::setColScaun(int* colScaun, int nrCol) {
	if (colScaun != nullptr && nrCol > 0) {
		delete[] this->colScaun;
		this->colScaun = new int[nrCol];
		for (int i = 0; i < nrCol; i++) {
			this->colScaun[i] = colScaun[i];
		}
		this->nrCol = nrCol;
	}
}
void locbil::setNrMaxLocuri(int nrMaxLocuri)
{
	locbil::nrMaxLocuri = nrMaxLocuri;
}

int locbil::getNrMaxLocuri()
{
	return nrMaxLocuri;
}


ostream& operator<<(ostream& out, locbil l)
{
	out << "Zona Bilet: " << l.zona << endl;
	out << "Nr rand: " << l.nrRand << endl;
	out << "Randuri: ";
	for (int i = 0; i < l.nrRand; i++)
	{
		out << l.randScaun[i] << " ";
	}
	out << endl;
	out << "Nr coloane: " << l.nrCol << endl;
	out << "Coloane: ";
	for (int i = 0; i < l.nrCol; i++)
	{
		out << l.colScaun[i] << " ";
	}
	out << endl;

	return out;
}

istream& operator>>(istream& in, locbil& l)
{
	cout << "Zona: ";
	in >> l.zona;

	cout << "Nr randuri: ";
	in >> l.nrRand;

	if (l.randScaun != nullptr)
	{
		delete[] l.randScaun;
		l.randScaun = nullptr;
	}

	l.randScaun = new int[l.nrRand];
	cout << "Randuri: ";
	for (int i = 0; i < l.nrRand; i++)
	{
		in >> l.randScaun[i];
	}

	cout << "Nr coloane: ";
	in >> l.nrCol;

	if (l.colScaun != nullptr)
	{
		delete[] l.colScaun;
		l.colScaun = nullptr;
	}

	l.colScaun = new int[l.nrCol];
	cout << "Coloane: ";
	for (int i = 0; i < l.nrCol; i++)
	{
		in >> l.colScaun[i];
	}

	return in;
}
int locbil::nrMaxLocuri = 10000;


















