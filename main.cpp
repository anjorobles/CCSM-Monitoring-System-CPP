#include <windows.h>    //include header files
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

#define FILE_MENU_ABOUT 99
#define FILE_MENU_EXIT 98
#define EDIT_BGCOLORTXT 97
#define BUTTON_LOGIN 96
#define TXTCOLOR_OPBUS 80
#define TXTCOLOR_OPBUS2 81
#define TXTCOLOR_QRTN2 82
#define TXTCOLOR_OPBUS3 83
#define TXTCOLOR_QRTN 79
#define BUTTON_ACCESS 78
#define BUTTON_PROCEED 77
#define BUTTON_GOBACK 76
#define CAPACITY_COLOR 74
#define QTYPE_COLOR 75
#define BUS_FCOLOR 73
#define PCT_COLOR 72
#define ID_RADIOBTN1 71
#define ID_RADIOBTN2 70
#define ID_RADIOBTN3 69
#define LOG_OUT 42
#define RES_INFO 1
#define ACC_REP 2
#define DIST_I 10
#define DIST_II 11
#define DIST_III 12
#define DIST_IV 13
#define DIST_V 14
#define DIST_VI 15
#define G_MALE 16
#define G_FEMALE 17

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);   //function prototypes
void AddControls(HWND);
void AddMenus(HWND);
void loadImages();
void registerWindowProcedureResInfo(HINSTANCE);
void registerWindowProcedureResInfo2(HINSTANCE);
void registerWindowProcedureAccRep(HINSTANCE);
void registerWindowProcedureAccRep2(HINSTANCE);
void registerWindowProcedureAccRepD(HINSTANCE);
void registerWindowProcedureAccRepW(HINSTANCE);
void registerWindowProcedureAccRepM(HINSTANCE);
void displayWindowProcedureResInfo(HWND);
void displayWindowProcedureResInfo2(HWND);
void displayWindowProcedureAccRep(HWND);
void displayWindowProcedureAccRep2(HWND);
void displayWindowProcedureAccRepD(HWND);
void displayWindowProcedureAccRepW(HWND);
void displayWindowProcedureAccRepM(HWND);
void AddWinProcResInfo(HWND);
void AddWinProcResInfo2(HWND);
void AddWinProcAccRep(HWND);
void AddWinProcAccRep2(HWND);
void AddWinProcAccRepD(HWND);
void AddWinProcAccRepW(HWND);
void AddWinProcAccRepM(HWND);
void open_fileD(HWND);
void open_fileW(HWND);
void open_fileM(HWND);

HMENU hMenu;
HWND hLogo, hResInfo, hSFontEnter, hPassword, hLoginWindow, hSecWindow, hResInfoWindow, hResInfoWindow2, hAccRepWindow, hAccRepWindow2, hAccRepWindowD, hAccRepWindowW, hAccRepWindowM, hPassInfoWindow, hADataBaseWindow, hADataBaseWWindow, hADataBaseMWindow,
		hSelectOpBus, hCheckBG, hTypeQ, hPercentage, hGstore, hDstore, hDstore2, hBarangay, hBarangayEdit, hGender, hMale, hFemale, hDistrict, hDistrictEdit, hGenderEdit, hAccEdit, hwhichAccess,
		hPassInfo, hName,hAge, hAddress, hContact, hNameEdit, hAgeEdit, hAddressEdit, hContactEdit, hAccEditBg, hSemiV, hD1, hD2, hD3, hD4, hD5, hD6,
		hBody, hAccess_Report, hExit, hResInfoTitle, hBack, hProceed, hDaily, hMonthly, hWeekly;

//Handler for Gboxes
HWND hGBox1, hGBox2, hGBox3, hGBox4, hGBox5, hGBox6, hGBox7, hGBox8, hGBox9, hGBox10, hGBox11,
    hGBox12, hGBox13, hGBox14, hGBox15, hGBox16, hGBox17, hGBox18, hGBox19, hGBox20, hGBox21, hGBox22, hGBox23, hSeatNo;

HWND hNameStat, hAddressStat, hContactStat, hAgeStat, hBarangayStat, hPickUpStat, hDropOffP, hDropOffStat;

HBITMAP bLogo, bResiInfo, bLogin, bCheckBG, bAccess, bProceed, bGoBack, bGCQBus, bExit, bResInfoTitle, bAccessInfoRec, bDaily, bWeekly, bMonthly;
HBRUSH hbrBkgnd;
HFONT hFontTypeQ = CreateFont (18, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
		      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

UINT t;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow){     //creating the parent window


    WNDCLASSW wc = {0};         //creating the window class
	HBRUSH hb = ::CreateSolidBrush(RGB(249, 235, 217));

    wc.hbrBackground = hb; //background color

    wc.hCursor = LoadCursor (NULL, IDC_ARROW);  //window cursor
    wc.hInstance = hInst;
    wc.lpszClassName = L"myWindowClass";        //defining class name
    wc.lpfnWndProc = WindowProcedure;           //calling window procedure

    if(!RegisterClassW(&wc))
        return -1;

    registerWindowProcedureResInfo(hInst);
    registerWindowProcedureResInfo2(hInst);
    registerWindowProcedureAccRep(hInst);
    registerWindowProcedureAccRep2(hInst);
    registerWindowProcedureAccRepD(hInst);
    registerWindowProcedureAccRepW(hInst);
    registerWindowProcedureAccRepM(hInst);



    hLoginWindow = CreateWindowW(L"myWindowClass", L"CCMSM", WS_SYSMENU | WS_VISIBLE | ES_LEFT | WS_MINIMIZEBOX,
                  500, 100, 340, 380, NULL, NULL, NULL, NULL);   //parent window

    MSG msg = {0};

    while(GetMessage(&msg, NULL, NULL, NULL)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){

	int mbVal;
	char pass[100];
	switch(msg){
        case WM_COMMAND:
            switch(wp){

			case FILE_MENU_ABOUT:              //about menu
                MessageBoxW(hWnd, L"CCMSM \n\nby Robles, John Joe Rimuel P.", L"About Digital Budget Planner", MB_OK | MB_ICONINFORMATION);
                break;
                case FILE_MENU_EXIT:               //program exit menu
                    mbVal = MessageBoxW(hWnd, L"Exit Program?", L"Exit", MB_YESNO | MB_ICONEXCLAMATION);
                    if (mbVal == IDYES)             //built in IDs for Message Boxes
                        DestroyWindow(hWnd);
                    else if (mbVal == IDNO)
                        break;
            case RES_INFO:
                displayWindowProcedureResInfo(hWnd);
                ShowWindow(hLoginWindow, SW_HIDE);
                break;
            case ACC_REP:
                displayWindowProcedureAccRep(hWnd);
                ShowWindow(hLoginWindow, SW_HIDE);
                break;
			}
		break;

		case WM_CTLCOLOREDIT:{

		    HDC hdc = (HDC)wp;
		    SetBkColor(hdc, RGB(255,254,254));
		    if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(208, 219, 232));
            }
            return (INT_PTR)hbrBkgnd;
		}break;

		case WM_CTLCOLORSTATIC:{

            HDC hdcStatic = (HDC) wp;
            SetTextColor(hdcStatic, RGB(0, 0, 0));
            hbrBkgnd = CreateSolidBrush(RGB(249, 235, 217));
            SetBkMode(hdcStatic,TRANSPARENT);


            if (hbrBkgnd == NULL){
            	hbrBkgnd = CreateSolidBrush(RGB(255, 254, 254));
            }

            return (INT_PTR)hbrBkgnd;
        }break;


		case WM_CREATE:        //executed once the window is created
	        loadImages();
	        AddMenus(hWnd);
	        AddControls(hWnd);
	        break;
		case WM_DESTROY:       //exiting session
	        PostQuitMessage(0);
	        break;
	    default:
	    	return DefWindowProcW(hWnd, msg, wp, lp);
	}
}

void AddMenus(HWND hWnd){       //add menu function that accepts the window handler as the parameter

    hMenu = CreateMenu();       //creating menus using HMENU

    AppendMenu(hMenu, MF_STRING, FILE_MENU_ABOUT, "About");     //menus
    SetMenu(hWnd, hMenu);
}

void AddControls(HWND hWnd){
	hLogo = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                  55, 10, 180, 160, hWnd, NULL, NULL, NULL);
    SendMessage(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bLogo);

    hResInfo = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
                  60, 135, 210, 35, hWnd, (HMENU)RES_INFO, NULL, NULL);
    SendMessage(hResInfo, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bResiInfo);

    HFONT hFontInside = CreateFont (17, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    hAccess_Report = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
                  60, 180, 210, 35, hWnd, (HMENU)ACC_REP, NULL, NULL);
    SendMessage(hAccess_Report, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bAccess);

    hExit = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
                  100, 240, 120, 25, hWnd, (HMENU)FILE_MENU_EXIT, NULL, NULL);
    SendMessage(hExit, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bExit);

}

