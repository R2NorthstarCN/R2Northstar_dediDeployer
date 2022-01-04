#include<bits/stdc++.h>
#include<stdio.h>  
#include<windows.h>  
#include<sql.h>  
#include<sqlext.h>  
#include<sqltypes.h>  
#include<string.h>
#include<conio.h>
#include<shlobj.h>
#include <windows.h>
#include <Commdlg.h>


//C:\Users\DELL\Desktop\?½Ú?????
#ifdef _WIN64 
typedef INT64 SQLLEN; 
typedef UINT64 SQLULEN; 
#else 
#define SQLLEN SQLINTEGER 
#define SQLULEN SQLUINTEGER 
#endif

using namespace std;

int Select(char *path)// choose file
{
	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn); 
    ofn.lpstrFile = path; 
    ofn.nMaxFile = MAX_PATH; 
    ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0"; 
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	return GetOpenFileName(&ofn);
}
int Select2(char *path)//choose compress feil save place 
{
	BROWSEINFO bi;   
	ZeroMemory(&bi,sizeof(BROWSEINFO));   
	bi.hwndOwner = NULL;   
	bi.pszDisplayName = path;   
	bi.lpszTitle = ("compress file will save at:");   
	bi.ulFlags = BIF_RETURNFSANCESTORS;   
	LPITEMIDLIST idl = SHBrowseForFolder(&bi);   
	SHGetPathFromIDList(idl,path); 
    if(NULL==idl)
    {
        return 0;
    }  
    else
    {
        return 1;
    }  
}
string fidd(int n)
{

	string path;
	char szFile[1000];
	memset(szFile, 0, 1000);
    if(n)
    {
        int temp=Select(szFile);
        //cout<<temp<<endl;
        if(temp==1)
        {
        	path+=szFile;
        	cout<<szFile<<endl;
            return path;
        }
        else 
        {
            cout<<"Something wrong "<<endl;
            getch();
            system("cls");
        }
    }
	/*if(n==2)
	{
		int temp2=Select2(szFile);
    	if(temp2==1)
    	{
			path=szFile;
        	return path;
    	}
    	else if(temp2==0)
    	{
        	cout<<"wrong press any button rechoose"<<endl;
			getch();
			fidd(2);
			system("cls");
    	}
	}*/
}  



