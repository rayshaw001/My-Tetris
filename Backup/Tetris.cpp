#include"Tetris.h"
#include "stdafx.h"
#include"time.h"

static int i=0;


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











int Rund(HDC hdc,POINT* apt,int flag)
{	
	
	i=flag;
	switch(flag)
	{
	case 1: LineU(hdc,apt,0);
			break;
	case 2: LineC(hdc,apt,0);
			break;
	case 3: Left(hdc,apt,0);
			break;
	case 4: Right(hdc,apt,0);
			break;
	case 5: Up(hdc,apt,0);
			break;
	case 6: Down(hdc,apt,0);
			break;
	case 7: zLeft(hdc,apt,0);
			break;
	case 8: zRight(hdc,apt,0);
			break;
	case 9: zUp(hdc,apt,0);
			break;
	case 10: zDown(hdc,apt,0);
			break;
	case 11: Tetris(hdc,apt,0);
			break;
	case 12:SevenOne(hdc,apt,0);
			break;
	case 13:SevenTwo(hdc,apt,0);
			break;
	case 14:SevenThree(hdc,apt,0);
			break;
	case 15:SevenFour(hdc,apt,0);
			break;
	case 16:uSevenOne(hdc,apt,0);
			break;
	case 17:uSevenTwo(hdc,apt,0);
			break;
	case 18:uSevenThree(hdc,apt,0);
			break;
	case 19:uSevenFour(hdc,apt,0);
			break;


	}
	return i;
}
	







void LineU(HDC hdc,POINT *apt,int flag)
{
	if(flag==0)
	{
			SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
			SetPolyFillMode(hdc,ALTERNATE);
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
			Polygon(hdc,apt,4);
	}
	else
	{
		

		SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
			SetPolyFillMode(hdc,ALTERNATE);
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
			Polygon(hdc,apt,4);
	}

		
}


void LineC(HDC hdc,POINT *apt,int flag)
{
	if(flag==0)
	{
	
			SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
			SetPolyFillMode(hdc,ALTERNATE);
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
			Polygon(hdc,apt,4);
			}
	else
	{
		SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
			SetPolyFillMode(hdc,ALTERNATE);
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
			Polygon(hdc,apt,4);
	}


}




void Left(HDC hdc,POINT* apt,int flag)
{

	if(flag==0)
	{
	
			SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
			SetPolyFillMode(hdc,ALTERNATE);
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
			Polygon(hdc,apt,8);
			}
	else
	{
		SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
		SetPolyFillMode(hdc,ALTERNATE);
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
		Polygon(hdc,apt,8);
	}
		
}


void Right(HDC hdc,POINT* apt,int flag)
{
	
	if(flag==0)
	{
	
			SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
			SetPolyFillMode(hdc,ALTERNATE);
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
			Polygon(hdc,apt,8);
						}
	else
	{
		SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
		SetPolyFillMode(hdc,ALTERNATE);
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
		Polygon(hdc,apt,8);
	}
		
}


void Up(HDC hdc,POINT* apt,int flag)
{
	if(flag==0)
	{
	
			SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
			SetPolyFillMode(hdc,WINDING);
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
			Polygon(hdc,apt,8);
	}
	else
	{
		SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
		SetPolyFillMode(hdc,ALTERNATE);
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
		Polygon(hdc,apt,8);
	}
		
		
}

void Down(HDC hdc,POINT* apt,int flag)
{
	if(flag==0)
	{
	
			SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
			SetPolyFillMode(hdc,WINDING);
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
			Polygon(hdc,apt,8);
	}
	else
	{
		SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
		SetPolyFillMode(hdc,ALTERNATE);
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
		Polygon(hdc,apt,8);
	}
	
		
	
}







void zLeft(HDC hdc,POINT* apt,int flag)
{
	if(flag==0)
	{
	
	
			SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
			SetPolyFillMode(hdc,WINDING);
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
			Polygon(hdc,apt,8);
			}
	else
	{
		SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
		SetPolyFillMode(hdc,ALTERNATE);
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
		Polygon(hdc,apt,8);
	}
		
}




void zRight(HDC hdc,POINT* apt,int flag)
{
	if(flag==0)
	{
			SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
			SetPolyFillMode(hdc,ALTERNATE);
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
			Polygon(hdc,apt,8);
			}
	else
	{
		SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
		SetPolyFillMode(hdc,ALTERNATE);
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
		Polygon(hdc,apt,8);
	}
		
}


