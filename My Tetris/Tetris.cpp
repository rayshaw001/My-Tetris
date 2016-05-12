#include"Tetris.h"
#include "stdafx.h"
#include"time.h"

static int i=0;

//static int color;
void Initial(HDC hdc)
{
	int x=0,y=0;
	MoveToEx(hdc,0,0,NULL);
	LineTo(hdc,0,21*Width);
	for(int y=0;y<12;y++)
	{
		MoveToEx(hdc,Width+x,0,NULL);
		LineTo(hdc,Width+x,21*Width);
		x=x+Width;
	}
	MoveToEx(hdc,0,0,NULL);
	LineTo(hdc,12*Width,0);
	for(x=0,y=0;y<21;y++)
	{
		MoveToEx(hdc,0,Width+x,NULL);
		LineTo(hdc,12*Width,Width+x);
		x=x+Width;
	}
}











int Rund(HDC hdc,POINT* apt,int flag,int sign[14][23])
{	
	
	i=flag;
	switch(flag)
	{
	case 1: LineU(hdc,apt,0,sign);
			break;
	case 2: LineC(hdc,apt,0,sign);
			break;
	case 3: Left(hdc,apt,0,sign);
			break;
	case 4: Right(hdc,apt,0,sign);
			break;
	case 5: Up(hdc,apt,0,sign);
			break;
	case 6: Down(hdc,apt,0,sign);
			break;
	case 7: zLeft(hdc,apt,0,sign);
			break;
	case 8: zRight(hdc,apt,0,sign);
			break;
	case 9: zUp(hdc,apt,0,sign);
			break;
	case 10: zDown(hdc,apt,0,sign);
			break;
	case 11: Tetris(hdc,apt,0,sign);
			break;
	case 12:SevenOne(hdc,apt,0,sign);
			break;
	case 13:SevenTwo(hdc,apt,0,sign);
			break;
	case 14:SevenThree(hdc,apt,0,sign);
			break;
	case 15:SevenFour(hdc,apt,0,sign);
			break;
	case 16:uSevenOne(hdc,apt,0,sign);
			break;
	case 17:uSevenTwo(hdc,apt,0,sign);
			break;
	case 18:uSevenThree(hdc,apt,0,sign);
			break;
	case 19:uSevenFour(hdc,apt,0,sign);
			break;


	}
	return i;
}
	







int LineU(HDC hdc,POINT* point,int flag,int sign[14][23])
{
	POINT *apt=new POINT[14];
	HBRUSH hbrush;
	for(int j=0;j<13;j++)
	{
		apt[j]=point[j];
	}
	
	if(flag==0)
	{

		//HBRUSH hBrush;
		//hBrush = CreateSolidBrush (RGB (rand () % 256, rand () % 256, rand () % 256)) ;


			//color=RGB (rand () % 256, rand () % 256, rand () % 256);
			apt[0].x=7*Width;
			apt[0].y=0;
			apt[1].x=7*Width;
			apt[1].y=4*Width;
			apt[2].x=6*Width;
			apt[2].y=4*Width;
			apt[3].x=6*Width;
			apt[3].y=0;
			apt[4]=apt[0];
			apt[5]=apt[0];
			apt[6]=apt[0];
			apt[7]=apt[0];
			apt[8].x=7;
			apt[8].y=1;
			apt[9].x=7;
			apt[9].y=2;
			apt[10].x=7;
			apt[10].y=3;
			apt[11].x=7;
			apt[11].y=4;
			apt[12].x=0;
			apt[12].y=0;
			//apt[13].x=color;
			
	}
	else
	{
			//color=RGB (rand () % 256, rand () % 256, rand () % 256);
			apt[0].x=(7+apt[12].x)*Width;
			apt[0].y=(0+apt[12].y)*Width;
			apt[1].x=(7+apt[12].x)*Width;
			apt[1].y=(4+apt[12].y)*Width;
			apt[2].x=(6+apt[12].x)*Width;
			apt[2].y=(4+apt[12].y)*Width;
			apt[3].x=(6+apt[12].x)*Width;
			apt[3].y=(0+apt[12].y)*Width;
			apt[4]=apt[0];
			apt[5]=apt[0];
			apt[6]=apt[0];
			apt[7]=apt[0];
			apt[8].x=(7+apt[12].x);
			apt[8].y=(1+apt[12].y);
			apt[9].x=(7+apt[12].x);
			apt[9].y=(2+apt[12].y);
			apt[10].x=(7+apt[12].x);
			apt[10].y=(3+apt[12].y);
			apt[11].x=(7+apt[12].x);
			apt[11].y=(4+apt[12].y);
			//apt[13].x=color;
			
	}
	if(sign!=NULL)
	{
		if(sign[apt[8].x][apt[8].y]==1||
			sign[apt[9].x][apt[9].y]==1||
			sign[apt[10].x][apt[10].y]==1||
			sign[apt[11].x][apt[11].y]==1)
		{
			//DeleteObject(hbrush);
			delete []apt;
			return 0;
		}
		else
		{
			//SelectObject(hdc,GetStockObject(GRAY_BRUSH));
			//SelectObject(hdc,GetStockObject(12345));
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
		}
	}
	else
	{		
			//color=RGB (rand () % 256, rand () % 256, rand () % 256);
			//apt[13].x=color;
			//SelectObject(hdc,GetStockObject(GRAY_BRUSH));
			//SelectObject(hdc,GetStockObject(123456));
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			delete []apt;
			DeleteObject(hbrush);
			return 1;
	}
}


int LineC(HDC hdc,POINT *point,int flag,int sign[14][23])
{
	POINT *apt=new POINT[14];
	HBRUSH hbrush;
	for(int j=0;j<13;j++)
	{
		apt[j]=point[j];
	}
	if(flag==0)
	{
	
			//color=RGB (rand () % 256, rand () % 256, rand () % 256);
			apt[0].x=4*Width;
			apt[0].y=0;
			apt[1].x=4*Width;
			apt[1].y=Width;
			apt[2].x=8*Width;
			apt[2].y=Width;
			apt[3].x=8*Width;
			apt[3].y=0;
			apt[4]=apt[0];
			apt[5]=apt[0];
			apt[6]=apt[0];
			apt[7]=apt[0];
			apt[8].x=5;
			apt[8].y=1;
			apt[9].x=6;
			apt[9].y=1;
			apt[10].x=7;
			apt[10].y=1;
			apt[11].x=8;
			apt[11].y=1;
			apt[12].x=0;
			apt[12].y=0;
			//apt[13].x=color;
			}
	else
	{		
			//color=RGB (rand () % 256, rand () % 256, rand () % 256);
			apt[0].x=(4+apt[12].x)*Width;
			apt[0].y=(0+apt[12].y)*Width;
			apt[1].x=(4+apt[12].x)*Width;
			apt[1].y=(1+apt[12].y)*Width;
			apt[2].x=(8+apt[12].x)*Width;
			apt[2].y=(1+apt[12].y)*Width;
			apt[3].x=(8+apt[12].x)*Width;
			apt[3].y=(0+apt[12].y)*Width;
			apt[4]=apt[0];
			apt[5]=apt[0];
			apt[6]=apt[0];
			apt[7]=apt[0];
			apt[8].x=(5+apt[12].x);
			apt[8].y=(1+apt[12].y);
			apt[9].x=(6+apt[12].x);
			apt[9].y=(1+apt[12].y);
			apt[10].x=(7+apt[12].x);
			apt[10].y=(1+apt[12].y);
			apt[11].x=(8+apt[12].x);
			apt[11].y=(1+apt[12].y);
			//apt[13].x=color;
	}
	if(sign!=NULL)
	{
		if(sign[apt[8].x][apt[8].y]==1||
			sign[apt[9].x][apt[9].y]==1||
			sign[apt[10].x][apt[10].y]==1||
			sign[apt[11].x][apt[11].y]==1)
		{
			//DeleteObject(hbrush);
			delete []apt;
			return 0;
		}
		else
		{
			//SelectObject(hdc,GetStockObject(GRAY_BRUSH));
			//SelectObject(hdc,GetStockObject(123456));
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
		}
	}
	else
	{
			//color=RGB (rand () % 256, rand () % 256, rand () % 256);
			//apt[13].x=color;
			//SelectObject(hdc,GetStockObject(GRAY_BRUSH));
			//SelectObject(hdc,GetStockObject(123456));
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
//			DeleteObject(hbrush);
			delete []apt;
			return 1;
	}
}




