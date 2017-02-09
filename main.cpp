#include <iostream>
#include <stdlib.h>
#include <"ADB1.3.cpp">
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void getcho()
	{
		device plus;
		int cho;
		cout<<"Press 1 For Backup\n";
		cout<<"Press 2 For Restore\n";
		cout<<"Choice: ";
		cin>>cho;
		if(cho==1)
		{
			plus.backup();
		}
		else if(cho==2)
		{
			plus.restore();
		}
		else
		{
			exit(1);
		}
	}
int main(int argc, char** argv)
{
	device test;
	test.devchk();
	getcho();
	return 0;
}
