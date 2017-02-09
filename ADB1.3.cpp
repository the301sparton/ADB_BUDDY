#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
using namespace std;
class device
{
	private:
		char bcho,bloc[50], bstr[100]="adb backup ",rfile[100],rstr[115]="adb restore ";
	public:
    void devchk()
	{
	cout<<"Cheaking Device Connected..\n";
	system("adb wait-for-device");
	cout<<"Device found!\n";
	system("adb devices");
	}	
	void backup()
	{
		system("cls");
		cout<<"Running Backup Module..\n\n";
		cout<<"Enter location Of Backup File\n\n";
		cin>>bloc;
		strcat(bstr,bloc);
		cout<<"Do You Want .apks [y/n] ? ";
		cin>>bcho;
		if(bcho=='y'||bcho=='Y')
		{
			strcat(bstr,"-apk ");
		}
		cout<<"Do You Want .obb Files? [y/n] ? ";
		cin>>bcho;
			if(bcho=='y'||bcho=='Y')
		{
			strcat(bstr,"-obb ");
		}
		strcat(bstr,"-all ");
		cout<<"Do You Want System apps[y/n] ? ";
		cin>>bcho;
			if(bcho=='n'||bcho=='N')
		{
			strcat(bstr,"-nosystem ");
		}
		puts(bstr);
		system(bstr);
	}
	void restore()
	{
		cout<<"Running Restore Module..\n\n";
		cout<<"Enter Path For Backup File: ";
		cin>>rfile;
		strcat(rstr,rfile);
		puts(rstr);
		getch();
		system(rstr);
	}
	
};