void zUp(HDC hdc,POINT* apt,int flag)
{
	if(flag==0)
	{
	
			SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
			SetPolyFillMode(hdc,ALTERNATE);
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
			Polygon(hdc,apt,8);
			}
	else
	{
		SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
		SetPolyFillMode(hdc,ALTERNATE);
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
		Polygon(hdc,apt,8);
	}
		
}




void zDown(HDC hdc,POINT* apt,int flag)
{
	if(flag==0)
	{
			SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
			SetPolyFillMode(hdc,ALTERNATE);
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
			Polygon(hdc,apt,8);
			}
	else
	{
		SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
		SetPolyFillMode(hdc,ALTERNATE);
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
		Polygon(hdc,apt,8);
	}
	
}



void SevenOne(HDC hdc,POINT* apt,int flag)					//7-1
{
	if(flag==0)
	{
			SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
			SetPolyFillMode(hdc,ALTERNATE);
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
			Polygon(hdc,apt,8);
			}
	else
	{
		SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
		SetPolyFillMode(hdc,ALTERNATE);
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
		Polygon(hdc,apt,8);
	}
}




void SevenTwo(HDC hdc,POINT* apt,int flag)					//7-2
{
	if(flag==0)
	{
			SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
			SetPolyFillMode(hdc,ALTERNATE);
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
			Polygon(hdc,apt,8);
	}
	else
	{
		SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
		SetPolyFillMode(hdc,ALTERNATE);
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
		Polygon(hdc,apt,8);
	}
}




void SevenThree(HDC hdc,POINT* apt,int flag)					//7-3
{
	if(flag==0)
	{
			SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
			SetPolyFillMode(hdc,ALTERNATE);
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
			Polygon(hdc,apt,8);
			}
	else
	{
		SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
		SetPolyFillMode(hdc,ALTERNATE);
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
		Polygon(hdc,apt,8);
	}
}







void SevenFour(HDC hdc,POINT* apt,int flag)					//7-4
{
	if(flag==0)
	{
			SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
			SetPolyFillMode(hdc,ALTERNATE);
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
			Polygon(hdc,apt,8);
			}
	else
	{
		SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
		SetPolyFillMode(hdc,ALTERNATE);
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
		Polygon(hdc,apt,8);
	}
}






void uSevenOne(HDC hdc,POINT* apt,int flag)					//~7-1
{

	if(flag==0)
	{

			SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
			SetPolyFillMode(hdc,ALTERNATE);
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
			Polygon(hdc,apt,8);
			}
	else
	{
		SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
		SetPolyFillMode(hdc,ALTERNATE);
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
		Polygon(hdc,apt,8);
	}
}





void uSevenTwo(HDC hdc,POINT* apt,int flag)					//~7-2
{
	if(flag==0)
	{
			SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
			SetPolyFillMode(hdc,ALTERNATE);
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
			Polygon(hdc,apt,8);
			}
	else
	{
		SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
		SetPolyFillMode(hdc,ALTERNATE);
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
		Polygon(hdc,apt,8);
	}
}




void uSevenThree(HDC hdc,POINT* apt,int flag)					//~7-3
{
	if(flag==0)
	{
			SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
			SetPolyFillMode(hdc,ALTERNATE);
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
			Polygon(hdc,apt,8);
			}
	else
	{

		SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
		SetPolyFillMode(hdc,ALTERNATE);
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
		Polygon(hdc,apt,8);
	}
}




void uSevenFour(HDC hdc,POINT* apt,int flag)					//~7-4
{
	if(flag==0)
	{
			SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
			SetPolyFillMode(hdc,ALTERNATE);
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
			Polygon(hdc,apt,8);
			}
	else
	{
		SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
		SetPolyFillMode(hdc,ALTERNATE);
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
		Polygon(hdc,apt,8);
	}
}









void Tetris(HDC hdc,POINT* apt,int flag)
{
	if(flag==0)
	{
			SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
			SetPolyFillMode(hdc,ALTERNATE);
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
			Polygon(hdc,apt,4);
			}
	else
	{
		SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
		SetPolyFillMode(hdc,ALTERNATE);
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
		Polygon(hdc,apt,8);
	}
	
}



