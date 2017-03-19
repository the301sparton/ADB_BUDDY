/*
This file is supposed to contain all the fastboot
related code which is device specific in many conditions.
for example Yureka and Yureka plus use device tag prefix
"fastboot -i 0x1ebf " so a file containg device specific tags is made
to identify the correct device specific code.
you can contribute by adding more devices and their fastboot specific code
to the file.
*/


#include <iostream.h>
using namespace std;

//functions going in
void fgetcho(void);
void unlockflashing(void);
void flashsystem(void);
void flashboot(void);
void flashrecovery(void);
void flashmodem(void);
void lockflashing(void);
void sideload(void);
void fastboot_mode(void);

void flog(char str[])
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

fastboot_mode()
{
	system("adb reboot fastboot");
	flog("adb reboot fastboot");
	cout<<"DEVICE IN FASTBOOT MODE!\nHAVE CATUTION\N\N";
	fgetcho();
}

void fgetcho()
{
	char devicecho[15];
	int flag=0;
	cout<<"Enter Your Device CODE Name: ";
	cin>>devicecho;
	cout<<"Cheving For Support..\n";
	FILE fp*;
	fp=fopen("devices.dat","r");
	while(!feof(fp))
	{
	fscanf(fp,"%s\t%s\n",device,bstr);
			if(strcmp(device,devicecho)==0)
			{
			break;flag=1;
			}
	}
	if(flag!=1)
	{
		cout<<"Sorry Your Device Is Not Yet Supported";
	}
	else
	{
		int cho;
		cout<<"Unlock Bootloader? [1]\n";
		cout<<"Flash MODEM? [2]\n";
		cout<<"Flash SYSTEM? [3]\n";
		cout<<"Flash BOOT? [4]\n";
		cout<<"Flash RECOVERY? [5]\n";
		cout<<"LOCK FLASHING? [6]";
		cout<<"SIDELOAD? [7]";
		cin>>cho;
			if(cho==1)
			{
			unlockflashing();	
			}
			else if(cho==2)
			{
				flashmodem();
			}
			else if (cho==3)
			{
				flashsystem();
			}
			else if (cho==4)
			{
				flashboot();
			}
			else if(cho==5)
			{
				flashrecovery();
			}
			else if (cho==6)
			{
				lockflashing();
			}
			else if(cho==7)
			{
				sideload();
			}
	}
}

