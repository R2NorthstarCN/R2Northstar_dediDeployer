/*版本1.4
Author:XGY4n
1.2 现在可以手动启动服务器不用输路径了
1.2 修改了一些不必要的代码
1.2 修改了部分函数传参,申明
1.2 修改了sleep的时间保证了不同性能的电脑进程扫入的准确性

1.3 现在执行时可以添加服务器了
1.3 现在可以通过指令来执行某些操作了

1.4 完成了关闭所有服务器的指令
1.4 完成了重启所有服务器的指令
1.4 稍微整洁了一下代码
*/

#include <iostream>
#include <bits/stdc++.h> 
#include <string>
#include <ctime>
#include <thread>
#include <Windows.h>
#include <processthreadsapi.h>
#include"filepart.h"
#include <tlhelp32.h>
#include<conio.h>
#include <shellapi.h>
using namespace std; 


#define Max 0x7f7f7f





DWORD once(string name, int mark); //Gets the pid at the top of the stack
DWORD qureyProcessId(string name, int *save); //Gets the pid for each target in the stack
int StarServer(int m);
int compare(int *ResultSet, struct EXE *exe, int n);
 //Look for the pid mapped by the structure in the current stack, if you can't find the subscript corresponding to the returned structure
string GetInstructions();
int restart(string path, int mark, int n, string name);
string check(string name, int *ResultSet, int n, struct EXE *exe);//Start the listening process


//Instructions part
void Help();
int ExecInstructions(string name, string Instructions, int n);
int InstructionsAdd(string name, int n);
int InstructionsClose(string name, int n);
int InstructionsRestart(string name, int n);



struct EXE
{   
	int SavePid;      // pid 
	string Pathway;  //pathway  
};
EXE exe[Max];

void Help()
{
    cout<<"-----------help------------"<<endl;
    cout<<"press \"a\" to add server"<<endl;
    cout<<"press \"f\" to close all server"<<endl;
    cout<<"press \"r\" to restart all server"<<endl;
    cout<<"else improving "<<endl;
    cout<<"---------------------------"<<endl;
    return ;
}



int ExecInstructions(string name,  string Instructions, int n)
{
    if(Instructions.compare("a")==0)//-add
    {
        int temp = InstructionsAdd(name, n);
        return temp ;
    }
    else if(Instructions.compare("f")==0)
    {
        int temp = InstructionsClose(name, n);
        return temp ;
    }
    else if(Instructions.compare("r")==0)
    {
        int temp = InstructionsRestart(name, n);
        return temp ;
    }
    else
    {
        cout<< "Instructions not define"<<endl;
        Sleep(1000);
        return -1;
    }
    
}



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
        exe[ExeMark].SavePid = once(name,ExeMark);
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









DWORD once(string name, int mark)
{
    DWORD pid;
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    if (Process32First(snapshot, &entry) == TRUE)
    {
        while (Process32Next(snapshot, &entry) == TRUE)
        {  
            if (std::string(entry.szExeFile) == name) 
            {
                HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);
                pid = GetProcessId(hProcess);
                CloseHandle(hProcess);
            }
        }
    }
    CloseHandle(snapshot);
    return pid;	
}

DWORD qureyProcessId(string name, int *save) 
{
    DWORD pid;
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);
    int i=0;
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    if (Process32First(snapshot, &entry) == TRUE)
    {
        while (Process32Next(snapshot, &entry) == TRUE)
        {
            if (std::string(entry.szExeFile) == name) 
            {
                HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);
                pid = GetProcessId(hProcess);
                save[i]=pid;
                i++;
            }
        }
    }
    CloseHandle(snapshot);
    return pid;
}


int StarServer(int m)
{
    for(int i=0;i<m;i++)
    {       
        char pathway[1145];
        exe[i].Pathway+=fidd(1);
        cout<<exe[i].Pathway<<endl;
        strcpy(pathway,exe[i].Pathway.c_str()); 
        HINSTANCE hNewExe = ShellExecute(NULL,"open",pathway,"","",SW_SHOWMINIMIZED); 
        if ((long long )hNewExe <= 32)
        {
            cout<<"start server failed return value: "<< (long long )hNewExe<<endl;
        }
        else
        {
            cout<<"start server successed!"<<endl;
        }
        Sleep(1000);
    }
    
}


