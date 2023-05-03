#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <mmsystem.h>
#include <tchar.h> 
using namespace std;

#pragma comment(lib, "winmm.lib")
#pragma comment(lib,"msimg32.lib")

HWND hwnd = GetConsoleWindow();
HDC hdc = GetDC(hwnd);
HANDLE tvin = GetStdHandle(STD_OUTPUT_HANDLE);



void _rect(int left, int top, int width, int height) {
	Rectangle(hdc, left, top, left + width, top + height);
}

void _ellips(int left, int top, int width, int height) {
	Ellipse(hdc, left, top, left + width, top + height);
}

DWORD  WINAPI playMusik(LPVOID param) {
	mciSendString(_T("open 1.mid type sequencer alias MUSIC"), NULL, 0, 0);
	mciSendString(_T("play MUSIC from 0"), NULL, 0, 0);
	return 0;
}

class Sudoku {

private:
	int size;
	int leve;
	int* mass;
	int* massx;
	int ar[9][9];
public:
	Sudoku();
	void massive();
	void Set_massive(int ar[][9]) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				this->ar[i][j] = ar[i][j];
			}
		}
	}
	int Get_Sudoky() { return *mass; }
	int Get_mass() { return *massx; }
	int Get_Size() { return size; }
	int Get_level() { return leve; }
	void Set_level(int level = 3) { this->leve = level; }
	int Get_massive() { return *ar[9]; }
	void sotvet();
	void print();
	void cleer();
	void game();
	void clened();
	void digit(int x, int y, int chislo, int index1, int index2, int arr[][9]);
	bool proverka(int index1, int index2);
	bool win();
	void pobeda();
	void menu();
	void help();
	void options();

};

Sudoku::Sudoku() {
	size = 81;
	mass = new int[size];
}


void Sudoku::massive() {
	srand(time(NULL));
	int yes = 0;
	int koll = 0;

	for (int i = 0; i < size; i++) {
		mass[i] = rand() % 9 + 1;

		if (i % 9 == 8 && (mass[i] == mass[i - 1] || mass[i] == mass[i - 2] || mass[i] == mass[i - 3] || mass[i] == mass[i - 4] || mass[i] == mass[i - 5] || mass[i] == mass[i - 6] || mass[i] == mass[i - 7] || mass[i] == mass[i - 8])) yes = 1;
		if (i % 9 == 7 && (mass[i] == mass[i - 1] || mass[i] == mass[i - 2] || mass[i] == mass[i - 3] || mass[i] == mass[i - 4] || mass[i] == mass[i - 5] || mass[i] == mass[i - 6] || mass[i] == mass[i - 7])) yes = 1;
		if (i % 9 == 6 && (mass[i] == mass[i - 1] || mass[i] == mass[i - 2] || mass[i] == mass[i - 3] || mass[i] == mass[i - 4] || mass[i] == mass[i - 5] || mass[i] == mass[i - 6])) yes = 1;
		if (i % 9 == 5 && (mass[i] == mass[i - 1] || mass[i] == mass[i - 2] || mass[i] == mass[i - 3] || mass[i] == mass[i - 4] || mass[i] == mass[i - 5])) yes = 1;
		if (i % 9 == 4 && (mass[i] == mass[i - 1] || mass[i] == mass[i - 2] || mass[i] == mass[i - 3] || mass[i] == mass[i - 4])) yes = 1;
		if (i % 9 == 3 && (mass[i] == mass[i - 1] || mass[i] == mass[i - 2] || mass[i] == mass[i - 3])) yes = 1;
		if (i % 9 == 2 && (mass[i] == mass[i - 1] || mass[i] == mass[i - 2])) yes = 1;
		if (i % 9 == 1 && (mass[i] == mass[i - 1])) yes = 1;

		if ((i % 27 == 9 || i % 27 == 12 || i % 27 == 15) && (mass[i] == mass[i - 9] || mass[i] == mass[i - 8] || mass[i] == mass[i - 7])) yes = 1;
		if ((i % 27 == 10 || i % 27 == 13 || i % 27 == 16) && (mass[i] == mass[i - 10] || mass[i] == mass[i - 9] || mass[i] == mass[i - 8])) yes = 1;
		if ((i % 27 == 11 || i % 27 == 14 || i % 27 == 17) && (mass[i] == mass[i - 11] || mass[i] == mass[i - 10] || mass[i] == mass[i - 9])) yes = 1;

		if ((i % 27 == 18 || i % 27 == 21 || i % 27 == 24) && (mass[i] == mass[i - 9] || mass[i] == mass[i - 8] || mass[i] == mass[i - 7] || mass[i] == mass[i - 18] || mass[i] == mass[i - 17] || mass[i] == mass[i - 16])) yes = 1;
		if ((i % 27 == 19 || i % 27 == 22 || i % 27 == 25) && (mass[i] == mass[i - 10] || mass[i] == mass[i - 9] || mass[i] == mass[i - 8] || mass[i] == mass[i - 19] || mass[i] == mass[i - 18] || mass[i] == mass[i - 17])) yes = 1;
		if ((i % 27 == 20 || i % 27 == 23 || i % 27 == 26) && (mass[i] == mass[i - 11] || mass[i] == mass[i - 10] || mass[i] == mass[i - 9] || mass[i] == mass[i - 20] || mass[i] == mass[i - 19] || mass[i] == mass[i - 18])) yes = 1;

		if (mass[i] == mass[i - 9] || mass[i] == mass[i - 18] || mass[i] == mass[i - 27] || mass[i] == mass[i - 36] || mass[i] == mass[i - 45] || mass[i] == mass[i - 54] || mass[i] == mass[i - 63] || mass[i] == mass[i - 72]) yes = 1;

		koll++;
		if (yes == 1) {
			i--;
			if (koll > 200) {
				i -= 9;
				koll = 0;
			}
			yes = 0;
		}
	}



}



