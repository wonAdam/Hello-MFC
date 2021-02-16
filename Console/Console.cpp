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

            //// 08. CRect 의 중심좌표 출력
            //CRect rect(120, 60, 120+150, 60+210); // left top right bottom
            //_tprintf("(%d, %d)", rect.CenterPoint().x, rect.CenterPoint().y);

            //// 09. 왼쪽상단 (120, 60) 오른쪽하단(270, 270) 인 CRect를 생성한 후 크기를 출력
            //CRect rect(120, 60, 270, 270);
            //_tprintf("size: %d * %d = %d", rect.Width(), rect.Height(), rect.Size());

            //// 10. CRect를 입력받고 해당 CRect를 47, 143만큼 이동시킨후 l, t, r, b출력
            //int l, t, r, b;
            //_tscanf_s(_T("%d %d %d %d"), &l, &t, &r, &b);
            //CRect rect(l, t, r, b);
            //rect.OffsetRect(47, 143);
            //_tprintf(_T("%d, %d, %d, %d"), rect.left, rect.top, rect.right, rect.bottom);

            //// 11. CRect와 CPoint를 각각 입력받고 CPoint가 CRect안에 있는지 출력
            //int l, t, r, b;
            //_tscanf_s(_T("%d %d %d %d"), &l, &t, &r, &b);
            //CRect rect(l, t, r, b);

            //int x, y;
            //_tscanf_s(_T("%d %d"), &x, &y);
            //CPoint point(x, y);

            //CString str;
            //if (rect.PtInRect(point)) str = _T("Inside");
            //else str = _T("Outside");
            //_tprintf("%s\n", str);

            //// 13. CTime으로 현재 시각을 받아 날짜 시 분 초 출력
            //CTime currTime = CTime::GetCurrentTime();
            //_tprintf(_T("%s\n"), currTime.Format("%Y-%m-%d %H:%M:%S"));

            //// 15. 오늘부터 1000일째 되는 기념일을 계산하여 날짜출력
            //CTime currTime = CTime::GetCurrentTime();
            //CTime oneThousandDayLater = currTime + 1000 * 24 * 60 * 60;
            //_tprintf(_T("%s\n"), oneThousandDayLater.Format("%Y-%m-%d %H:%M:%S"));

            //// 16. 두수를 입력받아 두 수 사이의 값들의 합과 평균을 CUIntArray를 이용하여 출력
            //int a, b;
            //_tscanf_s(_T("%d %d"), &a, &b);
            //CUIntArray arr;
            //int sum = 0;
            //for (int i = a; i <= b; i++)
            //{
            //    arr.Add(i);
            //    sum += i;
            //}
            //_tprintf(_T("sum: %d / mean: %f\n"), sum, sum/(float)arr.GetSize());

            // 20.
            //CMap<CString, CString&, UINT, UINT&> map;


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
