#define mLeft	1
#define mRight	2
#define mDown	3
#define fDown	4
#define Change	5
#define Stop	6
#define Restart 7
#define STATUS	8
#define READ	9
#define SAVE	10
#define CLEAR	11
#define TIMER	12


int Rund(HDC hdc,POINT*,int,int[14][23]);
int Rund_(HDC hdc,POINT*, int);

int LineU(HDC,POINT*,int flag,int[14][23]=NULL);
int LineC(HDC,POINT*,int flag,int[14][23]=NULL);
int Left(HDC,POINT*,int flag,int[14][23]=NULL);
int Right(HDC,POINT*,int flag,int[14][23]=NULL);
int Up(HDC hdc,POINT* apt,int flag,int[14][23]=NULL);
int Down(HDC hdc,POINT* apt,int flag,int[14][23]=NULL);
int zLeft(HDC hdc,POINT* apt,int flag,int[14][23]=NULL);
int zRight(HDC hdc,POINT* apt,int flag,int[14][23]=NULL);
int zUp(HDC hdc,POINT* apt,int flag,int[14][23]=NULL);
int zDown(HDC hdc,POINT* apt,int flag,int[14][23]=NULL);
int SevenOne(HDC hdc,POINT* apt,int flag,int[14][23]=NULL);
int SevenTwo(HDC hdc,POINT* apt,int flag,int[14][23]=NULL);
int SevenThree(HDC hdc,POINT* apt,int flag,int[14][23]=NULL);
int SevenFour(HDC hdc,POINT* apt,int flag,int[14][23]=NULL);
int uSevenOne(HDC hdc,POINT* apt,int flag,int[14][23]=NULL);
int uSevenTwo(HDC hdc,POINT* apt,int flag,int[14][23]=NULL);
int uSevenThree(HDC hdc,POINT* apt,int flag,int[14][23]=NULL);
int uSevenFour(HDC hdc,POINT* apt,int flag,int[14][23]=NULL);
int Tetris(HDC hdc,POINT*apt,int flag,int[14][23]=NULL);

void Initial(HDC hdc);

int Move(HDC,POINT*,int,int flag[14][23]);
bool Juadge(POINT*,int sign[14][23]);
void Paint(HDC,int flag[14][23]);

void Disapper(int flag[14][23],int Line);



void ReStart(HDC,int flag[14][23]);

void Write_i(int temp);
int Read_i();