int Left(HDC hdc,POINT* point,int flag,int sign[14][23])
{
	POINT *apt=new POINT[14];
	HBRUSH hbrush;
	int color=0;
	for(int j=0;j<13;j++)
	{
		apt[j]=point[j];
	}
	if(flag==0)
	{
	
			
			apt[0].x=6*Width;
			apt[0].y=0;
			apt[1].x=6*Width;
			apt[1].y=Width;
			apt[2].x=5*Width;
			apt[2].y=Width;
			apt[3].x=5*Width;
			apt[3].y=2*Width;
			apt[4].x=6*Width;////////////
			apt[4].y=2*Width;
			apt[5].x=6*Width;
			apt[5].y=3*Width;
			apt[6].x=7*Width;
			apt[6].y=3*Width;
			apt[7].x=7*Width;
			apt[7].y=0;
			apt[8].x=7;
			apt[8].y=1;
			apt[9].x=7;
			apt[9].y=2;
			apt[10].x=7;
			apt[10].y=3;
			apt[11].x=6;
			apt[11].y=2;
			apt[12].x=0;
			apt[12].y=0;
			//apt[13].x=color;
			}
	else
	{
			//color=RGB (rand () % 256, rand () % 256, rand () % 256);
			apt[0].x=(6+apt[12].x)*Width;
			apt[0].y=(0+apt[12].y)*Width;
			apt[1].x=(6+apt[12].x)*Width;
			apt[1].y=(1+apt[12].y)*Width;
			apt[2].x=(5+apt[12].x)*Width;
			apt[2].y=(1+apt[12].y)*Width;
			apt[3].x=(5+apt[12].x)*Width;
			apt[3].y=(2+apt[12].y)*Width;
			apt[4].x=(6+apt[12].x)*Width;
			apt[4].y=(2+apt[12].y)*Width;
			apt[5].x=(6+apt[12].x)*Width;
			apt[5].y=(3+apt[12].y)*Width;
			apt[6].x=(7+apt[12].x)*Width;
			apt[6].y=(3+apt[12].y)*Width;
			apt[7].x=(7+apt[12].x)*Width;
			apt[7].y=(0+apt[12].y)*Width;
			apt[8].x=(7+apt[12].x);
			apt[8].y=(1+apt[12].y);
			apt[9].x=(7+apt[12].x);
			apt[9].y=(2+apt[12].y);
			apt[10].x=(7+apt[12].x);
			apt[10].y=(3+apt[12].y);
			apt[11].x=(6+apt[12].x);
			apt[11].y=(2+apt[12].y);
			//apt[13].x=color;
	}
	if(sign!=NULL)
	{
		if(sign[apt[8].x][apt[8].y]==1||
			sign[apt[9].x][apt[9].y]==1||
			sign[apt[10].x][apt[10].y]==1||
			sign[apt[11].x][apt[11].y]==1)
		{
			//DeleteObject(hbrush);
			delete []apt;
			return 0;
		}
		else
		{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
		}
	}
	else
	{
		
		hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
		SetPolyFillMode(hdc,ALTERNATE);
		Polygon(hdc,apt,8);
		for(int j=0;j<13;j++)
		{
			point[j]=apt[j];
		}
		DeleteObject(hbrush);
		delete []apt;
		return 1;
	}
}

int Right(HDC hdc,POINT* point,int flag,int sign[14][23])
{
	POINT *apt=new POINT[14];
	HBRUSH hbrush;
	//int color=RGB (rand () % 256, rand () % 256, rand () % 256);
	for(int j=0;j<13;j++)
	{
		apt[j]=point[j];
	}
	if(flag==0)
	{
	
			apt[0].x=6*Width;
			apt[0].y=0;
			apt[1].x=6*Width;
			apt[1].y=Width;
			apt[2].x=7*Width;
			apt[2].y=Width;
			apt[3].x=7*Width;
			apt[3].y=2*Width;
			apt[4].x=6*Width;
			apt[4].y=2*Width;
			apt[5].x=6*Width;
			apt[5].y=3*Width;
			apt[6].x=5*Width;
			apt[6].y=3*Width;
			apt[7].x=5*Width;
			apt[7].y=0;
			apt[8].x=6;
			apt[8].y=1;
			apt[9].x=7;
			apt[9].y=2;
			apt[10].x=6;
			apt[10].y=2;
			apt[11].x=6;
			apt[11].y=3;
			apt[12].x=0;
			apt[12].y=0;
			//apt[13].x=color;
	}
	else
	{
		
			apt[0].x=(6+apt[12].x)*Width;
			apt[0].y=(0+apt[12].y)*Width;
			apt[1].x=(6+apt[12].x)*Width;
			apt[1].y=(1+apt[12].y)*Width;
			apt[2].x=(7+apt[12].x)*Width;
			apt[2].y=(1+apt[12].y)*Width;
			apt[3].x=(7+apt[12].x)*Width;
			apt[3].y=(2+apt[12].y)*Width;
			apt[4].x=(6+apt[12].x)*Width;
			apt[4].y=(2+apt[12].y)*Width;
			apt[5].x=(6+apt[12].x)*Width;
			apt[5].y=(3+apt[12].y)*Width;
			apt[6].x=(5+apt[12].x)*Width;
			apt[6].y=(3+apt[12].y)*Width;
			apt[7].x=(5+apt[12].x)*Width;
			apt[7].y=(0+apt[12].y)*Width;
			apt[8].x=(6+apt[12].x);
			apt[8].y=(1+apt[12].y);
			apt[9].x=(7+apt[12].x);
			apt[9].y=(2+apt[12].y);
			apt[10].x=(6+apt[12].x);
			apt[10].y=(2+apt[12].y);
			apt[11].x=(6+apt[12].x);
			apt[11].y=(3+apt[12].y);
			//apt[13].x=color;
	}
		if(sign!=NULL)
	{
		if(sign[apt[8].x][apt[8].y]==1||
			sign[apt[9].x][apt[9].y]==1||
			sign[apt[10].x][apt[10].y]==1||
			sign[apt[11].x][apt[11].y]==1)
		{
			//DeleteObject(hbrush);
			delete []apt;
			return 0;
		}
		else
		{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
		}
	}
	else
	{
		
		hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
		SetPolyFillMode(hdc,ALTERNATE);
		Polygon(hdc,apt,8);
		for(int j=0;j<13;j++)
		{
			point[j]=apt[j];
		}
		DeleteObject(hbrush);
		delete []apt;
		return 1;
	}
}


int Up(HDC hdc,POINT* point,int flag,int sign[14][23])
{
	POINT *apt=new POINT[14];
	HBRUSH hbrush;
	//int color=RGB (rand () % 256, rand () % 256, rand () % 256);
	for(int j=0;j<13;j++)
	{
		apt[j]=point[j];
	}



	if(flag==0)
	{
	
			
			apt[0].x=6*Width;
			apt[0].y=0;
			apt[1].x=6*Width;
			apt[1].y=Width;
			apt[2].x=5*Width;
			apt[2].y=Width;
			apt[3].x=5*Width;
			apt[3].y=2*Width;
			apt[4].x=8*Width;
			apt[4].y=2*Width;
			apt[5].x=8*Width;
			apt[5].y=Width;
			apt[6].x=7*Width;
			apt[6].y=Width;
			apt[7].x=7*Width;
			apt[7].y=0;
			apt[8].x=7;
			apt[8].y=1;
			apt[9].x=8;
			apt[9].y=2;
			apt[10].x=7;
			apt[10].y=2;
			apt[11].x=6;
			apt[11].y=2;
			apt[12].x=0;
			apt[12].y=0;
			//apt[13].x=color;
	}
	else
	{
			apt[0].x=(6+apt[12].x)*Width;
			apt[0].y=(0+apt[12].y)*Width;
			apt[1].x=(6+apt[12].x)*Width;
			apt[1].y=(1+apt[12].y)*Width;
			apt[2].x=(5+apt[12].x)*Width;
			apt[2].y=(1+apt[12].y)*Width;
			apt[3].x=(5+apt[12].x)*Width;
			apt[3].y=(2+apt[12].y)*Width;
			apt[4].x=(8+apt[12].x)*Width;
			apt[4].y=(2+apt[12].y)*Width;
			apt[5].x=(8+apt[12].x)*Width;
			apt[5].y=(1+apt[12].y)*Width;
			apt[6].x=(7+apt[12].x)*Width;
			apt[6].y=(1+apt[12].y)*Width;
			apt[7].x=(7+apt[12].x)*Width;
			apt[7].y=(0+apt[12].y)*Width;
			apt[8].x=(7+apt[12].x);
			apt[8].y=(1+apt[12].y);
			apt[9].x=(8+apt[12].x);
			apt[9].y=(2+apt[12].y);
			apt[10].x=(7+apt[12].x);
			apt[10].y=(2+apt[12].y);
			apt[11].x=(6+apt[12].x);
			apt[11].y=(2+apt[12].y);
			//apt[13].x=color;
	}
		if(sign!=NULL)
	{
		if(sign[apt[8].x][apt[8].y]==1||
			sign[apt[9].x][apt[9].y]==1||
			sign[apt[10].x][apt[10].y]==1||
			sign[apt[11].x][apt[11].y]==1)
		{
			//DeleteObject(hbrush);
			delete []apt;
			return 0;
		}
		else
		{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
		}
	}
	else
	{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
	}
}