void loadImages(){
	bLogo = (HBITMAP)LoadImageW(NULL, L"B-Logo.bmp", IMAGE_BITMAP, 0,0, LR_LOADFROMFILE);
	bResiInfo = (HBITMAP)LoadImageW(NULL, L"B-Resident_Info.bmp", IMAGE_BITMAP, 210, 35, LR_LOADFROMFILE);
	bAccess = (HBITMAP)LoadImageW(NULL, L"B-Access.bmp", IMAGE_BITMAP, 210, 35, LR_LOADFROMFILE);
	bProceed = (HBITMAP)LoadImageW(NULL, L"B-Proceed.bmp", IMAGE_BITMAP, 80, 30, LR_LOADFROMFILE);
	bGoBack = (HBITMAP)LoadImageW(NULL, L"B-Back.bmp", IMAGE_BITMAP, 80, 25, LR_LOADFROMFILE);
	bExit = (HBITMAP)LoadImageW(NULL, L"B-Exit.bmp", IMAGE_BITMAP, 120, 25, LR_LOADFROMFILE);
	bResInfoTitle = (HBITMAP)LoadImageW(NULL, L"B-Resident_Info_2.bmp", IMAGE_BITMAP, 200, 30, LR_LOADFROMFILE);
	bAccessInfoRec = (HBITMAP)LoadImageW(NULL, L"B-Access_Info.bmp", IMAGE_BITMAP, 230, 40, LR_LOADFROMFILE);
	bDaily = (HBITMAP)LoadImageW(NULL, L"B-Daily_Records.bmp", IMAGE_BITMAP, 200, 30, LR_LOADFROMFILE);
	bWeekly = (HBITMAP)LoadImageW(NULL, L"B-Weekly_Records.bmp", IMAGE_BITMAP, 230, 40, LR_LOADFROMFILE);
	bMonthly = (HBITMAP)LoadImageW(NULL, L"B-Monthly_Records.bmp", IMAGE_BITMAP, 230, 40, LR_LOADFROMFILE);

}
//--------------------------------------------------------------- RESIDENT INFO WIN PROC --------------------------------------------------
LRESULT CALLBACK WindowProcedureResInfo(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp ){

	int mbVal;
	bool checked = false;
	static int flag = 0, qFlag = 0;
	char name[100], age[100], address[100], barangay[100], contact[100], gender[100], district[100];

	switch(msg){
		//rescan:
		case WM_COMMAND:
		    if (LOWORD(wp) == DIST_I){
				checked = IsDlgButtonChecked(hWnd, DIST_I);
	            if (!checked) {
	                CheckDlgButton(hWnd, DIST_I, BST_CHECKED);
	                //SetWindowText(hD1, "Operational");
	                EnableWindow(hD1, TRUE);
	                SetWindowText(hDstore, "DISTRICT I");
	                EnableWindow(hD2, FALSE);
	                EnableWindow(hD3, FALSE);
	                EnableWindow(hD4, FALSE);
	                EnableWindow(hD5, FALSE);
	                EnableWindow(hD6, FALSE);
	                flag = 1;
	            } else {
	            	CheckDlgButton(hWnd, DIST_I, BST_UNCHECKED);
	            	//SetWindowText(hD1, "District I");
                    EnableWindow(hD2, TRUE);
	                EnableWindow(hD3, TRUE);
	                EnableWindow(hD4, TRUE);
	                EnableWindow(hD5, TRUE);
	                EnableWindow(hD6, TRUE);
	            	flag = 0;
	            }
			}

            //2
            if (LOWORD(wp) == DIST_II){
				checked = IsDlgButtonChecked(hWnd, DIST_II);
	            if (!checked) {
	                CheckDlgButton(hWnd, DIST_II, BST_CHECKED);
	                EnableWindow(hD1, FALSE);
	                EnableWindow(hD2, TRUE);
	                SetWindowText(hDstore, "DISTRICT II");
	                EnableWindow(hD3, FALSE);
	                EnableWindow(hD4, FALSE);
	                EnableWindow(hD5, FALSE);
	                EnableWindow(hD6, FALSE);
	                flag = 1;
	            } else {
	               CheckDlgButton(hWnd, DIST_II, BST_UNCHECKED);
	               //SetWindowText(hD2, "District II");
	                EnableWindow(hD1, TRUE);
	                EnableWindow(hD3, TRUE);
	                EnableWindow(hD4, TRUE);
	                EnableWindow(hD5, TRUE);
	                EnableWindow(hD6, TRUE);
	               flag = 0;
	            }
			}

            //3
            if (LOWORD(wp) == DIST_III){
				checked = IsDlgButtonChecked(hWnd, DIST_III);
	            if (!checked) {
	                CheckDlgButton(hWnd, DIST_III, BST_CHECKED);
	                SetWindowText(hDstore, "DISTRICT III");
	                EnableWindow(hD1, FALSE);
	                EnableWindow(hD2, FALSE);
	                EnableWindow(hD3, TRUE);
	                EnableWindow(hD4, FALSE);
	                EnableWindow(hD5, FALSE);
	                EnableWindow(hD6, FALSE);
	                flag = 1;
	            } else {
	               CheckDlgButton(hWnd, DIST_III, BST_UNCHECKED);
	               //SetWindowText(hD3, "District III");
                    EnableWindow(hD1, TRUE);
	                EnableWindow(hD2, TRUE);
	                EnableWindow(hD4, TRUE);
	                EnableWindow(hD5, TRUE);
	                EnableWindow(hD6, TRUE);
	               flag = 0;
	            }
			}
            //4
            if (LOWORD(wp) == DIST_IV){
				checked = IsDlgButtonChecked(hWnd, DIST_IV);
	            if (!checked) {
	                CheckDlgButton(hWnd, DIST_IV, BST_CHECKED);
	                SetWindowText(hDstore, "DISTRICT IV");
	                EnableWindow(hD1, FALSE);
	                EnableWindow(hD2, FALSE);
	                EnableWindow(hD3, FALSE);
	                EnableWindow(hD4, TRUE);
	                EnableWindow(hD5, FALSE);
	                EnableWindow(hD6, FALSE);
	                flag = 1;
	            } else {
	               CheckDlgButton(hWnd, DIST_IV, BST_UNCHECKED);
	               //SetWindowText(hD4, "District IV");
	               EnableWindow(hD1, TRUE);
	                EnableWindow(hD2, TRUE);
	                EnableWindow(hD3, TRUE);
	                EnableWindow(hD5, TRUE);
	                EnableWindow(hD6, TRUE);
	               flag = 0;
	            }
			}
			//5
            if (LOWORD(wp) == DIST_V){
				checked = IsDlgButtonChecked(hWnd, DIST_V);
	            if (!checked) {
	                CheckDlgButton(hWnd, DIST_V, BST_CHECKED);
	                SetWindowText(hDstore, "DISTRICT V");
	                EnableWindow(hD1, FALSE);
	                EnableWindow(hD2, FALSE);
	                EnableWindow(hD3, FALSE);
	                EnableWindow(hD4, FALSE);
	                EnableWindow(hD5, TRUE);
	                EnableWindow(hD6, FALSE);
	                flag = 1;
	            } else {
	               CheckDlgButton(hWnd, DIST_V, BST_UNCHECKED);
	               //SetWindowText(hD5, "District V");
	                EnableWindow(hD1, TRUE);
	                EnableWindow(hD2, TRUE);
	                EnableWindow(hD3, TRUE);
	                EnableWindow(hD4, TRUE);
	                EnableWindow(hD6, TRUE);
	               flag = 0;
	            }
			}
            //6
            if (LOWORD(wp) == DIST_VI){
				checked = IsDlgButtonChecked(hWnd, DIST_VI);
	            if (!checked) {
	                CheckDlgButton(hWnd, DIST_VI, BST_CHECKED);
	                SetWindowText(hDstore, "DISTRICT VI");
	                EnableWindow(hD1, FALSE);
	                EnableWindow(hD2, FALSE);
	                EnableWindow(hD3, FALSE);
	                EnableWindow(hD4, FALSE);
	                EnableWindow(hD5, FALSE);
	                EnableWindow(hD6, TRUE);
	                flag = 1;
	            } else {
	               CheckDlgButton(hWnd, DIST_VI, BST_UNCHECKED);
	               //SetWindowText(hD6, "District VI");
                    EnableWindow(hD1, TRUE);
	                EnableWindow(hD2, TRUE);
	                EnableWindow(hD3, TRUE);
	                EnableWindow(hD4, TRUE);
	                EnableWindow(hD5, TRUE);
	               flag = 0;
	            }
			}
			if (LOWORD(wp) == G_MALE){
				SetWindowText(hGstore, "MALE");
				qFlag = 1;
			}

			if (LOWORD(wp) == G_FEMALE){
				SetWindowText(hGstore, "FEMALE");
				qFlag = 1;
			}




            switch(wp){
            	case FILE_MENU_ABOUT:              //about menu
				 MessageBoxW(hWnd, L"CCMSM \n\nby Robles, John Joe Rimuel P.", L"About Digital Budget Planner", MB_OK | MB_ICONINFORMATION);                break;
                case FILE_MENU_EXIT:               //program exit menu
                    mbVal = MessageBoxW(hWnd, L"Exit Program?", L"Exit", MB_YESNO | MB_ICONEXCLAMATION);
                    if (mbVal == IDYES)             //built in IDs for Message Boxes
                        DestroyWindow(hWnd);
                    else if (mbVal == IDNO)
                        break;
				case BUTTON_PROCEED:
                        GetWindowText(hNameEdit, name, 100);
                        GetWindowText(hAgeEdit, age, 100);
                        GetWindowText(hAddressEdit, address, 100);
                        GetWindowText(hBarangayEdit, barangay, 100);
                        GetWindowText(hContactEdit, contact, 100);
                        GetWindowText(hGstore, gender, 100);
                        GetWindowText(hDstore, district, 100);

                        if (strcmp(name, "") == 0 || strcmp(address, "") == 0 || strcmp(contact, "") == 0 || strcmp(age, "") == 0 || strcmp(barangay, "") == 0 ||flag != 1){
						MessageBoxW(hWnd, L"Please fill up all fields!", L"Input Error", MB_OK | MB_ICONEXCLAMATION);
						return 0;
                        }
                        else {
                            ShowWindow(hResInfoWindow, SW_HIDE);
                        }

                        GetWindowText(hGstore, gender, 100);
                        GetWindowText(hDstore, district, 100);
                        if (strcmp(gender, "MALE") == 0){
                            displayWindowProcedureResInfo2(hWnd);
                        }
                        else if (strcmp(gender, "FEMALE") == 0){
                            displayWindowProcedureResInfo2(hWnd);
                        }
                        else if (strcmp(district, "DISTRICT I") == 0){
                            displayWindowProcedureResInfo2(hWnd);

                        }
                        else if (strcmp(district, "DISTRICT II") == 0){
                            displayWindowProcedureResInfo2(hWnd);

                        }
                        else if (strcmp(district, "DISTRICT III") == 0){
                            displayWindowProcedureResInfo2(hWnd);
                        }
                        else if (strcmp(district, "DISTRICT IV") == 0){
                            displayWindowProcedureResInfo2(hWnd);

                        }
                        else if (strcmp(district, "DISTRICT V") == 0){
                            displayWindowProcedureResInfo2(hWnd);

                        }
                        else if (strcmp(district, "DISTRICT VI") == 0){
                            displayWindowProcedureResInfo2(hWnd);

                        }
                        break;
                case BUTTON_GOBACK:
                        ShowWindow(hLoginWindow, SW_SHOW);
                        ShowWindow(hResInfoWindow, SW_HIDE);
                        break;
            }

        case WM_CTLCOLOREDIT:{

		    HDC hdc = (HDC)wp;
		    SetBkColor(hdc, RGB(232, 232, 232));
		    hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
		    if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
            }
            return (INT_PTR)hbrBkgnd;
		}break;

		case WM_CTLCOLORSTATIC:{

            HDC hdcStatic = (HDC) wp;
            SetTextColor(hdcStatic, RGB(0, 0, 0));
            hbrBkgnd = CreateSolidBrush(RGB(249, 235, 217));
            SetBkMode(hdcStatic,TRANSPARENT);

            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS) == (HWND)lp || GetDlgItem(hWnd, TXTCOLOR_QRTN) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(0, 0, 0));
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
			}

			if (GetDlgItem(hWnd, TXTCOLOR_OPBUS2) == (HWND)lp || GetDlgItem(hWnd, TXTCOLOR_QRTN2) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(0, 0, 0));
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
			}

            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS3) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(0, 0, 0));
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
			}

            if (hbrBkgnd == NULL){
            	hbrBkgnd = CreateSolidBrush(RGB(255, 254, 254));
            }

            return (INT_PTR)hbrBkgnd;

        }break;
		case WM_CLOSE:
	        EnableWindow(hLoginWindow, TRUE);
	        DestroyWindow(hWnd);
	        break;
	    case WM_CREATE:{

	        AddMenus(hWnd);
	        loadImages();
            AddWinProcResInfo(hWnd);
	        } break;
	    default:
	        return DefWindowProcW(hWnd, msg, wp, lp);
	}
}

