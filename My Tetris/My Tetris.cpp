// My Tetris.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "My Tetris.h"

#define MAX_LOADSTRING 100

#define TIMER_SPEED 1

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_MYTETRIS, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MYTETRIS));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDM_RAY));
	wcex.hCursor		= LoadCursor(hInstance,IDC_SIZEALL);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_MYTETRIS);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable
   
   hWnd = CreateWindow(							/*Éú³É´°¿Ú*/////////setting....../////
	   szWindowClass,
	   szTitle,      
	   (WS_OVERLAPPED     | \
        WS_CAPTION        | \
        WS_SYSMENU        | \
        !WS_THICKFRAME     | \
        !WS_MINIMIZEBOX    | \
        !WS_MAXIMIZEBOX)

	   , 0, 0, 20*Width,
	   23*Width, NULL, NULL, hInstance, NULL);



   //WS_OVERLAPPEDWINDOW 
	if (!hWnd)
	{
		return FALSE;
	}
	ShowWindow(hWnd, nCmdShow);

   
	SetWindowPos(hWnd,hWnd,0,0,720,680,0);

	//UpdateWindow(hWnd);

   return TRUE;
}



//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//start:
	// TODO: Place code here.
		int wmId, wmEvent;
	static int sign=0;				//for stop ----key enter	
	int i=0;					//record disapperred lines and common use
	int rayl=0,rayc=0;				//temp int for common use
	//static int ray=0;
	//static int shaw=0;
			//saved*************************
	static POINT apt[14];			//0-7 point for paint tetris	//8-11 for record		//12 for regional point		//13 for color
	static POINT point[14]={0};		//function same with apt /* sign for the next tetris
	static int flag[14][23]={0};	//record painted tetris
	
	static int score=0;				// record score
	static int rand1=0;			
	static int rand2=0;				//*********
	static int rank=0;
	static int status=0; 
	static int color1=0;
	static int color2=0;
	static int color_next=0;
	static int color_fall=0;
	//*********
	static int shape=0;
	
			//saved!************************



	PAINTSTRUCT ps;
	static HDC hdc=BeginPaint(hWnd,&ps);

	int *buffer=new int[1];
	TCHAR szBuffer[34];
	FILE *pf=NULL;
	
	
	//RECT rect;
	HPEN hPen=NULL;
	HBRUSH hBrush=NULL;
	point[12].x=10;
	point[12].y=1;
	
	srand((unsigned)time(NULL));
	srand(rand());
	color1=RGB (rand () % 256, rand () % 256, rand () % 256);
	rand1  =rand()%19+1;
	
	for(i=0;i<14;i++)
	{
		flag[i][22]=1;
	}

	for(i=0;i<23;i++)
	{
		flag[0][i]=1;
		flag[13][i]=1;
	}
	//i=RGB(1,2,3);
	//SendMessage(hWnd,WM_CREATE,100,0);
	//SendMessage(hWnd,TIMER_SPEED,READ,0);
	switch (message)

	{
	
	case WM_CREATE:
		SetTimer(hWnd,TIMER_SPEED,1000,0);             //////////////////////////////////
		srand((unsigned)time(NULL));
		srand(rand());
		break;
	case WM_COMMAND:
		HMENU hMenu;
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);

		// Parse the menu selections:
		switch (wmId)
		{
			hMenu = GetMenu (hWnd) ;
		case ID_GAME_NEW:
			SendMessage(hWnd,WM_USERCHANGED,Restart,0);
			break;
		case ID_GAME_START:
			SendMessage(hWnd,WM_KEYDOWN,VK_RETURN,0);
			break;
		case ID_GAME_SAVE:
			SendMessage(hWnd,WM_USERCHANGED,SAVE,0);
			break;
		case ID_GAME_READ:
			SendMessage(hWnd,WM_USERCHANGED,READ,0);
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
		break;
	case WM_PAINT:
		BeginPaint(hWnd,&ps);
		EndPaint(hWnd,&ps);
		break;
		
	case WM_TIMER:
			switch(wParam)
			{
					
				case TIMER_SPEED:
					if(sign%2==0)
					{
						SendMessage(hWnd,WM_USERCHANGED,mDown,0);
					}
					SendMessage(hWnd,WM_USERCHANGED,TIMER,0);
					SendMessage(hWnd,WM_USERCHANGED,STATUS,0);
					break;	
			}
			break;

	case WM_USERCHANGED:
		switch(wParam)
		{
		case mDown:
			{
				if(flag[apt[8].x][apt[8].y+1]!=0||
				flag[(apt[9].x)][apt[9].y+1]!=0||
				flag[(apt[10].x)][apt[10].y+1]!=0||
				flag[(apt[11].x)][apt[11].y+1]!=0)
				{
					flag[apt[8].x][apt[8].y]=apt[13].x;
					flag[apt[9].x][apt[9].y]=apt[13].x;
					flag[apt[10].x][apt[10].y]=apt[13].x;
					flag[apt[11].x][apt[11].y]=apt[13].x;
					InvalidateRect(hWnd,0,false);
					for(i=0,rayl=1;rayl<22;rayl++)
					{
						for(rayc=1;rayc<=13;rayc++)
						{
							if(flag[rayc][rayl]==0)
							{
								break;
							}
						}
						if(rayc>12)
						{
							i++;
							Disapper(flag,rayl);
						}
					}
					switch(i)
					{
						case 4:score+=40;
						case 3:score+=30;
						case 2:score+=20;
						case 1:score+=10;
						InvalidateRect(hWnd,0,false);
						hdc=BeginPaint(hWnd,&ps);
						hPen=CreatePen(PS_DASHDOTDOT,1,BLACK_PEN);
						SelectObject(hdc,hPen);
						Paint(hdc,flag);
						DeleteObject(hPen);
						rank=score/500;
						EndPaint(hWnd,&ps);
						DeleteObject(hPen);
						break;
					}
					SendMessage(hWnd,WM_USERCHANGED,100,0);
					break;
				}
				InvalidateRect(hWnd,0,false);
				hdc=BeginPaint(hWnd,&ps);
				
				TextOut (hdc, 391,230, szBuffer,wsprintf(szBuffer, TEXT ("%s"),TEXT("                                 "))) ;

				SetPolyFillMode(hdc,WINDING);
				Paint(hdc,flag);
				Polygon(hdc,apt,8);

				Move(hdc,apt,mDown,flag);
				hPen=CreatePen(PS_DASHDOTDOT,1,BLACK_PEN);
				SelectObject(hdc,hPen);
				Initial(hdc);
				EndPaint(hWnd,&ps);

				DeleteObject(hPen);
				
			}
			break;
		case mLeft:
			if(flag[apt[8].x-1][apt[8].y]!=0||
				flag[(apt[9].x-1)][apt[9].y]!=0||
				flag[(apt[10].x-1)][apt[10].y]!=0||
				flag[(apt[11].x-1)][apt[11].y]!=0);
			else
			{
				InvalidateRect(hWnd,0,false);
				hdc=BeginPaint(hWnd,&ps);
				hPen=CreatePen(PS_DASHDOTDOT,1,BLACK_PEN);
				SelectObject(hdc,hPen);
				Move(hdc,apt,mLeft,flag);
				Initial(hdc);
				DeleteObject(hPen);
				EndPaint(hWnd,&ps);
			}
			break;
		


		case mRight:
			if(flag[(apt[8].x+1)][apt[8].y]!=0||
				flag[(apt[9].x+1)][apt[9].y]!=0||
				flag[(apt[10].x+1)][apt[10].y]!=0||
				flag[(apt[11].x+1)][apt[11].y]!=0);
			else
			{
				InvalidateRect(hWnd,0,false);
				hdc=BeginPaint(hWnd,&ps);
				hPen=CreatePen(PS_DASHDOTDOT,1,BLACK_PEN);
				SelectObject(hdc,hPen);
				Move(hdc,apt,mRight,flag);
				Initial(hdc);
				DeleteObject(hPen);
				EndPaint(hWnd,&ps);
				
			}
			break;
		case fDown:
				InvalidateRect(hWnd,0,false);
				hdc=BeginPaint(hWnd,&ps);
				hPen=CreatePen(PS_DASHDOTDOT,1,BLACK_PEN);
				SelectObject(hdc,hPen);
				Move(hdc,apt,fDown,flag);
				if(flag[apt[8].x][apt[8].y+1]!=0||
				flag[(apt[9].x)][apt[9].y+1]!=0||
				flag[(apt[10].x)][apt[10].y+1]!=0||
				flag[(apt[11].x)][apt[11].y+1]!=0)
				{
					flag[apt[8].x][apt[8].y]=apt[13].x;;
					flag[apt[9].x][apt[9].y]=apt[13].x;;
					flag[apt[10].x][apt[10].y]=apt[13].x;;
					flag[apt[11].x][apt[11].y]=apt[13].x;;
					InvalidateRect(hWnd,0,false);
					hdc=BeginPaint(hWnd,&ps);
					for(i=0,rayl=1;rayl<22;rayl++)
					{
						for(rayc=1;rayc<=13;rayc++)
						{
							if(flag[rayc][rayl]==0)
							{
								break;
							}
						}
						if(rayc>12)
						{
							i++;
							Disapper(flag,rayl);
						}
					}
					switch(i)
					{
						case 4:score+=40;
						case 3:score+=30;
						case 2:score+=20;
						case 1:score+=10;
						hPen=CreatePen(PS_DASHDOTDOT,1,BLACK_PEN);
						SelectObject(hdc,hPen);
						Paint(hdc,flag);
						DeleteObject(hPen);
						break;
					}
					rank=score/500;
					SendMessage(hWnd,WM_USERCHANGED,100,0);
					DeleteObject(hPen);
					hPen=CreatePen(PS_DASHDOTDOT,1,BLACK_PEN);
					SelectObject(hdc,hPen);
					Initial(hdc);
					DeleteObject(hPen);
				}
				hPen=CreatePen(PS_DASHDOTDOT,1,BLACK_PEN);
				SelectObject(hdc,hPen);
				Initial(hdc);
				DeleteObject(hPen);
				EndPaint(hWnd,&ps);
				

				break;
		case Change:
			{
				InvalidateRect(hWnd,0,false);
				hdc=BeginPaint(hWnd,&ps);
				hPen=CreatePen(PS_DASHDOTDOT,1,BLACK_PEN);
				SelectObject(hdc,hPen);
				Move(hdc,apt,Change,flag);
				Initial(hdc);
				DeleteObject(hPen);
				EndPaint(hWnd,&ps);
			}
		break;
		case Restart:						
			for(i=0;i<13;i++)
			{
				apt[i].x=0;
				apt[i].y=0;
			}
			for(rayl=0;rayl<14;rayl++)
				for(rayc=0;rayc<23;rayc++)
					flag[rayl][rayc]=0;		
			for(i=0;i<14;i++)
			{
				flag[i][22]=1;
			}
			for(i=0;i<23;i++)
			{
				flag[0][i]=1;
				flag[13][i]=1;
			}				
			sign=0;	
			rayl=0;
			rayc=0;
			i=0;
			rayl=0,rayc=0;
			score=0;
			color2=RGB (((rand ()%59) *(rand()%61)) % 256, rand () % 256,( (rand ()%11)*rand()*(rand()%71)) % 256);													//********
			rand1=0;
			rand2=0;
			rank=0;
			InvalidateRect(hWnd,0,true);
			hdc=BeginPaint(hWnd,&ps);
			hPen=CreatePen(PS_DASHDOTDOT,1,WHITE_PEN);
			SelectObject(hdc,hPen);
			Paint(hdc,flag);
			Initial(hdc);
			DeleteObject(hPen);
			EndPaint(hWnd,&ps);
			SendMessage(hWnd,WM_USERCHANGED,100,0);
			SendMessage(hWnd,WM_USERCHANGED,STATUS,0);

			break;
		case Stop:
			sign=-1;
			break;
		case STATUS:

			InvalidateRect(hWnd,0,false);
			hdc=BeginPaint(hWnd,&ps);
			hPen=CreatePen(PS_DASHDOTDOT,1,WHITE_PEN);
			SelectObject(hdc,hPen);
			hBrush=CreateSolidBrush(0xFFFFF);
			SelectObject(hdc,hBrush);
			SetPolyFillMode(hdc,WINDING);
			TextOut (hdc, 465,7, szBuffer,wsprintf(szBuffer, TEXT ("%s"),TEXT("Next:"))) ;
			TextOut (hdc, 391,170, szBuffer,wsprintf(szBuffer, TEXT ("%s"),TEXT("Total Score:"))) ;
			TextOut (hdc, 500,170, szBuffer,wsprintf(szBuffer, TEXT ("%5d"),score)) ;
			TextOut (hdc, 391,150, szBuffer,wsprintf(szBuffer, TEXT ("%s"),TEXT("Level:"))) ;
			TextOut (hdc, 500,150, szBuffer,wsprintf(szBuffer, TEXT ("%d"),rank)) ;
			TextOut (hdc, 391,190, szBuffer,wsprintf(szBuffer, TEXT ("%s"),TEXT("Status:"))) ;
			TextOut (hdc, 391,300, szBuffer,wsprintf(szBuffer, TEXT ("%s"),TEXT("R  --  Restart"))) ;
			TextOut (hdc, 391,320, szBuffer,wsprintf(szBuffer, TEXT ("%s"),TEXT("S  --  Save File"))) ;
			TextOut (hdc, 391,340, szBuffer,wsprintf(szBuffer, TEXT ("%s"),TEXT("Q  --  Read File"))) ;
			TextOut (hdc, 391,360, szBuffer,wsprintf(szBuffer, TEXT ("%s"),TEXT("Enter  --  Start / Stop"))) ;
			TextOut (hdc, 391,380, szBuffer,wsprintf(szBuffer, TEXT ("%s"),TEXT("Esc  --  Quit"))) ;
			
			if(sign==0)																				  	
				TextOut (hdc, 451,190, szBuffer,wsprintf(szBuffer, TEXT ("%s"),TEXT("Ready!          "))) ;
			if(sign==2||sign==4)
			{
				TextOut (hdc, 451,190, szBuffer,wsprintf(szBuffer, TEXT ("%s"),TEXT("Ready!         "))) ;
				sign=sign%2+2;
			}
			if(sign==1||sign==3||sign==5)
			{
				TextOut (hdc, 451,190, szBuffer,wsprintf(szBuffer, TEXT ("%s"),TEXT("Stoped!   "))) ;
				sign=sign%2+2;
			}
					
			//hBrush=CreateSolidBrush(point[13].x);
			//SelectObject(hdc,hBrush);
			//Polygon(hdc,point,8);
			DeleteObject(hPen);		
			DeleteObject(hBrush);
			EndPaint(hWnd,&ps);
		break;
		


		case READ:
			fopen_s(&pf,"My Tetris.dat","rb");
			//fseek(pf,0,0);
			if(pf==NULL)
			{

				InvalidateRect(hWnd,0,false);
				hdc=BeginPaint(hWnd,&ps);
				TextOut (hdc, 391,230, szBuffer,wsprintf(szBuffer, TEXT ("%s"),TEXT("No File to Read!                "))) ;
				EndPaint(hWnd,&ps);


			}
			else
			{
				InvalidateRect(hWnd,0,true);
				point[13].x=color1;
				
				//read hard disk file***********************************************************
				for(rayc=0;rayc<14;rayc++)
				{
					
					fread(buffer,sizeof(int),1,pf);
					point[rayc].x=*buffer;
					fread(buffer,sizeof(int),1,pf);
					point[rayc].y=*buffer;
					
				}
				for(rayc=0;rayc<14;rayc++)
				{
					fread(buffer,sizeof(int),1,pf);
					apt[rayc].x=*buffer;
					fread(buffer,sizeof(int),1,pf);
					apt[rayc].y=*buffer;
				}

				for(rayc=0;rayc<14;rayc++)
					for(rayl=0;rayl<23;rayl++)
					{
						fread(buffer,sizeof(int),1,pf);
						flag[rayc][rayl]=*buffer;
					}
				fread(buffer,sizeof(int),1,pf);
				score=*buffer;
				fread(buffer,sizeof(int),1,pf);
				rand1=*buffer;
				fread(buffer,sizeof(int),1,pf);
				rand2=*buffer;
				fread(buffer,sizeof(int),1,pf);
				rank=*buffer;
				fread(buffer,sizeof(int),1,pf);
				shape=*buffer;
				fread(buffer,sizeof(int),1,pf);
				color_next=*buffer;
				fread(buffer,sizeof(int),1,pf);
				color_fall=*buffer;
				fclose(pf);
				//read hard disk file***********************************************************

				Write_i(shape);											//input current changed tetris
				sign=1;													//stop after read file
				InvalidateRect(hWnd,0,false);
				hdc=BeginPaint(hWnd,&ps);
				Paint(hdc,flag);										//recover signed tetris
				
				hBrush=CreateSolidBrush(color_fall);
				color2=0;

				SelectObject(hdc,hBrush);
				Polygon(hdc,apt,8);										//recover falling tetris
				
				SelectObject(hdc,CreatePen(PS_NULL,0,WHITE_BRUSH));		//recover the next tetris
				hBrush=CreateSolidBrush(color_next);
				SelectObject(hdc,hBrush);
				Polygon(hdc,point,8);
				
				SelectObject(hdc,CreatePen(PS_DASHDOTDOT,0,BLACK_PEN));	//recover background****
				Initial(hdc);
				TextOut (hdc, 391,230, szBuffer,wsprintf(szBuffer, TEXT ("%s"),TEXT("File Read!                  "))) ;
				EndPaint(hWnd,&ps);
			}

			break;
		case SAVE:
			fopen_s(&pf,"My Tetris.dat","wb+");
			if(pf==NULL)
			{
				//system("mkdir C:\\Users\\Public\\Games");
				TextOut(hdc,391,230, szBuffer,wsprintf(szBuffer, TEXT ("%s"),TEXT("Save Failed!                "))) ;
			}
			fseek(pf,0,0);
			for(rayc=0;rayc<14;rayc++)
			{
				
				*buffer=point[rayc].x;
				fwrite(buffer,sizeof(int),1,pf);
				*buffer=point[rayc].y;
				fwrite(buffer,sizeof(int),1,pf);

			}
			for(rayc=0;rayc<14;rayc++)
			{
				*buffer=apt[rayc].x;
				fwrite(buffer,sizeof(int),1,pf);
				*buffer=apt[rayc].y;
				fwrite(buffer,sizeof(int),1,pf);
			}

			for(rayc=0;rayc<14;rayc++)
				for(rayl=0;rayl<23;rayl++)
				{
					*buffer=flag[rayc][rayl];
					fwrite(buffer,sizeof(int),1,pf);

				}


			*buffer=score;
			fwrite(buffer,sizeof(int),1,pf);
			*buffer=Read_i();
			fwrite(buffer,sizeof(int),1,pf);
			*buffer=rand2;
			fwrite(buffer,sizeof(int),1,pf);
			*buffer=rank;
			fwrite(buffer,sizeof(int),1,pf);
			
			*buffer=Read_i();
			fwrite(buffer,sizeof(int),1,pf);
				//shape=*buffer;
			*buffer=color_next;
			fwrite(buffer,sizeof(int),1,pf);
				
			*buffer=color_fall;
			fwrite(buffer,sizeof(int),1,pf);

			


			fclose(pf);

			InvalidateRect(hWnd,0,false);
			hdc=BeginPaint(hWnd,&ps);
			TextOut (hdc, 391,230, szBuffer,wsprintf(szBuffer, TEXT ("%s"),TEXT("File Saved!                  "))) ;
			EndPaint(hWnd,&ps);
			break;

		case CLEAR:
			for(i=0;i<13;i++)
			{
				apt[i].x=0;
				apt[i].y=0;
			}
			for(rayl=0;rayl<14;rayl++)
				for(rayc=0;rayc<23;rayc++)
					flag[rayl][rayc]=0;		
			for(i=0;i<14;i++)
			{
				flag[i][22]=1;
			}
			for(i=0;i<23;i++)
			{
				flag[0][i]=1;
				flag[13][i]=1;
			}				
			sign=0;	
			rayl=0;
			rayc=0;
			i=0;
			rayl=0;
			rayc=0;
			score=0;
			rand1=0;
			rand2=0;
			//rand3=0;
			rank=0;
			break;

		case TIMER:
			switch(rank)
			{
			case 0:
				SetTimer(hWnd,TIMER_SPEED,1000,0);
				break;
			case 1:
				KillTimer(hWnd,TIMER_SPEED);
				SetTimer(hWnd,TIMER_SPEED,920,0);
				break;
			case 2:
				KillTimer(hWnd,TIMER_SPEED);
				SetTimer(hWnd,TIMER_SPEED,860,0); 
				break;
			case 3:
				KillTimer(hWnd,TIMER_SPEED);
				SetTimer(hWnd,TIMER_SPEED,800,0);
				break;
			case 4:
				KillTimer(hWnd,TIMER_SPEED);
				SetTimer(hWnd,TIMER_SPEED,740,0); 
				break;
			case 5:
				KillTimer(hWnd,TIMER_SPEED);
				SetTimer(hWnd,TIMER_SPEED,680,0); 
				break;
			case 6:
				KillTimer(hWnd,TIMER_SPEED);
				SetTimer(hWnd,TIMER_SPEED,620,0); 
				break;
			case 7:
				KillTimer(hWnd,TIMER_SPEED);
				SetTimer(hWnd,TIMER_SPEED,560,0); 
				break;
			case 8:
				KillTimer(hWnd,TIMER_SPEED);
				SetTimer(hWnd,TIMER_SPEED,500,0); 
				break;
			case 9:
				KillTimer(hWnd,TIMER_SPEED);
				SetTimer(hWnd,TIMER_SPEED,440,0); 
				break;
			case 10:
				KillTimer(hWnd,TIMER_SPEED);
				SetTimer(hWnd,TIMER_SPEED,380,0);
				break;
			case 11:
				KillTimer(hWnd,TIMER_SPEED);
				SetTimer(hWnd,TIMER_SPEED,320,0); 
				break;
			case 12:
				KillTimer(hWnd,TIMER_SPEED);
				SetTimer(hWnd,TIMER_SPEED,260,0); 
				break;
			case 13:
				KillTimer(hWnd,TIMER_SPEED);
				SetTimer(hWnd,TIMER_SPEED,200,0); 
				break;

			case 14:
				KillTimer(hWnd,TIMER_SPEED);
				SetTimer(hWnd,TIMER_SPEED,140,0);
				break;
			default:
				KillTimer(hWnd,TIMER_SPEED);
				SetTimer(hWnd,TIMER_SPEED,100,0);
				break;
			}
			//DeleteObject(hPen);
			//DeleteObject(hBrush);
			break;

		default:
			//SendMessage(hWnd,WM_USERCHANGED,Restart,0);
			InvalidateRect(hWnd,0,false);
			hdc=BeginPaint(hWnd,&ps);
			hPen=CreatePen(PS_DASHDOTDOT,1,BLACK_PEN);
			SelectObject(hdc,hPen);
			//POINT point[14]={0};
			//set the next tettris' position...
			
			
			if(color2!=0)
			{
				color1=color2;
				color_fall=color1;
			}
			else
			{
				color_fall=color_next;
			}
			//color=RGB (rand () % 256, rand () % 256, rand () % 256);
			
			if(rand2!=0)
			{
				rand1=rand2;
				
			}
			
			if(color_fall==0)
			{
				srand(rand());
				color_fall=RGB (rand () % 256, rand () % 256, rand () % 256);
			}

			apt[13].x=color_fall;
			Rund(hdc,apt,rand1,flag);								//random create///////////////
			if(flag[apt[8].x][apt[8].y]!=0||
				flag[(apt[9].x)][apt[9].y]!=0||
				flag[(apt[10].x)][apt[10].y]!=0||
				flag[(apt[11].x)][apt[11].y]!=0)
			{
				SendMessage(hWnd,WM_USERCHANGED,CLEAR,0);
				TextOut (hdc, 451,190, szBuffer,wsprintf(szBuffer, TEXT ("%s"),TEXT("Game Over!"))) ;
				TextOut (hdc, 391,230, szBuffer,wsprintf(szBuffer, TEXT ("%s"),TEXT("Press R to Restart!  "))) ;
				sign=11;
				Initial(hdc);
				EndPaint(hWnd,&ps);
				//return NULL;
			}
			////////game over

			DeleteObject(hPen);
			hPen=CreatePen(PS_NULL,1,WHITE_PEN);
			SelectObject(hdc,hPen);
			//hBrush=GetStockObject(WHITE_BRUSH);
			SelectObject(hdc,GetStockObject(WHITE_BRUSH));
			SetPolyFillMode(hdc,WINDING);

			point[13].x=0xFFFFFF;			//color white
			Rund_(hdc,point,rand2);			//rund_ for disapper the next tetris
			point[13].x=color1;
			rand2  =rand()%19+1;
			switch(sign)
				{
					case 0:
						TextOut (hdc, 451,190, szBuffer,wsprintf(szBuffer, TEXT ("%s"),TEXT("Unready!  "))) ;
						TextOut (hdc, 391,230, szBuffer,wsprintf(szBuffer, TEXT ("%s"),TEXT("Press Enter to Start!"))) ;
						break;																					
				}
			DeleteObject(hPen);
			srand(rand()*rand());
			color2=RGB (rand () % 256, rand () % 256, rand () % 256);
			color1=color2;
			point[13].x=color1;
			color_next=color1;
			Rund_(hdc,point,rand2);										//rund_ for create the next tetris
			//color1=color2;
			DeleteObject(hPen);
			hPen=CreatePen(PS_DASHDOTDOT,1,BLACK_PEN);
			SelectObject(hdc,hPen);
			Initial(hdc);
			DeleteObject(hBrush);
			DeleteObject(hPen);
			EndPaint(hWnd,&ps);
			
			if(sign==0)
				{
					//SendMessage(hWnd,WM_USERCHANGED,Restart,0);
					SendMessage(hWnd,WM_USERCHANGED,Stop,0);
					
				}
		}
		break;
	case WM_SYSKEYDOWN:
		break;
	case WM_KEYDOWN:
		
		if(sign%2==0)
			{
				switch(wParam)
				{
				case VK_DOWN: 
					SendMessage(hWnd,WM_USERCHANGED,mDown,0);
					break;
				case VK_UP: 
					SendMessage(hWnd,WM_USERCHANGED,Change,0);
					break;
				case VK_LEFT: 
					SendMessage(hWnd,WM_USERCHANGED,mLeft,0);
					break;
				case VK_RIGHT: 
					SendMessage(hWnd,WM_USERCHANGED,mRight,0);
					break;
				case VK_SPACE: 
					{
							SendMessage(hWnd,WM_USERCHANGED,fDown,0);
					}
					break;
				case VK_RETURN:
					if(sign!=11)
					{
					sign++;
					if(sign==0)
						sign=2;
					
					SendMessage(hWnd,WM_USERCHANGED,STATUS,0);
					//SendMessage(hWnd,WM_USERCHANGED,SAVE,0);
					hdc=BeginPaint(hWnd,&ps);
					//TextOut (hdc,551,260, szBuffer,wsprintf(szBuffer, TEXT ("%s"),TEXT("File Saved")));
					EndPaint(hWnd,&ps);
					}
				break;
				
				
				case 'R':
					SendMessage(hWnd,WM_USERCHANGED,Restart,0);
					break;

				case 'Q':
					SendMessage(hWnd,WM_USERCHANGED,READ,0);
					SendMessage(hWnd,WM_USERCHANGED,STATUS,0);
					break;

				case 'S':
					SendMessage(hWnd,WM_USERCHANGED,SAVE,0);
					break;
						
					
					break;
				case VK_ESCAPE:
					//SendMessage(hWnd,WM_USERCHANGED,SAVE,0);
					SendMessage(hWnd,WM_DESTROY,0,0);
					//PostQuitMessage(0);
					break;
				}
			}
		else
		{
			switch(wParam)
			{
			case VK_RETURN:
				if(sign!=11)
				{
					sign++;
					if(sign==0)
						sign=2;
					SendMessage(hWnd,WM_USERCHANGED,STATUS,0);
					//SendMessage(hWnd,WM_USERCHANGED,SAVE,0);
				}
			break;

		
			case 'R':
				SendMessage(hWnd,WM_USERCHANGED,Restart,0);
				break;

			case 'Q':
				SendMessage(hWnd,WM_USERCHANGED,READ,0);
				SendMessage(hWnd,WM_USERCHANGED,STATUS,0);
				break;

			case 'S':
				SendMessage(hWnd,WM_USERCHANGED,SAVE,0);
				break;
				
					break;
			case VK_ESCAPE:
					//SendMessage(hWnd,WM_USERCHANGED,SAVE,0);
					SendMessage(hWnd,WM_DESTROY,0,0);
					//PostQuitMessage(0);
					break;
			
			}
		}
		
		break;
	case WM_DESTROY:
		//SendMessage(hWnd,WM_USERCHANGED,SAVE,0);
		KillTimer(hWnd,TIMER_SPEED);
		delete []buffer;
		PostQuitMessage(0);
		
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
		

}

// Message handler for about box.
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


//HBRUSH hBrush;
//hBrush = CreateSolidBrush (RGB (rand () % 256, rand () % 256, rand () % 256)) ;