int Down(HDC hdc,POINT* point,int flag,int sign[14][23])
{
	POINT *apt=new POINT[14];
	HBRUSH hbrush;
	//int color=RGB (rand () % 256, rand () % 256, rand () % 256);
	SelectObject(hdc,GetStockObject(WHITE_BRUSH));
	SetPolyFillMode(hdc,WINDING);
	for(int j=0;j<13;j++)
	{
		apt[j]=point[j];
	}
	if(flag==0)
	{
			
			apt[0].x=6*Width;
			apt[0].y=2*Width;
			apt[1].x=6*Width;
			apt[1].y=Width;
			apt[2].x=5*Width;
			apt[2].y=Width;
			apt[3].x=5*Width;
			apt[3].y=0;
			apt[4].x=8*Width;
			apt[4].y=0;
			apt[5].x=8*Width;
			apt[5].y=Width;
			apt[6].x=7*Width;
			apt[6].y=Width;
			apt[7].x=7*Width;
			apt[7].y=2*Width;
			apt[8].x=6;
			apt[8].y=1;
			apt[9].x=7;
			apt[9].y=1;
			apt[10].x=8;
			apt[10].y=1;
			apt[11].x=7;
			apt[11].y=2;
			apt[12].x=0;
			apt[12].y=0;
			//apt[13].x=color;
	}
	else
	{
			apt[0].x=(6+apt[12].x)*Width;
			apt[0].y=(2+apt[12].y)*Width;
			apt[1].x=(6+apt[12].x)*Width;
			apt[1].y=(1+apt[12].y)*Width;
			apt[2].x=(5+apt[12].x)*Width;
			apt[2].y=(1+apt[12].y)*Width;
			apt[3].x=(5+apt[12].x)*Width;
			apt[3].y=(0+apt[12].y)*Width;
			apt[4].x=(8+apt[12].x)*Width;
			apt[4].y=(0+apt[12].y)*Width;
			apt[5].x=(8+apt[12].x)*Width;
			apt[5].y=(1+apt[12].y)*Width;
			apt[6].x=(7+apt[12].x)*Width;
			apt[6].y=(1+apt[12].y)*Width;
			apt[7].x=(7+apt[12].x)*Width;
			apt[7].y=(2+apt[12].y)*Width;
			apt[8].x=(6+apt[12].x);
			apt[8].y=(1+apt[12].y);
			apt[9].x=(7+apt[12].x);
			apt[9].y=(1+apt[12].y);
			apt[10].x=(8+apt[12].x);
			apt[10].y=(1+apt[12].y);
			apt[11].x=(7+apt[12].x);
			apt[11].y=(2+apt[12].y);
			//apt[13].x=color;
	}
	if(sign!=NULL)
	{
		if(sign[apt[8].x][apt[8].y]==1||
			sign[apt[9].x][apt[9].y]==1||
			sign[apt[10].x][apt[10].y]==1||
			sign[apt[11].x][apt[11].y]==1)
		{
			//DeleteObject(hbrush);
			delete []apt;
			return 0;
		}
		else
		{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
		}
	}
	else
	{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
	}
}
		

int zLeft(HDC hdc,POINT* point,int flag,int sign[14][23])
{


	POINT *apt=new POINT[14];
	HBRUSH hbrush;
	//int color=RGB (rand () % 256, rand () % 256, rand () % 256);
	for(int j=0;j<13;j++)
	{
		apt[j]=point[j];
	}
	if(flag==0)
	{
	
	
			apt[0].x=5*Width;
			apt[0].y=0;
			apt[1].x=5*Width;
			apt[1].y=Width;
			apt[2].x=6*Width;
			apt[2].y=Width;
			apt[3].x=6*Width;
			apt[3].y=2*Width;
			apt[4].x=8*Width;
			apt[4].y=2*Width;
			apt[5].x=8*Width;
			apt[5].y=Width;
			apt[6].x=7*Width;
			apt[6].y=Width;
			apt[7].x=7*Width;
			apt[7].y=0;
			apt[8].x=6;
			apt[8].y=1;
			apt[9].x=7;
			apt[9].y=1;
			apt[10].x=7;
			apt[10].y=2;
			apt[11].x=8;
			apt[11].y=2;
			apt[12].x=0;
			apt[12].y=0;
			//apt[13].x=color;
			}
	else
	{
			apt[0].x=(5+apt[12].x)*Width;
			apt[0].y=(0+apt[12].y)*Width;
			apt[1].x=(5+apt[12].x)*Width;
			apt[1].y=(1+apt[12].y)*Width;
			apt[2].x=(6+apt[12].x)*Width;
			apt[2].y=(1+apt[12].y)*Width;
			apt[3].x=(6+apt[12].x)*Width;
			apt[3].y=(2+apt[12].y)*Width;
			apt[4].x=(8+apt[12].x)*Width;
			apt[4].y=(2+apt[12].y)*Width;
			apt[5].x=(8+apt[12].x)*Width;
			apt[5].y=(1+apt[12].y)*Width;
			apt[6].x=(7+apt[12].x)*Width;
			apt[6].y=(1+apt[12].y)*Width;
			apt[7].x=(7+apt[12].x)*Width;
			apt[7].y=(0+apt[12].y)*Width;
			apt[8].x=(6+apt[12].x);
			apt[8].y=(1+apt[12].y);
			apt[9].x=(7+apt[12].x);
			apt[9].y=(1+apt[12].y);
			apt[10].x=(7+apt[12].x);
			apt[10].y=(2+apt[12].y);
			apt[11].x=(8+apt[12].x);
			apt[11].y=(2+apt[12].y);
			//apt[13].x=color;
	}
		if(sign!=NULL)
	{
		if(sign[apt[8].x][apt[8].y]==1||
			sign[apt[9].x][apt[9].y]==1||
			sign[apt[10].x][apt[10].y]==1||
			sign[apt[11].x][apt[11].y]==1)
		{
			//DeleteObject(hbrush);
			delete []apt;
			return 0;
		}
		else
		{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
		}
	}
	else
	{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
	}
}




int zRight(HDC hdc,POINT* point,int flag,int sign[14][23])
{
	POINT *apt=new POINT[14];
	HBRUSH hbrush;
	//int color=RGB (rand () % 256, rand () % 256, rand () % 256);
	SelectObject(hdc,GetStockObject(WHITE_BRUSH));
	SetPolyFillMode(hdc,WINDING);
	for(int j=0;j<14;j++)
	{
		apt[j]=point[j];
	}
	if(flag==0)
	{
			apt[0].x=8*Width;
			apt[0].y=0;
			apt[1].x=8*Width;
			apt[1].y=Width;
			apt[2].x=7*Width;
			apt[2].y=Width;
			apt[3].x=7*Width;
			apt[3].y=2*Width;
			apt[4].x=5*Width;
			apt[4].y=2*Width;
			apt[5].x=5*Width;
			apt[5].y=Width;
			apt[6].x=6*Width;
			apt[6].y=Width;
			apt[7].x=6*Width;
			apt[7].y=0;
			apt[8].x=8;
			apt[8].y=1;
			apt[9].x=7;
			apt[9].y=1;
			apt[10].x=7;
			apt[10].y=2;
			apt[11].x=6;
			apt[11].y=2;
			apt[12].x=0;
			apt[12].y=0;
			//apt[13].x=color;
			}
	else
	{
			apt[0].x=(8+apt[12].x)*Width;
			apt[0].y=(0+apt[12].y)*Width;
			apt[1].x=(8+apt[12].x)*Width;
			apt[1].y=(1+apt[12].y)*Width;
			apt[2].x=(7+apt[12].x)*Width;
			apt[2].y=(1+apt[12].y)*Width;
			apt[3].x=(7+apt[12].x)*Width;
			apt[3].y=(2+apt[12].y)*Width;
			apt[4].x=(5+apt[12].x)*Width;
			apt[4].y=(2+apt[12].y)*Width;
			apt[5].x=(5+apt[12].x)*Width;
			apt[5].y=(1+apt[12].y)*Width;
			apt[6].x=(6+apt[12].x)*Width;
			apt[6].y=(1+apt[12].y)*Width;
			apt[7].x=(6+apt[12].x)*Width;
			apt[7].y=(0+apt[12].y)*Width;
			apt[8].x=(8+apt[12].x);
			apt[8].y=(1+apt[12].y);
			apt[9].x=(7+apt[12].x);
			apt[9].y=(1+apt[12].y);
			apt[10].x=(7+apt[12].x);
			apt[10].y=(2+apt[12].y);
			apt[11].x=(6+apt[12].x);
			apt[11].y=(2+apt[12].y);
			//apt[13].x=color;
		
	}


	if(sign!=NULL)
	{
		if(sign[apt[8].x][apt[8].y]==1||
			sign[apt[9].x][apt[9].y]==1||
			sign[apt[10].x][apt[10].y]==1||
			sign[apt[11].x][apt[11].y]==1)
		{
			//DeleteObject(hbrush);
			delete []apt;
			return 0;
		}
		else
		{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
		}
	}
	else
	{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
	}
}