void registerWindowProcedureResInfo(HINSTANCE hInst){


	WNDCLASSW dialogResInfo = {0};

    HBRUSH hb = ::CreateSolidBrush(RGB(249, 235, 217));

    dialogResInfo.hbrBackground = hb;
    dialogResInfo.hCursor = LoadCursor (NULL, IDC_CROSS);
    dialogResInfo.hInstance = hInst;
    dialogResInfo.lpszClassName = L"WindProcResInfo";
    dialogResInfo.lpfnWndProc = WindowProcedureResInfo;

    RegisterClassW(&dialogResInfo);

}

void displayWindowProcedureResInfo(HWND hWnd){

    hResInfoWindow = CreateWindowW(L"WindProcResInfo", L"CCMSM", WS_VISIBLE | WS_MINIMIZEBOX | WS_SYSMENU,
                  500, 100, 400, 450, hWnd, NULL, NULL, NULL);

    EnableWindow(hWnd, TRUE);
}

void AddWinProcResInfo(HWND hWnd){

    HFONT hFontInside = CreateFont (17, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
    OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
    DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontInsideEdit = CreateFont (17, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
    OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
    DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    hLogo = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                  90, 10, 180, 160, hWnd, NULL, NULL, NULL);
    SendMessage(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bLogo);
    hResInfoTitle = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                  100, 105, 260, 180, hWnd, NULL, NULL, NULL);
    SendMessage(hResInfoTitle, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bResInfoTitle);

    hName = CreateWindowW(L"Static", L"NAME: ", WS_VISIBLE | WS_CHILD,
                  75, 140, 50, 17, hWnd, NULL, NULL, NULL);
    SendMessage(hName, WM_SETFONT, (LPARAM)hFontInside, FALSE);

    hNameEdit = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD|ES_AUTOVSCROLL,
                  130, 140, 170, 17, hWnd, (HMENU)TXTCOLOR_OPBUS, NULL, NULL);
    SendMessage(hNameEdit, WM_SETFONT, (LPARAM)hFontInsideEdit, FALSE);

    hAge = CreateWindowW(L"Static", L"AGE: ", WS_VISIBLE | WS_CHILD|SS_RIGHT,
                  78, 165, 50, 17, hWnd, NULL, NULL, NULL);
    SendMessage(hAge, WM_SETFONT, (LPARAM)hFontInside, FALSE);

    hAgeEdit = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD|ES_AUTOVSCROLL,
                  130, 165, 170, 17, hWnd, (HMENU)TXTCOLOR_QRTN, NULL, NULL);
    SendMessage(hAgeEdit, WM_SETFONT, (LPARAM)hFontInsideEdit, FALSE);


    hAddress = CreateWindowW(L"Static", L"ADDRESS: ", WS_VISIBLE | WS_CHILD|SS_RIGHT,
                  28, 190, 100, 17, hWnd, NULL, NULL, NULL);
    SendMessage(hAddress, WM_SETFONT, (LPARAM)hFontInside, FALSE);

    hAddressEdit = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD|ES_AUTOVSCROLL,
                  130, 190, 170, 17, hWnd, (HMENU)TXTCOLOR_OPBUS2, NULL, NULL);
    SendMessage(hAddressEdit, WM_SETFONT, (LPARAM)hFontInsideEdit, FALSE);

    hBarangay = CreateWindowW(L"Static", L"BARANGAY: ", WS_VISIBLE | WS_CHILD|SS_RIGHT,
                  28, 215, 100, 17, hWnd, NULL, NULL, NULL);
    SendMessage(hBarangay, WM_SETFONT, (LPARAM)hFontInside, FALSE);

    hBarangayEdit = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD|ES_AUTOVSCROLL,
                  130, 215, 170, 17, hWnd, (HMENU)TXTCOLOR_QRTN2, NULL, NULL);
    SendMessage(hBarangayEdit, WM_SETFONT, (LPARAM)hFontInsideEdit, FALSE);

    hContact = CreateWindowW(L"Static", L"CONTACT NO.: ", WS_VISIBLE | WS_CHILD|SS_RIGHT,
                  5, 240, 120, 17, hWnd, NULL, NULL, NULL);
    SendMessage(hContact, WM_SETFONT, (LPARAM)hFontInside, FALSE);

    hContactEdit = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD|ES_AUTOVSCROLL,
                  130, 240, 170, 17, hWnd, (HMENU)TXTCOLOR_OPBUS3, NULL, NULL);
    SendMessage(hContactEdit, WM_SETFONT, (LPARAM)hFontInsideEdit, FALSE);

    hGender = CreateWindowW(L"Static", L"GENDER", WS_VISIBLE | WS_CHILD|SS_CENTER,
                  45, 265, 70, 17, hWnd, NULL, NULL, NULL);
    SendMessage(hGender, WM_SETFONT, (LPARAM)hFontInside, FALSE);

    hMale = CreateWindowW(L"button", L"Male", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                20, 285, 50, 17, hWnd,(HMENU)G_MALE, NULL, NULL);

    hFemale = CreateWindowW(L"button", L"Female", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                80, 285, 70, 17, hWnd,(HMENU)G_FEMALE, NULL, NULL);
    hGstore = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER,
                80, 500, 70, 17, hWnd,(HMENU)hFontInside, NULL, NULL);

    hDistrict = CreateWindowW(L"Static", L"DISTRICT", WS_VISIBLE | WS_CHILD|SS_CENTER,
                  240, 265, 75, 17, hWnd, NULL, NULL, NULL);
    SendMessage(hDistrict, WM_SETFONT, (LPARAM)hFontInside, FALSE);

    hD1 = CreateWindowW(L"button", L"District I", WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                190, 285, 80, 17, hWnd,(HMENU)DIST_I, NULL, NULL);
    CheckDlgButton(hWnd, 1, BST_UNCHECKED);

    hD2 = CreateWindowW(L"button", L"District II", WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                190, 305, 80, 17, hWnd,(HMENU)DIST_II, NULL, NULL);
    CheckDlgButton(hWnd, 2, BST_UNCHECKED);

    hD3 = CreateWindowW(L"button", L"District III", WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                190, 325, 80, 17, hWnd,(HMENU)DIST_III, NULL, NULL);
    CheckDlgButton(hWnd, 3, BST_UNCHECKED);

    hD4 = CreateWindowW(L"button", L"District IV", WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                280, 285, 82, 17, hWnd,(HMENU)DIST_IV, NULL, NULL);
    CheckDlgButton(hWnd, 4, BST_UNCHECKED);

    hD5 = CreateWindowW(L"button", L"District V", WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                280, 305, 82, 17, hWnd,(HMENU)DIST_V, NULL, NULL);
    CheckDlgButton(hWnd, 5, BST_UNCHECKED);

    hD6 = CreateWindowW(L"button", L"District VI", WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                280, 325, 82, 17, hWnd,(HMENU)DIST_VI, NULL, NULL);
    CheckDlgButton(hWnd, 6, BST_UNCHECKED);

    hDstore = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER,
                280, 500, 100, 17, hWnd,(HMENU)hFontInside, NULL, NULL);

    hBack = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
                  40, 360, 80, 25, hWnd, (HMENU)BUTTON_GOBACK, NULL, NULL);
    SendMessage(hBack, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bGoBack);

    hProceed = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
                  270, 358, 80, 25, hWnd, (HMENU)BUTTON_PROCEED, NULL, NULL);
    SendMessage(hProceed, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bProceed);


}

