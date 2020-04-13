#include <windows.h>
#include "ho.h"

#define LOG_IN 1
#define SIGN_UP 2
#define LOG_OUT 3
#define REGISTER 4
#define BACK_TOMENU 5
#define DIET 6
#define ACTIVITY 7
#define PROHIBIT 8
#define WOUND 9
LRESULT CALLBACK WindowProcedure(HWND,UINT,WPARAM,LPARAM);

void LoadImgLogin();
void LoginPage(HWND);
void RegisterDialog(HWND);
void RegisterPage(HWND);
void LoadImgRe();
void PatientPage(HWND);
void LoadImgPa();
void DoctorPage(HWND);
void LoadImgDoc();
//void displayFile(char*,HWND);
HWND hTop,hUser,hPass,hReFn,hReLn,hReDay,hReMont,hReYear,hWei,hHeig,hGen,hReUsn,hRePass,hReConPass;
HWND hDietbut,hProbut,hWoubut,hActbut;//openfile but
HBITMAP hLogBg,hLogin,hReBg,hSi,hBa,hPaProM,hPaBg,hPaDiet,hPaPro,hPaWou,hPaActi,hPaLogout,hDocBg,hDocPro,hDocRe;
HFONT hFont;
char type,user[20],Illness[20];
string opLogin,gender;
int id;



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
                    char username[20],pass[20];
                    GetWindowText(hUser,username,20);
                    GetWindowText(hPass,pass,20);
                    if(login_page(username,pass) == "false"){
                        MessageBoxW(hWnd,L"USERNAME OR PASSWORD WRONG PLEASE ENTER AGAIN",L"ERROR",MB_OK | MB_ICONEXCLAMATION);
                    }else{
                        opLogin = login_page(username,pass);
                        sscanf(opLogin.c_str(),"%s %c",&user,&type);
                        cout << type;
                        if(type == 'D'){
                            EnumChildWindows(hWnd,DestoryChildCallback, NULL);
                            id=find_Sequence(username);
                            LoadImgDoc();     
                            DoctorPage(hWnd);
                        }else if(type == 'P'){
                            EnumChildWindows(hWnd,DestoryChildCallback, NULL);
                            id=find_Sequence(username);
                            LoadImgPa();
                            PatientPage(hWnd); 
                        }
                    }
                    break; 
                case SIGN_UP: 
                    char Gender[10],Firstname[10],Lastname[10],Day[3],Month[3],Year[5],Weight[3],Height[4],usn[20],ps[20],cps[20];
                    GetWindowText(hGen,Gender,10);
                    GetWindowText(hTop,Illness,20);
                    GetWindowText(hReFn,Firstname,10);
                    GetWindowText(hReLn,Lastname,10);
                    GetWindowText(hReDay,Day,3);
                    GetWindowText(hReMont,Month,3);
                    GetWindowText(hReYear,Year,5);
                    GetWindowText(hWei,Weight,3);
                    GetWindowText(hHeig,Height,4);
                    GetWindowText(hReUsn,usn,20);
                    GetWindowText(hRePass,ps,20);
                    GetWindowText(hReConPass,cps,20);

                    if(strcmp(Gender,"") == 0 || strcmp(Illness,"") == 0 || strcmp(Firstname,"") == 0 || strcmp(Lastname,"") == 0 || strcmp(Day,"") == 0 || strcmp(Month,"") == 0 || strcmp(Year,"") == 0 || strcmp(Weight,"") == 0 || strcmp(Height,"") == 0){
                        MessageBoxW(hWnd,L"Please Input All Patient Detail",L"Error",MB_OK | MB_ICONEXCLAMATION);
                    }else{

                        if(pdata_base(Gender,Illness,Firstname,Lastname,Day,Month,Year,Weight,Height) == 10){
                            MessageBoxW(hWnd,L"You can only input alpha here!",L"Error",MB_OK | MB_ICONEXCLAMATION);
                        }else if(pdata_base(Gender,Illness,Firstname,Lastname,Day,Month,Year,Weight,Height) == 11){
                            MessageBoxW(hWnd,L"This Patient has already Registred.",L"Error",MB_OK | MB_ICONEXCLAMATION);
                        }else if(pdata_base(Gender,Illness,Firstname,Lastname,Day,Month,Year,Weight,Height) == 12){
                            MessageBoxW(hWnd,L"Please Check your patient Weight !!",L"Error",MB_OK | MB_ICONEXCLAMATION);
                        }else if(pdata_base(Gender,Illness,Firstname,Lastname,Day,Month,Year,Weight,Height) == 13){
                            MessageBoxW(hWnd,L"Please Check your patient Height !!",L"Error",MB_OK | MB_ICONEXCLAMATION);
                        }else if(pdata_base(Gender,Illness,Firstname,Lastname,Day,Month,Year,Weight,Height) == 14){
                            MessageBoxW(hWnd,L"Please Input Day between 1-31 !",L"Error",MB_OK | MB_ICONEXCLAMATION);
                        }else if(pdata_base(Gender,Illness,Firstname,Lastname,Day,Month,Year,Weight,Height) == 15){
                            MessageBoxW(hWnd,L"Please Input Day between 1-29 !",L"Error",MB_OK | MB_ICONEXCLAMATION);
                        }else if(pdata_base(Gender,Illness,Firstname,Lastname,Day,Month,Year,Weight,Height) == 16){
                            MessageBoxW(hWnd,L"Please Input Day between 1-30 !",L"Error",MB_OK | MB_ICONEXCLAMATION);
                        }else if(pdata_base(Gender,Illness,Firstname,Lastname,Day,Month,Year,Weight,Height) == 17){
                            MessageBoxW(hWnd,L"Please Check  Years !",L"Error",MB_OK | MB_ICONEXCLAMATION);
                        }else if(!register_page(usn,ps,cps)){
                            MessageBoxW(hWnd,L"Your Password Not Match",L"Error",MB_OK | MB_ICONEXCLAMATION);
                        }else{
                            writeData(Firstname,Lastname,Day,Month,Year,Height,Weight,Gender,Illness,id);
                            EnumChildWindows(hWnd,DestoryChildCallback, NULL);
                            LoadImgDoc();     
                            DoctorPage(hWnd);
                        }
                    }
                    
                    break;
                case LOG_OUT:
                    EnumChildWindows(hWnd,DestoryChildCallback, NULL);
                    LoadImgLogin();
                    LoginPage(hWnd);
                    break;
                case REGISTER:
                    EnumChildWindows(hWnd,DestoryChildCallback, NULL);
                    LoadImgRe();
                    RegisterPage(hWnd);
                    break;
                case BACK_TOMENU:
                    EnumChildWindows(hWnd,DestoryChildCallback, NULL);
                    LoadImgDoc();     
                    DoctorPage(hWnd);
                    break;
                case DIET:
                    
                    if(strcmp(Illness,"Abdominal") == 0)){
                        MessageBoxW(hWnd,L"No Data Found",L"Sorry",MB_OK);
                    }else if(strcmp(Illness,"Cesarean"){
                        char directory[] = "database//postoperative_data//Cesarean//diet.txt";
                        displayFile(directory,hDietbut);
                    }else if(strcmp(Illness,"Eye") ==0 ){
                        MessageBoxW(hWnd,L"No Data Found",L"Sorry",MB_OK);
                    }else if(strcmp(Illness,"Eye") == 0){
                       char directory[] = "database//postoperative_data//Gynecologic//diet.txt";
                        displayFile(directory);
                    }else if(strcmp(Illness,"Hernia" == 0){
                        MessageBoxW(hWnd,L"No Data Found",L"Sorry",MB_OK);
                    }else if(strcmp(Illness,"Hip Replacement" == 0){
                        char directory[] = "database//postoperative_data//Hip Replacement//diet.txt";
                        displayFile(directory);
                    }else if(strcmp(Illness,"Spine" == 0){
                        MessageBoxW(hWnd,L"No Data Found",L"Sorry",MB_OK);
                    }
                    
                    break;
                case ACTIVITY:
                    /*char directory[30];
                    if(strcmp(Illness,"Abdominal") == 0)){
                        directory = 'database//postoperative_data//Cesarean//Abdominal.txt';
                        displayFile(directory);
                    }else if(strcmp(Illness,"Cesarean"){
                        directory = 'database//postoperative_data//Cesarean//diet.txt';
                        displayFile(directory);
                    }else if(strcmp(Illness,"Eye") ==0 ){
                        MessageBoxW(hWnd,L"No Data Found",L"Sorry",MB_OK);
                    }else if(strcmp(Illness,"Eye") == 0){
                        directory = 'database//postoperative_data//Gynecologic//diet.txt';
                        displayFile(directory);
                    }else if(strcmp(Illness,"Hernia" == 0){
                        MessageBoxW(hWnd,L"No Data Found",L"Sorry",MB_OK);
                    }else if(strcmp(Illness,"Hip Replacement" == 0){
                        directory = 'database//postoperative_data//Hip Replacement//diet.txt';
                        displayFile(directory);
                    }else if(strcmp(Illness,"Spine" == 0){
                        MessageBoxW(hWnd,L"No Data Found",L"Sorry",MB_OK);
                    }
                    */
                    break;
                case WOUND:
                    /*char directory[30];
                    if(strcmp(Illness,"Abdominal") == 0)){
                        MessageBoxW(hWnd,L"No Data Found",L"Sorry",MB_OK);
                    }else if(strcmp(Illness,"Cesarean"){
                        directory = 'database//postoperative_data//Cesarean//diet.txt';
                        displayFile(directory);
                    }else if(strcmp(Illness,"Eye") ==0 ){
                        MessageBoxW(hWnd,L"No Data Found",L"Sorry",MB_OK);
                    }else if(strcmp(Illness,"Eye") == 0){
                        directory = 'database//postoperative_data//Gynecologic//diet.txt';
                        displayFile(directory);
                    }else if(strcmp(Illness,"Hernia" == 0){
                        MessageBoxW(hWnd,L"No Data Found",L"Sorry",MB_OK);
                    }else if(strcmp(Illness,"Hip Replacement" == 0){
                        directory = 'database//postoperative_data//Hip Replacement//diet.txt';
                        displayFile(directory);
                    }else if(strcmp(Illness,"Spine" == 0){
                        MessageBoxW(hWnd,L"No Data Found",L"Sorry",MB_OK);
                    }
                    */
                    break;
                case PROHIBIT:
                    /*char directory[30];
                    if(strcmp(Illness,"Abdominal") == 0)){
                        MessageBoxW(hWnd,L"No Data Found",L"Sorry",MB_OK);
                    }else if(strcmp(Illness,"Cesarean"){
                        directory = 'database//postoperative_data//Cesarean//diet.txt';
                        displayFile(directory);
                    }else if(strcmp(Illness,"Eye") ==0 ){
                        MessageBoxW(hWnd,L"No Data Found",L"Sorry",MB_OK);
                    }else if(strcmp(Illness,"Eye") == 0){
                        directory = 'database//postoperative_data//Gynecologic//diet.txt';
                        displayFile(directory);
                    }else if(strcmp(Illness,"Hernia" == 0){
                        MessageBoxW(hWnd,L"No Data Found",L"Sorry",MB_OK);
                    }else if(strcmp(Illness,"Hip Replacement" == 0){
                        directory = 'database//postoperative_data//Hip Replacement//diet.txt';
                        displayFile(directory);
                    }else if(strcmp(Illness,"Spine" == 0){
                        MessageBoxW(hWnd,L"No Data Found",L"Sorry",MB_OK);
                    }
                    */
                    break;
            }
            break;       
        case WM_CREATE:
            LoadImgLogin();
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
    HWND hLog = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP,0,0,1280,720,hWnd,NULL,NULL,NULL);
    SendMessageW(hLog,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hLogBg);

    //CreateWindowW(L"Static",L"Username:",WS_VISIBLE | WS_CHILD,340,297,100,20,hWnd,NULL,NULL,NULL);
    hUser = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL | WS_BORDER,340,319,257,25,hWnd,NULL,NULL,NULL);//Edit for username
    //CreateWindowW(L"Static",L"Password:",WS_VISIBLE | WS_CHILD,340,360,100,20,hWnd,NULL,NULL,NULL);
    hPass = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL | WS_BORDER | ES_PASSWORD,340,382,257,25,hWnd,NULL,NULL,NULL);//Edit for password
    
    HWND hLogBut = CreateWindowW(L"Button",NULL,WS_VISIBLE | WS_CHILD | BS_BITMAP,400,479,101,45,hWnd,(HMENU)LOG_IN,NULL,NULL);
    SendMessageW(hLogBut,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hLogin);
 
}

