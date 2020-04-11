#include<windows.h>


#define LOG_IN 1
#define SIGN_UP 2
#define LOG_OUT 3
LRESULT CALLBACK WindowProcedure(HWND,UINT,WPARAM,LPARAM);

void LoadImgLog();
void LoginPage(HWND);
void RegisterPage(HWND);
void LoadImgRe();
void PatientPage(HWND);
void LoadImgPa();
void DoctorPage(HWND);
void LoadImgDoc();
HWND hLogF,hTop;
HBITMAP hLoBg,hLog,hLogIcon,hReBg,hSi,hPaProM,hPaBg,hPaClick,hPaLogout,hDocBg,hDocPro;
HFONT hFont;


BOOL CALLBACK DestoryChildCallback(HWND,LPARAM);

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPreInst,LPSTR args,int ncmdshow){
    WNDCLASSW wc ={0};

    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL,IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"myWindowClass";
    wc.lpfnWndProc = WindowProcedure;

    if(!RegisterClassW(&wc)) return-1;
    

    CreateWindowW(L"myWindowClass",L"Post Operative Care",WS_VISIBLE | WS_SYSMENU,CW_USEDEFAULT,CW_USEDEFAULT,1280,720,NULL,NULL,NULL,NULL);

    MSG msg = {0};

    while(GetMessage(&msg,NULL,NULL,NULL)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp){
    switch(msg){
        case WM_COMMAND:
            switch(wp){
                case LOG_IN:
                    EnumChildWindows(hWnd,DestoryChildCallback, NULL);
                    LoadImgRe();     
                    RegisterPage(hWnd);   
                    break; 
                case SIGN_UP: //Now use for test patient page
                    EnumChildWindows(hWnd,DestoryChildCallback, NULL);
                    LoadImgPa();
                    PatientPage(hWnd);
                    break;
                    case LOG_OUT:
                    EnumChildWindows(hWnd,DestoryChildCallback, NULL);
                    LoadImgDoc();
                    DoctorPage(hWnd);
                    break;
            }
            break;       
        case WM_CREATE:
            LoadImgLog();
            LoginPage(hWnd);            
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProcW(hWnd,msg,wp,lp);
    }
}



void LoginPage(HWND hWnd){
    HWND hBg = CreateWindowW(L"Static",NULL,WS_CHILD | WS_VISIBLE | SS_BITMAP,0,0,1280,720,hWnd,NULL,NULL,NULL);
    SendMessageW(hBg,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hLoBg);

    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL | WS_BORDER,340,317,257,20,hWnd,NULL,NULL,NULL);  

    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL | WS_BORDER | ES_PASSWORD,340,380,257,20,hWnd,NULL,NULL,NULL);

    HWND hLogBut = CreateWindowW(L"Button",NULL,WS_VISIBLE | WS_CHILD | BS_BITMAP,400,479,100,42,hWnd,(HMENU)LOG_IN,NULL,NULL);
    SendMessageW(hLogBut,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hLog);

 
}

