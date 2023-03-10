#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
using namespace std;

class eveniment
{
private:
	char* tipEv;
	string dataEv;
	string oraEv;
	string locatieEv;
	const int idEv;
	static char charInvalid;
	static string taraEv;


public:
	eveniment();
	eveniment(const char* tipEv, string dataEv, string oraEv, string locatieEv);
	eveniment(const eveniment& e);
	~eveniment();
	eveniment& operator=(const eveniment&);
	string getOraEv();
	string getDataEv();
	string getLocatieEv();
	void setTipEv(const char* tipEv);
	char* getTipEv();
	string getTipEvAsString();
	char& operator[](int index);
	friend istream& operator>>(istream& in, eveniment& e);
	friend ostream& operator<<(ostream& out, eveniment e);

};