bool Sudoku::proverka(int index2, int index1) { //index2-y(i) index1-x(j)

	int counter = 0;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			if (j == index1 && ar[index2][index1] == ar[i][j] && ar[i][j] != 0) counter++;
			if (i == index2 && ar[index2][index1] == ar[i][j] && ar[i][j] != 0) counter++;

			if (index1 < 3 && index2 < 3 && ar[i][j] != 0 && i < 3 && j < 3 && ar[index2][index1] == ar[i][j]) counter++;
			if (index1 > 2 && index1 < 6 && index2 < 3 && ar[i][j] != 0 && i < 3 && j>2 && j < 6 && ar[index2][index1] == ar[i][j]) counter++;
			if (index1 > 5 && index2 < 3 && ar[i][j] != 0 && i < 3 && j>5 && ar[index2][index1] == ar[i][j]) counter++;

			if (index2 > 2 && index2 < 6 && index1 < 3 && ar[i][j] != 0 && i>2 && i < 6 && j < 3 && ar[index2][index1] == ar[i][j]) counter++;
			if (index1 > 2 && index1 < 6 && index2>2 && index2 < 6 && ar[i][j] != 0 && i>2 && i < 6 && j>2 && j < 6 && ar[index2][index1] == ar[i][j]) counter++;
			if (index1 > 5 && index2 > 2 && index2 < 6 && ar[i][j] != 0 && i>2 && i < 6 && j>5 && ar[index2][index1] == ar[i][j]) counter++;

			if (index1 < 3 && index2>5 && ar[i][j] != 0 && i > 5 && j < 3 && ar[index2][index1] == ar[i][j]) counter++;
			if (index1 > 2 && index1 < 6 && index2>5 && ar[i][j] != 0 && i > 5 && j > 2 && j < 6 && ar[index2][index1] == ar[i][j]) counter++;
			if (index1 > 5 && index2 > 5 && ar[i][j] != 0 && i > 5 && j > 5 && ar[index2][index1] == ar[i][j]) counter++;
		}

	if ((counter - 3) != 0) return false;
	else return true;

}


