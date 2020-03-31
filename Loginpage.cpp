#include<windows.h>



LRESULT CALLBACK WindowProcedure(HWND,UINT,WPARAM,LPARAM);

void LoadImages();
void AddControls(HWND);
HWND hLogo;
HBITMAP hLogo200;



int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPreInst,LPSTR args,int ncmdshow){
    WNDCLASSW wc ={0};

    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL,IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"myWindowClass";
    wc.lpfnWndProc = WindowProcedure;

    if(!RegisterClassW(&wc)) return-1;
    

    CreateWindowW(L"myWindowClass",L"Log In Page",WS_OVERLAPPEDWINDOW | WS_VISIBLE,CW_USEDEFAULT,CW_USEDEFAULT,500,500,NULL,NULL,NULL,NULL);

    MSG msg = {0};

    while(GetMessage(&msg,NULL,NULL,NULL)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp){
    int val;
    switch(msg){
                
        case WM_CREATE:
            LoadImages();
            AddControls(hWnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProcW(hWnd,msg,wp,lp);
    }
}



void AddControls(HWND hWnd){
    hLogo = CreateWindowW(L"Static",NULL,WS_CHILD | WS_VISIBLE | SS_BITMAP,150,25,200,200,hWnd,NULL,NULL,NULL);
    SendMessageW(hLogo,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hLogo200);

    CreateWindowW(L"Static",L"username:",WS_VISIBLE | WS_CHILD | WS_BORDER,100,240,77,20,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL | WS_BORDER,182,240,200,20,hWnd,NULL,NULL,NULL);  

    CreateWindowW(L"Static",L"password:",WS_VISIBLE | WS_CHILD | WS_BORDER,100,265,77,20,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL | WS_BORDER | ES_PASSWORD,182,265,200,20,hWnd,NULL,NULL,NULL);
 
}

void LoadImages(){
    hLogo200 = (HBITMAP)LoadImageW(NULL,L"logo200X200Z.bmp",IMAGE_BITMAP,200,200,LR_LOADFROMFILE);

}





 