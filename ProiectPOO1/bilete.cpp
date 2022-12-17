#include "bilete.h"
#include <string>
#include<iostream>
#include<cstdlib>
using namespace std;


bilete::bilete() : idbilet(0)
{
	pret = 0;
	numeclient = "";
	zonabilet = "";
	categorieclient = "";
}



bilete::bilete(float pret, string numeclient, string zonabilet,string categorieclient) : idbilet(idbilet)
{
	this->pret = pret;
	this->numeclient = numeclient;
	this->zonabilet = zonabilet;
	this->categorieclient = categorieclient;
}



bilete::bilete(const bilete& b) : idbilet(b.idbilet)
{
	this->pret = b.pret;
	this->numeclient = b.numeclient;
	this->zonabilet = b.zonabilet;
	this->categorieclient = b.categorieclient;
}


bilete& bilete::operator=(const bilete& b)
{
	if (this != &b)
	{
		this->pret = b.pret;
		this->numeclient = b.numeclient;
		this->zonabilet = b.zonabilet;
		this->categorieclient = b.categorieclient;
	}
	return *this;
}

bilete& bilete::operator++()
{
	this->pret = this->pret + 1;
	return *this;
}

int bilete::getPret()
{
	return this->pret;
}


string bilete::getNumeclient()
{
	return this->numeclient;
}


string bilete::getZonabilet()
{
	return this->zonabilet;
}

string bilete::getCategorieclient()
{
	return this->categorieclient;
}

int bilete::getIdbilet()
{
	return idbilet;
}


void bilete::setNumeclient(string numeclient)
{
	this->numeclient = numeclient;

}

void bilete::setZonabilet(string zonabilet)
{
	this->zonabilet = zonabilet;

}

void bilete::setCategorieclient(string zonabilet)
{
	this->zonabilet = zonabilet;
}

istream& operator>>(istream& in, bilete& b)
{
	cout << "Nume client : " << endl;
	in >> b.numeclient;
	cout << "Categorie client ( introduceti doar una dintre urmatoarele :copil/student/adult/pensionar): ";
	in >> b.categorieclient;
	cout << "Zona unde doriti bilet ( introduceti doar una dintre urmatoarele :peluza/tribuna/loja/VIP): ";
	in >> b.zonabilet;
	cout << "Pretul maxim pe care l-ati putea plati: ";
	in >> b.pret;
	return in;
}

ostream& operator<<(ostream& out, bilete b)
{
	out << "Numele clientului: " << b.numeclient << endl;
	out << "Categoria clientului: " << b.categorieclient << endl;
	out << "Pretul: " << b.pret<<endl;
	out << "Zona unde va veti aseza: " << b.zonabilet<<endl;
	out << "ID bilet: " << b.idbilet << endl;


	out << endl;
	return out;
}
int idbilet = rand();