void Sudoku::print() {

	//код квадрата


	HPEN white_pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	HBRUSH white_brush = CreateSolidBrush(RGB(255, 255, 255));

	SelectObject(hdc, white_pen);
	SelectObject(hdc, white_brush);

	_rect(4, 5, 581, 580);//главный квадрат

	DeleteObject(white_pen);
	DeleteObject(white_brush);
	//////////////////////////////////////////
	////////////////////////////////////////

	HPEN black_pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	HBRUSH black_brush = CreateSolidBrush(RGB(0, 0, 0));

	SelectObject(hdc, black_pen);
	SelectObject(hdc, black_brush);
	//квадратики
	//9 по вертикали 
	_rect(65, 0, 1, 620);
	_rect(130, 0, 1, 620);
	_rect(195, 0, 3, 620);
	_rect(260, 0, 1, 620);
	_rect(325, 0, 1, 620);
	_rect(390, 0, 3, 620);
	_rect(455, 0, 1, 620);
	_rect(520, 0, 1, 620);
	_rect(585, 0, 1, 620);
	//9 по горизонтали
	_rect(0, 65, 585, 1);
	_rect(0, 130, 585, 1);
	_rect(0, 195, 585, 3);
	_rect(0, 260, 585, 1);
	_rect(0, 325, 585, 1);
	_rect(0, 390, 585, 3);
	_rect(0, 455, 585, 1);
	_rect(0, 520, 585, 1);
	_rect(0, 585, 585, 1);

	DeleteObject(black_pen);
	DeleteObject(black_brush);

	///////////////////////////
		///////////////////////////

	//////////////////////////

		///////////////////////////
	//цифры
	LOGFONT font;
	font.lfHeight = 70;// Устанавливает высоту шрифта или символа
	font.lfWidth = 0;// Устанавливает среднюю ширину символов в шрифте
	font.lfEscapement = 0;// Устанавливает угол, между вектором наклона и осью X устройства
	font.lfOrientation = 0;// Устанавливает угол, между основной линией каждого символа и осью X устройства
	font.lfWeight = 100;// Устанавливает толщину шрифта в диапазоне от 0 до 1000
	font.lfItalic = 0;// Устанавливает курсивный шрифт
	font.lfUnderline = 0;// Устанавливает подчеркнутый шрифт
	font.lfStrikeOut = 0;// Устанавливает зачеркнутый шрифт
	font.lfCharSet = RUSSIAN_CHARSET;// Устанавливает набор символов
	font.lfOutPrecision = 0;// Устанавливает точность вывода
	font.lfClipPrecision = 0;// Устанавливает точность отсечения
	font.lfQuality = 0;// Устанавливает качество вывода
	font.lfPitchAndFamily = 0;// Устанавливает ширину символов и семейство шрифта
	lstrcpy(font.lfFaceName, L"Comic Sans MS");//  устанавливает название шрифта

	HFONT hfont;
	hfont = CreateFontIndirect(&font);

	SetTextColor(hdc, RGB(0, 0, 0));
	SetBkMode(hdc, TRANSPARENT);
	SelectObject(hdc, hfont);


	/////////////////////////

	/////////////////////////
	int x1 = 20;
	int y1 = 0;
	for (int i = 0; i < size; i++) {
		if (i != 0) { x1 += 65; }
		if (i == 9 || i == 18 || i == 27 || i == 36 || i == 45 || i == 54 || i == 63 || i == 72 || i == 81) {
			x1 = 20;
			y1 += 65;
		}

		if (mass[i] == 1) {
			TextOutA(hdc, x1, y1, "1", 1);
		}

		else if (mass[i] == 2) {
			TextOutA(hdc, x1, y1, "2", 1);
		}
		else if (mass[i] == 3) {
			TextOutA(hdc, x1, y1, "3", 1);

		}
		else if (mass[i] == 4) {
			TextOutA(hdc, x1, y1, "4", 1);

		}
		else if (mass[i] == 5) {

			TextOutA(hdc, x1, y1, "5", 1);
		}
		else if (mass[i] == 6) {
			TextOutA(hdc, x1, y1, "6", 1);
		}
		else if (mass[i] == 7) {
			TextOutA(hdc, x1, y1, "7", 1);
		}
		else if (mass[i] == 8) {
			TextOutA(hdc, x1, y1, "8", 1);
		}
		else if (mass[i] == 9) {
			TextOutA(hdc, x1, y1, "9", 1);
		}
	}
}