//--------------------------------------------------------------- RESIDENT INFO2 WIN PROC --------------------------------------------------
LRESULT CALLBACK WindowProcedureResInfo2(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp ){

	int mbVal;
	bool checked = false;
	char district_no[100];
	char nameD[100], ageD[100], addressD[100], barangayD[100], contactD[100], genderD[100], districtD[100];


	switch(msg){
		//rescan:
		case WM_COMMAND:

            switch(wp){
            	case FILE_MENU_ABOUT:              //about menu
 				MessageBoxW(hWnd, L"CCMSM \n\nby Robles, John Joe Rimuel P.", L"About Digital Budget Planner", MB_OK | MB_ICONINFORMATION);                break;
                case FILE_MENU_EXIT:               //program exit menu
                    mbVal = MessageBoxW(hWnd, L"Exit Program?", L"Exit", MB_YESNO | MB_ICONEXCLAMATION);
                    if (mbVal == IDYES)             //built in IDs for Message Boxes
                        DestroyWindow(hWnd);
                    else if (mbVal == IDNO)
                        break;
				case BUTTON_PROCEED:
                        GetWindowText(hDistrictEdit, district_no, 100 );
                        if (strcmp(district_no, "DISTRICT I") == 0){
                            ofstream fileD;
                            fileD.open("District I.txt", std::ios_base::app);
                            GetWindowText(hNameEdit, nameD, 100);
                            GetWindowText(hAgeEdit, ageD, 100);
                            GetWindowText(hAddressEdit, addressD, 100);
                            GetWindowText(hBarangayEdit, barangayD, 100);
                            GetWindowText(hContactEdit, contactD, 100);
                            GetWindowText(hGenderEdit, genderD, 100);
                            GetWindowText(hDistrictEdit, districtD, 100);
                            fileD << "   " << nameD << "\t" << ageD << "\t" << addressD << "\t\t" << barangayD << "\t "
                                << contactD << "\t   " << districtD << "\t"<< genderD << "  " << "\n";
                            fileD.close();
                            MessageBox(hWnd, "Information Saved.", "CCMSM", MB_OK|MB_ICONEXCLAMATION);

                        }
                        if (strcmp(district_no, "DISTRICT II") == 0){
                            ofstream fileD;
                            fileD.open("District II.txt", std::ios_base::app);
                            GetWindowText(hNameEdit, nameD, 100);
                            GetWindowText(hAgeEdit, ageD, 100);
                            GetWindowText(hAddressEdit, addressD, 100);
                            GetWindowText(hBarangayEdit, barangayD, 100);
                            GetWindowText(hContactEdit, contactD, 100);
                            GetWindowText(hGenderEdit, genderD, 100);
                            GetWindowText(hDistrictEdit, districtD, 100);
                            fileD << "   " << nameD << "\t" << ageD << "\t" << addressD << "\t\t" << barangayD << "\t "
                                << contactD << "\t   " << districtD << "\t"<< genderD << "  " << "\n";
                            fileD.close();
                            MessageBox(hWnd, "Information Saved.", "CCMSM", MB_OK|MB_ICONEXCLAMATION);

                        }
                        if (strcmp(district_no, "DISTRICT III") == 0){
                            ofstream fileD;
                            fileD.open("District III.txt", std::ios_base::app);
                            GetWindowText(hNameEdit, nameD, 100);
                            GetWindowText(hAgeEdit, ageD, 100);
                            GetWindowText(hAddressEdit, addressD, 100);
                            GetWindowText(hBarangayEdit, barangayD, 100);
                            GetWindowText(hContactEdit, contactD, 100);
                            GetWindowText(hGenderEdit, genderD, 100);
                            GetWindowText(hDistrictEdit, districtD, 100);
                            fileD << "   " << nameD << "\t" << ageD << "\t" << addressD << "\t\t" << barangayD << "\t "
                                << contactD << "\t   " << districtD << "\t"<< genderD << "  " << "\n";
                            fileD.close();
                            MessageBox(hWnd, "Information Saved.", "CCMSM", MB_OK|MB_ICONEXCLAMATION);

                        }
                        if (strcmp(district_no, "DISTRICT IV") == 0){
                            ofstream fileD;
                            fileD.open("District IV.txt", std::ios_base::app);
                            GetWindowText(hNameEdit, nameD, 100);
                            GetWindowText(hAgeEdit, ageD, 100);
                            GetWindowText(hAddressEdit, addressD, 100);
                            GetWindowText(hBarangayEdit, barangayD, 100);
                            GetWindowText(hContactEdit, contactD, 100);
                            GetWindowText(hGenderEdit, genderD, 100);
                            GetWindowText(hDistrictEdit, districtD, 100);
                            fileD << "   " << nameD << "\t" << ageD << "\t" << addressD << "\t\t" << barangayD << "\t "
                                << contactD << "\t   " << districtD << "\t"<< genderD << "  " << "\n";
                            fileD.close();
                            MessageBox(hWnd, "Information Saved.", "CCMSM", MB_OK|MB_ICONEXCLAMATION);

                        }
                        if (strcmp(district_no, "DISTRICT V") == 0){
                            ofstream fileD;
                            fileD.open("District V.txt", std::ios_base::app);
                            GetWindowText(hNameEdit, nameD, 100);
                            GetWindowText(hAgeEdit, ageD, 100);
                            GetWindowText(hAddressEdit, addressD, 100);
                            GetWindowText(hBarangayEdit, barangayD, 100);
                            GetWindowText(hContactEdit, contactD, 100);
                            GetWindowText(hGenderEdit, genderD, 100);
                            GetWindowText(hDistrictEdit, districtD, 100);
                            fileD << "   " << nameD << "\t" << ageD << "\t" << addressD << "\t\t" << barangayD << "\t "
                                << contactD << "\t   " << districtD << "\t"<< genderD << "  " << "\n";
                            fileD.close();

                            MessageBox(hWnd, "Information Saved.", "CCMSM", MB_OK|MB_ICONEXCLAMATION);

                        }
                        if (strcmp(district_no, "DISTRICT VI") == 0){
                            ofstream fileD;
                            fileD.open("District VI.txt", std::ios_base::app);
                            GetWindowText(hNameEdit, nameD, 100);
                            GetWindowText(hAgeEdit, ageD, 100);
                            GetWindowText(hAddressEdit, addressD, 100);
                            GetWindowText(hBarangayEdit, barangayD, 100);
                            GetWindowText(hContactEdit, contactD, 100);
                            GetWindowText(hGenderEdit, genderD, 100);
                            GetWindowText(hDistrictEdit, districtD, 100);
                            fileD << "   " << nameD << "\t" << ageD << "\t" << addressD << "\t\t" << barangayD << "\t "
                                << contactD << "\t   " << districtD << "\t"<< genderD << "  " << "\n";
                            fileD.close();
                            MessageBox(hWnd, "Information Saved.", "CCMSM", MB_OK|MB_ICONEXCLAMATION);

                        }
                        ShowWindow(hLoginWindow,SW_SHOW);
                        ShowWindow(hResInfoWindow2, SW_HIDE);
                        break;
                case BUTTON_GOBACK:
                        ShowWindow(hResInfoWindow, SW_SHOW);
                        ShowWindow(hResInfoWindow2, SW_HIDE);
                        break;
            }

        case WM_CTLCOLOREDIT:{

		    HDC hdc = (HDC)wp;
		    SetBkColor(hdc, RGB(249, 235, 217));
		    hbrBkgnd = CreateSolidBrush(RGB(249, 235, 217));
		    if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(249, 235, 217));
            }
            return (INT_PTR)hbrBkgnd;
		}break;

		case WM_CTLCOLORSTATIC:{

            HDC hdcStatic = (HDC) wp;
            SetTextColor(hdcStatic, RGB(0, 0, 0));
            hbrBkgnd = CreateSolidBrush(RGB(249, 235, 217));
            SetBkMode(hdcStatic,TRANSPARENT);

            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS) == (HWND)lp || GetDlgItem(hWnd, TXTCOLOR_QRTN) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(0, 0, 0));
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
			}

			if (GetDlgItem(hWnd, TXTCOLOR_OPBUS2) == (HWND)lp || GetDlgItem(hWnd, TXTCOLOR_QRTN2) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(0, 0, 0));
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
			}

            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS3) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(0, 0, 0));
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
			}

            if (hbrBkgnd == NULL){
            	hbrBkgnd = CreateSolidBrush(RGB(255, 254, 254));
            }

            return (INT_PTR)hbrBkgnd;

        }break;
		case WM_CLOSE:
	        EnableWindow(hLoginWindow, TRUE);
	        DestroyWindow(hWnd);
	        break;
	    case WM_CREATE:{
	        AddMenus(hWnd);
	        loadImages();
            AddWinProcResInfo2(hWnd);

	        static char name[100], age[100], address[100], barangay[100], contact[100], gender[100], district[100];
	        GetWindowText(hNameEdit, name, 100);
	        SetWindowText(hNameStat, name);
	        GetWindowText(hAgeEdit, age, 100);
	        SetWindowText(hAgeStat, age);
	        GetWindowText(hAddressEdit, address, 100);
	        SetWindowText(hAddressStat, address);
	        GetWindowText(hBarangayEdit, barangay, 100);
	        SetWindowText(hBarangayStat, barangay);
	        GetWindowText(hContactEdit, contact, 100);
	        SetWindowText(hContactStat, contact);
	        GetWindowText(hGstore, gender, 100);
	        SetWindowText(hGenderEdit, gender);
	        GetWindowText(hDstore, district, 100);
	        SetWindowText(hDistrictEdit, district);

	        } break;
	    default:
	        return DefWindowProcW(hWnd, msg, wp, lp);
	}
}

void registerWindowProcedureResInfo2(HINSTANCE hInst){


	WNDCLASSW dialogResInfo2 = {0};

    HBRUSH hb = ::CreateSolidBrush(RGB(249, 235, 217));

    dialogResInfo2.hbrBackground = hb;
    dialogResInfo2.hCursor = LoadCursor (NULL, IDC_CROSS);
    dialogResInfo2.hInstance = hInst;
    dialogResInfo2.lpszClassName = L"WindProcResInfo2";
    dialogResInfo2.lpfnWndProc = WindowProcedureResInfo2;

    RegisterClassW(&dialogResInfo2);

}

void displayWindowProcedureResInfo2(HWND hWnd){

    hResInfoWindow2 = CreateWindowW(L"WindProcResInfo2", L"CCMSM", WS_VISIBLE | WS_MINIMIZEBOX | WS_SYSMENU,
                  500, 100, 400, 450, hWnd, NULL, NULL, NULL);

    EnableWindow(hWnd, TRUE);
}

