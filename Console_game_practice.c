#include <stdio.h>
#include <windows.h>


/* �ؾ��� ��
attack Ű�� ctrl �� �ޱ� 
����ǥ ��ȯ �ϴ� ��� 

�ϰ� ���� ���Ӽ��� ������ ���� ��� 
���� �����ϱ�
���� ����Ʈ�� ���ã�⿡ 
*/ 

 
// Ű���� ��
#define up 0
#define down 1
#define left 2 
#define right 3
#define submit 4
#define attack 5
// attack �� a Ű�� 
 
// <- 75 -> 77 �� 72 �Ʒ� 80 
//getch �� enter�� ������ �ʾƵ� �ٷ� ��ȯ���ִ� �Լ�  
// �Լ� ���� ����  
int keyControl(); 
void init();  // �ܼ�â �ٹ̱� 
void titleDraw();  // ���� ����ִ� �Լ�
void gotoxy(int, int); // Ŀ�� ������ �� ���̴� �ΰ��� �Լ�
void menuDraw(); // Ŀ�� �����̴� �Լ� + ���� ȭ��  

int main(){
	init();
	titleDraw(); 
	menuDraw();
	int keyCode = keyControl();
	
	return 0;  
}

int keyControl(){
	// ����Ű�� 224 �� �̷� ������ �� ���� Ű�� �������� �ޱ� ������ getch�� �� �� �ؾ��Ѵ�.  
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
	system("mode con cols = 56 lines = 20 | title �ʰ� �״��� ���� �״���");
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
	printf("> ���� ����");
	gotoxy(x, y+1);
	printf("���Ӽ���");
	gotoxy(x, y + 1); 
	printf("����");
	
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
				return y -12; // ���� ���� ��ġ�� 12 �����Ƿ� y -12 �ϸ��� 0, 1, 2 �߿��� ���ڸ� ������ ������ �����ϴ�. �� ���� ȭ������ �Ѿ�� ����.  
			}
		}
	}
} 



