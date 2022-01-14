/*
0 - pole biale
1- pole czarne
2 - pionek bialy
3 - pionek czarny
zasady:
-imiona
-ile zostało pionków
-damki
-kogo tura
-nie ma poruszania sie do tyłu
*/

#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <cstdlib>

using namespace std;

int pion = 0;
int poziom = 0;
int pion_ruch = 0;
int poziom_ruch = 0;

string nazwa_gracza_1;
string nazwa_gracza_2;

int licznik_pionkow_bialych = 12;
int licznik_pionkow_czarnych = 12;

void podanie_nazw() // Podanie nazwy graczy
{
	cout << "Podaj nazwe pierwszego gracza: ";
	cin >> nazwa_gracza_1;

	cout << "Podaj nazwe drogiego gracza: ";
	cin >> nazwa_gracza_2;
}

void wyswietlenie_planszy(int plansza[8][8]) {   // wyświetlenie planszy do gry

	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if (j % 2 == 0)
			{
				if (i % 2 == 0)
				{
					plansza[j][i] = 0;
				}

				else
				{
					plansza[j][i] = 2;
				}
			}
			else
			{
				if (i % 2 == 0)
				{
					plansza[j][i] = 2;
				}
				else
				{
					plansza[j][i] = 0;
				}
			}
		}
	}

	for (int j = 3; j < 5; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if (j % 2 == 0)
			{
				if (i % 2 == 0)
				{
					plansza[j][i] = 0;
				}
				else
				{
					plansza[j][i] = 1;
				}
			}
			else
			{
				if (i % 2 == 0)
				{
					plansza[j][i] = 1;
				}
				else
				{
					plansza[j][i] = 0;
				}
			}
		}
	}

	for (int j = 5; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if (j % 2 == 0)
			{
				if (i % 2 == 0)
				{
					plansza[j][i] = 0;
				}
				else
				{
					plansza[j][i] = 3;
				}
			}
			else
			{
				if (i % 2 == 0)
				{
					plansza[j][i] = 3;
				}
				else
				{
					plansza[j][i] = 0;
				}
			}
		}
	}
}

void podanie_ruchu_uzytkownika()   // ruch gracza 
{
	cout << "Podaj aktualny pion pionka ktorym wykonujesz ruch ";
	cin >> pion;

	cout << "Podaj aktualny poziom pionka ktorym wykonujesz ruch: ";
	cin >> poziom;

	cout << "Podaj przyszly poziom pionka ktorym wykonujesz ruch: ";
	cin >> pion_ruch;

	cout << "Podaj przyszly poziom pionka ktorym wykonujesz ruch: ";
	cin >> poziom_ruch;

}