void Sudoku::cleer() {
	/////////////////////////////////////////////////

	srand(time(NULL));
	HPEN white_pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	HBRUSH white_brush = CreateSolidBrush(RGB(255, 255, 255));

	SelectObject(hdc, white_pen);
	SelectObject(hdc, white_brush);

	//////////////////////////////////////////


	int ar2[81];
	for (int i = 0; i < 81; i++) {
		ar2[i] = mass[i];
	}
	//////////////////////////




	////////////////////////////////////////////////
	int w = 0;

	int x1 = 10;
	int y1 = 10;
	int random;


	for (int i = 0; i < size; i++)
	{
		if (i != 0) { x1 += 65; }
		if (i == 9 || i == 18 || i == 27 || i == 36 || i == 45 || i == 54 || i == 63 || i == 72 || i == 81) {
			x1 = 10;
			y1 += 65;
		}

		random = rand() % leve + 1;

		if (leve == 4) {
			if (random == 2) {
				ar2[i] = 0;
				_rect(x1, y1, 50, 50);
			}
		}
		else if (leve == 3) {
			if (random != 2) {
				ar2[i] = 0;
				_rect(x1, y1, 50, 50);
			}

		}

		else if (leve == 6) {
			if (random != 2) {
				ar2[i] = 0;
				_rect(x1, y1, 50, 50);
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			ar[i][j] = ar2[w];
			w++;
		}
	}
	Set_massive(ar);

	DeleteObject(white_pen);
	DeleteObject(white_brush);
}


void Sudoku::clened() {
	int x1 = 10;
	int y1 = 58;
	for (int i = 0; i < size; i++) {
		if (i != 0) { x1 += 65; }
		if (i == 9 || i == 18 || i == 27 || i == 36 || i == 45 || i == 54 || i == 63 || i == 72 || i == 81) {
			x1 = 10;
			y1 += 65;
		}
		HPEN point_pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
		HBRUSH point_brush = CreateSolidBrush(RGB(255, 255, 255));

		SelectObject(hdc, point_pen);
		SelectObject(hdc, point_brush);
		_rect(x1, y1, 50, 5);
		DeleteObject(point_pen);
		DeleteObject(point_brush);
	}
}


void Sudoku::digit(int x, int y, int chislo, int index1, int index2, int arr[][9]) {


	HPEN point_pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	HBRUSH point_brush = CreateSolidBrush(RGB(255, 255, 255));

	SelectObject(hdc, point_pen);
	SelectObject(hdc, point_brush);


	///////////////////////////////////////
	//цифры
	LOGFONT font;
	font.lfHeight = 70;// Устанавливает высоту шрифта или символа
	font.lfWidth = 0;// Устанавливает среднюю ширину символов в шрифте
	font.lfEscapement = 0;// Устанавливает угол, между вектором наклона и осью X устройства
	font.lfOrientation = 0;// Устанавливает угол, между основной линией каждого символа и осью X устройства
	font.lfWeight = 100;// Устанавливает толщину шрифта в диапазоне от 0 до 1000
	font.lfItalic = 0;// Устанавливает курсивный шрифт
	font.lfUnderline = 0;// Устанавливает подчеркнутый шрифт
	font.lfStrikeOut = 0;// Устанавливает зачеркнутый шрифт
	font.lfCharSet = RUSSIAN_CHARSET;// Устанавливает набор символов
	font.lfOutPrecision = 0;// Устанавливает точность вывода
	font.lfClipPrecision = 0;// Устанавливает точность отсечения
	font.lfQuality = 0;// Устанавливает качество вывода
	font.lfPitchAndFamily = 0;// Устанавливает ширину символов и семейство шрифта
	lstrcpy(font.lfFaceName, L"Comic Sans MS");//  устанавливает название шрифта

	HFONT hfont;
	hfont = CreateFontIndirect(&font);

	SetTextColor(hdc, RGB(169, 169, 169));
	SetBkMode(hdc, TRANSPARENT);
	SelectObject(hdc, hfont);



	if (arr[index2][index1] == 0) {

		switch (chislo) {
		case 49: { ar[index2][index1] = 1; if (proverka(index2, index1) == false) SetTextColor(hdc, RGB(255, 0, 0)); _rect(x, y -= 50, 50, 50); TextOutA(hdc, x += 10, y -= 8, "1", 1); if (win() == true) pobeda(); break; }
		case 50: { ar[index2][index1] = 2; if (proverka(index2, index1) == false) SetTextColor(hdc, RGB(255, 0, 0)); _rect(x, y -= 50, 50, 50); TextOutA(hdc, x += 10, y -= 8, "2", 1); if (win() == true) pobeda(); break; }
		case 51: { ar[index2][index1] = 3; if (proverka(index2, index1) == false) SetTextColor(hdc, RGB(255, 0, 0)); _rect(x, y -= 50, 50, 50); TextOutA(hdc, x += 10, y -= 8, "3", 1); if (win() == true) pobeda(); break; }
		case 52: { ar[index2][index1] = 4; if (proverka(index2, index1) == false) SetTextColor(hdc, RGB(255, 0, 0)); _rect(x, y -= 50, 50, 50); TextOutA(hdc, x += 10, y -= 8, "4", 1); if (win() == true) pobeda(); break; }
		case 53: { ar[index2][index1] = 5; if (proverka(index2, index1) == false) SetTextColor(hdc, RGB(255, 0, 0)); _rect(x, y -= 50, 50, 50); TextOutA(hdc, x += 10, y -= 8, "5", 1); if (win() == true) pobeda(); break; }
		case 54: { ar[index2][index1] = 6; if (proverka(index2, index1) == false) SetTextColor(hdc, RGB(255, 0, 0)); _rect(x, y -= 50, 50, 50); TextOutA(hdc, x += 10, y -= 8, "6", 1); if (win() == true) pobeda(); break; }
		case 55: { ar[index2][index1] = 7; if (proverka(index2, index1) == false) SetTextColor(hdc, RGB(255, 0, 0)); _rect(x, y -= 50, 50, 50); TextOutA(hdc, x += 10, y -= 8, "7", 1); if (win() == true) pobeda(); break; }
		case 56: { ar[index2][index1] = 8; if (proverka(index2, index1) == false) SetTextColor(hdc, RGB(255, 0, 0)); _rect(x, y -= 50, 50, 50); TextOutA(hdc, x += 10, y -= 8, "8", 1); if (win() == true) pobeda(); break; }
		case 57: { ar[index2][index1] = 9; if (proverka(index2, index1) == false) SetTextColor(hdc, RGB(255, 0, 0)); _rect(x, y -= 50, 50, 50); TextOutA(hdc, x += 10, y -= 8, "9", 1); if (win() == true) pobeda(); break; }
		case 48: { ar[index2][index1] = 0; _rect(x, y -= 50, 50, 50); break; }

		}
	}

	DeleteObject(point_pen);
	DeleteObject(point_brush);
}


void Sudoku::game() {


	//////////////////////////////////////
	int x2 = 10;
	int y2 = 58;
	int d;
	COORD index;
	index.X = 0;
	index.Y = 0;
	SetConsoleCursorPosition(tvin, index);

	int arr[9][9];

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			arr[i][j] = ar[i][j];
		}
	}

	while (1) {

		HPEN point2_pen = CreatePen(PS_SOLID, 1, RGB(255, 153, 0));
		HBRUSH point2_brush = CreateSolidBrush(RGB(255, 153, 0));

		SelectObject(hdc, point2_pen);
		SelectObject(hdc, point2_brush);
		_rect(x2, y2, 50, 5);
		d = _getch();
		if (d == 77) {
			if (x2 == 530)_rect(x2, y2, 50, 5);
			else { clened(); _rect(x2 += 65, y2, 50, 5); index.X++; }

		}
		if (d == 75) {
			if (x2 == 10)_rect(x2, y2, 50, 5);
			else { clened(); _rect(x2 -= 65, y2, 50, 5); index.X--; }
		}
		if (d == 72) {
			if (y2 == 58)_rect(x2, y2, 50, 5);
			else { clened(); _rect(x2, y2 -= 65, 50, 5); index.Y--; }
		}
		if (d == 80) {
			if (y2 == 578)_rect(x2, y2, 50, 5);
			else { clened(); _rect(x2, y2 += 65, 50, 5); index.Y++; }
		}
		if (d > 47 && d < 58) digit(x2, y2, d, index.X, index.Y, arr);
		if (d == 27) menu();
		DeleteObject(point2_pen);
		DeleteObject(point2_brush);

	}

	/////////////////////////////////////
}