int zUp(HDC hdc,POINT* point,int flag,int sign[14][23])
{
	POINT *apt=new POINT[14];
	HBRUSH hbrush;
	//int color=RGB (rand () % 256, rand () % 256, rand () % 256);
	for(int j=0;j<13;j++)
	{
		apt[j]=point[j];
	}
	if(flag==0)
	{
	
			apt[0].x=5*Width;
			apt[0].y=0;
			apt[1].x=5*Width;
			apt[1].y=2*Width;
			apt[2].x=6*Width;
			apt[2].y=2*Width;
			apt[3].x=6*Width;
			apt[3].y=3*Width;
			apt[4].x=7*Width;
			apt[4].y=3*Width;
			apt[5].x=7*Width;
			apt[5].y=Width;
			apt[6].x=6*Width;
			apt[6].y=Width;
			apt[7].x=6*Width;
			apt[7].y=0;
			apt[8].x=6;
			apt[8].y=1;
			apt[9].x=6;
			apt[9].y=2;
			apt[10].x=7;
			apt[10].y=2;
			apt[11].x=7;
			apt[11].y=3;
			apt[12].x=0;
			apt[12].y=0;
			//apt[13].x=color;
			}
	else
	{
			apt[0].x=(5+apt[12].x)*Width;
			apt[0].y=(0+apt[12].y)*Width;
			apt[1].x=(5+apt[12].x)*Width;
			apt[1].y=(2+apt[12].y)*Width;
			apt[2].x=(6+apt[12].x)*Width;
			apt[2].y=(2+apt[12].y)*Width;
			apt[3].x=(6+apt[12].x)*Width;
			apt[3].y=(3+apt[12].y)*Width;
			apt[4].x=(7+apt[12].x)*Width;
			apt[4].y=(3+apt[12].y)*Width;
			apt[5].x=(7+apt[12].x)*Width;
			apt[5].y=(1+apt[12].y)*Width;
			apt[6].x=(6+apt[12].x)*Width;
			apt[6].y=(1+apt[12].y)*Width;
			apt[7].x=(6+apt[12].x)*Width;
			apt[7].y=(0+apt[12].y)*Width;
			apt[8].x=(6+apt[12].x);
			apt[8].y=(1+apt[12].y);
			apt[9].x=(6+apt[12].x);
			apt[9].y=(2+apt[12].y);
			apt[10].x=(7+apt[12].x);
			apt[10].y=(2+apt[12].y);
			apt[11].x=(7+apt[12].x);
			apt[11].y=(3+apt[12].y);
			//apt[13].x=color;
	}
		if(sign!=NULL)
	{
		if(sign[apt[8].x][apt[8].y]==1||
			sign[apt[9].x][apt[9].y]==1||
			sign[apt[10].x][apt[10].y]==1||
			sign[apt[11].x][apt[11].y]==1)
		{
//			DeleteObject(hbrush);
			delete []apt;
			return 0;
		}
		else
		{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
		}
	}
	else
	{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
	}
}




int zDown(HDC hdc,POINT* point,int flag,int sign[14][23])
{
	POINT *apt=new POINT[14];
	HBRUSH hbrush;
	//int color=RGB (rand () % 256, rand () % 256, rand () % 256);
	for(int j=0;j<13;j++)
	{
		apt[j]=point[j];
	}
	if(flag==0)
	{
			apt[0].x=5*Width;
			apt[0].y=3*Width;
			apt[1].x=5*Width;
			apt[1].y=Width;
			apt[2].x=6*Width;
			apt[2].y=Width;
			apt[3].x=6*Width;
			apt[3].y=0;
			apt[4].x=7*Width;
			apt[4].y=0;
			apt[5].x=7*Width;
			apt[5].y=2*Width;
			apt[6].x=6*Width;
			apt[6].y=2*Width;
			apt[7].x=6*Width;
			apt[7].y=3*Width;
			apt[8].x=7;
			apt[8].y=1;
			apt[9].x=7;
			apt[9].y=2;
			apt[10].x=6;
			apt[10].y=2;
			apt[11].x=6;
			apt[11].y=3;
			apt[12].x=0;
			apt[12].y=0;
			//apt[13].x=color;
			}
	else
	{
			apt[0].x=(5+apt[12].x)*Width;
			apt[0].y=(3+apt[12].y)*Width;
			apt[1].x=(5+apt[12].x)*Width;
			apt[1].y=(1+apt[12].y)*Width;
			apt[2].x=(6+apt[12].x)*Width;
			apt[2].y=(1+apt[12].y)*Width;
			apt[3].x=(6+apt[12].x)*Width;
			apt[3].y=(0+apt[12].y)*Width;
			apt[4].x=(7+apt[12].x)*Width;
			apt[4].y=(0+apt[12].y)*Width;
			apt[5].x=(7+apt[12].x)*Width;
			apt[5].y=(2+apt[12].y)*Width;
			apt[6].x=(6+apt[12].x)*Width;
			apt[6].y=(2+apt[12].y)*Width;
			apt[7].x=(6+apt[12].x)*Width;
			apt[7].y=(3+apt[12].y)*Width;
			apt[8].x=(7+apt[12].x);
			apt[8].y=(1+apt[12].y);
			apt[9].x=(7+apt[12].x);
			apt[9].y=(2+apt[12].y);
			apt[10].x=(6+apt[12].x);
			apt[10].y=(2+apt[12].y);
			apt[11].x=(6+apt[12].x);
			apt[11].y=(3+apt[12].y);
			//apt[13].x=color;
	}
	if(sign!=NULL)
	{
		if(sign[apt[8].x][apt[8].y]==1||
			sign[apt[9].x][apt[9].y]==1||
			sign[apt[10].x][apt[10].y]==1||
			sign[apt[11].x][apt[11].y]==1)
		{
//			DeleteObject(hbrush);
			delete []apt;
			return 0;
		}
		else
		{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
		}
	}
	else
	{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
	}
}


int SevenOne(HDC hdc,POINT* point,int flag,int sign[14][23])					//7-1
{
	POINT *apt=new POINT[14];
	HBRUSH hbrush;
	int color=RGB (rand () % 256, rand () % 256, rand () % 256);
	for(int j=0;j<13;j++)
	{
		apt[j]=point[j];
	}



	if(flag==0)
	{
			apt[0].x=5*Width;
			apt[0].y=0;
			apt[1].x=7*Width;
			apt[1].y=0;
			apt[2].x=7*Width;
			apt[2].y=3*Width;
			apt[3].x=6*Width;
			apt[3].y=3*Width;
			apt[4].x=6*Width;
			apt[4].y=Width;
			apt[5].x=5*Width;
			apt[5].y=Width;
			apt[6]=apt[0];
			apt[7]=apt[0];
			apt[8].x=6;
			apt[8].y=1;
			apt[9].x=7;
			apt[9].y=1;
			apt[10].x=7;
			apt[10].y=2;
			apt[11].x=7;
			apt[11].y=3;
			apt[12].x=0;
			apt[12].y=0;
			//apt[13].x=color;
			}
	else
	{
			apt[0].x=(5+apt[12].x)*Width;
			apt[0].y=(0+apt[12].y)*Width;
			apt[1].x=(7+apt[12].x)*Width;
			apt[1].y=(0+apt[12].y)*Width;
			apt[2].x=(7+apt[12].x)*Width;
			apt[2].y=(3+apt[12].y)*Width;
			apt[3].x=(6+apt[12].x)*Width;
			apt[3].y=(3+apt[12].y)*Width;
			apt[4].x=(6+apt[12].x)*Width;
			apt[4].y=(1+apt[12].y)*Width;
			apt[5].x=(5+apt[12].x)*Width;
			apt[5].y=(1+apt[12].y)*Width;
			apt[6]=apt[0];
			apt[7]=apt[0];
			apt[8].x=(6+apt[12].x);
			apt[8].y=(1+apt[12].y);
			apt[9].x=(7+apt[12].x);
			apt[9].y=(1+apt[12].y);
			apt[10].x=(7+apt[12].x);
			apt[10].y=(2+apt[12].y);
			apt[11].x=(7+apt[12].x);
			apt[11].y=(3+apt[12].y);
			//apt[13].x=color;
	}
	if(sign!=NULL)
	{
		if(sign[apt[8].x][apt[8].y]==1||
			sign[apt[9].x][apt[9].y]==1||
			sign[apt[10].x][apt[10].y]==1||
			sign[apt[11].x][apt[11].y]==1)
		{
//			DeleteObject(hbrush);
			delete []apt;
			return 0;
		}
		else
		{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
		}
	}
	else
	{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
	}
}



