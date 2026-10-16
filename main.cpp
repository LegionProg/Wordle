#include <iostream>

using namespace std;

#define Green "\033[32m"
#define Orange "\033[33m"
#define Red "\033[31m"
#define Default "\033[m"
int Generator(int max);
void AskInt(char wordPlayer[])
{
	bool askInt = true;
	for (int i = 0; i < 5; i++)
	{
		while (true)
		{
			if (askInt)
			{
				cout << "entrer un mot de 4 caractere en majuscule -> ";
				cin >> wordPlayer;
				askInt = false;
			}

			if (wordPlayer[i] >= 65 && wordPlayer[i] <= 90)
				break;

			else
			{
				cout << "Recomancer saisi non valide" << endl;
				askInt = true;
			}
		}

	}
}

void PlayWordle(const char* word[], const char* p_word, char wordPlayer[], int b, int t, bool test, int turn, bool win)
{
	int random = Generator(3);
	p_word = word[random];

	for (int i = 0; i < turn; i++)
	{
		cout << "Debug Mot secret -> " << p_word << endl;
		AskInt(wordPlayer);
		b = 0;
		for (int a = 0; a <= 4; a++)
		{
			b++;
			if (wordPlayer[a] == p_word[a])
			{
				cout << Green << wordPlayer[a] << Default;
				t++;
			}
			else if (wordPlayer[a] != p_word[a])
			{
				for (int b = 0; b < 5; b++)
				{
					if (wordPlayer[b] == p_word[a])
					{
						cout << Orange << wordPlayer[a] << Default; // petit problème ici
						t = 0;
						test = true;
						break;
					}
				}
				if (!test)
				{

					cout << Red << wordPlayer[a] << Default;
					t = 0;
				}
				test = false;
			}



			if (t == 5)
			{
				cout << endl << "GG win" << endl;
				win = true;
				break;
			}

		}
		t = 0;
		if (win)
			break;

	}
	if (!win)
		cout << endl << "Loose" << endl;
}

int Generator(int max)
{
	return rand() % (max + 1);
}

int main()
{
	srand(time(NULL));
	int turn = 6;
	bool win = false;
	char wordPlayer[6];
	const char* word[] = { "TABLE", "BALLE", "TARTE","BALAI" };
	const char* p_word = word[0];




	bool test = false;
	int b = 0;
	int t = 0;
	//const char* word[] = {"TARTE","TABLE","BALAI","BALLE"};

	while (true)
	{
		PlayWordle(word, p_word, wordPlayer, b, t, test, turn, win);
		cout << "rejouer Oui / Non" << endl;
		cin >> wordPlayer;
		if (wordPlayer != "Oui" || wordPlayer != "OUI" || wordPlayer != "oui")
			break;
	}


	return 0;
}