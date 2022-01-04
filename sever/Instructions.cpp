#include <iostream>
#include <bits/stdc++.h> 
#include <string>
#include <ctime>
#include <thread>
#include <Windows.h>
#include <processthreadsapi.h>
#include <tlhelp32.h>
#include<conio.h>
#include <shellapi.h>

using namespace std;


int InstructionsAdd(string name, int n);
int InstructionsClose(string name, int n);
int InstructionsRestart(string name, int n);
int InstructionsWriteIni(struct EXE *exe, int Number);
string GetInstructions();

int InstructionsAdd(string name , int n)
{
    int ExeMark = n;
    char pathway[1145];
    exe[ExeMark].Pathway+=fidd(1);
    cout<<exe[ExeMark].Pathway<<endl;
    strcpy(pathway,exe[ExeMark].Pathway.c_str()); 
    HINSTANCE hNewExe = ShellExecute(NULL,"open",pathway,"","",SW_SHOWMINIMIZED); 
    if ((long long )hNewExe <= 32)
    {
        cout<<"start server failed return value: "<< (long long )hNewExe<<endl;
        
        return -1;
    }
    else
    {
        cout<<"start server successed!"<<endl;
        exe[ExeMark].SavePid = once(name);//,ExeMark
        return 1;
    }
    Sleep(1000);
}



int InstructionsClose(string name , int n)
{
    string p;
    cout<<"sure?[y/n]"<<endl;
    p = GetInstructions();
    if(p.compare("y")==0)
    {
        string close = string("TASKKILL /F /IM ") + name;
        cout<<close<<endl;
        int sta=system(close.c_str());
        if(sta!=-1)
        {
            exit(0);
            return 0;
        }
        else 
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }

}


int InstructionsRestart(string name , int n)
{
    string p;
    cout<<"sure?[y/n]"<<endl;
    //cin>>p;
    p = GetInstructions();
    if(p.compare("y")==0)
    {
        string close = string("TASKKILL /F /IM ") + name;
        cout<<close<<endl;
        int sta=system(close.c_str());
        if(sta!=-1)
        { 
            return 2;
        }
        else 
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }

}

int InstructionsWriteIni(struct EXE *exe, int Number)
{
    WriterServerNumberIni(Number);
    IniWriter(exe, Number);
}

string GetInstructions() 
{
    string a;
    time_t timeBegin = time(0);
    while(0|1)  //the main loop  
    {           
        if(_kbhit())//detect the keyboard 
        {       
            a+=_getch();
            return a;
        }
        else if(time(0)-timeBegin>=4)
        {
            timeBegin = time(0);
            return a;
        }
    }
}