int SevenTwo(HDC hdc,POINT* point,int flag,int sign[14][23])					//7-2
{

	POINT *apt=new POINT[14];
	HBRUSH hbrush;
	//int color=RGB (rand () % 256, rand () % 256, rand () % 256);
	for(int j=0;j<13;j++)
	{
		apt[j]=point[j];
	}
	if(flag==0)
	{
			apt[0].x=5*Width;
			apt[0].y=0;
			apt[1].x=8*Width;
			apt[1].y=0;
			apt[2].x=8*Width;
			apt[2].y=1*Width;
			apt[3].x=6*Width;
			apt[3].y=1*Width;
			apt[4].x=6*Width;
			apt[4].y=2*Width;
			apt[5].x=5*Width;
			apt[5].y=2*Width;
			apt[6]=apt[0];
			apt[7]=apt[0];
			apt[8].x=6;
			apt[8].y=1;
			apt[9].x=6;
			apt[9].y=2;
			apt[10].x=7;
			apt[10].y=1;
			apt[11].x=8;
			apt[11].y=1;
			apt[12].x=0;
			apt[12].y=0;
			//apt[13].x=color;
	}
			
	else
	{
			apt[0].x=(5+apt[12].x)*Width;
			apt[0].y=(0+apt[12].y)*Width;
			apt[1].x=(8+apt[12].x)*Width;
			apt[1].y=(0+apt[12].y)*Width;
			apt[2].x=(8+apt[12].x)*Width;
			apt[2].y=(1+apt[12].y)*Width;
			apt[3].x=(6+apt[12].x)*Width;
			apt[3].y=(1+apt[12].y)*Width;
			apt[4].x=(6+apt[12].x)*Width;
			apt[4].y=(2+apt[12].y)*Width;
			apt[5].x=(5+apt[12].x)*Width;
			apt[5].y=(2+apt[12].y)*Width;
			apt[6]=apt[0];
			apt[7]=apt[0];
			apt[8].x=(6+apt[12].x);
			apt[8].y=(1+apt[12].y);
			apt[9].x=(6+apt[12].x);
			apt[9].y=(2+apt[12].y);
			apt[10].x=(7+apt[12].x);
			apt[10].y=(1+apt[12].y);
			apt[11].x=(8+apt[12].x);
			apt[11].y=(1+apt[12].y);
			//apt[13].x=color;
	}
	if(sign!=NULL)
	{
		if(sign[apt[8].x][apt[8].y]==1||
			sign[apt[9].x][apt[9].y]==1||
			sign[apt[10].x][apt[10].y]==1||
			sign[apt[11].x][apt[11].y]==1)
		{
//			DeleteObject(hbrush);
			delete []apt;
			return 0;
		}
		else
		{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
		}
	}
	else
	{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
	}
}



int SevenThree(HDC hdc,POINT* point,int flag,int sign[14][23])					//7-3
{
	POINT *apt=new POINT[14];
	HBRUSH hbrush;
	//int color=RGB (rand () % 256, rand () % 256, rand () % 256);
	for(int j=0;j<14;j++)
	{
		apt[j]=point[j];
	}
	if(flag==0)
	{
			apt[0].x=5*Width;
			apt[0].y=0;
			apt[1].x=5*Width;
			apt[1].y=3*Width;
			apt[2].x=7*Width;
			apt[2].y=3*Width;
			apt[3].x=7*Width;
			apt[3].y=2*Width;
			apt[4].x=6*Width;
			apt[4].y=2*Width;
			apt[5].x=6*Width;
			apt[5].y=0;
			apt[6]=apt[0];
			apt[7]=apt[0];
			apt[8].x=6;
			apt[8].y=1;
			apt[9].x=6;
			apt[9].y=2;
			apt[10].x=6;
			apt[10].y=3;
			apt[11].x=7;
			apt[11].y=3;
			apt[12].x=0;
			apt[12].y=0;
			//apt[13].x=color;
			}
	else
	{
			apt[0].x=(5+apt[12].x)*Width;
			apt[0].y=(0+apt[12].y)*Width;
			apt[1].x=(5+apt[12].x)*Width;
			apt[1].y=(3+apt[12].y)*Width;
			apt[2].x=(7+apt[12].x)*Width;
			apt[2].y=(3+apt[12].y)*Width;
			apt[3].x=(7+apt[12].x)*Width;
			apt[3].y=(2+apt[12].y)*Width;
			apt[4].x=(6+apt[12].x)*Width;
			apt[4].y=(2+apt[12].y)*Width;
			apt[5].x=(6+apt[12].x)*Width;
			apt[5].y=(0+apt[12].y)*Width;
			apt[6]=apt[0];
			apt[7]=apt[0];
			apt[8].x=(6+apt[12].x);
			apt[8].y=(1+apt[12].y);
			apt[9].x=(6+apt[12].x);
			apt[9].y=(2+apt[12].y);
			apt[10].x=(6+apt[12].x);
			apt[10].y=(3+apt[12].y);
			apt[11].x=(7+apt[12].x);
			apt[11].y=(3+apt[12].y);
			//apt[13].x=color;
	}
	if(sign!=NULL)
	{
		if(sign[apt[8].x][apt[8].y]==1||
			sign[apt[9].x][apt[9].y]==1||
			sign[apt[10].x][apt[10].y]==1||
			sign[apt[11].x][apt[11].y]==1)
		{
//			DeleteObject(hbrush);
			delete []apt;
			return 0;
		}
		else
		{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
		}
	}
	else
	{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
	}
}








int SevenFour(HDC hdc,POINT* point,int flag,int sign[14][23])					//7-4
{
	POINT *apt=new POINT[14];
	HBRUSH hbrush;
	//int color=RGB (rand () % 256, rand () % 256, rand () % 256);
	for(int j=0;j<14;j++)
	{
		apt[j]=point[j];
	}
	if(flag==0)
	{
			apt[0].x=5*Width;
			apt[0].y=1*Width;
			apt[1].x=5*Width;
			apt[1].y=2*Width;
			apt[2].x=8*Width;
			apt[2].y=2*Width;
			apt[3].x=8*Width;
			apt[3].y=0*Width;
			apt[4].x=7*Width;
			apt[4].y=0*Width;
			apt[5].x=7*Width;
			apt[5].y=1*Width;
			apt[6]=apt[0];
			apt[7]=apt[0];
			apt[8].x=6;
			apt[8].y=2;
			apt[9].x=7;
			apt[9].y=2;
			apt[10].x=8;
			apt[10].y=2;
			apt[11].x=8;
			apt[11].y=1;
			apt[12].x=0;
			apt[12].y=0;
			//apt[13].x=color;
			}
	else
	{
			apt[0].x=(5+apt[12].x)*Width;
			apt[0].y=(1+apt[12].y)*Width;
			apt[1].x=(5+apt[12].x)*Width;
			apt[1].y=(2+apt[12].y)*Width;
			apt[2].x=(8+apt[12].x)*Width;
			apt[2].y=(2+apt[12].y)*Width;
			apt[3].x=(8+apt[12].x)*Width;
			apt[3].y=(0+apt[12].y)*Width;
			apt[4].x=(7+apt[12].x)*Width;
			apt[4].y=(0+apt[12].y)*Width;
			apt[5].x=(7+apt[12].x)*Width;
			apt[5].y=(1+apt[12].y)*Width;
			apt[6]=apt[0];
			apt[7]=apt[0];
			apt[8].x=(6+apt[12].x);
			apt[8].y=(2+apt[12].y);
			apt[9].x=(7+apt[12].x);
			apt[9].y=(2+apt[12].y);
			apt[10].x=(8+apt[12].x);
			apt[10].y=(2+apt[12].y);
			apt[11].x=(8+apt[12].x);
			apt[11].y=(1+apt[12].y);
			//apt[13].x=color;
	}
	if(sign!=NULL)
	{
		if(sign[apt[8].x][apt[8].y]==1||
			sign[apt[9].x][apt[9].y]==1||
			sign[apt[10].x][apt[10].y]==1||
			sign[apt[11].x][apt[11].y]==1)
		{
//			DeleteObject(hbrush);
			delete []apt;
			return 0;
		}
		else
		{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
		}
	}
	else
	{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
	}
}






