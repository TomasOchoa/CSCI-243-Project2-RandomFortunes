/*************************************************************/
/*                                                           */
/*  CSCI 243 UNIX/VMS Operating Systems                      */
/*  Fall 2015 Program #2                                     */
/*  Author: Tomas Ochoa                                      */
/*  Date Due: 23 October 2015  								 */
/*	File Name: Curses2.cpp 									 */											
/*                                                           */
/*  This file contains code to implement a simple calculator */
/*  built using lex and yacc.                                */
/*                                                           */
/*************************************************************/

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <iostream>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

int main()
{
	int x, y;
 	pid_t id;
 	int status;


 	initscr();
 	srand(time(NULL));
 	
 	while(true)
	{
		clear();

  		x = 80.0*rand()/RAND_MAX;
  		y = 24.0*rand()/RAND_MAX;
 		move(y,x);

  		id = fork();
  		if(id>0)
		{
			sleep(1);
   			wait(&status);
  		}
		else if(id==0)
		{
			execl("/usr/local/bin/fortune","",(char*)NULL);
   			cout<<"exec must have failed errno="<<errno<<endl;
		}
		else if(id==-1)
		{
			cout<<"Couldnt fork erno="<<errno<<endl;
   			exit(-1);
  		}
 
		refresh();
  	}
	
 	endwin();
 	return 0;
}