void LoadImgLogin(){ //loadimage for login page
    hLogBg =(HBITMAP)LoadImageW(NULL,L"LoginPage\\LoginPage.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    
    hLogin = (HBITMAP)LoadImageW(NULL,L"LoginPage\\Log In.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
}


void RegisterPage(HWND hWnd){
    HWND hRe = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP,0,0,1280,720,hWnd,NULL,NULL,NULL);
    SendMessageW(hRe,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hReBg);

    hReFn = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL | WS_BORDER,568,203,250,25,hWnd,NULL,NULL,NULL); //Edit for Firstname
    hReDay = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL | WS_BORDER | ES_NUMBER,568,285,145,25,hWnd,NULL,NULL,NULL); //Edit for Day
    hWei = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL | WS_BORDER | ES_NUMBER,568,366,145,25,hWnd,NULL,NULL,NULL); //Edit for Weight
    hReMont = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL | WS_BORDER | ES_NUMBER,764,285,145,25,hWnd,NULL,NULL,NULL); //Edit for Month
    hHeig = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL | WS_BORDER | ES_NUMBER,764,366,145,25,hWnd,NULL,NULL,NULL); //Edit for Height
    hReLn = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL | WS_BORDER,860,203,250,25,hWnd,NULL,NULL,NULL); //Edit for Lastname
    hReYear = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL | WS_BORDER | ES_NUMBER,965,285,145,25,hWnd,NULL,NULL,NULL); //Edit for Year
    hGen = CreateWindowW(L"Combobox",NULL,WS_VISIBLE | WS_CHILD | CBS_DROPDOWN | WS_OVERLAPPED | CBS_HASSTRINGS,965,366,145,100,hWnd,NULL,NULL,NULL); //Combobox for Gender
    SendMessageW(hGen,CB_ADDSTRING,0,(LPARAM)L"Man");
    SendMessageW(hGen,CB_ADDSTRING,0,(LPARAM)L"Woman");

    //SendMessageW(hGen,CB_SETCURSEL,2,0);

    hTop = CreateWindowW(L"Combobox",L"",CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,568,449,145,350,hWnd,NULL,NULL,NULL); //Combobox for Type of Patient
    SendMessageW(hTop,CB_ADDSTRING,0,(LPARAM)L"Abdominal");
    SendMessageW(hTop,CB_ADDSTRING,0,(LPARAM)L"Cesarean");
    SendMessageW(hTop,CB_ADDSTRING,0,(LPARAM)L"Eye");
    SendMessageW(hTop,CB_ADDSTRING,0,(LPARAM)L"Glynecologic");
    SendMessageW(hTop,CB_ADDSTRING,0,(LPARAM)L"Hernia");
    SendMessageW(hTop,CB_ADDSTRING,0,(LPARAM)L"Hip Replacement");
    SendMessageW(hTop,CB_ADDSTRING,0,(LPARAM)L"Spine");

    hReUsn = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL | WS_BORDER,570,526,145,25,hWnd,NULL,NULL,NULL);
    hRePass = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL | WS_BORDER,766,526,145,25,hWnd,NULL,NULL,NULL);
    hReConPass = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL | WS_BORDER,967,526,145,25,hWnd,NULL,NULL,NULL);

    HWND hSign = CreateWindowW(L"Button",NULL,WS_VISIBLE | WS_CHILD | BS_BITMAP,725,588,205,43,hWnd,(HMENU)SIGN_UP,NULL,NULL);
    SendMessageW(hSign,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hSi);

    HWND hBack = CreateWindowW(L"Button",NULL,WS_VISIBLE | WS_CHILD | BS_BITMAP | BS_FLAT,458,51,119,26,hWnd,(HMENU)BACK_TOMENU,NULL,NULL);
    SendMessageW(hBack,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBa);

}
void LoadImgRe(){ //loadimage for register page
    hReBg = (HBITMAP)LoadImageW(NULL,L"RegisterPage\\repatient.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    hSi = (HBITMAP)LoadImageW(NULL,L"RegisterPage\\button_registerpage.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    hBa = (HBITMAP)LoadImageW(NULL,L"RegisterPage\\back to home.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
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
    
    HWND hPro = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP,200,84,247,247,hWnd,NULL,NULL,NULL); // profile pic -16
    SendMessageW(hPro,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hPaProM);

    HWND hPa = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP,0,0,1280,720,hWnd,NULL,NULL,NULL);
    SendMessageW(hPa,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hPaBg);

    hDietbut = CreateWindowW(L"Button",NULL,WS_VISIBLE | WS_CHILD | BS_BITMAP,91,332,200,30,hWnd,(HMENU)DIET,NULL,NULL); //button for diet menu
    SendMessageW(hDietbut,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hPaDiet);
    hProbut = CreateWindowW(L"Button",NULL,WS_VISIBLE | WS_CHILD | BS_BITMAP,91,377,200,30,hWnd,(HMENU)PROHIBIT,NULL,NULL); //button for Proni menu
    SendMessageW(hProbut,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hPaPro);
    hWoubut = CreateWindowW(L"Button",NULL,WS_VISIBLE | WS_CHILD | BS_BITMAP,91,422,200,30,hWnd,(HMENU)WOUND,NULL,NULL); //button for Wound menu
    SendMessageW(hWoubut,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hPaWou);
    hActbut = CreateWindowW(L"Button",NULL,WS_VISIBLE | WS_CHILD | BS_BITMAP,91,467,200,30,hWnd,(HMENU)ACTIVITY,NULL,NULL); //button for Activity menu
    SendMessageW(hActbut,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hPaActi);
    string sfname,slname,sAge,sWeight,sHeight,sDate,sIllness;
    char fname[20],lname[20],Age[3],Weight[4],Height[4],Date[10],Fullname[50];  
    sfname = SDataDB(id,'N');
    slname = SDataDB(id,'L');
    sDate = SDataDB(id,'D');
    sAge = SDataDB(id,'A');
    sHeight = SDataDB(id,'H');
    sWeight = SDataDB(id,'W');
    sIllness = SDataDB(id,'I');

    strcpy(fname,sfname.c_str());
    strcpy(lname,slname.c_str());
    strcpy(Age,sAge.c_str());
    strcpy(Weight,sWeight.c_str());
    strcpy(Height,sHeight.c_str());
    strcpy(Date,sDate.c_str());
    strcpy(Illness,sIllness.c_str());

    strcat(Fullname,fname);
    strcat(Fullname,"  ");
    strcat(Fullname,lname);

    HWND hPaName = CreateWindowW(L"Static",L"", WS_GROUP |WS_VISIBLE | WS_CHILD,466,115,150,15,hWnd,NULL,NULL,NULL);//name
    SetWindowText(hPaName,Fullname);

    HWND hPaDate = CreateWindowW(L"Static",L"",WS_VISIBLE | WS_CHILD | ES_READONLY,859,112,90,15,hWnd,NULL,NULL,NULL);//date
    SetWindowText(hPaDate,Date);

    HWND hPaAge = CreateWindowW(L"Static",L"",WS_VISIBLE | WS_CHILD | ES_READONLY,779,138,25,15,hWnd,NULL,NULL,NULL);//age
    SetWindowText(hPaAge,Age);
    
    HWND hPaHeight = CreateWindowW(L"Static",L"",WS_VISIBLE | WS_CHILD | ES_READONLY,804,168,35,15,hWnd,NULL,NULL,NULL);//height
    SetWindowText(hPaHeight,Height);

    HWND hPaWeight = CreateWindowW(L"Static",L"",WS_VISIBLE | WS_CHILD | ES_READONLY,808,195,35,15,hWnd,NULL,NULL,NULL);//weight
    SetWindowText(hPaWeight,Weight);


    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | ES_MULTILINE | WS_VSCROLL | WS_HSCROLL |  ES_READONLY,344,287,842,363,hWnd,NULL,NULL,NULL);

    HWND hLogout = CreateWindowW(L"Button",NULL,WS_VISIBLE | WS_CHILD | BS_BITMAP,408,193,70,20,hWnd,(HMENU)LOG_OUT,NULL,NULL);
    SendMessageW(hLogout,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hPaLogout);
}

