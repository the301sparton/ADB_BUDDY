#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <C:\Users\Jenkin\Documents\GitHub\ADB_BUDDY\ADB_BUDDY-master\fasthandler.cpp>
#include <C:\Users\Jenkin\Documents\GitHub\ADB_BUDDY\ADB_BUDDY-master\ADB1.3.cpp>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void getcho()
	{
		device plus;
		int cho;
		cout<<"Press 1 For Backup\n";
		cout<<"Press 2 For Restore\n";
		cout<<"Press 3 To Reboot In Recovery\n";
		cout<<"Press 4 To Start Fastboot Mode\n";
		cout<<"Press 5 To Install A Package\n";
		cout<<"Press 6 To Push Files\n";
		cout<<"Press 7 To Pull Files\n";
		cout<<"Press 8 To Start Shell Session\n\n";
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
		else if(cho==3)
		{
			plus.rreboot();
		}
		else if(cho==4)
		{
            		fastboot_device plus;
			plus.fastboot_mode();   //fastboot mode
		}
		else if(cho==5)
		{
			plus.install();
		}
		else if(cho==6)
		{
			plus.push();
		}
		else if(cho==7)
		{
			plus.pull();
		}
		else if(cho==8)
		{
			plus.shellcmd();
		}
		else
		{
			exit(1);
		}
	}
int main(int argc, char** argv)
{
	device test;
	while(1)
	{
	system("cls");
	test.devchk();
	getcho();	
	}
	return 0;
}
 
