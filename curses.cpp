// Program to play with curses...
// Author: Tomas Ochoa
// Date: 10/16/2015

#include <ncurses.h>

int main()
{
	initscr();
	printw("Go Away!");
	refresh();
	getch();
	endwin();
	
	return 0;
}