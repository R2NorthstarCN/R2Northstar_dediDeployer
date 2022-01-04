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
//#include"ini.h"
/*#include"filepart.h"

#include"pid.h"*/

using namespace std; 

DWORD once(string name)
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