bool Sudoku::win() {
	int m = 0;
	int schet = 0;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			if (mass[m] == ar[i][j]) {
				schet++;
			}
			m++;
		}
	if (schet == 81) return true;
	else false;
}

void Sudoku::pobeda() {



	HPEN white_pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	HBRUSH white_brush = CreateSolidBrush(RGB(255, 255, 255));

	SelectObject(hdc, white_pen);
	SelectObject(hdc, white_brush);

	_rect(4, 5, 581, 580);//главный квадрат

	DeleteObject(white_pen);
	DeleteObject(white_brush);

	///////////////////////////////////////
	//цифры
	LOGFONT font;
	font.lfHeight = 70;// Устанавливает высоту шрифта или символа
	font.lfWidth = 0;// Устанавливает среднюю ширину символов в шрифте
	font.lfEscapement = 0;// Устанавливает угол, между вектором наклона и осью X устройства
	font.lfOrientation = 0;// Устанавливает угол, между основной линией каждого символа и осью X устройства
	font.lfWeight = 100;// Устанавливает толщину шрифта в диапазоне от 0 до 1000
	font.lfItalic = 0;// Устанавливает курсивный шрифт
	font.lfUnderline = 0;// Устанавливает подчеркнутый шрифт
	font.lfStrikeOut = 0;// Устанавливает зачеркнутый шрифт
	font.lfCharSet = RUSSIAN_CHARSET;// Устанавливает набор символов
	font.lfOutPrecision = 0;// Устанавливает точность вывода
	font.lfClipPrecision = 0;// Устанавливает точность отсечения
	font.lfQuality = 0;// Устанавливает качество вывода
	font.lfPitchAndFamily = 0;// Устанавливает ширину символов и семейство шрифта
	lstrcpy(font.lfFaceName, L"Comic Sans MS");//  устанавливает название шрифта

	HFONT hfont;
	hfont = CreateFontIndirect(&font);

	SetTextColor(hdc, RGB(255, 0, 0));
	SetBkMode(hdc, TRANSPARENT);
	SelectObject(hdc, hfont);
	/*TextOutA(hdc,200,200,"Победа!",9);*/
	TextOutA(hdc, 200, 200, "ПОБЕДА!", 8);
	TextOutA(hdc, 80, 250, "для выхода нажмите", 38);
	TextOutA(hdc, 230, 300, "-esc-", 6);
	int k;
	k = _getch();
	if (k == 27) menu();
	else pobeda();
	ReleaseDC(hwnd, hdc);
	/////////////////////////////


}
/////////////////////////////////////////////////////


