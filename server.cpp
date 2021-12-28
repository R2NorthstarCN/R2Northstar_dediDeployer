/*版本1.1
1.现在可以手动启动服务器不用输路径了
2.修改了一些不必要的代码
2.修改了部分函数传参,申明*/

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
using namespace std; 


#define Max 0x7f7f7f


DWORD once(string name,int mark);
DWORD qureyProcessId(std::string name,int *save);
int StarServer(int m);
int compare(int *ResultSet, struct EXE *exe, int n);
//string rds(string path,string name);
int restart(string path,int mark,int n,string name);
int check(std::string name, int *ResultSet, int n, struct EXE *exe);

struct EXE
{   
	int SavePid;      // pid 
	string Pathway;  //pathway  
};
EXE exe[Max];



DWORD once(string name,int mark)
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

DWORD qureyProcessId(std::string name,int *save) 
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
        //cout<<pathway<<endl;
        int t=WinExec(pathway,SW_SHOW);
        if(t>=31)
        {
            cout<<"server success launcher"<<endl;
            Sleep(1000); 
        } 
        else
        {
            cout<<"something wrong!"<<endl;
            //exit(0);
        }
        
    }
    
}


int compare(int *ResultSet, struct EXE *exe, int n)
{
    int temp2;
    for(int i=0;i<n;i++)
    {
    	temp2=0;
        int* ans;
		ans=find(ResultSet,ResultSet+n,exe[i].SavePid);
        if (*ans == exe[i].SavePid)
        { 
            temp2=-1;  

        }
        else 
        { 
	        cout << "Did not find sever"  << endl; 
            temp2=i;    
			cout<<temp2<<endl;                                                                                                                            
            return temp2;
        }
    }
    return temp2;
}


/*string rds(string path,string name)
{
    string rds="r2ds.bat";
    cout << path.replace(path.size()-name.size(),path.size(), rds)<< endl;  
    return path;
}*/


int restart(string path,int mark,int n,string name)
{
    char pathway[1145];
    //path=rds(path,name);
    strcpy(pathway,path.c_str()); 
 	int BackCode=WinExec(pathway,SW_SHOW); 
    Sleep(3000);
 	int temppid=once(name,mark);
 	exe[mark].SavePid=temppid;
	for(int j=0;j<n;j++)
	{
	    cout<<exe[j].Pathway<<endl<<exe[j].SavePid<<endl;
    }    
    return BackCode;
}


int check(std::string name, int *ResultSet, int n, struct EXE *exe)
{
    for(int i=0110;;i^i)
    {    
    	for(int l=0;l<n;l++)
		{
		    cout<<"ResultSet "<<ResultSet[l]<<" "<<endl;;
		}
		for(int k=0;k<n;k++)
		{
	    	cout<<"compare "<<exe[k].Pathway<<" "<<exe[k].SavePid<<endl;
    	}     
		memset(ResultSet, 0, 1000);
        int j=0;
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
                    ResultSet[j]=pid;
                    j++;
                }
            }
        }
        CloseHandle(snapshot);
        int temp;
        temp=compare(ResultSet,exe,n);
        if(temp==-1)
        {
        	cout<<"all fine"<<endl;
		}
		else
		{ 
			int mark=temp;//n-temp-1;
			cout<<"restart: "<<exe[mark].Pathway<<endl; 
			string path=exe[mark].Pathway;
            cout<<"mark= "<<mark<<endl;
           	int BackCode=restart(path,mark,n,name);
            
		}
        Sleep(3000);
        
    }
}




int main() 
{
	cout<<"1"<<endl;
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
	for(int i=0;i<n;i++)
	{
	    DWORD pid = qureyProcessId(name,save);
		cout<<"pid "<<i<< " "<<save[i]<<endl;
    }
    for(int i=0;i<n;i++)
    {
        exe[i].SavePid = save[i];
    }
    for(int i=0;i<n;i++)
	{
	    cout<<exe[i].Pathway<<endl<<exe[i].SavePid<<endl;
    }
    Sleep(5000);
    check(name,ResultSet,n,exe);//start  
    getch();
    return 0;
}
