// Practica1_IngSoft.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

static const int	ANCHOMUNDO = 20;
static const char	PLAYER = 'X';
static int			POS_CHAR = ANCHOMUNDO / 2;
static const char	BACKGROUND = '-';
static const char	BULLET = 'o';
static int			POS_BULLET = -1;
static bool			b = false;
static bool			d = false;

int main()
{

	int key;

	while (1) {
		if (!b) {
			if (_kbhit()) {
				key = _getch();
				if (key == 'a') {
					if (POS_CHAR > 0) { --POS_CHAR; }
				}
				else if (key == 'd') {
					if (POS_CHAR < ANCHOMUNDO - 1) { ++POS_CHAR; }
				}
				else if (key == 'j') {
					if (POS_BULLET < ANCHOMUNDO - 1) {
						POS_BULLET = POS_CHAR - 1;
						b = true;
						d = false;
					}
				}
				else if (key == 'k') {
					if (POS_BULLET < ANCHOMUNDO - 1) {
						POS_BULLET = POS_CHAR + 1;
						b = true;
						d = true;
					}
				}
			}
		}
		if (b) {
			if (POS_BULLET < 0 || POS_BULLET>ANCHOMUNDO) {
				POS_BULLET = -1;
				b = false;
				d = false;
			}
			else {
				if (d == true) { ++POS_BULLET; }
				else { --POS_BULLET; }
			}
		}
		for (int i = 0; i < ANCHOMUNDO; i++) {
			if (i == POS_CHAR) { printf("%c", PLAYER); }
			else if (i == POS_BULLET) { printf("%c", BULLET); }
			else { printf("%c", BACKGROUND); }
		}
		cout << '\r';
		Sleep(50);
	}

	return 0;
}
