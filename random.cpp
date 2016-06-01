// Author:Tomas Ochoa
// Date:October 21 2015

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
	cout << "Max value is " << RAND_MAX << endl;

	time_t now;
	now = time(NULL);
	cout << "time = " << now << endl;

	for(int i = 0; i < 10; i++)
	{
		cout << "srand = " << time(NULL) << endl;
		sleep(1);
	} 

	return 0;
}