void LoadImgLog(){ //loadimage for login page
    hLog = (HBITMAP)LoadImageW(NULL,L"LoginPage\\Log In.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    hLoBg = (HBITMAP)LoadImageW(NULL,L"LoginPage\\02.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
   
}

void RegisterPage(HWND hWnd){
    HWND hRe = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP,0,0,1280,720,hWnd,NULL,NULL,NULL);
    SendMessageW(hRe,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hReBg);

    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL | WS_BORDER,568,203,250,25,hWnd,NULL,NULL,NULL); //Edit for Firstname
    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL | WS_BORDER,568,285,145,25,hWnd,NULL,NULL,NULL); //Edit for Day
    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL | WS_BORDER,568,366,145,25,hWnd,NULL,NULL,NULL); //Edit for Weight
    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL | WS_BORDER,764,285,145,25,hWnd,NULL,NULL,NULL); //Edit for Month
    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL | WS_BORDER,764,366,145,25,hWnd,NULL,NULL,NULL); //Edit for Height
    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL | WS_BORDER,860,203,250,25,hWnd,NULL,NULL,NULL); //Edit for Lastname
    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL | WS_BORDER,965,285,145,25,hWnd,NULL,NULL,NULL); //Edit for Year
    HWND hGen = CreateWindowW(L"Combobox",L"",WS_VISIBLE | WS_CHILD | CBS_DROPDOWN | WS_OVERLAPPED | CBS_HASSTRINGS ,965,366,145,100,hWnd,NULL,NULL,NULL); //Combobox for Gender
    SendMessageW(hGen,CB_ADDSTRING,0,(LPARAM)L"Man");
    SendMessageW(hGen,CB_ADDSTRING,0,(LPARAM)L"Woman");

    hTop = CreateWindowW(L"Combobox",L"",CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,568,449,222,50,hWnd,NULL,NULL,NULL); //Combobox for Type of Patient
    SendMessageW(hTop,CB_ADDSTRING,0,(LPARAM)L"item1");

    HWND hSign = CreateWindowW(L"Button",NULL,WS_VISIBLE | WS_CHILD | BS_BITMAP,740,549,205,43,hWnd,(HMENU)SIGN_UP,NULL,NULL);
    SendMessageW(hSign,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hSi);

}
void LoadImgRe(){ //loadimage for register page
    hReBg = (HBITMAP)LoadImageW(NULL,L"RegisterPage\\ReBg.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    hSi = (HBITMAP)LoadImageW(NULL,L"RegisterPage\\button_registerpage.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    
}
BOOL CALLBACK DestoryChildCallback(
  HWND   hwnd,
  LPARAM lParam
)
{
  if (hwnd != NULL) {
    DestroyWindow(hwnd);
  }

  return TRUE;
}

void PatientPage(HWND hWnd){ 
    HWND hPro = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP,129,68,247,247,hWnd,NULL,NULL,NULL);
    SendMessageW(hPro,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hPaProM);

    HWND hPa = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP,0,0,1280,720,hWnd,NULL,NULL,NULL);
    SendMessageW(hPa,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hPaBg);

    HWND hDietbut = CreateWindowW(L"Button",NULL,WS_VISIBLE | WS_CHILD | BS_BITMAP | BS_FLAT,987,93,146,24,hWnd,NULL,NULL,NULL); //button for diet menu
    SendMessageW(hDietbut,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hPaClick);
    HWND hProbut = CreateWindowW(L"Button",NULL,WS_VISIBLE | WS_CHILD | BS_BITMAP | BS_FLAT,987,138,146,24,hWnd,NULL,NULL,NULL); //button for Proni menu
    SendMessageW(hProbut,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hPaClick);
    HWND hWoubut = CreateWindowW(L"Button",NULL,WS_VISIBLE | WS_CHILD | BS_BITMAP | BS_FLAT,987,183,146,24,hWnd,NULL,NULL,NULL); //button for Wound menu
    SendMessageW(hWoubut,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hPaClick);
    HWND hActbut = CreateWindowW(L"Button",NULL,WS_VISIBLE | WS_CHILD | BS_BITMAP | BS_FLAT,987,228,146,24,hWnd,NULL,NULL,NULL); //button for Activity menu
    SendMessageW(hActbut,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hPaClick);

    HWND hLogout = CreateWindowW(L"Button",NULL,WS_VISIBLE | WS_CHILD | BS_BITMAP,76,631,112,35,hWnd,(HMENU)LOG_OUT,NULL,NULL);
    SendMessageW(hLogout,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hPaLogout);
}

void LoadImgPa(){ //Loadimage for patient page
    hPaProM = (HBITMAP)LoadImageW(NULL,L"PatientPage\\male.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);//male profile pic
    hPaBg = (HBITMAP)LoadImageW(NULL,L"PatientPage\\patient oage.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);//Background

    hPaClick = (HBITMAP)LoadImageW(NULL,L"PatientPage\\button click.bmp",IMAGE_BITMAP,146,24,LR_LOADFROMFILE);

    hPaLogout = (HBITMAP)LoadImageW(NULL,L"PatientPage\\logout.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    
}

void DoctorPage(HWND hWnd){
    HWND hPro = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP,129,68,247,247,hWnd,NULL,NULL,NULL);
    SendMessageW(hPro,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hDocPro);
    
    HWND hDoc = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP,0,0,1280,720,hWnd,NULL,NULL,NULL);
    SendMessageW(hDoc,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hDocBg);
}

void LoadImgDoc(){
    hDocBg = (HBITMAP)LoadImageW(NULL,L"DoctorPage\\wallpaper.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);

    hDocPro = (HBITMAP)LoadImageW(NULL,L"DoctorPage\\man.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);

}
 