void LoadImgPa(){ //Loadimage for patient page
    gender = SDataDB(id,'G');
    if(gender == "Man"){
        hPaProM = (HBITMAP)LoadImageW(NULL,L"PatientPage\\male.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    }else{
        hPaProM = (HBITMAP)LoadImageW(NULL,L"PatientPage\\female.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    }
    //male profile pic
    hPaBg = (HBITMAP)LoadImageW(NULL,L"PatientPage\\patient oage.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);//Background

    hPaActi = (HBITMAP)LoadImageW(NULL,L"PatientPage\\Activity.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    hPaDiet = (HBITMAP)LoadImageW(NULL,L"PatientPage\\diet.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    hPaWou = (HBITMAP)LoadImageW(NULL,L"PatientPage\\wound care.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    hPaPro = (HBITMAP)LoadImageW(NULL,L"PatientPage\\Prohibit.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);

    hPaLogout = (HBITMAP)LoadImageW(NULL,L"PatientPage\\logout.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    
}

void DoctorPage(HWND hWnd){
    HWND hPro = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP,202,246,106,105,hWnd,NULL,NULL,NULL);
    SendMessageW(hPro,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hDocPro);
    
    HWND hDoc = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP,0,0,1280,720,hWnd,NULL,NULL,NULL);
    SendMessageW(hDoc,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hDocBg);

    HWND hRegisbut = CreateWindowW(L"Button",NULL,WS_VISIBLE | WS_CHILD | BS_BITMAP | BS_FLAT,148,481,210,45,hWnd,(HMENU)REGISTER,NULL,NULL); //button for reister menu
    SendMessageW(hRegisbut,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hDocRe);
    
    HWND hLogout = CreateWindowW(L"Button",NULL,WS_VISIBLE | WS_CHILD | BS_BITMAP,210,559,90,32,hWnd,(HMENU)LOG_OUT,NULL,NULL);
    SendMessageW(hLogout,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hPaLogout);
    string sfname,slname;
    char fname[15],lname[15],Fullname[30]={};
    sfname = SDataDB(id,'N');
    slname = SDataDB(id,'L');
    
    strcpy(fname,sfname.c_str());
    strcpy(lname,slname.c_str());
    strcat(Fullname,"Dr.");
    strcat(Fullname,fname);
    strcat(Fullname,"  ");
    strcat(Fullname,lname);

    HWND DrName = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_CENTER,126,381,250,20,hWnd,NULL,NULL,NULL);
    SetWindowText(DrName,Fullname);

    HWND hEdit = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | ES_MULTILINE | WS_VSCROLL | WS_HSCROLL |  ES_READONLY,450,87,731,565,hWnd,NULL,NULL,NULL);
}

void LoadImgDoc(){
    gender = SDataDB(id,'G');
    if(gender == "Man"){
        hDocPro = (HBITMAP)LoadImageW(NULL,L"DoctorPage\\doc_male.bmp",IMAGE_BITMAP,106,105,LR_LOADFROMFILE); //male profile pic
    }else{
        hDocPro = (HBITMAP)LoadImageW(NULL,L"DoctorPage\\doc_female.bmp",IMAGE_BITMAP,106,105,LR_LOADFROMFILE); //male profile pic
    }
    hDocBg = (HBITMAP)LoadImageW(NULL,L"DoctorPage\\Doctor_page.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);

    

    hDocRe = (HBITMAP)LoadImageW(NULL,L"DoctorPage\\register_button.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);

    hPaLogout = (HBITMAP)LoadImageW(NULL,L"DoctorPage\\LogOut_button.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    

}
 
/*void displayFile(char *path,HWND hWnd){
	FILE *file;
	file = fopen(path,"rb");
	fseek(file,0,SEEK_END);
	int _size = ftell(file);
	rewind(file);
	char *data = new char(_size+1);
	fread(data,_size,1,file);
	data[_size] = '\0';
	
	SetWindowText(hWnd,data);
}*/