void AddWinProcResInfo2(HWND hWnd){

    HFONT hFontInside = CreateFont (17, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
    OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
    DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontInsideEdit = CreateFont (17, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
    OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
    DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    hLogo = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                  90, 10, 180, 160, hWnd, NULL, NULL, NULL);
    SendMessage(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bLogo);
    hResInfoTitle = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                  100, 105, 260, 180, hWnd, NULL, NULL, NULL);
    SendMessage(hResInfoTitle, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bResInfoTitle);

    hName = CreateWindowW(L"Static", L"NAME: ", WS_VISIBLE | WS_CHILD,
                  75, 140, 50, 17, hWnd, NULL, NULL, NULL);
    SendMessage(hName, WM_SETFONT, (LPARAM)hFontInside, FALSE);

    hNameStat = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD|ES_AUTOVSCROLL|ES_READONLY,
                  130, 140, 170, 17, hWnd, NULL, NULL, NULL);
    SendMessage(hNameStat, WM_SETFONT, (LPARAM)hFontInsideEdit, FALSE);

    hAge = CreateWindowW(L"Static", L"AGE: ", WS_VISIBLE | WS_CHILD|SS_RIGHT,
                  78, 165, 50, 17, hWnd, NULL, NULL, NULL);
    SendMessage(hAge, WM_SETFONT, (LPARAM)hFontInside, FALSE);

    hAgeStat = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD|ES_AUTOVSCROLL|ES_READONLY,
                  130, 165, 170, 17, hWnd, NULL, NULL, NULL);
    SendMessage(hAgeStat, WM_SETFONT, (LPARAM)hFontInsideEdit, FALSE);


    hAddress = CreateWindowW(L"Static", L"ADDRESS: ", WS_VISIBLE | WS_CHILD|SS_RIGHT,
                  28, 190, 100, 17, hWnd, NULL, NULL, NULL);
    SendMessage(hAddress, WM_SETFONT, (LPARAM)hFontInside, FALSE);

    hAddressStat = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD|ES_AUTOVSCROLL|ES_READONLY,
                  130, 190, 170, 17, hWnd, NULL, NULL, NULL);
    SendMessage(hAddressStat, WM_SETFONT, (LPARAM)hFontInsideEdit, FALSE);

    hBarangay = CreateWindowW(L"Static", L"BARANGAY: ", WS_VISIBLE | WS_CHILD|SS_RIGHT,
                  28, 215, 100, 17, hWnd, NULL, NULL, NULL);
    SendMessage(hBarangay, WM_SETFONT, (LPARAM)hFontInside, FALSE);

    hBarangayStat = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD|ES_AUTOVSCROLL|ES_READONLY,
                  130, 215, 170, 17, hWnd, NULL, NULL, NULL);
    SendMessage(hBarangayStat, WM_SETFONT, (LPARAM)hFontInsideEdit, FALSE);

    hContact = CreateWindowW(L"Static", L"CONTACT NO.: ", WS_VISIBLE | WS_CHILD|SS_RIGHT,
                  5, 240, 120, 17, hWnd, NULL, NULL, NULL);
    SendMessage(hContact, WM_SETFONT, (LPARAM)hFontInside, FALSE);

    hContactStat = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD|ES_AUTOVSCROLL|ES_READONLY,
                  130, 240, 170, 17, hWnd, NULL, NULL, NULL);
    SendMessage(hContactStat, WM_SETFONT, (LPARAM)hFontInsideEdit, FALSE);

    hDistrict = CreateWindowW(L"Static", L"DISTRICT: ", WS_VISIBLE | WS_CHILD|SS_CENTER,
                  50, 265, 75, 17, hWnd, NULL, NULL, NULL);
    SendMessage(hDistrict, WM_SETFONT, (LPARAM)hFontInside, FALSE);

    hDistrictEdit = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD|ES_AUTOVSCROLL|ES_READONLY,
                  130, 265, 170, 17, hWnd, NULL, NULL, NULL);
    SendMessage(hDistrictEdit, WM_SETFONT, (LPARAM)hFontInsideEdit, FALSE);

    hGender= CreateWindowW(L"Static", L"GENDER: ", WS_VISIBLE | WS_CHILD|SS_CENTER,
                  50, 290, 75, 17, hWnd, NULL, NULL, NULL);
    SendMessage(hGender, WM_SETFONT, (LPARAM)hFontInside, FALSE);

    hGenderEdit = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD|ES_AUTOVSCROLL|ES_READONLY,
                  130, 290, 170, 17, hWnd, NULL, NULL, NULL);
    SendMessage(hGenderEdit, WM_SETFONT, (LPARAM)hFontInsideEdit, FALSE);

    hBack = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
                  40, 360, 80, 25, hWnd, (HMENU)BUTTON_GOBACK, NULL, NULL);
    SendMessage(hBack, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bGoBack);

    hProceed = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
                  270, 358, 80, 25, hWnd, (HMENU)BUTTON_PROCEED, NULL, NULL);
    SendMessage(hProceed, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bProceed);

}
//--------------------------------------------------------------- ACCESS REPORT WIN PROC --------------------------------------------------
LRESULT CALLBACK WindowProcedureAccRep(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp ){

	int mbVal;
	bool checked = false;
    static int flag = 0, qFlag = 0;
    char address[100];

	switch(msg){
	    case WM_COMMAND:
		//rescan:
		if (LOWORD(wp) == DIST_I){
				checked = IsDlgButtonChecked(hWnd, DIST_I);
	            if (!checked) {
	                CheckDlgButton(hWnd, DIST_I, BST_CHECKED);
	                //SetWindowText(hD1, "Operational");
	                SetWindowText(hDstore2, "DISTRICT I");
	                EnableWindow(hD1, TRUE);
	                EnableWindow(hD2, FALSE);
	                EnableWindow(hD3, FALSE);
	                EnableWindow(hD4, FALSE);
	                EnableWindow(hD5, FALSE);
	                EnableWindow(hD6, FALSE);
	                flag = 1;
	            } else {
	            	CheckDlgButton(hWnd, DIST_I, BST_UNCHECKED);
	            	//SetWindowText(hD1, "District I");
                    EnableWindow(hD2, TRUE);
	                EnableWindow(hD3, TRUE);
	                EnableWindow(hD4, TRUE);
	                EnableWindow(hD5, TRUE);
	                EnableWindow(hD6, TRUE);
	            	flag = 0;
	            }
			}

            //2
            if (LOWORD(wp) == DIST_II){
				checked = IsDlgButtonChecked(hWnd, DIST_II);
	            if (!checked) {
	                CheckDlgButton(hWnd, DIST_II, BST_CHECKED);
	                //SetWindowText(hD2, "Operational");
	                SetWindowText(hDstore2, "DISTRICT II");
	                EnableWindow(hD1, FALSE);
	                EnableWindow(hD2, TRUE);
	                EnableWindow(hD3, FALSE);
	                EnableWindow(hD4, FALSE);
	                EnableWindow(hD5, FALSE);
	                EnableWindow(hD6, FALSE);
	                flag = 1;
	            } else {
	               CheckDlgButton(hWnd, DIST_II, BST_UNCHECKED);
	               //SetWindowText(hD2, "District II");
	                EnableWindow(hD1, TRUE);
	                EnableWindow(hD3, TRUE);
	                EnableWindow(hD4, TRUE);
	                EnableWindow(hD5, TRUE);
	                EnableWindow(hD6, TRUE);
	               flag = 0;
	            }
			}

            //3
            if (LOWORD(wp) == DIST_III){
				checked = IsDlgButtonChecked(hWnd, DIST_III);
	            if (!checked) {
	                CheckDlgButton(hWnd, DIST_III, BST_CHECKED);
	                //SetWindowText(hD3, "Operational");
	                SetWindowText(hDstore2, "DISTRICT III");
	                EnableWindow(hD1, FALSE);
	                EnableWindow(hD2, FALSE);
	                EnableWindow(hD3, TRUE);
	                EnableWindow(hD4, FALSE);
	                EnableWindow(hD5, FALSE);
	                EnableWindow(hD6, FALSE);
	                flag = 1;
	            } else {
	               CheckDlgButton(hWnd, DIST_III, BST_UNCHECKED);
	               //SetWindowText(hD3, "District III");
	               EnableWindow(hD1, TRUE);
	                EnableWindow(hD2, TRUE);
	                EnableWindow(hD4, TRUE);
	                EnableWindow(hD5, TRUE);
	                EnableWindow(hD6, TRUE);
	               flag = 0;
	            }
			}
            //4
            if (LOWORD(wp) == DIST_IV){
				checked = IsDlgButtonChecked(hWnd, DIST_IV);
	            if (!checked) {
	                CheckDlgButton(hWnd, DIST_IV, BST_CHECKED);
	                //SetWindowText(hD4, "Operational");
	                SetWindowText(hDstore2, "DISTRICT IV");
	                EnableWindow(hD1, FALSE);
	                EnableWindow(hD2, FALSE);
	                EnableWindow(hD3, FALSE);
	                EnableWindow(hD4, TRUE);
	                EnableWindow(hD5, FALSE);
	                EnableWindow(hD6, FALSE);
	                flag = 1;
	            } else {
	               CheckDlgButton(hWnd, DIST_IV, BST_UNCHECKED);
	               //SetWindowText(hD4, "District IV");
                    EnableWindow(hD1, TRUE);
	                EnableWindow(hD2, TRUE);
	                EnableWindow(hD3, TRUE);
	                EnableWindow(hD5, TRUE);
	                EnableWindow(hD6, TRUE);
	               flag = 0;
	            }
			}
			//5
            if (LOWORD(wp) == DIST_V){
				checked = IsDlgButtonChecked(hWnd, DIST_V);
	            if (!checked) {
	                CheckDlgButton(hWnd, DIST_V, BST_CHECKED);
	                //SetWindowText(hD5, "Operational");
	                SetWindowText(hDstore2, "DISTRICT V");
	                EnableWindow(hD1, FALSE);
	                EnableWindow(hD2, FALSE);
	                EnableWindow(hD3, FALSE);
	                EnableWindow(hD4, FALSE);
	                EnableWindow(hD5, TRUE);
	                EnableWindow(hD6, FALSE);
	                flag = 1;
	            } else {
	               CheckDlgButton(hWnd, DIST_V, BST_UNCHECKED);
	               //SetWindowText(hD5, "District V");
	               EnableWindow(hD1, TRUE);
	                EnableWindow(hD2, TRUE);
	                EnableWindow(hD3, TRUE);
	                EnableWindow(hD4, TRUE);
	                EnableWindow(hD6, TRUE);
	               flag = 0;
	            }
			}
            //6
            if (LOWORD(wp) == DIST_VI){
				checked = IsDlgButtonChecked(hWnd, DIST_VI);
	            if (!checked) {
	                CheckDlgButton(hWnd, DIST_VI, BST_CHECKED);
	                //SetWindowText(hD6, "Operational");
	                SetWindowText(hDstore2, "DISTRICT VI");
	                EnableWindow(hD1, FALSE);
	                EnableWindow(hD2, FALSE);
	                EnableWindow(hD3, FALSE);
	                EnableWindow(hD4, FALSE);
	                EnableWindow(hD5, FALSE);
	                EnableWindow(hD6, TRUE);
	                flag = 1;
	            } else {
	               CheckDlgButton(hWnd, DIST_VI, BST_UNCHECKED);
	               //SetWindowText(hD6, "District VI");
	                EnableWindow(hD1, TRUE);
	                EnableWindow(hD2, TRUE);
	                EnableWindow(hD3, TRUE);
	                EnableWindow(hD4, TRUE);
	                EnableWindow(hD5, TRUE);
	               flag = 0;
	            }
			}



            switch(wp){
            	case FILE_MENU_ABOUT:              //about menu
 				MessageBoxW(hWnd, L"CCMSM \n\nby Robles, John Joe Rimuel P.", L"About Digital Budget Planner", MB_OK | MB_ICONINFORMATION);                break;
                case FILE_MENU_EXIT:               //program exit menu
                    mbVal = MessageBoxW(hWnd, L"Exit Program?", L"Exit", MB_YESNO | MB_ICONEXCLAMATION);
                    if (mbVal == IDYES)             //built in IDs for Message Boxes
                        DestroyWindow(hWnd);
                    else if (mbVal == IDNO)
                        break;
				case BUTTON_PROCEED:
				    if (flag != 1){
						MessageBoxW(hWnd, L"Please fill up all fields!", L"Input Error", MB_OK | MB_ICONEXCLAMATION);
						return 0;
                        }
                        else {
                            ShowWindow(hAccRepWindow, SW_HIDE);
                        }
                            displayWindowProcedureAccRep2(hWnd);

                        break;
                case BUTTON_GOBACK:
                    ShowWindow(hLoginWindow, SW_SHOW);
                    ShowWindow(hAccRepWindow, SW_HIDE);
                        break;
            }

        case WM_CTLCOLOREDIT:{

		    HDC hdc = (HDC)wp;
		    SetBkColor(hdc, RGB(249, 235, 217));
		    hbrBkgnd = CreateSolidBrush(RGB(249, 235, 217));
		    if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(249, 235, 217));
            }
            return (INT_PTR)hbrBkgnd;
		}break;

		case WM_CTLCOLORSTATIC:{

            HDC hdcStatic = (HDC) wp;
            SetTextColor(hdcStatic, RGB(0, 0, 0));
            hbrBkgnd = CreateSolidBrush(RGB(249, 235, 217));
            SetBkMode(hdcStatic,TRANSPARENT);

            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS) == (HWND)lp || GetDlgItem(hWnd, TXTCOLOR_QRTN) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(0, 0, 0));
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
			}

			if (GetDlgItem(hWnd, TXTCOLOR_OPBUS2) == (HWND)lp || GetDlgItem(hWnd, TXTCOLOR_QRTN2) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(0, 0, 0));
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
			}

            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS3) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(0, 0, 0));
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
			}

            if (hbrBkgnd == NULL){
            	hbrBkgnd = CreateSolidBrush(RGB(255, 254, 254));
            }
            if ((HWND)lp == hD1)
            {
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
            }
             if ((HWND)lp == hD2)
            {
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
            }
             if ((HWND)lp == hD3)
            {
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
            }
             if ((HWND)lp == hD4)
            {
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
            }
             if ((HWND)lp == hD5)
            {
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
            }
             if ((HWND)lp == hD6)
            {
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
            }

            return (INT_PTR)hbrBkgnd;

        }break;
		case WM_CLOSE:
	        EnableWindow(hLoginWindow, TRUE);
	        DestroyWindow(hWnd);
	        break;
	    case WM_CREATE:{

	        AddMenus(hWnd);
	        loadImages();
            AddWinProcAccRep(hWnd);
	        } break;
	    default:
	        return DefWindowProcW(hWnd, msg, wp, lp);
	}
}