int compare(int *ResultSet, struct EXE *exe, int n)
{
    int temp2;
    for(int i=0;i<n;i++)
    {
    	temp2 = 0;
        int* ans;
		ans=find(ResultSet, ResultSet+n, exe[i].SavePid);
        if (*ans == exe[i].SavePid)
        { 
            temp2 = -1;  
        }
        else 
        { 
	        cout << "Did not find sever"  << endl; 
            temp2 = i;    
			cout<<temp2<<endl;                                                                                                                            
            return temp2;
        }
    }
    return temp2;
}



int restart(string path, int mark, int n, string name)
{
    char pathway[1145];
    strcpy(pathway, path.c_str()); 
 	HINSTANCE hNewExe = ShellExecute(NULL, "open", pathway, "", "", SW_SHOWMINIMIZED); //WinExec(pathway,SW_SHOW); 
    Sleep(3000);
 	int temppid = once(name, mark);
 	exe[mark].SavePid = temppid;
	for(int j=0;j<n;j++)
	{
	    cout<<exe[j].Pathway<<endl<<exe[j].SavePid<<endl;
    }    
    return (long long )hNewExe;
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


string check(string name, int *ResultSet, int n, struct EXE *exe)
{
    system("cls");
    for(int i=0110;;i^i)
    {  
        cout<<"This is not a simple script!!!!!! Please dont call it script I will be sad (T_T)"<<endl;  
    	for(int l=0;l<n;l++)
		{
		    cout<<"ResultSet "<<ResultSet[l]<<" "<<endl;;
		}
		for(int k=0;k<n;k++)
		{
	    	cout<<"compare "<<exe[k].Pathway<<" "<<exe[k].SavePid<<endl;
    	}     
		memset(ResultSet, 0, 1000);
        int j = 0;
        DWORD pid;
        PROCESSENTRY32 entry;
        entry.dwSize = sizeof(PROCESSENTRY32);
        HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
        if (Process32First(snapshot, &entry) == TRUE)
        {
            while (Process32Next(snapshot, &entry) == TRUE)
            {
                if (std::string(entry.szExeFile) == name) 
                {
                    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);
                    pid = GetProcessId(hProcess);
                    ResultSet[j] = pid;
                    j++;
                }
            }
        }
        CloseHandle(snapshot);
        int temp;
        temp = compare(ResultSet,exe,n);
        if(temp == -1)
        {
        	cout<<"all fine"<<endl;
            cout<<"now server number : "<<n<<"/10"<<endl;
            Help();
            string Instructions;
            Instructions += GetInstructions();
            if(!Instructions.empty())
            {
                return Instructions;
            }
		}
		else
		{ 
			int mark = temp;//n-temp-1;
			cout<<"restart: "<<exe[mark].Pathway<<endl; 
			string path=exe[mark].Pathway;
            cout<<"mark= "<<mark<<endl;
           	int BackCode=restart(path, mark, n, name);
		}
        system("cls");
    }
}




int main() 
{
    cout<<"This is not a simple script!!!!!! Please dont call it script I will be sad (T_T)"<<endl;
    cout<< "target :"<< endl;
    string name="Titanfall2-unpacked.exe";  // sort Titanfall2-unpacked
    cout<<name<<endl;
    int n;
    cout<< "Number of sever" <<endl;
    cin>>n;
    StarServer(n);
    int save[1000];//save pid
    int ResultSet[1000];
    memset(save, 0, 1000);
	for(int i=0; i<n; i++)
	{
	    DWORD pid = qureyProcessId(name, save);
		cout<<"pid "<<i<< " "<<save[i]<<endl;
    }
    for(int i=0; i<n; i++)
    {
        exe[i].SavePid = save[i];
    }
    for(int i=0; i<n; i++)
	{
	    cout<<exe[i].Pathway<<endl<<exe[i].SavePid<<endl;
    }
    Sleep(3000);
    while(0|1)
    {
        string comd;
        comd = check(name, ResultSet, n, exe);//start  
        int state = ExecInstructions(name, comd, n);
        if(state==1)
        {
            cout<<"successed join"<<endl;
            Sleep(1000);
            n++;
        }
        else if(state==2)
        {
            cout<<"successed restart all"<<endl;
            Sleep(1000);
        }
        else
        {
            cout<<"failed"<<endl;
            Sleep(1000);
        }
        system("cls");
    }
    getch();
    return 0;
}
