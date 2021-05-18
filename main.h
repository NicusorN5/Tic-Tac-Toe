#pragma once
#include <windows.h>

#define BUTTON1_EVENT_ID 150
#define BUTTON2_EVENT_ID 151

enum class CheckState : short
{
    Undefined=0,
    Player1 = 1,
    Player2 = 2,
};

enum class GameFinalState : short
{
    Running = 0,
    Finished = 1,
    Draw = 2,
};

INT WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd);

LRESULT CALLBACK WindowEvents(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

void SetButton(int id,int turn);

void SetButtonText(HWND hButton,int turn);

GameFinalState CheckWin();

CheckState ToggleCheckState(CheckState initialch,int turn);

void ResetGame();
