// Program to play with fork
// Author: Tomas Ochoa
// Date: 10/14/15

#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main()
{	
	pid_t id;
	int status;

	id = 1;
	cout << "Running your program\n";
	cout << "Looping...\n";
	while(id != 0)
	{
		cout << "Forking...\n";
		id = fork();
		cout << "id = " << id << endl;
		if(id > 0)
		{
			cout << "I am the parent!\n";
			wait(&status);
		}
		else if(id == 0)
		{
			cout << "I am the child!\n";
			cout << "Exiting..." << id << endl;
		}
		else if(id == -1)
		{
			cerr << "couldn't fork...errno = " << errno << endl;
			exit(-1);
		}
	}

	return 0;
}