void Sudoku::menu() {

	HPEN white_pen = CreatePen(PS_SOLID, 1, RGB(26, 26, 26));
	HBRUSH white_brush = CreateSolidBrush(RGB(26, 26, 26));

	SelectObject(hdc, white_pen);
	SelectObject(hdc, white_brush);

	_rect(4, 5, 581, 580);//главный квадрат

	DeleteObject(white_pen);
	DeleteObject(white_brush);
	///////////////////////////////////////
	//цифры
	LOGFONT font;
	font.lfHeight = 30;// Устанавливает высоту шрифта или символа
	font.lfWidth = 0;// Устанавливает среднюю ширину символов в шрифте
	font.lfEscapement = 0;// Устанавливает угол, между вектором наклона и осью X устройства
	font.lfOrientation = 0;// Устанавливает угол, между основной линией каждого символа и осью X устройства
	font.lfWeight = 100;// Устанавливает толщину шрифта в диапазоне от 0 до 1000
	font.lfItalic = 0;// Устанавливает курсивный шрифт
	font.lfUnderline = 0;// Устанавливает подчеркнутый шрифт
	font.lfStrikeOut = 0;// Устанавливает зачеркнутый шрифт
	font.lfCharSet = RUSSIAN_CHARSET;// Устанавливает набор символов
	font.lfOutPrecision = 0;// Устанавливает точность вывода
	font.lfClipPrecision = 0;// Устанавливает точность отсечения
	font.lfQuality = 0;// Устанавливает качество вывода
	font.lfPitchAndFamily = 0;// Устанавливает ширину символов и семейство шрифта
	lstrcpy(font.lfFaceName, L"Comic Sans MS");//  устанавливает название шрифта

	HFONT hfont;
	hfont = CreateFontIndirect(&font);
	SetBkMode(hdc, TRANSPARENT);
	SelectObject(hdc, hfont);

	SetTextColor(hdc, RGB(8, 21, 143));
	TextOutA(hdc, 100, 500, "СУДОКУ", 6);
	TextOutA(hdc, 200, 500, "версия 1.0", 10);

	SetTextColor(hdc, RGB(255, 0, 0));
	TextOutA(hdc, 50, 50, "Новая игра", 10);
	SetTextColor(hdc, RGB(100, 0, 0));
	TextOutA(hdc, 50, 100, "Управление", 12);
	TextOutA(hdc, 50, 150, "Опции", 5);
	TextOutA(hdc, 50, 200, "Выход", 6);

	///////////////////


	int k = 0;	// код клавиши
	int cur = 1;	// какой пункт выбран сейчас
	while (1) {
		k = _getch();
		if (k == 80) {
			if (cur < 4) {
				cur++;
				if (cur == 1) {
					SetTextColor(hdc, RGB(255, 0, 0));
					TextOutA(hdc, 50, 50, "Новая игра", 10);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 100, "Управление", 12);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 150, "Опции", 5);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 200, "Выход", 6);
				}

				if (cur == 2) {
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 50, "Новая игра", 10);
					SetTextColor(hdc, RGB(255, 0, 0));
					TextOutA(hdc, 50, 100, "Управление", 12);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 150, "Опции", 5);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 200, "Выход", 6);
				}
				if (cur == 3) {
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 50, "Новая игра", 10);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 100, "Управление", 12);
					SetTextColor(hdc, RGB(255, 0, 0));
					TextOutA(hdc, 50, 150, "Опции", 5);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 200, "Выход", 6);
				}
				if (cur == 4) {
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 50, "Новая игра", 10);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 100, "Управление", 12);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 150, "Опции", 5);
					SetTextColor(hdc, RGB(255, 0, 0));
					TextOutA(hdc, 50, 200, "Выход", 6);
				}
			}
		}
		else if (k == 72) {
			if (cur > 1) {
				cur--;
				if (cur == 4) {
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 50, "Новая игра", 10);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 100, "Управление", 12);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 150, "Опции", 5);
					SetTextColor(hdc, RGB(255, 0, 0));
					TextOutA(hdc, 50, 200, "Выход", 6);
				}
				if (cur == 3) {
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 50, "Новая игра", 10);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 100, "Управление", 12);
					SetTextColor(hdc, RGB(255, 0, 0));
					TextOutA(hdc, 50, 150, "Опции", 5);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 200, "Выход", 6);

				}
				else if (cur == 2) {
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 50, "Новая игра", 10);
					SetTextColor(hdc, RGB(255, 0, 0));
					TextOutA(hdc, 50, 100, "Управление", 12);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 150, "Опции", 5);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 200, "Выход", 6);
				}
				else if (cur == 1) {
					SetTextColor(hdc, RGB(255, 0, 0));
					TextOutA(hdc, 50, 50, "Новая игра", 10);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 100, "Управление", 12);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 150, "Опции", 5);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 200, "Выход", 6);
				}
			}
		}
		else if (k == 13) {
			system("cls");
			if (cur == 1) {
				massive(); print(); cleer(); game();
			}
			else if (cur == 2)help();
			else if (cur == 3)options();
			else exit(0);

		}
	}



	///////////////////




	ReleaseDC(hwnd, hdc);

}


