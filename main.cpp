#include "main.h"

HWND button1,button2,button3;
HWND button4,button5,button6;
HWND button7,button8,button9;

CheckState matrix[3][3];
int GameTurn = 0;

HWND MainWindow;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{

    WNDCLASS wndclass;
    memset(&wndclass,0,sizeof(wndclass));
    wndclass.hInstance = hInstance;
    wndclass.lpszClassName = "TicTacToeCLS";
    wndclass.lpfnWndProc = WindowEvents;

    RegisterClass(&wndclass);

    MainWindow = CreateWindow("TicTacToeCls","Tic Tac Toe",WS_OVERLAPPEDWINDOW,0,0,250,200,nullptr,nullptr,hInstance,nullptr);

    button1 = CreateWindow("Button","_",WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,10,10,20,20,MainWindow,(HMENU)BUTTON1_EVENT_ID,hInstance,nullptr);
    button2 = CreateWindow("Button","_",WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,40,10,20,20,MainWindow,(HMENU)BUTTON2_EVENT_ID,hInstance,nullptr);
    button3 = CreateWindow("Button","_",WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,70,10,20,20,MainWindow,(HMENU)BUTTON2_EVENT_ID,hInstance,nullptr);

    button4 = CreateWindow("Button","_",WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,10,40,20,20,MainWindow,(HMENU)BUTTON2_EVENT_ID,hInstance,nullptr);
    button5 = CreateWindow("Button","_",WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,40,40,20,20,MainWindow,(HMENU)BUTTON2_EVENT_ID,hInstance,nullptr);
    button6 = CreateWindow("Button","_",WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,70,40,20,20,MainWindow,(HMENU)BUTTON2_EVENT_ID,hInstance,nullptr);

    button7 = CreateWindow("Button","_",WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,10,70,20,20,MainWindow,(HMENU)BUTTON2_EVENT_ID,hInstance,nullptr);
    button8 = CreateWindow("Button","_",WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,40,70,20,20,MainWindow,(HMENU)BUTTON2_EVENT_ID,hInstance,nullptr);
    button9 = CreateWindow("Button","_",WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,70,70,20,20,MainWindow,(HMENU)BUTTON2_EVENT_ID,hInstance,nullptr);

    ShowWindow(MainWindow,1);

    MSG msg = {0};
    while(GetMessage(&msg,nullptr,0,0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

LRESULT CALLBACK WindowEvents(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_COMMAND:
        {
            switch(HIWORD(wParam))
            {
                case BN_CLICKED:
                {
                    if((HWND)lParam == button1)
                        SetButton(0,GameTurn);
                    else if((HWND)lParam == button2)
                        SetButton(1,GameTurn);
                    else if((HWND)lParam == button3)
                        SetButton(2,GameTurn);

                    else if((HWND)lParam == button4)
                        SetButton(3,GameTurn);
                    else if((HWND)lParam == button5)
                        SetButton(4,GameTurn);
                    else if((HWND)lParam == button6)
                        SetButton(5,GameTurn);

                    else if((HWND)lParam == button7)
                        SetButton(6,GameTurn);
                    else if((HWND)lParam == button8)
                        SetButton(7,GameTurn);
                    else if((HWND)lParam == button9)
                        SetButton(8,GameTurn);
                    break;
                }
                default: break;
            }
            break;
        }
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(MainWindow, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.
            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
            EndPaint(hwnd, &ps);
        }
        default: break;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void SetButton(int id,int turn)
{

    switch(id)
    {
        case 0:
        {
            if(matrix[0][0] == CheckState::Undefined) SetButtonText(button1,turn);
            matrix[0][0] = ToggleCheckState(matrix[0][0],turn);
            break;
        }
        case 1:
        {
            if(matrix[0][1] == CheckState::Undefined) SetButtonText(button2,turn);
            matrix[0][1] = ToggleCheckState(matrix[0][1],turn);
            break;
        }
        case 2:
        {
            if(matrix[0][2] == CheckState::Undefined) SetButtonText(button3,turn);
            matrix[0][2] = ToggleCheckState(matrix[0][2],turn);
            break;
        }

        case 3:
        {
            if(matrix[1][0] == CheckState::Undefined) SetButtonText(button4,turn);
            matrix[1][0] = ToggleCheckState(matrix[1][0],turn);
            break;
        }
        case 4:
        {
            if(matrix[1][1] == CheckState::Undefined) SetButtonText(button5,turn);
            matrix[1][1] = ToggleCheckState(matrix[1][1],turn);
            break;
        }
        case 5:
        {
            if(matrix[1][2] == CheckState::Undefined) SetButtonText(button6,turn);
            matrix[1][2] = ToggleCheckState(matrix[1][2],turn);
            break;
        }

        case 6:
        {
            if(matrix[2][0] == CheckState::Undefined) SetButtonText(button7,turn);
            matrix[2][0] = ToggleCheckState(matrix[2][0],turn);
            break;
        }
        case 7:
        {
            if(matrix[2][1] == CheckState::Undefined) SetButtonText(button8,turn);
            matrix[2][1] = ToggleCheckState(matrix[2][1],turn);
            break;
        }
        case 8:
        {
            if(matrix[2][2] == CheckState::Undefined) SetButtonText(button9,turn);
            matrix[2][2] = ToggleCheckState(matrix[2][2],turn);
            break;
        }
        default:break;
    }

    GameFinalState gameState = CheckWin();
    if(gameState == GameFinalState::Finished)
    {
        int m = GameTurn % 2;
        if(m % 2 == 0) MessageBox(MainWindow,"O a castigat!","Joc terminat!",MB_OK | MB_ICONINFORMATION);
        else MessageBox(MainWindow,"X a castigat!","Joc terminat!",MB_OK | MB_ICONINFORMATION);
        exit(0);
    }
    else if(gameState == GameFinalState::Draw)
    {
        int msg = MessageBox(MainWindow,"Whoops. Nu a castigat nimeni. Incerci  din nou?","Joc terminat!",MB_YESNO | MB_ICONWARNING);
        if(msg == IDYES)
        {
            ResetGame();
        }
        else exit(0);
    }
}

void SetButtonText(HWND hButton,int turn)
{
    int m = turn % 2;
    if(m == 0) SetWindowText(hButton,"X");
    else SetWindowText(hButton,"O");
}

GameFinalState CheckWin()
{
    CheckState m10 = matrix[0][0], m11 = matrix[0][1] ,m12 = matrix[0][2];
    CheckState m20 = matrix[1][0], m21 = matrix[1][1] ,m22 = matrix[1][2];
    CheckState m30 = matrix[2][0], m31 = matrix[2][1] ,m32 = matrix[2][2];

    // left to right
    if(m10 != CheckState::Undefined && m10 == m11 && m11 == m12)
        return GameFinalState::Finished;
    if(m20 != CheckState::Undefined && m20 == m21 && m21 == m22)
        return GameFinalState::Finished;
    if(m30 != CheckState::Undefined && m30 == m31 && m31 == m32)
        return GameFinalState::Finished;

    //downwards
    if(m10 != CheckState::Undefined && m10 == m20 && m20 == m30)
        return GameFinalState::Finished;
    if(m11 != CheckState::Undefined && m11 == m21 && m21 == m31)
        return GameFinalState::Finished;
    if(m12 != CheckState::Undefined && m12 == m22 && m22 == m32)
        return GameFinalState::Finished;

    if(m10 != CheckState::Undefined && m10 == m21 && m21 == m32)
        return GameFinalState::Finished;

    if(m12 != CheckState::Undefined && m12 == m21 && m21 == m30)
        return GameFinalState::Finished;

    bool f = true;
    for(int i =0 ; i < 3; i++)
    {
        for(int j =0 ; j < 3;j++)
        {
            if(matrix[i][j] == CheckState::Undefined) f = false;
        }
    }
    if(f) return GameFinalState::Draw;

    return GameFinalState::Running;
}

CheckState ToggleCheckState(CheckState initialch,int turn)
{
    if(initialch == CheckState::Undefined)
    {
        GameTurn++;
        int m = turn %2;
        if(m == 0) return CheckState::Player1;
        else return CheckState::Player2;
    }
    return initialch;
}

void ResetGame()
{
    for(int i =0 ; i < 3 ;i++)
    {
        for(int j =0 ; j < 3; j++)
        {
            matrix[i][j] = CheckState::Undefined;
        }
    }
    SetWindowText(button1,"_");
    SetWindowText(button2,"_");
    SetWindowText(button3,"_");

    SetWindowText(button4,"_");
    SetWindowText(button5,"_");
    SetWindowText(button6,"_");

    SetWindowText(button7,"_");
    SetWindowText(button8,"_");
    SetWindowText(button9,"_");
}
