// Console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "framework.h"
#include "Console.h"

#include "locale.h"
#include <string>

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
            
            //// 04. IDS_FORMAT에 리소스로 %d, %s등의 문자열을 추가하고 _tprintf로 포맷팅해서 출력
            //CString str;
            //str.LoadString(IDS_FORMAT);
            //_tprintf(_T(str), _T("wondong"), 28);

            //// 05. _tscanf_s로 문자열 입력받은 후 CString으로 변경하여 메세지박스로 출력
            //TCHAR szBuf[1024];
            //_tscanf_s(_T("%s"), szBuf, _countof(szBuf));
            //CString str(szBuf);

            //MessageBox(NULL, str.MakeLower(), _T("Workout Question 05"), MB_OK); 

            //// 06. 문자열을 입력받고 어떤 문자열 A를 어떤 문자열 B로 대체하여 메세지박스로 출력
            //TCHAR szBuf[1024];
            //_tscanf_s("%s", szBuf, _countof(szBuf));
            //CString str(szBuf);
            //str.Replace(_T("a"), _T("b"));
            //MessageBox(NULL, str, _T("Workout Question 06"), MB_OK);

            //// 07. "1248+379"과 같은 덧셈수식을 문자열로 받고 "1248+379=1627"과 같이 연산결과를 메세지박스로 출력. 단, 입력으로 공백과 음수를 입력불가
            //TCHAR szBuf[1024];
            //_tscanf_s("%s", szBuf, _countof(szBuf));
            //CString str(szBuf);
            //int plusIdx = str.Find(_T("+"));
            //CString left = str.Left(plusIdx);
            //CString right = str.Right(str.GetLength() - plusIdx - 1);
            //int lefti = _tstoi(left);
            //int righti = _tstoi(right);
            //str.Insert(str.GetLength(), _T("="));
            //CString answer;
            //answer.Format("%d", lefti + righti);
            //str.Insert(str.GetLength(), answer);
            //MessageBox(NULL, str, _T("Workout Question 07"), MB_OK);

            // 08.


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