int main()
{

	int plansza[8][8];
	int kolor_pionka;

	podanie_nazw();

	system("cls");

	wyswietlenie_planszy(plansza);

	cout << "   ";  // dolna czesc planszy
	for (int i = 0; i < 9; i++)
	{
		if (i != 8)
			cout << "--";
		else
			cout << "-";

	}
	cout << endl;

	for (int j = 0; j < 8; j++)
	{

		for (int i = 0; i < 8; i++)  // boki planszy
		{
			if (i == 0)
			{
				cout << j << "  " << "|";
			}


			if (plansza[j][i] == 0)
			{
				if (i != 7)
					cout << " |";
				else
					cout << " ";

			}

			if (plansza[j][i] == 1)
			{
				if (i != 7)
					cout << " |";
				else
					cout << " ";
			}

			if (plansza[j][i] == 2)
			{
				if (i != 7)
					cout << "B|";
				else
					cout << "B";
			}

			if (plansza[j][i] == 3)
			{
				if (i != 7)
					cout << "C|";
				else
					cout << "C";
			}

			if (i == 7)
			{
				cout << "|";
			}

			if ((j == 3) && (i == 7))
			{
				cout << "    licznik pionkow bialych:  " << licznik_pionkow_bialych;
			}

			if ((j == 2) && (i == 7))
			{
				cout << "    licznik pionkow czarnych: " << licznik_pionkow_czarnych;
			}

			if ((j == 6) && (i == 7))
			{
				cout << "    jesli chcesz zbic danego pionka podaj jego wspolrzedne zamiast wspolrzednych za nim";
			}
		}
		cout << endl;
	}

	cout << "   ";  // gora planszy
	for (int i = 0; i < 9; i++)
	{
		if (i != 8)
			cout << "--";
		else
			cout << "-";
	}
	cout << endl;

	cout << "    ";
	for (int i = 0; i < 8; i++)
	{
		cout << i << " ";
	}
	cout << endl;

// calosc programy i ponowowne wyswietlanie zmienionenj planszy po kazdym ruchu

	for (int x = 1; x < 1000; x++)
	{
		if (x % 2 != 0)
		{
			cout << endl << "Kolej gracza: " << nazwa_gracza_1 << "  wykonaj ruch" << endl;
		}
		else
		{
			cout << endl << "Kolej gracza: " << nazwa_gracza_2 << "  wykonaj ruch" << endl;
		}

		if (licznik_pionkow_bialych == 0)
		{
			system("cls");
			cout << "Zwyciestwo pionkow koloru czarnego";
			exit(0);
		}

		if (licznik_pionkow_czarnych == 0)
		{
			system("cls");
			cout << "Zwyciestwo pionkow koloru bialego";
			exit(0);
		}

		podanie_ruchu_uzytkownika();

		system("pause");
		system("cls");


		for (int j = 0; j < 8; j++) // bicie pionków 
		{

			for (int i = 0; i < 8; i++)
			{

				if ((j == pion) && (i == poziom))
				{

					if (plansza[j][i] == 0)
					{
						cout << "Niepoprawne pole";
						exit(0);
					}
					else
					{
						if (plansza[j][i] == 2)
						{
							kolor_pionka = 2;                              //kolor_pionka = 2 - biały
							plansza[j][i] = 1;
						}
						else if (plansza[j][i] == 4)                         // plansza[j][i] = 4 - czarny
						{
							kolor_pionka = 4;							 //kolor_pionka = 4 - czarny
							plansza[j][i] = 1;
						}
						else if (plansza[j][i] == 5)
						{
							kolor_pionka = 5;							// plansza[j][i] = 5 - bialy
							plansza[j][i] = 1;
						}													//kolor_pionka = 5 - czarny
						else
						{
							kolor_pionka = 1;                                   //kolor_pionka = 1 - czarny
							plansza[j][i] = 1;
						}
					}

				}

			}
		}

		int pion_bicie = pion_ruch + 1;
		int poziom_p = poziom_ruch + 1;
		int pion_bicie_2 = pion_ruch - 1;
		int poziom_p_2 = poziom_ruch - 1;

		for (int j = 0; j < 8; j++)
		{
			for (int i = 0; i < 8; i++)
			{

				if ((j == pion_ruch) && (i == poziom_ruch))
				{
					if (kolor_pionka == 2)
					{
						if ((plansza[j][i] == 3) || (plansza[j][i] == 4))
						{
							if (((pion_ruch - pion == 1) && (poziom_ruch - poziom == 1)) || ((pion_ruch - pion == 1) && (poziom_ruch - poziom == -1)) || ((pion_ruch - pion == -1) && (poziom_ruch - poziom == -1)) || ((pion_ruch - pion == -1) && (poziom_ruch - poziom == 1)))
							{
								licznik_pionkow_czarnych--;

								if (pion_bicie - pion == 0)
								{
									if (poziom_p - poziom == 0)
									{
										if (plansza[pion_bicie_2][poziom_p_2] == 3)
										{
											system("cls");
											cout << "nie mozna zbic pionka";
											exit(0);
										}
										else
										{
											plansza[pion_bicie_2][poziom_p_2] = 2;
										}
									}

									else
									{
										if (plansza[pion_bicie_2][poziom_p] == 3)
										{
											system("cls");
											cout << "nie mozna zbic pionka";
											exit(0);
										}
										else
										{
											plansza[pion_bicie_2][poziom_p] = 2;
										}
									}
								}
								else
								{
									if (poziom_p - poziom == 0)
									{
										if (plansza[pion_bicie][poziom_p_2] == 3)
										{
											system("cls");
											cout << "nie mozna zbic pionka";
											exit(0);
										}
										else if (plansza[pion_bicie][poziom_p_2] == 1)
										{
											if (j == 6)
											{
												plansza[pion_bicie][poziom_p_2] = 5;
											}
											else
											{
												plansza[pion_bicie][poziom_p_2] = 2;
											}
										}

									}

									else
									{
										if (plansza[pion_bicie][poziom_p] == 3)
										{
											system("cls");
											cout << "nie mozna zbic pionka";
											exit(0);
										}
										else if (plansza[pion_bicie][poziom_p] == 1)
										{
											if (j == 6)
											{
												plansza[pion_bicie][poziom_p] = 5;
											}
											else
											{
												plansza[pion_bicie][poziom_p] = 2;
											}
										}
									}
								}

								if (plansza[j][i] == 0)
								{
									cout << "Niepoprawne pole";
									exit(0);
								}

								else
								{
									if (kolor_pionka == 2)
									{
										plansza[j][i] = 1;
									}
									else
									{
										plansza[j][i] = 1;
									}

								}
							}
							else
							{
								exit(0);
							}
						}

						else
						{
							if (((pion_ruch - pion == 1) && (poziom_ruch - poziom == 1)) || ((pion_ruch - pion == 1) && (poziom_ruch - poziom == -1)))
							{
								if (j != 7)
								{
									if (plansza[j][i] == 0)
									{
										cout << "Niepoprawne pole";
										exit(0);
									}

									if (plansza[j][i] == 2)
									{
										cout << "Niepoprawne pole, nie mozesz zbic swojego pionka";
										exit(0);
									}

									else
									{
										if (kolor_pionka == 2)
										{
											plansza[j][i] = 2;
										}
										else
										{
											plansza[j][i] = 3;
										}

									}
								}
								else
								{
									if (plansza[j][i] == 0)
									{
										cout << "Niepoprawne pole";
										exit(0);
									}
									else
									{
										if (kolor_pionka == 2)
										{
											plansza[j][i] = 5;
										}

									}
								}

							}
							else
							{
								exit(0);
							}
						}
					}

					else if (kolor_pionka == 1)
					{
						if ((plansza[j][i] == 2) || (plansza[j][i] == 5))
						{
							if (((pion_ruch - pion == -1) && (poziom_ruch - poziom == -1)) || ((pion_ruch - pion == -1) && (poziom_ruch - poziom == 1)) || /*tu*/ ((pion_ruch - pion == 1) && (poziom_ruch - poziom == 1)) || ((pion_ruch - pion == 1) && (poziom_ruch - poziom == -1)))
							{
								licznik_pionkow_bialych--;

								if (pion_bicie - pion == 0)
								{
									if (poziom_p - poziom == 0)
									{
										if (plansza[pion_bicie_2][poziom_p_2] == 2)
										{
											system("cls");
											cout << "nie mozna zbic";
											exit(0);
										}
										else if (plansza[pion_bicie_2][poziom_p_2] == 1)
										{
											if (j == 1)
											{
												plansza[pion_bicie_2][poziom_p_2] = 4;
											}
											else
											{
												plansza[pion_bicie_2][poziom_p_2] = 3;
											}
										}
									}
									else
									{
										if (plansza[pion_bicie_2][poziom_p] == 2)
										{
											system("cls");
											cout << "nie mozna zbic";
											exit(0);
										}
										else if (plansza[pion_bicie_2][poziom_p] == 1)
										{
											if (j == 1)
											{
												plansza[pion_bicie_2][poziom_p] = 4;
											}
											else
											{
												plansza[pion_bicie_2][poziom_p] = 3;
											}
										}
									}
								}
								else
								{
									if (poziom_p - poziom == 0)
									{
										if (plansza[pion_bicie][poziom_p_2] == 2)
										{
											system("cls");
											cout << "nie mozna zbic";
											exit(0);
										}

										else
										{
											plansza[pion_bicie][poziom_p_2] = 3;
										}
									}
									else
									{
										if (plansza[pion_bicie][poziom_p] == 2)
										{
											system("cls");
											cout << "nie mozna zbic";
											exit(0);
										}
										else
										{
											plansza[pion_bicie][poziom_p] = 3;
										}
									}
								}

								if (plansza[j][i] == 0)
								{
									cout << "Niepoprawne pole";
									exit(0);
								}
								else
								{
									if (kolor_pionka == 2)
									{
										plansza[j][i] = 1;
									}
									else
									{
										plansza[j][i] = 1;
									}

								}
							}
							else
							{
                                if(((pion_ruch - pion == 1) && (poziom_ruch - poziom == 1)) || ((pion_ruch - pion == 1) && (poziom_ruch - poziom == -1)))
                                {
                                plansza[j][i] = 2;  
                                }
                                else
                                {
                                system("cls");
                                std::cout << "Wybrane pole jest niedozwolone" << "\n";
								exit(0);
							}
						}
                        }
						else
						{
							if (((pion_ruch - pion == -1) && (poziom_ruch - poziom == -1)) || ((pion_ruch - pion == -1) && (poziom_ruch - poziom == 1)))
							{
								if (j != 0)
								{
									if (plansza[j][i] == 0)
									{
										cout << "Niepoprawne pole";
										exit(0);
									}

									if (plansza[j][i] == 3)
									{
										cout << "Niepoprawne pole, nie mozesz zbic swojego pionka"; //
										exit(0);
									}
									else
									{
										if (kolor_pionka == 2)
										{
											plansza[j][i] = 2;
										}
										else
										{
											plansza[j][i] = 3;
										}

									}
								}
								else
								{
									if (plansza[j][i] == 0)
									{
										cout << "Niepoprawne pole";
										exit(0);
									}
									else
									{
										if (kolor_pionka == 1)
										{
											plansza[j][i] = 4;
										}

									}
								}

							}
							else
							{
								exit(0);
							}
						}

					}
					else if (kolor_pionka == 4)
					{
						if ((plansza[j][i] == 2) || (plansza[j][i] == 5))
						{
							if (((pion_ruch - pion == -1) && (poziom_ruch - poziom == -1)) || ((pion_ruch - pion == -1) && (poziom_ruch - poziom == 1)) || /*tu*/ ((pion_ruch - pion == 1) && (poziom_ruch - poziom == 1)) || ((pion_ruch - pion == 1) && (poziom_ruch - poziom == -1)) || /* 2*/((pion_ruch - pion == -2) && (poziom_ruch - poziom == -2)) || ((pion_ruch - pion == -2) && (poziom_ruch - poziom == 2)) || /*tu*/ ((pion_ruch - pion == 2) && (poziom_ruch - poziom == 2)) || ((pion_ruch - pion == 2) && (poziom_ruch - poziom == -2)) || /* 3 */((pion_ruch - pion == -3) && (poziom_ruch - poziom == -3)) || ((pion_ruch - pion == -3) && (poziom_ruch - poziom == 3)) || /*tu*/ ((pion_ruch - pion == 3) && (poziom_ruch - poziom == 3)) || ((pion_ruch - pion == 3) && (poziom_ruch - poziom == -3)) || /* 4 */((pion_ruch - pion == -4) && (poziom_ruch - poziom == -4)) || ((pion_ruch - pion == -4) && (poziom_ruch - poziom == 4)) || /*tu*/ ((pion_ruch - pion == 4) && (poziom_ruch - poziom == 4)) || ((pion_ruch - pion == 4) && (poziom_ruch - poziom == -4)) || /* 5 */((pion_ruch - pion == -5) && (poziom_ruch - poziom == -5)) || ((pion_ruch - pion == -5) && (poziom_ruch - poziom == 5)) || /*tu*/ ((pion_ruch - pion == 5) && (poziom_ruch - poziom == 5)) || ((pion_ruch - pion == 5) && (poziom_ruch - poziom == -5)) || /* 6*/ ((pion_ruch - pion == -6) && (poziom_ruch - poziom == -6)) || ((pion_ruch - pion == -6) && (poziom_ruch - poziom == 6)) || /*tu*/ ((pion_ruch - pion == 6) && (poziom_ruch - poziom == 6)) || ((pion_ruch - pion == 6) && (poziom_ruch - poziom == -6)) || /* 7 */((pion_ruch - pion == -7) && (poziom_ruch - poziom == -7)) || ((pion_ruch - pion == -7) && (poziom_ruch - poziom == 7)) || /*tu*/ ((pion_ruch - pion == 7) && (poziom_ruch - poziom == 7)) || ((pion_ruch - pion == 7) && (poziom_ruch - poziom == -7)))
							{
								licznik_pionkow_bialych--;

								if ((pion_bicie - pion == 0) || (pion_bicie - pion <= 0))
								{
									if ((poziom_p - poziom == 0) || (poziom_p - poziom <= 0))
									{
										if (plansza[pion_bicie_2][poziom_p_2] == 2)
										{
											system("cls");
											cout << "nie mozna zbic";
											exit(0);
										}
										else if (plansza[pion_bicie_2][poziom_p_2] == 1)
										{
											if (j == 1)
											{
												plansza[pion_bicie_2][poziom_p_2] = 4;
											}
											else
											{
												plansza[pion_bicie_2][poziom_p_2] = 4;
											}
										}
									}
									else
									{
										if (plansza[pion_bicie_2][poziom_p] == 2)
										{
											system("cls");
											cout << "nie mozna zbic";
											exit(0);
										}
										else if (plansza[pion_bicie_2][poziom_p] == 1)
										{
											if (j == 1)
											{
												plansza[pion_bicie_2][poziom_p] = 4;
											}
											else
											{
												plansza[pion_bicie_2][poziom_p] = 4;
											}
										}
									}
								}
								else
								{
									if ((poziom_p - poziom == 0) || (poziom_p - poziom <= 0))
									{
										if (plansza[pion_bicie][poziom_p_2] == 2)
										{
											system("cls");
											cout << "nie mozna zbic";
											exit(0);
										}

										else
										{
											plansza[pion_bicie][poziom_p_2] = 4;
										}
									}
									else
									{
										if (plansza[pion_bicie][poziom_p] == 2)
										{
											system("cls");
											cout << "nie mozna zbic";
											exit(0);
										}
										else
										{
											plansza[pion_bicie][poziom_p] = 4;
										}
									}
								}

								if (plansza[j][i] == 0)
								{
									cout << "Niepoprawne pole";
									exit(0);
								}
								else
								{
									if (kolor_pionka == 2)
									{
										plansza[j][i] = 1;
									}
									else
									{
										plansza[j][i] = 1;
									}
								}
							}
							else
							{
								system("cls");
								cout << "dama zostala zbita";
								exit(0);
							}
						}
						else
						{
							if (((pion_ruch - pion == -1) && (poziom_ruch - poziom == -1)) || ((pion_ruch - pion == -1) && (poziom_ruch - poziom == 1)) || /*tu*/ ((pion_ruch - pion == 1) && (poziom_ruch - poziom == 1)) || ((pion_ruch - pion == 1) && (poziom_ruch - poziom == -1)) || /* 2*/((pion_ruch - pion == -2) && (poziom_ruch - poziom == -2)) || ((pion_ruch - pion == -2) && (poziom_ruch - poziom == 2)) || /*tu*/ ((pion_ruch - pion == 2) && (poziom_ruch - poziom == 2)) || ((pion_ruch - pion == 2) && (poziom_ruch - poziom == -2)) || /* 3 */((pion_ruch - pion == -3) && (poziom_ruch - poziom == -3)) || ((pion_ruch - pion == -3) && (poziom_ruch - poziom == 3)) || /*tu*/ ((pion_ruch - pion == 3) && (poziom_ruch - poziom == 3)) || ((pion_ruch - pion == 3) && (poziom_ruch - poziom == -3)) || /* 4 */((pion_ruch - pion == -4) && (poziom_ruch - poziom == -4)) || ((pion_ruch - pion == -4) && (poziom_ruch - poziom == 4)) || /*tu*/ ((pion_ruch - pion == 4) && (poziom_ruch - poziom == 4)) || ((pion_ruch - pion == 4) && (poziom_ruch - poziom == -4)) || /* 5 */((pion_ruch - pion == -5) && (poziom_ruch - poziom == -5)) || ((pion_ruch - pion == -5) && (poziom_ruch - poziom == 5)) || /*tu*/ ((pion_ruch - pion == 5) && (poziom_ruch - poziom == 5)) || ((pion_ruch - pion == 5) && (poziom_ruch - poziom == -5)) || /* 6*/ ((pion_ruch - pion == -6) && (poziom_ruch - poziom == -6)) || ((pion_ruch - pion == -6) && (poziom_ruch - poziom == 6)) || /*tu*/ ((pion_ruch - pion == 6) && (poziom_ruch - poziom == 6)) || ((pion_ruch - pion == 6) && (poziom_ruch - poziom == -6)) || /* 7 */((pion_ruch - pion == -7) && (poziom_ruch - poziom == -7)) || ((pion_ruch - pion == -7) && (poziom_ruch - poziom == 7)) || /*tu*/ ((pion_ruch - pion == 7) && (poziom_ruch - poziom == 7)) || ((pion_ruch - pion == 7) && (poziom_ruch - poziom == -7)))
							{
								if (plansza[j][i] == 0)
								{
									cout << "Niepoprawne pole";
									exit(0);
								}
								else
								{
									if (kolor_pionka == 2)
									{
										plansza[j][i] = 2;
									}
									else
									{
										plansza[j][i] = 4;
									}

								}
							}
							else
							{
								system("cls");
								cout << "dama zostala zbita";
								exit(0);
							}
						}
					}
					else if (kolor_pionka == 5)
					{
						if ((plansza[j][i] == 3) || (plansza[j][i] == 4))
						{
							if (((pion_ruch - pion == -1) && (poziom_ruch - poziom == -1)) || ((pion_ruch - pion == -1) && (poziom_ruch - poziom == 1)) || /*tu*/ ((pion_ruch - pion == 1) && (poziom_ruch - poziom == 1)) || ((pion_ruch - pion == 1) && (poziom_ruch - poziom == -1)) || /* 2*/((pion_ruch - pion == -2) && (poziom_ruch - poziom == -2)) || ((pion_ruch - pion == -2) && (poziom_ruch - poziom == 2)) || /*tu*/ ((pion_ruch - pion == 2) && (poziom_ruch - poziom == 2)) || ((pion_ruch - pion == 2) && (poziom_ruch - poziom == -2)) || /* 3 */((pion_ruch - pion == -3) && (poziom_ruch - poziom == -3)) || ((pion_ruch - pion == -3) && (poziom_ruch - poziom == 3)) || /*tu*/ ((pion_ruch - pion == 3) && (poziom_ruch - poziom == 3)) || ((pion_ruch - pion == 3) && (poziom_ruch - poziom == -3)) || /* 4 */((pion_ruch - pion == -4) && (poziom_ruch - poziom == -4)) || ((pion_ruch - pion == -4) && (poziom_ruch - poziom == 4)) || /*tu*/ ((pion_ruch - pion == 4) && (poziom_ruch - poziom == 4)) || ((pion_ruch - pion == 4) && (poziom_ruch - poziom == -4)) || /* 5 */((pion_ruch - pion == -5) && (poziom_ruch - poziom == -5)) || ((pion_ruch - pion == -5) && (poziom_ruch - poziom == 5)) || /*tu*/ ((pion_ruch - pion == 5) && (poziom_ruch - poziom == 5)) || ((pion_ruch - pion == 5) && (poziom_ruch - poziom == -5)) || /* 6*/ ((pion_ruch - pion == -6) && (poziom_ruch - poziom == -6)) || ((pion_ruch - pion == -6) && (poziom_ruch - poziom == 6)) || /*tu*/ ((pion_ruch - pion == 6) && (poziom_ruch - poziom == 6)) || ((pion_ruch - pion == 6) && (poziom_ruch - poziom == -6)) || /* 7 */((pion_ruch - pion == -7) && (poziom_ruch - poziom == -7)) || ((pion_ruch - pion == -7) && (poziom_ruch - poziom == 7)) || /*tu*/ ((pion_ruch - pion == 7) && (poziom_ruch - poziom == 7)) || ((pion_ruch - pion == 7) && (poziom_ruch - poziom == -7)))
							{
								licznik_pionkow_czarnych--;
								if ((pion_bicie - pion == 0) || (pion_bicie - pion <= 0))
								{
									if ((poziom_p - poziom == 0) || (poziom_p - poziom <= 0))
									{
										if (plansza[pion_bicie_2][poziom_p_2] == 3)
										{
											system("cls");
											cout << "nie mozna zbic";
											exit(0);
										}
										else
										{
											plansza[pion_bicie_2][poziom_p_2] = 5;
										}
									}

									else
									{
										if (plansza[pion_bicie_2][poziom_p] == 3)
										{
											system("cls");
											cout << "nie mozna zbic";
											exit(0);
										}
										else
										{
											plansza[pion_bicie_2][poziom_p] = 5;
										}
									}
								}
								else
								{
									if ((poziom_p - poziom == 0) || (poziom_p - poziom <= 0))
									{
										if (plansza[pion_bicie][poziom_p_2] == 3)
										{
											system("cls");
											cout << "nie mozna zbic";
											exit(0);
										}
										else if (plansza[pion_bicie][poziom_p_2] == 1)
										{
											if (j == 6)
											{
												plansza[pion_bicie][poziom_p_2] = 5;
											}
											else
											{
												plansza[pion_bicie][poziom_p_2] = 5;
											}
										}
									}

									else
									{
										if (plansza[pion_bicie][poziom_p] == 3)
										{
											system("cls");
											cout << "nie mozna zbic";
											exit(0);
										}
										else if (plansza[pion_bicie][poziom_p] == 1)
										{
											if (j == 6)
											{
												plansza[pion_bicie][poziom_p] = 5;
											}
											else
											{
												plansza[pion_bicie][poziom_p] = 5;
											}
										}
									}
								}

								if (plansza[j][i] == 0)
								{
									cout << "Niepoprawne pole";
									exit(0);
								}

								else
								{
									if (kolor_pionka == 2)
									{
										plansza[j][i] = 1;
									}
									else
									{
										plansza[j][i] = 1;
									}

								}
							}
							else
							{
								system("cls");
								cout << "dama zostala zbita";
								exit(0);
							}
						}
						else
						{
							if (((pion_ruch - pion == -1) && (poziom_ruch - poziom == -1)) || ((pion_ruch - pion == -1) && (poziom_ruch - poziom == 1)) || /*tu*/ ((pion_ruch - pion == 1) && (poziom_ruch - poziom == 1)) || ((pion_ruch - pion == 1) && (poziom_ruch - poziom == -1)) || /* 2*/((pion_ruch - pion == -2) && (poziom_ruch - poziom == -2)) || ((pion_ruch - pion == -2) && (poziom_ruch - poziom == 2)) || /*tu*/ ((pion_ruch - pion == 2) && (poziom_ruch - poziom == 2)) || ((pion_ruch - pion == 2) && (poziom_ruch - poziom == -2)) || /* 3 */((pion_ruch - pion == -3) && (poziom_ruch - poziom == -3)) || ((pion_ruch - pion == -3) && (poziom_ruch - poziom == 3)) || /*tu*/ ((pion_ruch - pion == 3) && (poziom_ruch - poziom == 3)) || ((pion_ruch - pion == 3) && (poziom_ruch - poziom == -3)) || /* 4 */((pion_ruch - pion == -4) && (poziom_ruch - poziom == -4)) || ((pion_ruch - pion == -4) && (poziom_ruch - poziom == 4)) || /*tu*/ ((pion_ruch - pion == 4) && (poziom_ruch - poziom == 4)) || ((pion_ruch - pion == 4) && (poziom_ruch - poziom == -4)) || /* 5 */((pion_ruch - pion == -5) && (poziom_ruch - poziom == -5)) || ((pion_ruch - pion == -5) && (poziom_ruch - poziom == 5)) || /*tu*/ ((pion_ruch - pion == 5) && (poziom_ruch - poziom == 5)) || ((pion_ruch - pion == 5) && (poziom_ruch - poziom == -5)) || /* 6*/ ((pion_ruch - pion == -6) && (poziom_ruch - poziom == -6)) || ((pion_ruch - pion == -6) && (poziom_ruch - poziom == 6)) || /*tu*/ ((pion_ruch - pion == 6) && (poziom_ruch - poziom == 6)) || ((pion_ruch - pion == 6) && (poziom_ruch - poziom == -6)) || /* 7 */((pion_ruch - pion == -7) && (poziom_ruch - poziom == -7)) || ((pion_ruch - pion == -7) && (poziom_ruch - poziom == 7)) || /*tu*/ ((pion_ruch - pion == 7) && (poziom_ruch - poziom == 7)) || ((pion_ruch - pion == 7) && (poziom_ruch - poziom == -7)))
							{
								if (plansza[j][i] == 0)
								{
									cout << "Niepoprawne pole";
									exit(0);
								}

								if ((plansza[j][i] == 2) || (plansza[j][i] == 5))
								{
									cout << "Niepoprawne pole , nie mozesz zbic swojego pionka";
									exit(0);
								}

								else
								{
									if (kolor_pionka == 2)
									{
										plansza[j][i] = 5;
									}
									else
									{
										plansza[j][i] = 5;
									}
								}
							}
							else
							{
								system("cls");
								cout << "dama zostala zbita";
								exit(0);
							}
						}
					}
				}
			}
		}

		cout << endl << "   ";
		for (int b = 0; b < 9; b++)
		{
			if (b != 8)
				cout << "--";
			else
				cout << "-";
		}
		cout << endl;

		for (int j = 0; j < 8; j++)
		{
			for (int i = 0; i < 8; i++)
			{
				if (i == 0)
				{
					cout << j << "  " << '|';
				}
				if (plansza[j][i] == 0)
				{
					if (i != 7)
						cout << " |";
					else
						cout << " ";
				}

				else if (plansza[j][i] == 2)
				{
					if (i != 7)
						cout << "B|";
					else
						cout << "B";
				}

				else if (plansza[j][i] == 1)
				{
					if (i != 7)
						cout << " |";
					else
						cout << " ";
				}

				else if (plansza[j][i] == 3)
				{
					if (i != 7)
						cout << "C|";
					else
						cout << "C";
				}

				else if (plansza[j][i] == 4)
				{
					if (i != 7)
						cout << "C|";
					else
						cout << "C";
				}

				else if (plansza[j][i] == 5)
				{
					if (i != 7)
						cout << "B|";
					else
						cout << "B";
				}

				if (i == 7)
				{
					cout << "|";
				}

				if ((j == 3) && (i == 7))
				{
					cout << "    licznik pionkow bialych:  " << licznik_pionkow_bialych;
				}
				if ((j == 2) && (i == 7))
				{
					cout << "    licznik pionkow czarnych: " << licznik_pionkow_czarnych;
				}

				if ((j == 6) && (i == 7))
				{
					cout << "    jesli chcesz zbic danego pionka podaj jego wspolrzedne zamiast wspolrzednych za nim";
				}
			}
			if (j != 7)
			{
				cout << endl;
			}
		}
		cout << endl << "   ";
		for (int b = 0; b < 9; b++)
		{
			if (b != 8)
				cout << "--";
			else
				cout << "-";
		}
		cout << endl << "    ";
		for (int b = 0; b < 8; b++)
		{
			cout << b << " ";
		}
		cout << endl;
	}
}