int uSevenOne(HDC hdc,POINT* point,int flag,int sign[14][23])					//~7-1
{
	POINT *apt=new POINT[14];
	HBRUSH hbrush;
	//int color=RGB (rand () % 256, rand () % 256, rand () % 256);
	SelectObject(hdc,GetStockObject(WHITE_BRUSH));
	SetPolyFillMode(hdc,WINDING);
	for(int j=0;j<13;j++)
	{
		apt[j]=point[j];
	}
	if(flag==0)
	{
			apt[0].x=5*Width;
			apt[0].y=0*Width;
			apt[1].x=5*Width;
			apt[1].y=3*Width;
			apt[2].x=6*Width;
			apt[2].y=3*Width;
			apt[3].x=6*Width;
			apt[3].y=1*Width;
			apt[4].x=7*Width;
			apt[4].y=1*Width;
			apt[5].x=7*Width;
			apt[5].y=0*Width;
			apt[6]=apt[0];
			apt[7]=apt[0];
			apt[8].x=6;
			apt[8].y=1;
			apt[9].x=6;
			apt[9].y=2;
			apt[10].x=6;
			apt[10].y=3;
			apt[11].x=7;
			apt[11].y=1;
			apt[12].x=0;
			apt[12].y=0;
			//apt[13].x=color;
		}
	else
	{
			apt[0].x=(5+apt[12].x)*Width;
			apt[0].y=(0+apt[12].y)*Width;
			apt[1].x=(5+apt[12].x)*Width;
			apt[1].y=(3+apt[12].y)*Width;
			apt[2].x=(6+apt[12].x)*Width;
			apt[2].y=(3+apt[12].y)*Width;
			apt[3].x=(6+apt[12].x)*Width;
			apt[3].y=(1+apt[12].y)*Width;
			apt[4].x=(7+apt[12].x)*Width;
			apt[4].y=(1+apt[12].y)*Width;
			apt[5].x=(7+apt[12].x)*Width;
			apt[5].y=(0+apt[12].y)*Width;
			apt[6]=apt[0];
			apt[7]=apt[0];
			apt[8].x=(6+apt[12].x);
			apt[8].y=(1+apt[12].y);
			apt[9].x=(6+apt[12].x);
			apt[9].y=(2+apt[12].y);
			apt[10].x=(6+apt[12].x);
			apt[10].y=(3+apt[12].y);
			apt[11].x=(7+apt[12].x);
			apt[11].y=(1+apt[12].y);
			//apt[13].x=color;
	}
	if(sign!=NULL)
	{
		if(sign[apt[8].x][apt[8].y]==1||
			sign[apt[9].x][apt[9].y]==1||
			sign[apt[10].x][apt[10].y]==1||
			sign[apt[11].x][apt[11].y]==1)
		{
//			DeleteObject(hbrush);
			delete []apt;
			return 0;
		}
		else
		{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
		}
	}
	else
	{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
	}
}




int uSevenTwo(HDC hdc,POINT* point,int flag,int sign[14][23])					//~7-2
{
	POINT *apt=new POINT[14];
	HBRUSH hbrush;
	////int color=RGB (rand () % 256, rand () % 256, rand () % 256);
	for(int j=0;j<13;j++)
	{
		apt[j]=point[j];
	}
	if(flag==0)
	{
			apt[0].x=5*Width;
			apt[0].y=0*Width;
			apt[1].x=5*Width;
			apt[1].y=2*Width;
			apt[2].x=8*Width;
			apt[2].y=2*Width;
			apt[3].x=8*Width;
			apt[3].y=1*Width;
			apt[4].x=6*Width;
			apt[4].y=1*Width;
			apt[5].x=6*Width;
			apt[5].y=0*Width;
			apt[6]=apt[0];
			apt[7]=apt[0];
			apt[8].x=6;
			apt[8].y=1;
			apt[9].x=6;
			apt[9].y=2;
			apt[10].x=7;
			apt[10].y=2;
			apt[11].x=8;
			apt[11].y=2;
			apt[12].x=0;
			apt[12].y=0;
			//apt[13].x=color;
			}
	else
	{
			apt[0].x=(5+apt[12].x)*Width;
			apt[0].y=(0+apt[12].y)*Width;
			apt[1].x=(5+apt[12].x)*Width;
			apt[1].y=(2+apt[12].y)*Width;
			apt[2].x=(8+apt[12].x)*Width;
			apt[2].y=(2+apt[12].y)*Width;
			apt[3].x=(8+apt[12].x)*Width;
			apt[3].y=(1+apt[12].y)*Width;
			apt[4].x=(6+apt[12].x)*Width;
			apt[4].y=(1+apt[12].y)*Width;
			apt[5].x=(6+apt[12].x)*Width;
			apt[5].y=(0+apt[12].y)*Width;
			apt[6]=apt[0];
			apt[7]=apt[0];
			apt[8].x=(6+apt[12].x);
			apt[8].y=(1+apt[12].y);
			apt[9].x=(6+apt[12].x);
			apt[9].y=(2+apt[12].y);
			apt[10].x=(7+apt[12].x);
			apt[10].y=(2+apt[12].y);
			apt[11].x=(8+apt[12].x);
			apt[11].y=(2+apt[12].y);
			//apt[13].x=color;
	}
	if(sign!=NULL)
	{
		if(sign[apt[8].x][apt[8].y]==1||
			sign[apt[9].x][apt[9].y]==1||
			sign[apt[10].x][apt[10].y]==1||
			sign[apt[11].x][apt[11].y]==1)
		{
//			DeleteObject(hbrush);
			delete []apt;
			return 0;
		}
		else
		{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
		}
	}
	else
	{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
	}
}




int uSevenThree(HDC hdc,POINT* point,int flag,int sign[14][23])					//~7-3
{
	POINT *apt=new POINT[14];
	HBRUSH hbrush;
	//int color=RGB (rand () % 256, rand () % 256, rand () % 256);
	for(int j=0;j<13;j++)
	{
		apt[j]=point[j];
	}
	if(flag==0)
	{
			apt[0].x=6*Width;
			apt[0].y=0*Width;
			apt[1].x=6*Width;
			apt[1].y=2*Width;
			apt[2].x=5*Width;
			apt[2].y=2*Width;
			apt[3].x=5*Width;
			apt[3].y=3*Width;
			apt[4].x=7*Width;
			apt[4].y=3*Width;
			apt[5].x=7*Width;
			apt[5].y=0*Width;
			apt[6]=apt[0];
			apt[7]=apt[0];
			apt[8].x=7;
			apt[8].y=1;
			apt[9].x=7;
			apt[9].y=2;
			apt[10].x=7;
			apt[10].y=3;
			apt[11].x=6;
			apt[11].y=3;
			apt[12].x=0;
			apt[12].y=0;
			//apt[13].x=color;
			}
	else
	{

			apt[0].x=(6+apt[12].x)*Width;
			apt[0].y=(0+apt[12].y)*Width;
			apt[1].x=(6+apt[12].x)*Width;
			apt[1].y=(2+apt[12].y)*Width;
			apt[2].x=(5+apt[12].x)*Width;
			apt[2].y=(2+apt[12].y)*Width;
			apt[3].x=(5+apt[12].x)*Width;
			apt[3].y=(3+apt[12].y)*Width;
			apt[4].x=(7+apt[12].x)*Width;
			apt[4].y=(3+apt[12].y)*Width;
			apt[5].x=(7+apt[12].x)*Width;
			apt[5].y=(0+apt[12].y)*Width;
			apt[6]=apt[0];
			apt[7]=apt[0];
			apt[8].x=(7+apt[12].x);
			apt[8].y=(1+apt[12].y);
			apt[9].x=(7+apt[12].x);
			apt[9].y=(2+apt[12].y);
			apt[10].x=(7+apt[12].x);
			apt[10].y=(3+apt[12].y);
			apt[11].x=(6+apt[12].x);
			apt[11].y=(3+apt[12].y);
			//apt[13].x=color;
	}
if(sign!=NULL)
	{
		if(sign[apt[8].x][apt[8].y]==1||
			sign[apt[9].x][apt[9].y]==1||
			sign[apt[10].x][apt[10].y]==1||
			sign[apt[11].x][apt[11].y]==1)
		{
//			DeleteObject(hbrush);
			delete []apt;
			return 0;
		}
		else
		{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
		}
	}
	else
	{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
	}
}