void Sudoku::help() {

	HPEN  black_pen = CreatePen(PS_SOLID, 1, RGB(26, 26, 26));
	HBRUSH black_brush = CreateSolidBrush(RGB(26, 26, 26));

	SelectObject(hdc, black_pen);
	SelectObject(hdc, black_brush);

	_rect(4, 5, 581, 580);//главный квадрат

	DeleteObject(black_pen);
	DeleteObject(black_brush);
	///////////////////////////////////////
	HPEN white_pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	HBRUSH white_brush = CreateSolidBrush(RGB(255, 255, 255));

	SelectObject(hdc, white_pen);
	SelectObject(hdc, white_brush);

	RoundRect(hdc, 50, 50, 80, 80, 10, 10);
	RoundRect(hdc, 90, 50, 120, 80, 10, 10);
	RoundRect(hdc, 130, 50, 160, 80, 10, 10);
	RoundRect(hdc, 170, 50, 200, 80, 10, 10);
	RoundRect(hdc, 210, 50, 240, 80, 10, 10);
	RoundRect(hdc, 250, 50, 280, 80, 10, 10);
	RoundRect(hdc, 290, 50, 320, 80, 10, 10);
	RoundRect(hdc, 330, 50, 360, 80, 10, 10);
	RoundRect(hdc, 370, 50, 400, 80, 10, 10);
	RoundRect(hdc, 410, 50, 440, 80, 10, 10);
	/////////////////////


	RoundRect(hdc, 370, 170, 400, 200, 10, 10);
	RoundRect(hdc, 370, 210, 400, 240, 10, 10);
	RoundRect(hdc, 330, 210, 360, 240, 10, 10);
	RoundRect(hdc, 410, 210, 440, 240, 10, 10);
	DeleteObject(white_pen);
	DeleteObject(white_brush);
	///////////////////////////////////////////

	LOGFONT font;
	font.lfHeight = 30;// Устанавливает высоту шрифта или символа
	font.lfWidth = 0;// Устанавливает среднюю ширину символов в шрифте
	font.lfEscapement = 0;// Устанавливает угол, между вектором наклона и осью X устройства
	font.lfOrientation = 0;// Устанавливает угол, между основной линией каждого символа и осью X устройства
	font.lfWeight = 100;// Устанавливает толщину шрифта в диапазоне от 0 до 1000
	font.lfItalic = 0;// Устанавливает курсивный шрифт
	font.lfUnderline = 0;// Устанавливает подчеркнутый шрифт
	font.lfStrikeOut = 0;// Устанавливает зачеркнутый шрифт
	font.lfCharSet = RUSSIAN_CHARSET;// Устанавливает набор символов
	font.lfOutPrecision = 0;// Устанавливает точность вывода
	font.lfClipPrecision = 0;// Устанавливает точность отсечения
	font.lfQuality = 0;// Устанавливает качество вывода
	font.lfPitchAndFamily = 0;// Устанавливает ширину символов и семейство шрифта
	lstrcpy(font.lfFaceName, L"Comic Sans MS");//  устанавливает название шрифта

	HFONT hfont;
	hfont = CreateFontIndirect(&font);
	SetBkMode(hdc, TRANSPARENT);
	SetTextColor(hdc, RGB(0, 0, 0));
	SelectObject(hdc, hfont);

	SetTextColor(hdc, RGB(8, 21, 143));
	TextOutA(hdc, 100, 500, "СУДОКУ", 6);
	TextOutA(hdc, 200, 500, "версия 1.0", 10);

	TextOutA(hdc, 60, 50, "1", 1);
	TextOutA(hdc, 100, 50, "2", 1);
	TextOutA(hdc, 140, 50, "3", 1);
	TextOutA(hdc, 180, 50, "4", 1);
	TextOutA(hdc, 220, 50, "5", 1);
	TextOutA(hdc, 260, 50, "6", 1);
	TextOutA(hdc, 300, 50, "7", 1);
	TextOutA(hdc, 340, 50, "8", 1);
	TextOutA(hdc, 380, 50, "9", 1);
	TextOutA(hdc, 420, 50, "0", 1);

	TextOutA(hdc, 380, 170, "^", 1);
	TextOutA(hdc, 380, 210, "v", 1);
	TextOutA(hdc, 340, 210, "<", 1);
	TextOutA(hdc, 420, 210, ">", 2);
	int k;
	k = _getch();
	if (k == 27) menu();
	else help();

	ReleaseDC(hwnd, hdc);

	///////////////////////////////////////


}


