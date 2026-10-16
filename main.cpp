#include <iostream>

using namespace std;

#define Green "\033[32m"
#define Orange "\033[33m"
#define Red "\033[31m"
#define Default "\033[m"
int Generator(int max);
void PlayWordle(char word[], char wordPlayer[],int b, int t, bool test, int turn, bool win)
{
	int random = Generator(3);
	if (random == 1)
	{

		word[0] = 'T';
		word[1] = 'A';
		word[2] = 'R';
		word[3] = 'T';
		word[4] = 'E';
		word[5] = '\0';// cherche amelioration
	}
	else if (random == 2)
	{
		word[0] = 'T';
		word[1] = 'A';
		word[2] = 'B';
		word[3] = 'L';
		word[4] = 'E';
		word[5] = '\0';
	}
	else if (random == 3)
	{
		word[0] = 'B';
		word[1] = 'A';
		word[2] = 'L';
		word[3] = 'L';
		word[4] = 'E';
		word[5] = '\0';
	}
	else

	{
		word[0] = 'B';
		word[1] = 'A';
		word[2] = 'L';
		word[3] = 'A';
		word[4] = 'I';
		word[5] = '\0';
	}
	
	for (int i = 0; i < turn; i++)
	{
		cout << "Debug Mot secret -> " << word << endl;
		cout << "entrer un mot de 4 caractere en majuscule -> ";
		cin >> wordPlayer;
		b = 0;
		for (int a = 0; a <= 4; a++)
		{
			b++;
			if (wordPlayer[a] == word[a])
			{
				cout << Green << wordPlayer[a] << Default;
				t++;
			}
			else if (wordPlayer[a] != word[a])
			{
				for (int b = 0; b < 5; b++)
				{
					if (wordPlayer[b] == word[a])
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
	char word[6];
	char* p_word = &word[6];

	

	bool test = false;
	int b = 0;
	int t = 0;
	//const char* word[] = {"TARTE","TABLE","BALAI","BALLE"};
	
	while (true)
	{
		PlayWordle(word, wordPlayer, b, t, test, turn, win);
		cout << "rejouer Oui / Non" << endl;
		cin >> wordPlayer;
		if (wordPlayer == "Non" || wordPlayer == "NON")
			break;
	}

	
	return 0;
}