int uSevenFour(HDC hdc,POINT* point,int flag,int sign[14][23])					//~7-4
{
	POINT *apt=new POINT[14];
	HBRUSH hbrush;
	//int color=RGB (rand () % 256, rand () % 256, rand () % 256);
	for(int j=0;j<13;j++)
	{
		apt[j]=point[j];
	}
	if(flag==0)
	{
			apt[0].x=5*Width;
			apt[0].y=0*Width;
			apt[1].x=5*Width;
			apt[1].y=1*Width;
			apt[2].x=7*Width;
			apt[2].y=1*Width;
			apt[3].x=7*Width;
			apt[3].y=2*Width;
			apt[4].x=8*Width;
			apt[4].y=2*Width;
			apt[5].x=8*Width;
			apt[5].y=0*Width;
			apt[6]=apt[0];
			apt[7]=apt[0];
			apt[8].x=6;
			apt[8].y=1;
			apt[9].x=7;
			apt[9].y=1;
			apt[10].x=8;
			apt[10].y=1;
			apt[11].x=8;
			apt[11].y=2;
			apt[12].x=0;
			apt[12].y=0;
			//apt[13].x=color;
			}
	else
	{
			apt[0].x=(5+apt[12].x)*Width;
			apt[0].y=(0+apt[12].y)*Width;
			apt[1].x=(5+apt[12].x)*Width;
			apt[1].y=(1+apt[12].y)*Width;
			apt[2].x=(7+apt[12].x)*Width;
			apt[2].y=(1+apt[12].y)*Width;
			apt[3].x=(7+apt[12].x)*Width;
			apt[3].y=(2+apt[12].y)*Width;
			apt[4].x=(8+apt[12].x)*Width;
			apt[4].y=(2+apt[12].y)*Width;
			apt[5].x=(8+apt[12].x)*Width;
			apt[5].y=(0+apt[12].y)*Width;
			apt[6]=apt[0];
			apt[7]=apt[0];
			apt[8].x=(6+apt[12].x);
			apt[8].y=(1+apt[12].y);
			apt[9].x=(7+apt[12].x);
			apt[9].y=(1+apt[12].y);
			apt[10].x=(8+apt[12].x);
			apt[10].y=(1+apt[12].y);
			apt[11].x=(8+apt[12].x);
			apt[11].y=(2+apt[12].y);
			//apt[13].x=color;
	}
	if(sign!=NULL)
	{
		if(sign[apt[8].x][apt[8].y]==1||
			sign[apt[9].x][apt[9].y]==1||
			sign[apt[10].x][apt[10].y]==1||
			sign[apt[11].x][apt[11].y]==1)
		{
//			DeleteObject(hbrush);
			delete []apt;
			return 0;
		}
		else
		{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
		}
	}
	else
	{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
	}
}









int Tetris(HDC hdc,POINT* point,int flag,int sign[14][23])
{
	POINT *apt=new POINT[14];
	HBRUSH hbrush;
	//int color=RGB (rand () % 256, rand () % 256, rand () % 256);
	for(int j=0;j<13;j++)
			{
				apt[j]=point[j];
			}
	if(flag==0)
	{
			apt[0].x=5*Width;
			apt[0].y=0;
			apt[1].x=5*Width;
			apt[1].y=2*Width;
			apt[2].x=7*Width;
			apt[2].y=2*Width;
			apt[3].x=7*Width;
			apt[3].y=0;
			apt[4]=apt[0];
			apt[5]=apt[0];
			apt[6]=apt[0];
			apt[7]=apt[0];
			apt[8].x=6;
			apt[8].y=1;
			apt[9].x=6;
			apt[9].y=2;
			apt[10].x=7;
			apt[10].y=1;
			apt[11].x=7;
			apt[11].y=2;
			apt[12].x=0;
			apt[12].y=0;
			//apt[13].x=color;
	}
	else
	{
			apt[0].x=(5+apt[12].x)*Width;
			apt[0].y=(0+apt[12].y)*Width;
			apt[1].x=(5+apt[12].x)*Width;
			apt[1].y=(2+apt[12].y)*Width;
			apt[2].x=(7+apt[12].x)*Width;
			apt[2].y=(2+apt[12].y)*Width;
			apt[3].x=(7+apt[12].x)*Width;
			apt[3].y=(0+apt[12].y)*Width;
			apt[4]=apt[0];
			apt[5]=apt[0];
			apt[6]=apt[0];
			apt[7]=apt[0];
			apt[8].x=(6+apt[12].x);
			apt[8].y=(1+apt[12].y);
			apt[9].x=(6+apt[12].x);
			apt[9].y=(2+apt[12].y);
			apt[10].x=(7+apt[12].x);
			apt[10].y=(1+apt[12].y);
			apt[11].x=(7+apt[12].x);
			apt[11].y=(2+apt[12].y);
			//apt[13].x=color;
	}
	if(sign!=NULL)
	{
		if(sign[apt[8].x][apt[8].y]==1||
			sign[apt[9].x][apt[9].y]==1||
			sign[apt[10].x][apt[10].y]==1||
			sign[apt[11].x][apt[11].y]==1)
		{
//			DeleteObject(hbrush);
			delete []apt;
			return 0;
		}
		else
		{	hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
		}
	}
	else
	{
			hbrush=CreateSolidBrush(point[13].x);
			SelectObject(hdc,hbrush);
			SetPolyFillMode(hdc,ALTERNATE);
			Polygon(hdc,apt,8);
			for(int j=0;j<13;j++)
			{
				point[j]=apt[j];
			}
			DeleteObject(hbrush);
			delete []apt;
			return 1;
	}
}

	




int Move(HDC hdc,POINT* apt,int flag,int sign[14][23])
{
	int temp=1;
	HBRUSH hbrush;
	SelectObject(hdc,GetStockObject(WHITE_BRUSH));
	SetPolyFillMode(hdc,WINDING);
	//Polygon(hdc,apt,8);
	switch(flag)
	{
		
		case mLeft:
		{
			/*if(sign[(apt[8].x-1)][apt[8].y]==1||
				sign[(apt[9].x-1)][apt[9].y]==1||
				sign[(apt[10].x-1)][apt[10].y]==1||
				sign[(apt[11].x-1)][apt[11].y]==1);
			else
			{*/
				//SelectObject(hdc,GetStockObject(WHITE_BRUSH));
				//SetPolyFillMode(hdc,WINDING);
				Polygon(hdc,apt,8);
				
				apt[0].x-=Width;
				apt[1].x-=Width;
				apt[2].x-=Width;
				apt[3].x-=Width;
				apt[4].x-=Width;
				apt[5].x-=Width;
				apt[6].x-=Width;
				apt[7].x-=Width;
				apt[8].x-=1;
				apt[9].x-=1;
				apt[10].x-=1;
				apt[11].x-=1;
				apt[12].x-=1;
				hbrush=CreateSolidBrush(apt[13].x);
				SelectObject(hdc,hbrush);
				SetPolyFillMode(hdc,ALTERNATE);
				Polygon(hdc,apt,8);
				DeleteObject(hbrush);
			//}
		}
		break;
	case mRight:
		{
			//SelectObject(hdc,GetStockObject(WHITE_BRUSH));
	//SetPolyFillMode(hdc,WINDING);
	Polygon(hdc,apt,8);

			/*if(sign[(apt[8].x+1)][apt[8].y]==1||
				sign[(apt[9].x+1)][apt[9].y]==1||
				sign[(apt[10].x+1)][apt[10].y]==1||
				sign[(apt[11].x+1)][apt[11].y]==1);
			else
			{*/
			

				
				apt[0].x+=Width;
				apt[1].x+=Width;
				apt[2].x+=Width;
				apt[3].x+=Width;
				apt[4].x+=Width;
				apt[5].x+=Width;
				apt[6].x+=Width;
				apt[7].x+=Width;
				apt[8].x+=1;
				apt[9].x+=1;
				apt[10].x+=1;
				apt[11].x+=1;
				apt[12].x+=1;
				hbrush=CreateSolidBrush(apt[13].x);
				SelectObject(hdc,hbrush);
				SetPolyFillMode(hdc,ALTERNATE);
				Polygon(hdc,apt,8);
				DeleteObject(hbrush);
			//}
		}
		break;
	case mDown:
		{
			
				Polygon(hdc,apt,8);
				apt[0].y+=Width;
				apt[1].y+=Width;
				apt[2].y+=Width;
				apt[3].y+=Width;
				apt[4].y+=Width;
				apt[5].y+=Width;
				apt[6].y+=Width;
				apt[7].y+=Width;
				apt[8].y+=1;
				apt[9].y+=1;
				apt[10].y+=1;
				apt[11].y+=1;
				apt[12].y+=1;
				hbrush=CreateSolidBrush(apt[13].x);
				SelectObject(hdc,hbrush);
				SetPolyFillMode(hdc,ALTERNATE);
				Polygon(hdc,apt,8);
				DeleteObject(hbrush);
			//}
		}
		break;


	case Change:
		{
			if(Juadge(apt,sign))
			{
				Polygon(hdc,apt,8);
				switch(i)
						{
						case 1:	if(temp=LineC(hdc,apt,1,sign)==1)
								i=2;
								break;
						case 2:if(temp=LineU(hdc,apt,1,sign)==1)
								i=1;
								break;
						case 3:if(temp=Up(hdc,apt,1,sign)==1)
								i=5;
								break;
						case 4:if(temp=Down(hdc,apt,1,sign)==1)
								i=6;
								break;
						case 5:if(temp=Right(hdc,apt,1,sign)==1)
								i=4;
								break;
						case 6:if(temp=Left(hdc,apt,1,sign)==1)
								i=3;
								break;
						case 7:if(temp=zDown(hdc,apt,1,sign)==1)
								i=10;
								break;
						case 8:if(temp=zUp(hdc,apt,1,sign)==1)
								i=9;
								break;
						case 9:if(temp=zRight(hdc,apt,1,sign)==1)
								i=8;
								break;
						case 10:if(temp=zLeft(hdc,apt,1,sign)==1)
								i=7;
								break;
						case 11:if(temp=Tetris(hdc,apt,1,sign)==1)
								i=11;
								break;
						case 12:if(temp=SevenFour(hdc,apt,1,sign)==1)
								i=15;
								break;
						case 13:if(temp=SevenOne(hdc,apt,1,sign)==1)
								i=12;
								break;
						case 14:if(temp=SevenTwo(hdc,apt,1,sign)==1)
								i=13;
								break;
						case 15:if(temp=SevenThree(hdc,apt,1,sign)==1)
								i=14;
								break;
						case 16:if(temp=uSevenFour(hdc,apt,1,sign)==1)
								i=19;
								break;
						case 17:if(temp=uSevenOne(hdc,apt,1,sign)==1)
								i=16;
								break;
						case 18:if(temp=uSevenTwo(hdc,apt,1,sign)==1)
								i=17;	
								break;
						case 19:if(temp=uSevenThree(hdc,apt,1,sign)==1)
								i=18;
								break;
						}
				hbrush=CreateSolidBrush(apt[13].x);
				SelectObject(hdc,hbrush);
				SetPolyFillMode(hdc,ALTERNATE);
				Polygon(hdc,apt,8);
				DeleteObject(hbrush);
			}
		}
		break;
		
	case fDown:
		{
			while(sign[(apt[8].x)][apt[8].y+1]==0&&
				sign[(apt[9].x)][apt[9].y+1]==0&&
				sign[(apt[10].x)][apt[10].y+1]==0&&
				sign[(apt[11].x)][apt[11].y+1]==0)
			{
				//SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
				//SetPolyFillMode(hdc,ALTERNATE);
				Move(hdc,apt,mDown,sign);
				//Polygon(hdc,apt,8);
			}
			//Move(hdc,apt,mDown,sign);
		}
		break;
	}
	
	//Paint(hdc,sign);
	return temp;
}







