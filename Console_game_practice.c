#include <stdio.h>
#include <windows.h>


/* 해야할 것
attack 키는 ctrl 로 받기 
방향표 전환 하는 방법 

하고 나서 게임설명 탭으로 가는 방법 
게임 실행하기
참고 사이트는 즐겨찾기에 
*/ 

 
// 키보드 값
#define up 0
#define down 1
#define left 2 
#define right 3
#define submit 4
#define attack 5
// attack 은 a 키로 
 
// <- 75 -> 77 위 72 아래 80 
//getch 는 enter를 누르지 않아도 바로 반환해주는 함수  
// 함수 원형 선언  
int keyControl(); 
void init();  // 콘솔창 꾸미기 
void titleDraw();  // 제목 띄워주는 함수
void gotoxy(int, int); // 커서 움직일 때 쓰이는 부가적 함수
void menuDraw(); // 커서 움직이는 함수 + 메인 화면  

int main(){
	init();
	titleDraw(); 
	menuDraw();
	int keyCode = keyControl();
	
	return 0;  
}

int keyControl(){
	// 방향키는 224 ㅁ 이런 식으로 두 개의 키를 연속으로 받기 때문에 getch를 두 번 해야한다.  
	char temp = _getch();
	if (temp == -32){
	temp = _getch();
	}
	

	if (temp == 75){
		return left;
	}
	else if (temp == 77){
		return right;
	}
	else if (temp == 72){
		return up;
	}
	else if (temp == 80){
		return down;
	}
	else if (temp == ' '){
		return submit;
	}
	else if (temp == 97){
		return attack;
	}

} 

void init(){ 
	system("mode con cols = 56 lines = 20 | title 너가 죽던가 내가 죽던가");
}

void titleDraw(){
	printf("\n\n\n\n");
	printf("#       # # ##   #     #### ####    #   #### #### ####  \n");
	printf(" #     #  # # #  #     #  # #  #    #   #  # #    #     \n");
	printf(" #  #  #  # #  # #     #  # ###     #   #  # #### ####  \n");
	printf("  # # #   # #  # #     #  # # #     #   #  #    # #     \n");
	printf("  #   #   # #   ##     #### #  #    ### #### #### ####  \n");
} 

void gotoxy(int x, int y){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void menuDraw(){
	int x = 24;
	int y = 12;
	gotoxy(x-2, y);
	printf("> 게임 시작");
	gotoxy(x, y+1);
	printf("게임설명");
	gotoxy(x, y + 1); 
	printf("종료");
	
	while(1){
		int n = keyControl();
		switch(n){
			case up: { 
				if (y > 12){
					gotoxy(x- 2, y);
					printf(" ");
					gotoxy(x-2, --y);
					printf(">");
				}
				break;
			}
			
			case down: {
				if(y < 14){
					gotoxy(x-2,y);
					printf(" ");
					gotoxy(x-2, ++y);
					printf(">");
				}
				break;
			}
			
			case submit: {
				return y -12; // 원래 시작 위치가 12 였으므로 y -12 하면은 0, 1, 2 중에서 숫자를 받으니 선택이 가능하다. 즉 다음 화면으로 넘어가기 수월.  
			}
		}
	}
} 