void Move(HDC hdc,POINT* apt,int flag,int sign[14][23])
{
	SelectObject(hdc,GetStockObject(WHITE_BRUSH));
	SetPolyFillMode(hdc,WINDING);
	Polygon(hdc,apt,8);
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
				SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
				SetPolyFillMode(hdc,ALTERNATE);
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
				Polygon(hdc,apt,8);
			//}
		}
		break;
	case mRight:
		{


			/*if(sign[(apt[8].x+1)][apt[8].y]==1||
				sign[(apt[9].x+1)][apt[9].y]==1||
				sign[(apt[10].x+1)][apt[10].y]==1||
				sign[(apt[11].x+1)][apt[11].y]==1);
			else
			{*/
				SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
				SetPolyFillMode(hdc,ALTERNATE);
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

				Polygon(hdc,apt,8);
			//}
		}
		break;
	case mDown:
		{
			/*if(sign[(apt[8].x)][apt[8].y+1]==1||
				sign[(apt[9].x)][apt[9].y+1]==1||
				sign[(apt[10].x)][apt[10].y+1]==1||
				sign[(apt[11].x)][apt[11].y+1]==1)
			{
				sign[apt[8].x][apt[8].y]=1;
				sign[apt[9].x][apt[9].y]=1;
				sign[apt[10].x][apt[10].y]=1;
				sign[apt[11].x][apt[11].y]=1;
			}
			else
			{*/
				SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
				SetPolyFillMode(hdc,ALTERNATE);
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
				Polygon(hdc,apt,8);
			//}
		break;
		}



	case Change:
		{

			switch(i)
					{
					case 1:	
						if(sign[apt[8].x][apt[8].y])
						{
						}
						LineC(hdc,apt,1);
							i=2;
							break;
					case 2:
						if(sign[apt[8].x-1][apt[8].y]==1||
							sign[apt[9].x-1][apt[9].y]==1||
							sign[apt[10].x-1][apt[10].y]==1||
							sign[apt[11].x-1][apt[11].y]==1||
							sign[apt[8].x+1][apt[8].y]==1||
							sign[apt[9].x+1][apt[8].y]==1||
							sign[apt[10].x+1][apt[8].y]==1||
							sign[apt[11].x+1][apt[8].y]==1);
						else
						{
							LineU(hdc,apt,1);
							i=1;
						}
							break;
					case 3: Up(hdc,apt,1);
							i=5;
							break;
					case 4:Down(hdc,apt,1);
							i=6;
							break;
					case 5: Right(hdc,apt,1);
							i=4;
							break;
					case 6:Left(hdc,apt,1);
							i=3;
							break;
					case 7: zDown(hdc,apt,1);
							i=10;
							break;
					case 8: zUp(hdc,apt,1);
							i=9;
							break;
					case 9: zRight(hdc,apt,1);
							i=8;
							break;
					case 10: zLeft(hdc,apt,1);
							i=7;
							break;
					case 11: Tetris(hdc,apt,1);
							i=11;
							break;
					case 12:SevenFour(hdc,apt,1);
							i=15;
							break;
					case 13:SevenOne(hdc,apt,1);
							i=12;
							break;
					case 14:SevenTwo(hdc,apt,1);
							i=13;
							break;
					case 15:SevenThree(hdc,apt,1);
							i=14;
							break;
					case 16:uSevenFour(hdc,apt,1);
							i=19;
							break;
					case 17:uSevenOne(hdc,apt,1);
							i=16;
							break;
					case 18:uSevenTwo(hdc,apt,1);
							i=17;	
							break;
					case 19:uSevenThree(hdc,apt,1);
							i=18;
							break;
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
		}
		break;
	default:;
		/*SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
		SetPolyFillMode(hdc,ALTERNATE);
		Polygon(hdc,apt,8);*/
	}
}



void Paint(HDC hdc,int flag[14][23])
{
	int i=0;
	int j=0;
	for(i=1;i<13;i++)
	{
		for(j=1;j<22;j++)
		{
			if(flag[i][j]==1)
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
				SelectObject(hdc,GetStockObject(LTGRAY_BRUSH));
				SetPolyFillMode(hdc,ALTERNATE);
				Polygon(hdc,apt,4);
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
				SelectObject(hdc,GetStockObject(WHITE_BRUSH));
				SetPolyFillMode(hdc,ALTERNATE);
				Polygon(hdc,apt,4);
			}
		}
	}
}


void Disapper(int flag[14][23],int rayl)
{
		int i=1;
		int j=1;
		for(i=rayl;i>1;i--)
		{
			for(j=1;j<13;j++)
			{
				flag[j][i]=flag[j][i-1];
			}
		}
}











////  zUp----zRight
////  zDown----zLeft




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
	
int Judge(POINT const * const apt,int flag[14][23]);