void registerWindowProcedureAccRep(HINSTANCE hInst){


	WNDCLASSW dialogAccRep = {0};

    HBRUSH hb = ::CreateSolidBrush(RGB(249, 235, 217));

    dialogAccRep.hbrBackground = hb;
    dialogAccRep.hCursor = LoadCursor (NULL, IDC_CROSS);
    dialogAccRep.hInstance = hInst;
    dialogAccRep.lpszClassName = L"WindProcAccRep";
    dialogAccRep.lpfnWndProc = WindowProcedureAccRep;

    RegisterClassW(&dialogAccRep);

}

void displayWindowProcedureAccRep(HWND hWnd){

    hAccRepWindow = CreateWindowW(L"WindProcAccRep", L"CCMSM", WS_VISIBLE | WS_MINIMIZEBOX | WS_SYSMENU,
                  500, 100, 400, 450, hWnd, NULL, NULL, NULL);

    EnableWindow(hWnd, TRUE);
}

void AddWinProcAccRep(HWND hWnd){

    HFONT hFontInside = CreateFont (19, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
    OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
    DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontInsideEdit = CreateFont (17, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
    OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
    DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    hLogo = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                  90, 10, 190, 170, hWnd, NULL, NULL, NULL);
    SendMessage(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bLogo);
    hResInfoTitle = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                  90, 105, 260, 180, hWnd, NULL, NULL, NULL);
    SendMessage(hResInfoTitle, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bAccessInfoRec);

    HWND hAccBg = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD,
                  60 , 150, 280, 160, hWnd, (HMENU)TXTCOLOR_OPBUS, NULL, NULL);

    hD1 = CreateWindowW(L"button", L"District I", WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                80, 180, 90, 17, hWnd,(HMENU)DIST_I, NULL, NULL);
    SendMessage(hD1, WM_SETFONT, (LPARAM)hFontInside, FALSE);
    CheckDlgButton(hWnd, 1, BST_UNCHECKED);


    hD2 = CreateWindowW(L"button", L"District II", WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                80, 220, 90, 17, hWnd,(HMENU)DIST_II, NULL, NULL);
    SendMessage(hD2, WM_SETFONT, (LPARAM)hFontInside, FALSE);
    CheckDlgButton(hWnd, 2, BST_UNCHECKED);


    hD3 = CreateWindowW(L"button", L"District III", WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                80, 260, 100, 17, hWnd,(HMENU)DIST_III, NULL, NULL);
    SendMessage(hD3, WM_SETFONT, (LPARAM)hFontInside, FALSE);
    CheckDlgButton(hWnd, 3, BST_UNCHECKED);


    hD4 = CreateWindowW(L"button", L"District IV", WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                220, 180, 100, 17, hWnd,(HMENU)DIST_IV, NULL, NULL);
    SendMessage(hD4, WM_SETFONT, (LPARAM)hFontInside, FALSE);
    CheckDlgButton(hWnd, 4, BST_UNCHECKED);


    hD5 = CreateWindowW(L"button", L"District V", WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                220, 220, 90, 17, hWnd,(HMENU)DIST_V, NULL, NULL);
    SendMessage(hD5, WM_SETFONT, (LPARAM)hFontInside, FALSE);
    CheckDlgButton(hWnd, 5, BST_UNCHECKED);


    hD6 = CreateWindowW(L"button", L"District VI", WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                220, 260, 100, 17, hWnd,(HMENU)DIST_VI, NULL, NULL);
    SendMessage(hD6, WM_SETFONT, (LPARAM)hFontInside, FALSE);
    CheckDlgButton(hWnd, 6, BST_UNCHECKED);

    hDstore2 = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD|WS_BORDER,
                100, 500, 100, 17, hWnd,(HMENU)hFontInside, NULL, NULL);



    hBack = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
                  40, 360, 80, 25, hWnd, (HMENU)BUTTON_GOBACK, NULL, NULL);
    SendMessage(hBack, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bGoBack);

    hProceed = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
                  270, 358, 80, 25, hWnd, (HMENU)BUTTON_PROCEED, NULL, NULL);
    SendMessage(hProceed, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bProceed);

}
//--------------------------------------------------------------- ACCESS REPORT 2 WIN PROC --------------------------------------------------
LRESULT CALLBACK WindowProcedureAccRep2(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp ){

	int mbVal;
	bool checked = false;
    static int flag = 0, qFlag = 0;

	switch(msg){
	    case WM_COMMAND:
		//rescan:
            if (LOWORD(wp) == ID_RADIOBTN1){
				qFlag = 1;
			}
			if (LOWORD(wp) == ID_RADIOBTN2){
				qFlag = 1;
			}
			if (LOWORD(wp) == ID_RADIOBTN3){
				qFlag = 1;
			}

            switch(wp){
            	case FILE_MENU_ABOUT:              //about menu
 					MessageBoxW(hWnd, L"CCMSM \n\nby Robles, John Joe Rimuel P.", L"About Digital Budget Planner", MB_OK | MB_ICONINFORMATION);                break;
                case FILE_MENU_EXIT:               //program exit menu
                    mbVal = MessageBoxW(hWnd, L"Exit Program?", L"Exit", MB_YESNO | MB_ICONEXCLAMATION);
                    if (mbVal == IDYES)             //built in IDs for Message Boxes
                        DestroyWindow(hWnd);
                    else if (mbVal == IDNO)
                        break;
                case ID_RADIOBTN1:
		            if (IsDlgButtonChecked(hWnd, LOWORD(wp)) == BST_CHECKED){
		                SetWindowText(hwhichAccess, "1"); }
		        	break;
		        case ID_RADIOBTN2:
		            if (IsDlgButtonChecked(hWnd, LOWORD(wp)) == BST_CHECKED){
		                SetWindowText(hwhichAccess, "2"); }
		        	break;
		        case ID_RADIOBTN3:
		            if (IsDlgButtonChecked(hWnd, LOWORD(wp)) == BST_CHECKED){
		                SetWindowText(hwhichAccess, "3"); }
		        	break;
				case BUTTON_PROCEED:
				    char get[100];
					GetWindowText(hwhichAccess, get, 100);
					if (strcmp(get, "1") == 0){
						displayWindowProcedureAccRepD(hWnd);
					}
					if (strcmp(get, "2") == 0){
						displayWindowProcedureAccRepW(hWnd);
					}
					if (strcmp(get, "3") == 0){
						displayWindowProcedureAccRepM(hWnd);
					}

				    ShowWindow(hAccRepWindow2, SW_HIDE);
                        break;
                case BUTTON_GOBACK:
                    ShowWindow(hAccRepWindow, SW_SHOW);
                    ShowWindow(hAccRepWindow2, SW_HIDE);
                        break;
            }

        case WM_CTLCOLOREDIT:{

		    HDC hdc = (HDC)wp;
		    SetBkColor(hdc, RGB(249, 235, 217));
		    hbrBkgnd = CreateSolidBrush(RGB(249, 235, 217));
		    if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(249, 235, 217));
            }
            return (INT_PTR)hbrBkgnd;
		}break;

		case WM_CTLCOLORSTATIC:{

            HDC hdcStatic = (HDC) wp;
            SetTextColor(hdcStatic, RGB(0, 0, 0));
            hbrBkgnd = CreateSolidBrush(RGB(249, 235, 217));
            SetBkMode(hdcStatic,TRANSPARENT);

            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS) == (HWND)lp || GetDlgItem(hWnd, TXTCOLOR_QRTN) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(0, 0, 0));
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
			}

			if (GetDlgItem(hWnd, TXTCOLOR_OPBUS2) == (HWND)lp || GetDlgItem(hWnd, TXTCOLOR_QRTN2) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(0, 0, 0));
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
			}

            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS3) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(0, 0, 0));
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
			}

            if (hbrBkgnd == NULL){
            	hbrBkgnd = CreateSolidBrush(RGB(255, 254, 254));
            }
            if ((HWND)lp == hDaily)
            {
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
            }
            if ((HWND)lp == hWeekly)
            {
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
            }
            if ((HWND)lp == hMonthly)
            {
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
            }

            return (INT_PTR)hbrBkgnd;

        }break;
		case WM_CLOSE:
	        EnableWindow(hLoginWindow, TRUE);
	        DestroyWindow(hWnd);
	        break;
	    case WM_CREATE:{

	        AddMenus(hWnd);
	        loadImages();
            AddWinProcAccRep2(hWnd);
	        } break;
	    default:
	        return DefWindowProcW(hWnd, msg, wp, lp);
	}
}

void registerWindowProcedureAccRep2(HINSTANCE hInst){


	WNDCLASSW dialogAccRep2 = {0};

    HBRUSH hb = ::CreateSolidBrush(RGB(249, 235, 217));

    dialogAccRep2.hbrBackground = hb;
    dialogAccRep2.hCursor = LoadCursor (NULL, IDC_CROSS);
    dialogAccRep2.hInstance = hInst;
    dialogAccRep2.lpszClassName = L"WindProcAccRep2";
    dialogAccRep2.lpfnWndProc = WindowProcedureAccRep2;

    RegisterClassW(&dialogAccRep2);

}

void displayWindowProcedureAccRep2(HWND hWnd){

    hAccRepWindow2 = CreateWindowW(L"WindProcAccRep2", L"CCMSM", WS_VISIBLE | WS_MINIMIZEBOX | WS_SYSMENU,
                  500, 100, 400, 450, hWnd, NULL, NULL, NULL);

    EnableWindow(hWnd, TRUE);
}

