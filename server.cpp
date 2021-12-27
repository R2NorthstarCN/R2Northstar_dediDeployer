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
struct EXE
{   
	int SavePid;        //  id 
	string Pathway;  //pathway  
};
EXE exe[0x7f7f7f];
DWORD once(string name,int mark)
{
   DWORD pid;
    //DWORD save[1000];
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
                //std::cout << "pid = " << pid << std::endl;
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
    //DWORD save[1000];
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
                //std::cout << "pid = " << pid << std::endl;
               //CloseHandle(hProcess);
            }
        }
    }
    CloseHandle(snapshot);
    return pid;
}
int FileChoose(int m)
{
    /*for(int i=0;i<m;i++)
    {       
        exe[i].Pathway=fidd(1);//fidd 
    }*/
    cout<<"exe path way"<<endl; 
    /*for(int i=0;i<m;i++)
    {       
        //cin>>
        exe[i].Pathway=fidd(1);
    }*/
        exe[0].Pathway="E:\\PS1\\Titanfall2-unpacked.exe";
        
        exe[1].Pathway="E:\\PS2\\Titanfall2-unpacked.exe";
        
        exe[2].Pathway="E:\\PS3\\Titanfall2-unpacked.exe";
        
        exe[3].Pathway="E:\\PS4\\Titanfall2-unpacked.exe";
}
int compare(int *ResultSet, struct EXE *exe, int n)
{
    int temp2;
    for(int i=0;i<n;i++)
    {
	    /*for(int j=0;j<n;j++)
		{
		    cout<<ResultSet[j]<<endl;
		}	*/
    	temp2=0;
        int* ans;
		ans=find(ResultSet,ResultSet+n,exe[i].SavePid);
        if (*ans == exe[i].SavePid)
        { 
            temp2=-1;
            //cout<<exe[i].SavePid<<" "<<ans<<endl;
            //continue;
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
string rds(string path,string name)
{
    string rds="r2ds.bat";
    cout << path.replace(path.size()-name.size(),path.size(), rds)<< endl;  
    return path;
}
void restart(string path,int mark,int n,string name)
{
    char pathway[1145];
    path=rds(path,name);
    strcpy(pathway,path.c_str()); 
 	WinExec(pathway,SW_SHOW); 
    Sleep(3000);
 	int temppid=once(name,mark);
 	exe[mark].SavePid=temppid;
	for(int j=0;j<n;j++)
	{
	    cout<<exe[j].Pathway<<endl<<exe[j].SavePid<<endl;
    }    
    return ;
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
                    //std::cout << "pid = " << pid << std::endl;
                    //CloseHandle(hProcess);
                }
            }
        }
        CloseHandle(snapshot);
        int temp;
        temp=compare(ResultSet,exe,n);
        //cout<<temp<<endl;
        if(temp==-1)
        {
        	cout<<"all fine"<<endl;
		}
		else
		{ 
			int mark=temp;//n-temp-1;
			cout<<"restart: "<<exe[mark].Pathway<<endl; 
			string path=exe[mark].Pathway;
            cout<<"makrk= "<<mark<<endl;
           	restart(path,mark,n,name);
		}
        Sleep(3000);
        
    }
}

int main() 
{
    int n;
    std::cout << "Number of sever" << std::endl;
    cin>>n;
    string name; 
    cout<<"exe's name"<<endl;
    cin>>name; 
    FileChoose(n);
    int save[1000];//save pid
    int ResultSet[1000];
    memset(save, 0, 1024);
	for(int i=0;i<n;i++)
	{
	    DWORD pid = qureyProcessId(name,save);
		std::cout << "pid "<<i<<" "<< save[i] << std::endl;
    }
    for(int i=0;i<n;i++)
    {
        exe[i].SavePid = save[i];
    }
    for(int i=0;i<n;i++)
	{
	    cout<<exe[i].Pathway<<endl<<exe[i].SavePid<<endl;
    }
    check(name,ResultSet,n,exe);//start  
    getch();
    return 0;
}