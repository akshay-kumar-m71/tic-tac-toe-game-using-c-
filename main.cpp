#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<conio.h>
#include<mmsystem.h>
#pragma comment (lib,"winmm.lib")
using namespace std;
class board {
public:
	void bod(char d[][7])
	{
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if ((i % 2 == 0) and (j % 2 == 0))
					d[i][j] = ' ';
				if ((i % 2 != 0) and (j % 2 == 0))
					d[i][j] = '|';
				if ((i % 2 == 0) and (j % 2 != 0))
					d[i][j] = '-';

			}
		}
		d[1][1] = '1';
		d[1][3] = '2';
		d[1][5] = '3';
		d[3][1] = '4';
		d[3][3] = '5';
		d[3][5] = '6';
		d[5][1] = '7';
		d[5][3] = '8';
		d[5][5] = '9';

	}
	void display(char d[][7]) {
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
				cout << d[i][j] << "  ";
			cout << endl;
		}
	}

};
class possiblities {
public:
	void attack(char d[][7],int* vacnt, int* possi, char* ico) {
		int c;
		for (int k = 0; k < 9; k++)
		{
			if ((*(vacnt + k) == 1) && (*(vacnt + k + 9) == 1))
			{
				if ((d[3][1] == *ico) && (d[5][1] == *ico))
				{
					*possi = 1;
					*(possi + 1) = 1;
				}
				if ((d[1][3] == *ico) && (d[1][5] == *ico))
				{
					*possi = 1;
					*(possi + 1) = 1;
					//delete[] vacnt;
				}
				if ((d[3][3] == *ico) && (d[5][5] == *ico))
				{
					*possi = 1;
					*(possi + 1) = 1;
					//delete[] vacnt;
				}
			}
			else if ((*(vacnt + k) == 1) && (*(vacnt + k + 9) == 3))
			{
				if (d[1][1] == *ico && d[1][5] == *ico)
				{
					*possi = 1;
					*(possi + 1) = 3;
					//delete[] vacnt;
				}
				if (d[3][3] == *ico && d[5][5] == *ico)
				{
					*possi = 1;
					*(possi + 1) = 3;
					//delete[] vacnt;
				}
			}
			else if ((*(vacnt + k) == 1) && (*(vacnt + k + 9) == 5))
			{
				if (d[1][1] == *ico && d[1][3] == *ico)
				{
					*possi = 1;
					*(possi + 1) = 5;
					//delete[] vacnt;
				}
				if (d[3][5] == *ico && d[5][5] == *ico)
				{
					*possi = 1;
					*(possi + 1) = 5;
					//delete[] vacnt;
				}
				if (d[3][3] == *ico && d[5][1] == *ico)
				{
					*possi = 1;
					*(possi + 1) = 5;
					//delete[] vacnt;
				}
			}
			else if ((*(vacnt + k) == 3) && (*(vacnt + k + 9) == 1))
			{
				if (d[1][1] == *ico && d[5][1] == *ico)
				{
					*possi = 3;
					*(possi + 1) = 1;
					//delete[] vacnt;
				}
				if (d[3][3] == *ico && d[3][5] == *ico)
				{
					*possi = 3;
					*(possi + 1) = 1;
					//delete[] vacnt;
				}
			}
			else if ((*(vacnt + k) == 3) && (*(vacnt + k + 9) == 3))
			{
				if (d[1][1] == *ico && d[5][5] == *ico)
				{
					*possi = 3;
					*(possi + 1) = 3;
					//delete[] vacnt;
				}
				if (d[1][3] == *ico && d[5][3] == *ico)
				{
					*possi = 3;
					*(possi + 1) = 3;
					//delete[] vacnt;
				}
				if (d[3][1] == *ico && d[3][5] == *ico)
				{
					*possi = 3;
					*(possi + 1) = 3;
					//delete[] vacnt;
				}
			}
			else if ((*(vacnt + k) == 3) && (*(vacnt + k + 9) == 5))
			{
				if (d[3][1] == *ico && d[3][3] == *ico)
				{
					*possi = 3;
					*(possi + 1) = 5;
					//delete[] vacnt;
				}
				if (d[1][5] == *ico && d[5][5] == *ico)
				{
					*possi = 3;
					*(possi + 1) = 5;
					//delete[] vacnt;
				}
			}
			else if ((*(vacnt + k) == 5) && (*(vacnt + k + 9) == 1))
			{
				if (d[1][1] == *ico && d[3][1] == *ico)
				{
					*possi = 5;
					*(possi + 1) = 1;
					//delete[] vacnt;
				}
				if (d[5][3] == *ico && d[5][5] == *ico)
				{
					*possi = 5;
					*(possi + 1) = 1;
					//delete[] vacnt;
				}
				if (d[3][3] == *ico && d[1][5] == *ico)
				{
					*possi = 5;
					*(possi + 1) = 1;
					//delete[] vacnt;
				}
			}
			else if ((*(vacnt + k) == 5) && (*(vacnt + k + 9) == 3))
			{
				if (d[5][1] == *ico && d[5][5] == *ico)
				{
					*possi = 5;
					*(possi + 1) = 3;
					//delete[] vacnt;
				}
				if (d[3][3] == *ico && d[1][3] == *ico)
				{
					*possi = 5;
					*(possi + 1) = 3;
					//delete[] vacnt;
				}
			}
			else if ((*(vacnt + k) == 5) && (*(vacnt + k + 9) == 5))
			{
				if (d[5][1] == *ico && d[5][3] == *ico)
				{
					*possi = 5;
					*(possi + 1) = 5;
					//delete[] vacnt;
				}
				else if (d[3][5] == *ico && d[1][5] == *ico)
				{
					*possi = 5;
					*(possi + 1) = 5;
					//delete[] vacnt;
				}
				else if (d[3][3] == *ico && d[1][1] == *ico)
				{
					*possi = 5;
					*(possi + 1) = 5;
					//delete[] vacnt;
				}
			}


		}

	}
};
class check {
public:
	int chck(char d[][7], int* temp) {
		for (int k = 0; k < 18; k++)
		{
			*(temp + k) = -1;
		}
		int k = 0;
		for (int i = 1; i < 7; i = i + 2)
		{
			for (int j = 1; j < 7; j = j + 2)
			{
				if (!((d[i][j] == 'O') || (d[i][j] == 'X')))
				{
					*(temp + k) = i;
					*(temp + k + 9) = j;
					k++;
				}
			}
		}
		return 0;
	}
	void value(char* val, char d[][7],char v)
	{
		switch (*val)
		{
		case '1':
		{
			if (!((d[1][1] == 'X') || (d[1][1] == 'O')))
				d[1][1] = v;
			else
				cout << endl << "please enter the valid column!";
			break;
		}
		case '2':
		{
			if (!((d[1][3] == 'X') || (d[1][3] == 'O')))
				d[1][3] = v;
			else
				cout << endl << "please enter the valid column!";
			break;
		}
		case '3':
		{
			if (!((d[1][5] == 'X') || (d[1][5] == 'O')))
				d[1][5] = v;
			else
				cout << endl << "please enter the valid box!";
			break;
		}
		case '4':
		{
			if (!((d[3][1] == 'X') || (d[3][1] == 'O')))
				d[3][1] = v;
			else
				cout << endl << "please enter the valid box!";
			break;
		}
		case '5':
		{
			if (!((d[3][3] == 'X') || (d[3][3] == 'O')))
				d[3][3] = v;
			else
				cout << endl << "please enter the valid box!";
			break;
		}
		case '6':
		{
			if (!((d[3][5] == 'X') || (d[3][5] == 'O')))
				d[3][5] = v;
			else
				cout << endl << "please enter the valid box!";
			break;
		}
		case '7':
		{
			if (!((d[5][1] == 'X') || (d[5][1] == 'O')))
				d[5][1] = v;
			else
				cout << endl << "please enter the valid box!";
			break;
		}
		case '8':
		{
			if (!((d[5][3] == 'X') || (d[5][3] == 'O')))
				d[5][3] = v;
			else
				cout << endl << "please enter the valid box!";
			break;
		}
		case '9':
		{
			if (!((d[5][5] == 'X') || (d[5][5] == 'O')))
				d[5][5] = v;
			else
				cout << endl << "please enter the valid box!";
			break;
		}
		}
	}
};
class strt {
public:
	int st()
	{
		system("cls");
		int op;
		cout << "1.START" << endl << "2.EXIT"<<endl<<"3.MULTIPLAYER"<<endl;
		cout << "enter the option: ";
		cin >> op;
		if (op == 1)
			return 0;
		if (op == 2)
			exit(0);
		if (op == 3)
			return -1;
	}
};
class win {
public:
	int wn(char d[][7],int *temp)
	{
		strt s;
		char a;
		board b;
		system("cls");

		if ((d[1][1] == d[1][3]) && (d[1][1] == d[1][5]))
		{
			b.display(d);
			cout <<endl<< d[1][1] << " win" << endl << "press m to move to main menu:";
			cin >> a;
			delete[] temp;
			if (a == 'm')
				return (- 1);
		}
		else if ((d[1][1] == d[3][1]) && (d[1][1] == d[5][1]))
		{
			b.display(d);
			cout <<endl<< d[1][1] << " win" << endl << "press m to move to main menu:";
			cin >> a;
			delete[] temp;
			if (a == 'm')
				return -1;
		}
		else if ((d[1][1] == d[3][3]) && (d[1][1] == d[5][5]))
		{
			b.display(d);
			cout <<endl<< d[1][1] << " win" << endl << "press m to move to main menu:";
			cin >> a;
			delete[] temp;
			if (a == 'm')
				return -1;
		}
		else if ((d[3][1] == d[3][3]) && (d[3][1] == d[3][5]))
		{
			b.display(d);
			cout <<endl<< d[3][1] << " win" << endl << "press m to move to main menu:";
			cin >> a;
			delete[] temp;
			if (a == 'm')
				return -1;
		}
		else if ((d[1][5] == d[3][3]) && (d[1][5] == d[5][1]))
		{
			b.display(d);
			cout << endl << d[1][5] << " win" << endl << "press m to move to main menu:";
			cin >> a;
			delete[] temp;
			if (a == 'm')
				return -1;
		}
		else if ((d[5][1] == d[5][3]) && (d[5][1] == d[5][5]))
		{
			b.display(d);
			cout <<endl<<d[5][1] << " win" << endl << "press m to move to main menu:";
			cin >> a;
			delete[] temp;
			if (a == 'm')
				return -1;
		}
		else if ((d[1][3] == d[3][3]) && (d[1][3] == d[5][3]))
		{
			b.display(d);
			cout <<endl<< d[1][3] << " win" << endl << "press m to move to main menu:";
			cin >> a;
			delete[] temp;
			if (a == 'm')
				return -1;
		
		}
		else if ((d[1][5] == d[3][5]) && (d[1][5] == d[5][5]))
		{
			b.display(d);
			cout <<endl<< d[1][5] << " win" << endl << "press m to move to main menu:";
			cin >> a;
			delete[] temp;
			if (a == 'm')
				return -1;
		}
		else
		{
			system("CLS");
			if (*temp == -1) {
				b.display(d);
				cout <<endl<< "Nobody win! Draw "<<endl<<"press m to move to main menu:";
				cin >> a;
				delete[] temp;
				if (a == 'm')
					return -1;
			}
			    
		}
		return 0;

	}
};
class cmplyr {
public:
	board b;
	check c;
	possiblities p;
	char val;

