#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> 
#include <time.h>

using namespace std;
class device
{
	private:		
	public:
	void logit(char str[])
{
	FILE *fp;
	fp=fopen("log-ADB_BUDDY.log","a+");
	char buff[20];
	struct tm *sTm;
	time_t now=time(0);
	sTm = gmtime(&now);
	strftime(buff,sizeof(buff),"%Y-%m-%d %H:%M:%S",sTm);
	fprintf(fp,"%s -- %s\n",buff,str);
	fclose(fp);
	
}
    void devchk()
	{	
	cout<<"Cheaking Device Connected..\n";
	system("adb wait-for-device");
	cout<<"Device found!\n";
	system("adb devices");
	}	
	void backup()
	{
		char bcho,bloc[50], bstr[100]="adb backup ";
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
		logit(bstr);
	}
	void restore()
	{
		char rfile[100],rstr[115]="adb restore ";
		cout<<"Running Restore Module..\n\n";
		cout<<"Enter Path For Backup File: ";
		cin>>rfile;
		strcat(rstr,rfile);
		puts(rstr);
		getch();
		system(rstr);
		logit(rstr);
	}
	void rreboot()
	{
		char str[23]={"adb reboot recovery"};
		system(str);
		logit(str);
	}
	void breboot()
	{
		char str[23]={"adb reboot bootloader"};
		system(str);
		system("fastboot devices");
		system("fastboot flashing get_unlock_ability");
		logit(str);
	}
	void install()
	{
		char str[100]="adb install",cho,apkloc[100];
		cout<<"Do You Want To Install On SD-Card? [Y/N]";
		cin>>cho;
		if(cho=='Y'||cho=='y')
		{
			strcat(str," -s");
		}
		cout<<"Give All Runtime Permissions? [Y/N]";
		cin>>cho;
		if(cho=='Y'||cho=='y')
		{
			strcat(str," -g");
		}
		cout<<"Enter Location Of APK: ";
		cin>>apkloc;
		strcat(str,apkloc);
		system(str);
		logit(str);
	
	}
	
	void push()
	{
		char floc[100],rloc[200],str[300]={"adb push -p "};
		cout<<"Enter Location Of Local File";
		cin>>floc;
		strcat(str,floc);
		cout<<"Enter Remote Location";
		cin>>rloc;
		strcat(str, " ");
		strcat(str,rloc);
		system(str);
		logit(str);
	}
	
	void pull()
	{
		char floc[100],rloc[200],str[300]={"adb pull -p "};
		cout<<"Enter Location Of Remote File";
		cin>>floc;
		strcat(str,floc);
		cout<<"Enter Local Location";
		cin>>rloc;
		strcat(str, " ");
		strcat(str,rloc);
		system(str);
		logit(str);	
	}
	void shellcmd()
	{
		char get[220];
		cout<<"\t\tEnter 'DONE()' To End Shell Session\n";
		for(int a=1;strcmp(get,"DONE()")!=0;a++)
		{
			if(a==1)
			{
				cin.getline(get,220);
			}
			cout<<"#";
			cin.getline(get,220);
			char cmd[200]="adb shell ";
			strcat(cmd,get);
			system(cmd);
		}
	}
};
