#include<iostream>
#include<string>
#include "eveniment.h"
#include "locbil.h"
#include "bilete.h"
using namespace std;
int main()
{
	//temporar loc de testare clase,retusarea finala pentru faza 2 :)
	//pe parcursul construirii meniului interactiv cu siguranta voi mai gasi atribute pe care le-as putea utiliza
	eveniment e1;
	eveniment e2("fotbal", " 19 decembrie", " 19", " BUCURESTI");
	eveniment e3 = e2;
	e1 = e3;
	cout << e1;

	locbil l1;
	int v[]{ 1,2 };
	int w[]{ 3,4 };
	locbil l2(" peluza", 2, 2, v, w);
	l1 = l2;
	cout << l1<<endl;
	cout << l1.getNrMaxLocuri;
	cout << endl;



	bilete b1;
	bilete b2(50 ,"Yasin", "VIP", "student");
	bilete b3(b2);
	cout << b3;
	bilete b4;
	cin >> b4;
	cout << endl;
	cout << "Afisarea biletului inregistrat cu datele anterioare:" << endl;
	cout << b4;
	bilete b5 = ++b2;//operatorul de pre incrementare creste pretul cu o unitate
	cout << endl;
	cout << b5;




	return 0;
}