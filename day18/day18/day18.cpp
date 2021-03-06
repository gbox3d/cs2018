// day18.cpp: 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "day18.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_DAY18, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 응용 프로그램 초기화를 수행합니다.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DAY18));

    MSG msg;

	plusEngine::GDIPLUS_Loop(msg, Rect(0, 0, 320, 240));

   
    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  목적: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DAY18));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_DAY18);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   목적: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   설명:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   MoveWindow(hWnd,0, 0, 320+32, 240+64,TRUE);

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}


namespace exam1 {
	void OnGdiPlusSetup();
	void OnGdiPlusApply(double fDelta);
	void OnGdiPlusRender(double fDelta, Graphics *pGrp);
	void OnGdiPlusFinish();
}

namespace exam2 {
	void OnGdiPlusSetup();
	void OnGdiPlusApply(double fDelta);
	void OnGdiPlusRender(double fDelta, Graphics *pGrp);
	void OnGdiPlusFinish();
}


namespace exam3 {
	void OnGdiPlusSetup();
	void OnGdiPlusApply(double fDelta);
	void OnGdiPlusRender(double fDelta, Graphics *pGrp);
	void OnGdiPlusFinish();
}
namespace exam4 {
	void OnGdiPlusSetup();
	void OnGdiPlusApply(double fDelta);
	void OnGdiPlusRender(double fDelta, Graphics *pGrp);
	void OnGdiPlusFinish();
}
namespace exam5 {
	void OnGdiPlusSetup();
	void OnGdiPlusApply(double fDelta);
	void OnGdiPlusRender(double fDelta, Graphics *pGrp);
	void OnGdiPlusFinish();
	void OnKeyDown(WORD keycode);
}

namespace exam6 {
	void OnGdiPlusSetup();
	void OnGdiPlusApply(double fDelta);
	void OnGdiPlusRender(double fDelta, Graphics *pGrp);
	void OnGdiPlusFinish();
	void OnKeyDown(WORD keycode);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_KEYDOWN:
		exam5::OnKeyDown(wParam);
		exam6::OnKeyDown(wParam);
		break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다.
            switch (wmId)
            {
			case ID_EXAM_EX1:
				OutputDebugString(L"start exam1...\n");
				plusEngine::fpOnRender = exam1::OnGdiPlusRender;
				break;
			case ID_EXAM_EX2:
				OutputDebugString(L"start exam2...\n");
				plusEngine::fpOnRender = exam2::OnGdiPlusRender;
				break;
			case ID_EXAM_EX3:
				OutputDebugString(L"start exam3...\n");
				plusEngine::fpOnRender = exam3::OnGdiPlusRender;
				break;
			case ID_EXAM_EX4:
				OutputDebugString(L"start exam4...\n");
				plusEngine::fpOnRender = exam4::OnGdiPlusRender;
				plusEngine::fpOnLoop = exam4::OnGdiPlusApply;
				break;
			case ID_EXAM_EX5:
				OutputDebugString(L"start exam4...\n");
				exam5::OnGdiPlusSetup();
				plusEngine::fpOnRender = exam5::OnGdiPlusRender;
				plusEngine::fpOnLoop = exam5::OnGdiPlusApply;
				break;
			case ID_EXAM_EX6:
				OutputDebugString(L"start exam6...\n");
				plusEngine::fpOnRender = exam6::OnGdiPlusRender;
				plusEngine::fpOnLoop = exam6::OnGdiPlusApply;
				break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다.
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
		exam5::OnGdiPlusFinish();
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
