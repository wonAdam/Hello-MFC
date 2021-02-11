﻿// Console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "framework.h"
#include "Console.h"

#include "locale.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // initialize MFC and print and error on failure
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: code your application's behavior here.
            wprintf(L"Fatal Error: MFC initialization failed\n");
            nRetCode = 1;
        }
        else
        {
            _tsetlocale(LC_ALL, ""); // 유니코드 한국어 출력에 필요
            
            CString szFruits[] = {
                _T("apple"), _T("grape"), _T("strawberry"), _T("plum"), _T("orange")
            };


            CStringList list;
            for (int i = 0; i < 5; i++)
                list.AddTail(szFruits[i]);

            POSITION pos = list.GetHeadPosition();
            while (pos != NULL)
            {
                CString str = list.GetNext(pos);
                _tprintf(_T("%s "), str);
            }

            _tprintf(_T("\n"));
            pos = list.GetTailPosition();
            while (pos != NULL)
            {
                CString str = list.GetPrev(pos);
                _tprintf(_T("%s "), str);
            }
            _tprintf(_T("\n"));

            getchar();
        }
    }
    else
    {
        // TODO: change error code to suit your needs
        wprintf(L"Fatal Error: GetModuleHandle failed\n");
        nRetCode = 1;
    }

    return nRetCode;
}
