#include <unistd.h>
#include <errno.h>
using namespace std;

int main()
{
	cout << "inmain\n";
	cout << "exec'ing fortune\n";
	execl ("/usr/local/bin/fortune"," ",(char *)NULL);
	cout << "exec must have failed\n";
	cout << "errno = " << errno << endl;
	// cout << "sys_errlist[errno]" << endl;
	return 0;
}
