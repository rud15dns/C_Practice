#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
	int player;
	int com;
	int count = 0;
	
	int high = 100;
	int low = 1;
	
	
	srand(time(NULL));
	com = rand() % 100 + 1;

	
	while(1){
		count++;
		printf("write the number %d ~ %d: ", low, high);
		scanf("%d", &player);
		
		
		
		if (com < player){
			printf("High\n");
			high = player;
		}
		else if (com > player){
			printf("Low\n");
			low = player;
	
		}
		else{
			printf("%d times you tried. you win\n", count);
			break;
		}
	}
	system("pause");
	return 0;
}