	void cmp(int* temp,int* possi,char d[][7],char ico)
	{
		system("CLS");
			*possi = -1;
			*(possi + 1) = -1;
			b.display(d);
			cout << endl << endl << endl << "enter the box no: ";
			cin >> val;
			PlaySound(TEXT("mixkit-extra-bonus-in-a-video-game-2045.wav"), NULL, SND_FILENAME | SND_SYNC);
			c.value(&val, d,'O');
			c.chck(d, temp);
			if (*temp != -1)
			{
				if ((*possi == -1) && (*(possi + 1) == -1))
				{
					p.attack(d, temp, possi, &ico);
					if (*possi != -1)
						d[*possi][*(possi + 1)] = 'X';
					ico = 'O';
				}

				if ((*possi == -1) && (*(possi + 1) == -1))
				{
					p.attack(d, temp, possi, &ico);
					if (*possi != -1)
						d[*possi][*(possi + 1)] = 'X';
				}//ok
				if ((*possi == -1) && (*(possi + 1) == -1))
				{
					for (int i = 0; i >= 0; i++)
					{
						srand(time(0));
						int ra = (1 + (rand() % 8));
						if (*(temp + ra) != -1)
						{
							//	for (int k = 0; k < 18; k++)
								//	cout << "temp" << *(temp + k) << endl;
								d[*(temp + ra)][*(temp + ra + 9)] = 'X';
								i = -2;
							}

						//delete[] temp;
					}
				}
			}
	}
	
};
class twplyr {
public:
	board b;
	check c;
	void twp1(char d[][7],int* temp) {
		char val;
		system("CLS");
		b.display(d);
		cout << endl << endl << endl << "player 1 -> enter the box no: ";
		cin >> val;
		c.value(&val, d,'O');
		c.chck(d, temp);
	}
	void twp2(char d[][7],int* temp) {
		char val;
		system("CLS");
		b.display(d);
		cout << endl << endl << endl << "player 2 -> enter the box no: ";
		cin >> val;
		c.value(&val, d, 'X');
		c.chck(d, temp);
	}
};
int main()
{
	for (int z = 0; z <= 0; z++) 
	{
		board b;
		check c;
		possiblities p;
		strt s;
		twplyr t;
		cmplyr cm;
		win w;
		int change;
		int v;
		char d[7][7];
		char ico = 'X';
		int* possi = new int[2];
		b.bod(d);
		v=s.st();
		if (v == 0)
		{

			for (int j = 0; j >= 0; j++)
			{
				int* temp = new int[18];
				cm.cmp(temp, possi, d, ico);
				
				change = w.wn(d, temp);
				if (change == -1)
				{
					j = -2;
					z = -2;
				}
			}
		}
		else if (v == -1)
		{
			for (int j = 0; j >= 0; j++)
			{
				int* temp = new int[18];
				t.twp1(d,temp);
			    change = w.wn(d, temp);
			    if (change == -1)
			    {
				   // j = -2;
				    z = -2;
					break;
			    }
				t.twp2(d,temp);
				change = w.wn(d, temp);
				if (change == -1)
				{
				//	j = -2;
					z = -2;
					break;
				}
	     	}
		}
	}
	return 0;

}