void AddWinProcAccRep2(HWND hWnd){

    HFONT hFontInside = CreateFont (23, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
    OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
    DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontInsideEdit = CreateFont (17, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
    OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
    DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    hLogo = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                  90, 10, 190, 170, hWnd, NULL, NULL, NULL);
    SendMessage(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bLogo);
    hResInfoTitle = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                  90, 105, 260, 180, hWnd, NULL, NULL, NULL);
    SendMessage(hResInfoTitle, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bAccessInfoRec);

    HWND hAccBg = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD,
                  60 , 150, 280, 160, hWnd, (HMENU)TXTCOLOR_OPBUS, NULL, NULL);

    hDaily = CreateWindowW(L"button", L"Daily Records", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                120, 180, 170, 17, hWnd,(HMENU)ID_RADIOBTN1, NULL, NULL);
    SendMessage(hDaily, WM_SETFONT, (LPARAM)hFontInside, FALSE);

    hWeekly = CreateWindowW(L"button", L"Weekly Records", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                120, 220, 170, 17, hWnd,(HMENU)ID_RADIOBTN2, NULL, NULL);
    SendMessage(hWeekly, WM_SETFONT, (LPARAM)hFontInside, FALSE);

    hMonthly = CreateWindowW(L"button", L"Monthly Records", WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                120, 260, 180, 17, hWnd,(HMENU)ID_RADIOBTN3, NULL, NULL);
    SendMessage(hMonthly, WM_SETFONT, (LPARAM)hFontInside, FALSE);

    hwhichAccess = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,
                42,500, 150, 32, hWnd, NULL, NULL, NULL);

    hBack = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
                  40, 360, 80, 25, hWnd, (HMENU)BUTTON_GOBACK, NULL, NULL);
    SendMessage(hBack, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bGoBack);

    hProceed = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
                  270, 358, 80, 25, hWnd, (HMENU)BUTTON_PROCEED, NULL, NULL);
    SendMessage(hProceed, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bProceed);

}
//--------------------------------------------------------------- ACCESS REPORT DAILY WIN PROC --------------------------------------------------
LRESULT CALLBACK WindowProcedureAccRepD(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp ){

	int mbVal;
	bool checked = false;
    static int flag = 0, qFlag = 0;

	switch(msg){
	    case WM_COMMAND:
		//rescan:

            switch(wp){
            	case FILE_MENU_ABOUT:              //about menu
 					MessageBoxW(hWnd, L"CCMSM \n\nby Robles, John Joe Rimuel P.", L"About Digital Budget Planner", MB_OK | MB_ICONINFORMATION);                break;
                case FILE_MENU_EXIT:               //program exit menu
                    mbVal = MessageBoxW(hWnd, L"Exit Program?", L"Exit", MB_YESNO | MB_ICONEXCLAMATION);
                    if (mbVal == IDYES)             //built in IDs for Message Boxes
                        DestroyWindow(hWnd);
                    else if (mbVal == IDNO)
                        break;
                case BUTTON_GOBACK:
                    ShowWindow(hAccRepWindow2, SW_SHOW);
                    ShowWindow(hAccRepWindowD, SW_HIDE);
                        break;
            }

        case WM_CTLCOLOREDIT:{

		    HDC hdc = (HDC)wp;
		    SetBkColor(hdc, RGB(232, 232, 232));
		    hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
		    if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
            }
            return (INT_PTR)hbrBkgnd;
		}break;

		case WM_CTLCOLORSTATIC:{

            HDC hdcStatic = (HDC) wp;
            SetTextColor(hdcStatic, RGB(0, 0, 0));
            hbrBkgnd = CreateSolidBrush(RGB(249, 235, 217));
            SetBkMode(hdcStatic,TRANSPARENT);

            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS) == (HWND)lp || GetDlgItem(hWnd, TXTCOLOR_QRTN) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(0, 0, 0));
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
			}

			if (GetDlgItem(hWnd, TXTCOLOR_OPBUS2) == (HWND)lp || GetDlgItem(hWnd, TXTCOLOR_QRTN2) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(0, 0, 0));
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
			}

            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS3) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(0, 0, 0));
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
			}

            if (hbrBkgnd == NULL){
            	hbrBkgnd = CreateSolidBrush(RGB(255, 254, 254));
            }
            if ((HWND)lp == hDaily)
            {
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
            }
            if ((HWND)lp == hWeekly)
            {
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
            }
            if ((HWND)lp == hMonthly)
            {
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
            }

            return (INT_PTR)hbrBkgnd;

        }break;
		case WM_CLOSE:
	        EnableWindow(hLoginWindow, TRUE);
	        DestroyWindow(hWnd);
	        break;
	    case WM_CREATE:{

	        AddMenus(hWnd);
	        loadImages();
            AddWinProcAccRepD(hWnd);

            open_fileD(hWnd);
	        } break;
	    default:
	        return DefWindowProcW(hWnd, msg, wp, lp);
	}
}
void display_fileD(char* path){

    FILE *file;
    file = fopen(path, "rb");
    fseek(file, 0, SEEK_END);
    int _size = ftell(file);
    rewind(file);

    char *data = new char[_size+1];
    fread(data, _size, 1, file);
    data[_size] = '\0';

    SetWindowText(hAccEdit, data);

}

void open_fileD( HWND hWnd){

    OPENFILENAME ofn;
    ZeroMemory(&ofn, sizeof(OPENFILENAME));

    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = hWnd;
    static char getD[100];
    GetWindowText(hDstore2,getD, 100);

    if(strcmp(getD, "DISTRICT I")==0){
        ofn.lpstrFile = "District I.txt";
    }
    if(strcmp(getD, "DISTRICT II")==0){
        ofn.lpstrFile = "District II.TXT";
    }
    if(strcmp(getD, "DISTRICT III")==0){
        ofn.lpstrFile = "District III.TXT";
    }
    if(strcmp(getD, "DISTRICT IV")==0){
        ofn.lpstrFile = "District IV.TXT";
    }
    if(strcmp(getD, "DISTRICT V")==0){
        ofn.lpstrFile = "District V.TXT";
    }
    if(strcmp(getD, "DISTRICT VI")==0){
        ofn.lpstrFile = "District VI.TXT";
    }
    GetOpenFileName(&ofn);
    display_fileD(ofn.lpstrFile);

}

void registerWindowProcedureAccRepD(HINSTANCE hInst){


	WNDCLASSW dialogAccRepD = {0};

    HBRUSH hb = ::CreateSolidBrush(RGB(249, 235, 217));

    dialogAccRepD.hbrBackground = hb;
    dialogAccRepD.hCursor = LoadCursor (NULL, IDC_CROSS);
    dialogAccRepD.hInstance = hInst;
    dialogAccRepD.lpszClassName = L"WindProcAccRepD";
    dialogAccRepD.lpfnWndProc = WindowProcedureAccRepD;

    RegisterClassW(&dialogAccRepD);

}

void displayWindowProcedureAccRepD(HWND hWnd){

    hAccRepWindowD = CreateWindowW(L"WindProcAccRepD", L"CCMSM", WS_VISIBLE | WS_MINIMIZEBOX | WS_SYSMENU,
                  200, 100, 870, 510, hWnd, NULL, NULL, NULL);

    EnableWindow(hWnd, TRUE);
}

void AddWinProcAccRepD(HWND hWnd){

    HFONT hFontInside = CreateFont (23, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
    OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
    DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontInsideEdit = CreateFont (17, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
    OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
    DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    hLogo = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                  30, 10, 190, 170, hWnd, NULL, NULL, NULL);
    SendMessage(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bLogo);

    hResInfoTitle = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                  370, 50, 260, 180, hWnd, NULL, NULL, NULL);
    SendMessage(hResInfoTitle, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bDaily);

    HWND hAccTop = CreateWindowW(L"Static", L"          NAME          ||  AGE  ||          ADDRESS          ||     BARANGAY     ||     CONTACT NO.    ||     DISTRICT     ||   GENDER  ", WS_VISIBLE | WS_CHILD,
                  30 , 100, 800, 20, hWnd, (HMENU)TXTCOLOR_OPBUS, NULL, NULL);

    hAccEdit = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD|ES_MULTILINE,
                  30 , 130, 800, 270, hWnd, (HMENU)hAccEditBg, NULL, NULL);

    hBack = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
                  40, 410, 80, 25, hWnd, (HMENU)BUTTON_GOBACK, NULL, NULL);
    SendMessage(hBack, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bGoBack);
}
//--------------------------------------------------------------- ACCESS REPORT WEEKLY WIN PROC --------------------------------------------------
LRESULT CALLBACK WindowProcedureAccRepW(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp ){

	int mbVal;
	bool checked = false;
    static int flag = 0, qFlag = 0;

	switch(msg){
	    case WM_COMMAND:
		//rescan:

            switch(wp){
            	case FILE_MENU_ABOUT:              //about menu
 					MessageBoxW(hWnd, L"CCMSM \n\nby Robles, John Joe Rimuel P.", L"About Digital Budget Planner", MB_OK | MB_ICONINFORMATION);                break;
                case FILE_MENU_EXIT:               //program exit menu
                    mbVal = MessageBoxW(hWnd, L"Exit Program?", L"Exit", MB_YESNO | MB_ICONEXCLAMATION);
                    if (mbVal == IDYES)             //built in IDs for Message Boxes
                        DestroyWindow(hWnd);
                    else if (mbVal == IDNO)
                        break;
                case BUTTON_GOBACK:
                    ShowWindow(hAccRepWindow2, SW_SHOW);
                    ShowWindow(hAccRepWindowW, SW_HIDE);
                        break;
            }

        case WM_CTLCOLOREDIT:{

		    HDC hdc = (HDC)wp;
		    SetBkColor(hdc, RGB(232, 232, 232));
		    hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
		    if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(249, 235, 217));
            }
            return (INT_PTR)hbrBkgnd;
		}break;

		case WM_CTLCOLORSTATIC:{

            HDC hdcStatic = (HDC) wp;
            SetTextColor(hdcStatic, RGB(0, 0, 0));
            hbrBkgnd = CreateSolidBrush(RGB(249, 235, 217));
            SetBkMode(hdcStatic,TRANSPARENT);

            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS) == (HWND)lp || GetDlgItem(hWnd, TXTCOLOR_QRTN) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(0, 0, 0));
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
			}

			if (GetDlgItem(hWnd, TXTCOLOR_OPBUS2) == (HWND)lp || GetDlgItem(hWnd, TXTCOLOR_QRTN2) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(0, 0, 0));
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
			}

            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS3) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(0, 0, 0));
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
			}

            if (hbrBkgnd == NULL){
            	hbrBkgnd = CreateSolidBrush(RGB(255, 254, 254));
            }
            if ((HWND)lp == hDaily)
            {
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
            }
            if ((HWND)lp == hWeekly)
            {
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
            }
            if ((HWND)lp == hMonthly)
            {
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
            }

            return (INT_PTR)hbrBkgnd;

        }break;
		case WM_CLOSE:
	        EnableWindow(hLoginWindow, TRUE);
	        DestroyWindow(hWnd);
	        break;
	    case WM_CREATE:{

	        AddMenus(hWnd);
	        loadImages();
            AddWinProcAccRepW(hWnd);
            open_fileW(hWnd);
	        } break;
	    default:
	        return DefWindowProcW(hWnd, msg, wp, lp);
	}
}
void display_fileW(char* path){

    FILE *file;
    file = fopen(path, "rb");
    fseek(file, 0, SEEK_END);
    int _size = ftell(file);
    rewind(file);

    char *data = new char[_size+1];
    fread(data, _size, 1, file);
    data[_size] = '\0';

    SetWindowText(hAccEdit, data);

}

