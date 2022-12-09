#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>



using namespace std;

#define ROZMIAR 8


long** kreator_szachownicy();

long** kreator_figur();
char** kreator_pol();

void wyswietl_szachownice(long** szachownica);
void wyswietl_figury_i_pola(long** figury, char** pola);

void stawianie_figur(long** szachownica, long** figury, char** pola);

int main()
{

	long** figury = kreator_figur();


	char** pola = kreator_pol();

	long** szachownica = kreator_szachownicy();

	wyswietl_szachownice(szachownica);

	cout << "\n\n\n";

	stawianie_figur(szachownica, figury, pola);

	wyswietl_szachownice(szachownica);

	wyswietl_figury_i_pola(figury, pola);


	cout << "\n\n\nNacisnij dowolny klawisz, aby zakonczyc dzialanie programu..." << endl;
	_getch();

}



long** kreator_szachownicy()
{
	long** temp = new long* [8];

	for (int i = 0; i < 8; i++)
	{
		*(temp + i) = new long[8];

		for (int j = 0; j < 8; j++)
		{
			temp[i][j] = 0;
			//cout << temp[i][j] << "\t";
		}

		//	cout << "\n";
	}

	return temp;

}


long** kreator_figur()
{
	long** temp = new long* [64];

	for (int i = 0; i < 64; i++)
	{
		temp[i] = 0;
	}

	return temp;
}



char** kreator_pol()
{
	char** temp = new char* [64];

	for (int i = 0; i < 64; i++)
	{
		temp[i] = new char[2];
	}

	return temp;
}


void wyswietl_szachownice(long** szachownica)
{
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << szachownica[i][j] << "\t";
		}
		cout << "\n";
	}
}

void stawianie_figur(long** szachownica, long** figury, char** pola)
{
	char rzad, kolumna;
	int wlasciwy_rzad, wlasciwa_kolumna;
	int licznik_figur = 0;

	while (1)
	{
		cout << "Na ktorym polu mam postawic figure? ";
		kolumna = _getch(); cout << kolumna;
		wlasciwa_kolumna = kolumna - 65;

		if ((kolumna == 'x') || (kolumna == 'X'))
		{
			cout << "\nWybrano X, dlatego nastepuje zakonczenie wstawiania...\n\n\n";
			break;
		}

		rzad = _getch(); cout << rzad << endl;
		wlasciwy_rzad = rzad - 49;

		if (szachownica[wlasciwy_rzad][wlasciwa_kolumna])
		{
			cout << "To pole jest juz zajete. Wybierz jakies inne...";
			continue;
		}

		else
		{
			szachownica[wlasciwy_rzad][wlasciwa_kolumna] = (wlasciwy_rzad * 8 + wlasciwa_kolumna) * sizeof(long);
			figury[licznik_figur] = &szachownica[wlasciwy_rzad][wlasciwa_kolumna];

			pola[licznik_figur][0] = kolumna;
			pola[licznik_figur][1] = rzad;
			licznik_figur++;
		}

	}
}



void wyswietl_figury_i_pola(long** figury, char** pola)
{
	int i = 0;
	cout << "\n\n\n";

	while (pola[i] && figury[i])
	{
		cout << "Pole " << pola[i][0] << pola[i][1] << ": " << *figury[i] << endl;
		i++;
	}
}