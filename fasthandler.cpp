/*
This file is supposed to contain all the fastboot
related code which is device specific in many conditions.
for example Yureka and Yureka plus use device tag prefix
"0x1ebf " so a file containg device specific tags is made
to identify the correct device specific code.
you can contribute by adding more devices and their fastboot specific code
to the file.
*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> 
#include <time.h>
using namespace std;

//functions going in
/*void fgetcho(void);
void unlockflashing(void);
void flashsystem(void);
void flashboot(void);
void flashrecovery(void);
void flashmodem(void);
void lockflashing(void);
void sideload(void);
void fastboot_mode(void);
*/

class fastboot_device
{
private: 
char bstr[250];
public:
fastboot_device()   {
    strcpy(bstr,"fastboot -i ");
}
    
void flog(char str[])   {
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
    
void fastboot_mode()    {
    char str[25];
    strcpy(str,"adb reboot bootloader");
	system(str);
    flog(str);
	cout<<"DEVICE IN FASTBOOT MODE!\nHAVE CATUTION\n\n";
	fgetcho();
}

void unlockflashing()  {
	/*
		Fuction unlocks bootloader 
		that means flashing for all non-bootloader
		partisions is valid.
	*/
    char bstrcp[250];
	char str[180]=" oem unlock";
    strcpy(bstrcp,bstr);
    strcat(bstrcp,str);
	system(bstrcp);
    flog(bstrcp);
}

void flashsystem()  {
    char str[180];
    char bstrcp[250];
    strcpy(bstrcp,bstr);
    cout<<"Enter location to System.img file: ";
    cin>>str;
    strcat(bstrcp," flash system ");
    strcat(bstrcp,str);
    system(bstrcp);
    flog(bstrcp);
}

void flashboot()    {
    char str[180];
    char bstrcp[250];
    strcpy(bstrcp,bstr);
    cout<<"Enter location to boot.img file: ";
    cin>>str;
    strcat(bstrcp," flash boot ");
    strcat(bstrcp,str);
    system(bstrcp);
    flog(bstrcp);
}

void flashrecovery()    {
    char str[180];
    char bstrcp[250];
    strcpy(bstrcp,bstr);
    cout<<"Enter location to recovery.img file: ";
    cin>>str;
    strcat(bstrcp,"flash recovery ");
    strcat(bstrcp,str);
    system(bstrcp);
    flog(bstrcp);
}

void flashmodem()   {
    char str[180];
    char bstrcp[250];
    strcpy(bstrcp,bstr);
    cout<<"Enter location to modem.bin file: ";
    cin>>str;
    strcat(bstrcp,"flash modem ");
    strcat(bstrcp,str);
    system(bstrcp);
    flog(bstrcp);
}

void lockflashing() {
    char bstrcp[250];
	char str[180]=" flashing lock";
    strcpy(bstrcp,bstr);
    strcat(bstrcp,str);
	system(bstrcp);
    flog(bstrcp);
}

void sideload()   {
    char str[180];
    char bstrcp[250];
    strcpy(bstrcp,bstr);
    cout<<"Enter location of file to sideload: ";
    cin>>str;
    strcat(bstrcp," sideload ");
    strcat(bstrcp,str);
    system(bstrcp);
    flog(bstrcp);
}

void format()   {
    int choice;
    char bstrcp[250];
    strcpy(bstrcp,bstr);
    cout<<"Select partition you want to format\n ";
    cout<<"system[1]\nuserdata[2]\ncache[3]\nrecovery[4]\n";
    cout<<"choice: ";
    cin>>choice;
    strcat(bstrcp," format ");
    if(choice==1)   {
        strcat(bstrcp,"system");
    }
    if(choice==2)   {
        strcat(bstrcp,"userdata");
    }
    if(choice==3)   {
        strcat(bstrcp,"cache");
    }
    if(choice==4)   {
        strcat(bstrcp,"recovery");
    }
    system(bstrcp);
    flog(bstrcp);  
}

void fgetcho()  {
	char getstr[10];
	char devicecho[15];
	char device[15];
    int flag=0;
	cout<<"Enter Your Device CODE Name: ";
	cin>>devicecho;
	cout<<"Cheving For Support..\n";
	FILE *fp1;
	fp1=fopen("devices.dat","r");
	while(!feof(fp1))
	{
	fscanf(fp1,"%s\t%s\n",device,getstr);
			if(strcmp(device,devicecho)==0)
			{
            flag=1;
			break;
			}
	}
	if(flag!=1)
	{
		cout<<"Sorry Your Device Is Not Yet Supported\n\n";
        system("pause");
	}
	else
	{
        do
        {
		int cho;
        strcat(bstr,getstr);
		cout<<"Unlock Bootloader? [1]\n";
		cout<<"Flash MODEM? [2]\n";
		cout<<"Flash SYSTEM? [3]\n";
		cout<<"Flash BOOT? [4]\n";
		cout<<"Flash RECOVERY? [5]\n";
		cout<<"LOCK FLASHING? [6]\n";
        cout<<"Format a partition[7]";
		cout<<"SIDELOAD? [8]\n";
        cout<<"$";
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
				format();
			}
            else if(cho==8)
			{
				sideload();
			}
            else
            {
                break;
            }
	}while(1);
    }
}

};