void open_fileW( HWND hWnd){

    OPENFILENAME ofn;
    ZeroMemory(&ofn, sizeof(OPENFILENAME));

    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = hWnd;
    static char getD[100];
    GetWindowText(hDstore2,getD, 100);

    if(strcmp(getD, "DISTRICT I")==0){
        ofn.lpstrFile = "District I.txt";
    }
    if(strcmp(getD, "DISTRICT II")==0){
        ofn.lpstrFile = "District II.TXT";
    }
    if(strcmp(getD, "DISTRICT III")==0){
        ofn.lpstrFile = "District III.TXT";
    }
    if(strcmp(getD, "DISTRICT IV")==0){
        ofn.lpstrFile = "District IV.TXT";
    }
    if(strcmp(getD, "DISTRICT V")==0){
        ofn.lpstrFile = "District V.TXT";
    }
    if(strcmp(getD, "DISTRICT VI")==0){
        ofn.lpstrFile = "District VI.TXT";
    }
    GetOpenFileName(&ofn);
    display_fileW(ofn.lpstrFile);

}

void registerWindowProcedureAccRepW(HINSTANCE hInst){


	WNDCLASSW dialogAccRepW = {0};

    HBRUSH hb = ::CreateSolidBrush(RGB(249, 235, 217));

    dialogAccRepW.hbrBackground = hb;
    dialogAccRepW.hCursor = LoadCursor (NULL, IDC_CROSS);
    dialogAccRepW.hInstance = hInst;
    dialogAccRepW.lpszClassName = L"WindProcAccRepW";
    dialogAccRepW.lpfnWndProc = WindowProcedureAccRepW;

    RegisterClassW(&dialogAccRepW);

}

void displayWindowProcedureAccRepW(HWND hWnd){

    hAccRepWindowW = CreateWindowW(L"WindProcAccRepW", L"CCMSM", WS_VISIBLE | WS_MINIMIZEBOX | WS_SYSMENU,
                  200, 100, 870, 510, hWnd, NULL, NULL, NULL);

    EnableWindow(hWnd, TRUE);
}

void AddWinProcAccRepW(HWND hWnd){

    HFONT hFontInside = CreateFont (23, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
    OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
    DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontInsideEdit = CreateFont (17, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
    OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
    DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    hLogo = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                  30, 10, 190, 170, hWnd, NULL, NULL, NULL);
    SendMessage(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bLogo);

    hResInfoTitle = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                  370, 50, 260, 180, hWnd, NULL, NULL, NULL);
    SendMessage(hResInfoTitle, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bWeekly);

    HWND hAccTop = CreateWindowW(L"Static", L"          NAME          ||  AGE  ||          ADDRESS          ||     BARANGAY     ||     CONTACT NO.    ||     DISTRICT     ||   GENDER  ", WS_VISIBLE | WS_CHILD,
                  30 , 100, 800, 20, hWnd, (HMENU)TXTCOLOR_OPBUS, NULL, NULL);

    hAccEdit = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD|ES_MULTILINE,
                  30 , 130, 800, 270, hWnd, NULL, NULL, NULL);

    hBack = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
                  40, 410, 80, 25, hWnd, (HMENU)BUTTON_GOBACK, NULL, NULL);
    SendMessage(hBack, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bGoBack);
}
//--------------------------------------------------------------- ACCESS REPORT MONTHLY WIN PROC --------------------------------------------------
LRESULT CALLBACK WindowProcedureAccRepM(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp ){

	int mbVal;
	bool checked = false;


	switch(msg){
	    case WM_COMMAND:
		//rescan:

            switch(wp){
            	case FILE_MENU_ABOUT:              //about menu
 					MessageBoxW(hWnd, L"CCMSM \n\nby Robles, John Joe Rimuel P.", L"About Digital Budget Planner", MB_OK | MB_ICONINFORMATION);                break;
                case FILE_MENU_EXIT:               //program exit menu
                    mbVal = MessageBoxW(hWnd, L"Exit Program?", L"Exit", MB_YESNO | MB_ICONEXCLAMATION);
                    if (mbVal == IDYES)             //built in IDs for Message Boxes
                        DestroyWindow(hWnd);
                    else if (mbVal == IDNO)
                        break;
                case BUTTON_GOBACK:
                    ShowWindow(hAccRepWindow2, SW_SHOW);
                    ShowWindow(hAccRepWindowM, SW_HIDE);
                        break;
            }

        case WM_CTLCOLOREDIT:{

		    HDC hdc = (HDC)wp;
		    SetBkColor(hdc, RGB(232, 232, 232));
		    hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
		    if (hbrBkgnd == NULL)
            {
                hbrBkgnd = CreateSolidBrush(RGB(249, 235, 217));
            }
            return (INT_PTR)hbrBkgnd;
		}break;

		case WM_CTLCOLORSTATIC:{

            HDC hdcStatic = (HDC) wp;
            SetTextColor(hdcStatic, RGB(0, 0, 0));
            hbrBkgnd = CreateSolidBrush(RGB(249, 235, 217));
            SetBkMode(hdcStatic,TRANSPARENT);

            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS) == (HWND)lp || GetDlgItem(hWnd, TXTCOLOR_QRTN) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(0, 0, 0));
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
			}

			if (GetDlgItem(hWnd, TXTCOLOR_OPBUS2) == (HWND)lp || GetDlgItem(hWnd, TXTCOLOR_QRTN2) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(0, 0, 0));
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
			}

            if (GetDlgItem(hWnd, TXTCOLOR_OPBUS3) == (HWND)lp){
                SetTextColor(hdcStatic, RGB(0, 0, 0));
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
			}

            if (hbrBkgnd == NULL){
            	hbrBkgnd = CreateSolidBrush(RGB(255, 254, 254));
            }
            if ((HWND)lp == hDaily)
            {
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
            }
            if ((HWND)lp == hWeekly)
            {
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
            }
            if ((HWND)lp == hMonthly)
            {
                hbrBkgnd = CreateSolidBrush(RGB(232, 232, 232));
            }

            return (INT_PTR)hbrBkgnd;

        }break;
		case WM_CLOSE:
	        EnableWindow(hLoginWindow, TRUE);
	        DestroyWindow(hWnd);
	        break;
	    case WM_CREATE:{

	        AddMenus(hWnd);
	        loadImages();
            AddWinProcAccRepM(hWnd);
            open_fileM(hWnd);
	        } break;
	    default:
	        return DefWindowProcW(hWnd, msg, wp, lp);
	}
}
void display_fileM(char* path){

    FILE *file;
    file = fopen(path, "rb");
    fseek(file, 0, SEEK_END);
    int _size = ftell(file);
    rewind(file);

    char *data = new char[_size+1];
    fread(data, _size, 1, file);
    data[_size] = '\0';

    SetWindowText(hAccEdit, data);

}

void open_fileM( HWND hWnd){

    OPENFILENAME ofn;
    ZeroMemory(&ofn, sizeof(OPENFILENAME));

    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = hWnd;
    static char getD[100];
    GetWindowText(hDstore2,getD, 100);

    if(strcmp(getD, "DISTRICT I")==0){
        ofn.lpstrFile = "District I.txt";
    }
    if(strcmp(getD, "DISTRICT II")==0){
        ofn.lpstrFile = "District II.TXT";
    }
    if(strcmp(getD, "DISTRICT III")==0){
        ofn.lpstrFile = "District III.TXT";
    }
    if(strcmp(getD, "DISTRICT IV")==0){
        ofn.lpstrFile = "District IV.TXT";
    }
    if(strcmp(getD, "DISTRICT V")==0){
        ofn.lpstrFile = "District V.TXT";
    }
    if(strcmp(getD, "DISTRICT VI")==0){
        ofn.lpstrFile = "District VI.TXT";
    }
    GetOpenFileName(&ofn);
    display_fileM(ofn.lpstrFile);

}

void registerWindowProcedureAccRepM(HINSTANCE hInst){


	WNDCLASSW dialogAccRepM = {0};

    HBRUSH hb = ::CreateSolidBrush(RGB(249, 235, 217));

    dialogAccRepM.hbrBackground = hb;
    dialogAccRepM.hCursor = LoadCursor (NULL, IDC_CROSS);
    dialogAccRepM.hInstance = hInst;
    dialogAccRepM.lpszClassName = L"WindProcAccRepM";
    dialogAccRepM.lpfnWndProc = WindowProcedureAccRepM;

    RegisterClassW(&dialogAccRepM);

}

void displayWindowProcedureAccRepM(HWND hWnd){

    hAccRepWindowM = CreateWindowW(L"WindProcAccRepM", L"CCMSM", WS_VISIBLE | WS_MINIMIZEBOX | WS_SYSMENU,
                  200, 100, 870, 510, hWnd, NULL, NULL, NULL);

    EnableWindow(hWnd, TRUE);
}

void AddWinProcAccRepM(HWND hWnd){

    HFONT hFontInside = CreateFont (23, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
    OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
    DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    HFONT hFontInsideEdit = CreateFont (17, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
    OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
    DEFAULT_PITCH | FF_DONTCARE, TEXT("Open Sans"));

    hLogo = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                  30, 10, 190, 170, hWnd, NULL, NULL, NULL);
    SendMessage(hLogo, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bLogo);

    hResInfoTitle = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_BITMAP,
                  370, 50, 260, 180, hWnd, NULL, NULL, NULL);
    SendMessage(hResInfoTitle, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bMonthly);

    HWND hAccTop = CreateWindowW(L"Static", L"          NAME          ||  AGE  ||          ADDRESS          ||     BARANGAY     ||     CONTACT NO.    ||     DISTRICT     ||   GENDER  ", WS_VISIBLE | WS_CHILD,
                  30 , 100, 800, 20, hWnd, (HMENU)TXTCOLOR_OPBUS, NULL, NULL);

    hAccEdit = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD|ES_MULTILINE,
                  30 , 130, 800, 270, hWnd, NULL, NULL, NULL);

    hBack = CreateWindowW(L"Button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
                  40, 410, 80, 25, hWnd, (HMENU)BUTTON_GOBACK, NULL, NULL);
    SendMessage(hBack, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bGoBack);
}






