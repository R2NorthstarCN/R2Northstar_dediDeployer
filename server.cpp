/*版本1.3
Author:XGY4n
现在执行时可以添加服务器了
现在可以通过指令来执行某些操作了
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





DWORD once(string name, int mark);//Gets the pid at the top of the stack
DWORD qureyProcessId(string name, int *save);//Gets the pid for each target in the stack
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





struct EXE
{   
	int SavePid;      // pid 
	string Pathway;  //pathway  
};
EXE exe[Max];

void Help()
{
    cout<<"-----------help------------"<<endl;
    cout<<"press a to add server"<<endl;
    cout<<"else Improving "<<endl;
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
    else
    {
        cout<< "Instructions not define"<<endl;
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
    //int t=WinExec(pathway,SW_SHOW);
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

/*int InstructionsClose(string name , int n)
{

}*/






















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
        //int t=WinExec(pathway,SW_SHOW);
        HINSTANCE hNewExe = ShellExecute(NULL,"open",pathway,"","",SW_SHOWMINIMIZED); 
        if ((long long )hNewExe <= 32)
        {
            cout<<"start server failed return value: "<< (long long )hNewExe<<endl;
            //return -1;
        }
        else
        {
            cout<<"start server successed!"<<endl;
            //return 1;
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
            temp2=-1;  
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
    //path=rds(path,name);
    strcpy(pathway,path.c_str()); 
 	HINSTANCE hNewExe = ShellExecute(NULL,"open",pathway,"","",SW_SHOWMINIMIZED); //WinExec(pathway,SW_SHOW); 
    Sleep(3000);
 	int temppid = once(name, mark);
 	exe[mark].SavePid=temppid;
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
        else if(time(0)-timeBegin>=5)
        {
            timeBegin = time(0);
            return a;
        }
    }
}


string check(string name, int *ResultSet, int n, struct EXE *exe)
{
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
            //cout<<"s : "<<Instructions<<endl;
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
        //Sleep(3000);
        system("cls");
    }
}




int main() 
{
	//cout<<"1"<<endl;
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
        //cout<<"break "<< comd<<endl;
        int state = ExecInstructions(name, comd, n);
        if(state>=0)
        {
            cout<<"successed"<<endl;
            Sleep(2000);
        }
        else
        {
            cout<<"failed"<<endl;
            break;
        }
        n++;
    }
    getch();
    return 0;
}