void Sudoku::options() {

	HPEN white_pen = CreatePen(PS_SOLID, 1, RGB(26, 26, 26));
	HBRUSH white_brush = CreateSolidBrush(RGB(26, 26, 26));

	SelectObject(hdc, white_pen);
	SelectObject(hdc, white_brush);

	_rect(4, 5, 581, 580);//главный квадрат

	DeleteObject(white_pen);
	DeleteObject(white_brush);
	///////////////////////////////////////
	//цифры
	LOGFONT font;
	font.lfHeight = 30;// Устанавливает высоту шрифта или символа
	font.lfWidth = 0;// Устанавливает среднюю ширину символов в шрифте
	font.lfEscapement = 0;// Устанавливает угол, между вектором наклона и осью X устройства
	font.lfOrientation = 0;// Устанавливает угол, между основной линией каждого символа и осью X устройства
	font.lfWeight = 100;// Устанавливает толщину шрифта в диапазоне от 0 до 1000
	font.lfItalic = 0;// Устанавливает курсивный шрифт
	font.lfUnderline = 0;// Устанавливает подчеркнутый шрифт
	font.lfStrikeOut = 0;// Устанавливает зачеркнутый шрифт
	font.lfCharSet = RUSSIAN_CHARSET;// Устанавливает набор символов
	font.lfOutPrecision = 0;// Устанавливает точность вывода
	font.lfClipPrecision = 0;// Устанавливает точность отсечения
	font.lfQuality = 0;// Устанавливает качество вывода
	font.lfPitchAndFamily = 0;// Устанавливает ширину символов и семейство шрифта
	lstrcpy(font.lfFaceName, L"Comic Sans MS");//  устанавливает название шрифта

	HFONT hfont;
	hfont = CreateFontIndirect(&font);
	SetBkMode(hdc, TRANSPARENT);
	SelectObject(hdc, hfont);

	SetTextColor(hdc, RGB(8, 21, 143));
	TextOutA(hdc, 100, 500, "СУДОКУ", 6);
	TextOutA(hdc, 200, 500, "версия 1.0", 10);

	SetTextColor(hdc, RGB(255, 153, 0));
	TextOutA(hdc, 50, 10, "Уровень сложности: ", 19);

	SetTextColor(hdc, RGB(255, 0, 0));
	TextOutA(hdc, 50, 50, "Новичок", 7);
	SetTextColor(hdc, RGB(100, 0, 0));
	TextOutA(hdc, 50, 100, "Эксперт", 7);
	TextOutA(hdc, 50, 150, "Профессионал", 13);

	SetTextColor(hdc, RGB(255, 153, 0));
	TextOutA(hdc, 50, 200, "Настойка звука: ", 16);
	SetTextColor(hdc, RGB(100, 0, 0));
	TextOutA(hdc, 50, 250, "Музыка: вкл/выкл", 17);

	///////////////////


	int d = 0;	// код клавиши
	int cur2 = 1;	// какой пункт выбран сейчас
	while (1) {
		d = _getch();
		if (d == 80) {
			if (cur2 < 4) {
				cur2++;
				if (cur2 == 1) {
					SetTextColor(hdc, RGB(255, 0, 0));
					TextOutA(hdc, 50, 50, "Новичок", 7);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 100, "Эксперт", 7);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 150, "Профессионал", 13);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 250, "Музыка: вкл/выкл", 17);
				}

				if (cur2 == 2) {
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 50, "Новичок", 7);
					SetTextColor(hdc, RGB(255, 0, 0));
					TextOutA(hdc, 50, 100, "Эксперт", 7);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 150, "Профессионал", 13);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 250, "Музыка: вкл/выкл", 17);
				}
				if (cur2 == 3) {
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 50, "Новичок", 7);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 100, "Эксперт", 7);
					SetTextColor(hdc, RGB(255, 0, 0));
					TextOutA(hdc, 50, 150, "Профессионал", 13);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 250, "Музыка: вкл/выкл", 17);
				}
				if (cur2 == 4) {
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 50, "Новичок", 7);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 100, "Эксперт", 7);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 150, "Профессионал", 13);
					SetTextColor(hdc, RGB(255, 0, 0));
					TextOutA(hdc, 50, 250, "Музыка: вкл/выкл", 17);
				}
			}
		}
		else if (d == 72) {
			if (cur2 > 1) {
				cur2--;
				if (cur2 == 4) {
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 50, "Новичок", 7);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 100, "Эксперт", 7);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 150, "Профессионал", 13);
					SetTextColor(hdc, RGB(255, 0, 0));
					TextOutA(hdc, 50, 250, "Музыка: вкл/выкл", 17);
				}
				if (cur2 == 3) {
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 50, "Новичок", 7);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 100, "Эксперт", 7);
					SetTextColor(hdc, RGB(255, 0, 0));
					TextOutA(hdc, 50, 150, "Профессионал", 13);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 250, "Музыка: вкл/выкл", 17);

				}
				else if (cur2 == 2) {
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 50, "Новичок", 7);
					SetTextColor(hdc, RGB(255, 0, 0));
					TextOutA(hdc, 50, 100, "Эксперт", 7);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 150, "Профессионал", 13);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 250, "Музыка: вкл/выкл", 17);
				}
				else if (cur2 == 1) {
					SetTextColor(hdc, RGB(255, 0, 0));
					TextOutA(hdc, 50, 50, "Новичок", 7);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 100, "Эксперт", 7);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 150, "Профессионал", 13);
					SetTextColor(hdc, RGB(100, 0, 0));
					TextOutA(hdc, 50, 250, "Музыка: вкл/выкл", 17);
				}
			}
		}
		else if (d == 13) {
			if (cur2 == 1) Set_level(4);
			else if (cur2 == 2) Set_level(3);
			else if (cur2 == 3) Set_level(6);
			else if (cur2 == 4) {
				mciSendString(_T("play MUSIC"), NULL, 0, 0);
				playMusik(0);
			}
		}
		else if (d == 27)menu();
	}

	///////////////////
	ReleaseDC(hwnd, hdc);

}

//---------------------------------------------------
int _tmain(int _targc, char* _targv[]) {
	setlocale(0, "");
	system("mode con cols=74 lines=49 ");
	system("color 00");
	SetConsoleTitleA("SUDOKU");

	////////////programms////////////////

	////////////////

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = 0;
	cci.dwSize = 100;
	SetConsoleCursorInfo(h, &cci);
	////////////////////////////////
	Sudoku a;
	a.Set_level();
	a.menu();

	////////////////////////
	ReleaseDC(hwnd, hdc);
}