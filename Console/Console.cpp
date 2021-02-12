// Console.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
            
            CMapStringToString map;
            map[_T("apple")] = _T("JUICE");
            map[_T("strawberry")] = _T("ICECREAM");
            map[_T("grape")] = _T("WINE");
            map[_T("milk")] = _T("TEA");


            POSITION pos = map.GetStartPosition();
            while (pos != NULL)
            {
                CString strKey, strValue;
                map.GetNextAssoc(pos, strKey, strValue);
                _tprintf(_T("%s -> %s\n"), strKey, strValue);
            }

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
