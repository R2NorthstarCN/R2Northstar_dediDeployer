#include <iostream>
#include <bits/stdc++.h> 
#include <string>
#include <ctime>
#include <thread>
#include <Windows.h>
#include <processthreadsapi.h>
#include <tlhelp32.h>
#include<conio.h>
#include <io.h>   
#include"pid.h"
using namespace std; 

#define Max 0x7f7f7f
struct EXE
{   
	int SavePid;      // pid 
	string Pathway;  //pathway  
};
EXE exe[Max];

string lpAppName = "ExeNode";
string Number = "Number";
char lName[1145];
char InIPath[1000]="C:\\Users\\Public\\Documents\\TTFServer.ini";;
char Targetpath[1000];
char Exemaessage[1000];
char SavePid[1000];
char Numbermaessage[1145];
char ServerNumber[1145];

string lpAppName1(string Node,int n)
{
    char pid[100];
    itoa(n,pid,10);
    Node += pid;
    cout<<Node<<endl;
    return Node;
}

int IniWriter(struct EXE *exe, int n)
{
    for(int i = 0; i<n; i++)
    {
		string s = lpAppName1(lpAppName, i);
		strcpy(lName,s.c_str());
        WritePrivateProfileString(lName, "Path", strcpy(Exemaessage, exe[i].Pathway.c_str()), InIPath);
		Sleep(1000);
    }
}

int WriterServerNumberIni(int n)
{
    string SNumber ;
    //strcpy(lName,Number.c_str());
    SNumber=lpAppName1(SNumber , n);
    WritePrivateProfileString("Number", "ServerNumber", strcpy(Numbermaessage, SNumber.c_str()), InIPath);
}

int ReadServerNumberIni()
{
    GetPrivateProfileString("Number" ,"ServerNumber" ,"NULL" ,Exemaessage ,1000 ,InIPath);
    return atoi(Exemaessage);
}

int Iniread(string name, struct EXE *exe, int n)
{
    for(int i=0;i<n;i++)
    {
        string s = lpAppName1(lpAppName, i);
		strcpy(lName,s.c_str());
        GetPrivateProfileString(lName ,"Path" ,"NULL" ,Exemaessage ,100 ,InIPath);
        exe[i].Pathway+=Exemaessage;  
        cout<<exe[i].Pathway<<endl;
        ShellExecute(NULL,"open",Exemaessage,"","",SW_SHOW); 
        Sleep(1000);
        exe[i].SavePid = once(name);
        cout<<exe[i].SavePid<<endl;
        Exemaessage[1000]={'\0'};    
    }
}

int UseIni(struct EXE *exe)
{
    if(0 == access(InIPath, 0)) 
    {
        cout<<"ini exist."<<endl;
        cout<<"if u want use InI file press \"y\" or press else Manual input"<<endl;
        string cc;
        cin>>cc;
        if(cc.compare("y")==0)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }      
	else    
    {
        cout<<"file not exist."<<endl;
        cout<<"if u r first use server.exe you dont have inifile so you should Manual input once"<<endl;
        cout<<"press any button"<<endl;
        getch();
        system("cls");
        return -1;
    }                               

}