int Rund_(HDC hdc,POINT* apt,int flag)
{	
	
	switch(flag)
	{
	case 1: LineU(hdc,apt,1);
			break;
	case 2: LineC(hdc,apt,1);
			break;
	case 3: Left(hdc,apt,1);
			break;
	case 4: Right(hdc,apt,1);
			break;
	case 5: Up(hdc,apt,1);
			break;
	case 6: Down(hdc,apt,1);
			break;
	case 7: zLeft(hdc,apt,1);
			break;
	case 8: zRight(hdc,apt,1);
			break;
	case 9: zUp(hdc,apt,1);
			break;
	case 10: zDown(hdc,apt,1);
			break;
	case 11: Tetris(hdc,apt,1);
			break;
	case 12:SevenOne(hdc,apt,1);
			break;
	case 13:SevenTwo(hdc,apt,1);
			break;
	case 14:SevenThree(hdc,apt,1);
			break;
	case 15:SevenFour(hdc,apt,1);
			break;
	case 16:uSevenOne(hdc,apt,1);
			break;
	case 17:uSevenTwo(hdc,apt,1);
			break;
	case 18:uSevenThree(hdc,apt,1);
			break;
	case 19:uSevenFour(hdc,apt,1);
			break;


	}
	return flag;
}
	
void ReStart(HDC hdc,int flag[14][23])
{
	int j=0,k=0;
	for(j=0;j<14;j++)
	{
		for(k=0;k<23;k++)
		{
			flag[j][k]=0;
		}
	}
	for(j=0;j<14;j++)
	{
		//flag[i][0]=1;
		flag[j][22]=1;
	}
	for(j=0;j<23;j++)
	{
		flag[0][j]=1;
		flag[13][j]=1;
	}
	Paint(hdc,flag);
}





void Paint(HDC hdc,int flag[14][23])
{
	int i=0;
	int j=0;
	HBRUSH hbrush;
	//HPEN hPen;
	for(i=1;i<13;i++)
	{
		for(j=1;j<22;j++)
		{
			if(flag[i][j]!=0)
			{
				POINT apt[4]={0};
				apt[0].x=(i-1)*Width;
				apt[0].y=(j-1)*Width;
				apt[1].x=(i-1)*Width;
				apt[1].y=j*Width;
				apt[2].x=i*Width;
				apt[2].y=j*Width;
				apt[3].x=i*Width;
				apt[3].y=(j-1)*Width;
				hbrush=CreateSolidBrush(flag[i][j]);;
				SelectObject(hdc,hbrush);;

				//SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
				//CreateSolidBrush(1224);
				SetPolyFillMode(hdc,ALTERNATE);
				Polygon(hdc,apt,4);
				DeleteObject(hbrush);
			}
			else
			{
				POINT apt[4]={0};
				apt[0].x=(i-1)*Width;
				apt[0].y=(j-1)*Width;
				apt[1].x=(i-1)*Width;
				apt[1].y=j*Width;
				apt[2].x=i*Width;
				apt[2].y=j*Width;
				apt[3].x=i*Width;
				apt[3].y=(j-1)*Width;

				//hbrush=CreateSolidBrush(WHITE_BRUSH);
				SelectObject(hdc,GetStockObject(WHITE_BRUSH));
				SetPolyFillMode(hdc,ALTERNATE);
				Polygon(hdc,apt,4);
				DeleteObject(hbrush);
			}
		}
	}
	
	//DeleteObject(hPen);
}


void Disapper(int flag[14][23],int rayl)
{
		int i=1;
		int j=1;
		for(i=rayl;i>0;i--)
		{
			for(j=1;j<13;j++)
			{
				flag[j][i]=flag[j][i-1];
			}
		}
}

void Write_i(int temp)
{
	i=temp;
}

int Read_i()
{
	return i;
}




bool Juadge(POINT* apt,int sign[14][23])
{
	POINT point[14];
	for(int t0=0;t0<14;t0++)
	{
		point[t0]=apt[t0];
	}

	switch(i)
	{
		case 1:	if(LineC(NULL,point,1,sign)==1)
				//i=2;
				break;
		case 2:if(LineU(NULL,point,1,sign)==1)
				//i=1;
				break;
		case 3:if(Up(NULL,point,1,sign)==1)
				//i=5;
				break;
		case 4:if(Down(NULL,point,1,sign)==1)
				//i=6;
				break;
		case 5:if(Right(NULL,point,1,sign)==1)
				//i=4;
				break;
		case 6:if(Left(NULL,point,1,sign)==1)
				//i=3;
				break;
		case 7:if(zDown(NULL,point,1,sign)==1)
				//i=10;
				break;
		case 8:if(zUp(NULL,point,1,sign)==1)
				//i=9;
				break;
		case 9:if(zRight(NULL,point,1,sign)==1)
				//i=8;
				break;
		case 10:if(zLeft(NULL,point,1,sign)==1)
				//i=7;
				break;
		case 11:if(Tetris(NULL,point,1,sign)==1)
				//i=11;
				break;
		case 12:if(SevenFour(NULL,point,1,sign)==1)
				//i=15;
				break;
		case 13:if(SevenOne(NULL,point,1,sign)==1)
				//i=12;
				break;
		case 14:if(SevenTwo(NULL,point,1,sign)==1)
				//i=13;
				break;
		case 15:if(SevenThree(NULL,point,1,sign)==1)
				//i=14;
				break;
		case 16:if(uSevenFour(NULL,point,1,sign)==1)
				//i=19;
				break;
		case 17:if(uSevenOne(NULL,point,1,sign)==1)
				//i=16;
				break;
		case 18:if(uSevenTwo(NULL,point,1,sign)==1)
				//i=17;	
				break;
		case 19:if(uSevenThree(NULL,point,1,sign)==1)
				//i=18;
				break;
	}

	if(sign[(point[8].x)][point[8].y]==0&&
		sign[(point[9].x)][point[9].y]==0&&
		sign[(point[10].x)][point[10].y]==0&&
		sign[(point[11].x)][point[11].y]==0)
	{
		return true;
	}
	else
	{
		return false;
	}

}