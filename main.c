#include <stdio.h> 
#include <math.h>
#include <time.h>
#include <stdlib.h>

/***Summary***
 
	1 - Happy tickets 
	2 - Defined random massive
	3 - Bubble sorting
	4 - HZ

	***Commons***
	0 - Exit
	5 - Help Desk
	8 - About
*/

//Section voids list
void desk_list();
void tickets();
void ran_Massive();
void sorting(int option);
void mass_different();


int main(int argc, char const *argv[])
{
	int command;
	short abort;

	printf("ExersicerComLine: Welcome!\n");
	abort = 1;
	do
	{
		printf("\nExersicerComLine: To help - 5, To exit - 0. Waiting for input...\n");
		scanf("%i", &command);
		switch (command)
		{
			case 1: 
				tickets();
				break;
			case 2:
				ran_Massive();
				break;
			case 3:
				sorting(1);
				break;
			case 4:
				sorting(2);
				break;
			case 5:
				mass_different();
				break;
			case 0:
				abort = 0;
				break;
			case 8:
				desk_list();
				break;
			case 9:
				printf("\nCreat by M.Ignatov. Made with GCC.\n\n");
				break;
			default:
				printf("ExersicerComLine: Unknown command. Please correct you command and try again.\n");
				break;
		};
	}while (abort == 1);
	return 0;
}


void desk_list(){
	printf("\nExersicerComLine:\n\n ****Menu****\n 1. Happy Tickets; \n 2. Defined random massive;\n 3. Bubble sorting;\n 4. Select sorting.\n ************\n");
}

void tickets(){

	printf("\nExersicerComLine: Happy Tickets\n\n");
	clock_t st = clock();//start timer
	int count, a, b, lside, rside;
	double timer;
	
	count = 1;

	for (int i = 1; i <= 999999; i++)
	{
		rside = i; //v
		lside = 0; //z

		//сount sum of last three numbers
		while (lside < 3)
		{
			lside += 1;
			a = (rside % 10) + a;
			rside = rside / 10;
		} 

		//count sum of first three numbers
		while (lside < 6)
		{
			lside += 1;
			b = (rside % 10) + b;
			rside = rside / 10;
		}

		if (a == b) count += 1;
		a = 0;
		b = 0;
	}
	clock_t end = clock();//stop timer
	timer = (double)(end - st) / CLOCKS_PER_SEC;
	printf("-- Count of happy tickets: %i in %f \n\n", count, timer);
}

void ran_Massive(){
	int a_var, b_var, rand(void), size;
	
	//pointers
	int *mass;

	printf("\nExersicerComLine: Defined random massive\n\n");

	printf("-- Enter two random numbers, separating by spaces:\n-- ");
	scanf("%d %d", &a_var, &b_var);

	//Calculate size of massive and range
	size = rand() % 80;
	a_var = a_var + rand() % (b_var - a_var + 1);
	b_var = a_var + rand() % (b_var - a_var + 1);

	mass = calloc(size, sizeof(int));
	
	//printf("-- Size of massive: %d\n", size);

	for (int i = 0; i < size; i++)
	{
		mass[i] = rand() % 100;
		printf("-- %d. %d \n", i, mass[i]);
	}

	b_var = 0;

	//Local search loop
	do{
		a_var = 0;

		printf("\n-- Enter the number for which you want to determine the index(es):\n-- ");
		scanf("%d", &a_var);

		int k = 0;
		
		for (int j = 0; j < size; j++){
			if (mass[j] == a_var) k++;
		}

		if (k == 0){
			printf("-- Entered number %d haven't indexes!\n", a_var);
		} 
		else{
			k = 0;
			printf("-- Entered number %d have next indexes:\n", a_var);
			for (int j = 0; j < size; j++){
				if (mass[j] == a_var) printf("-- %d. %d \n", ++k, j);
			}
		}
		
		printf("\n-- Continue search? Yes=0, No=1\n-- ");
		scanf("%d", &b_var);
	}while(b_var == 0);
	
	free(mass);
}

void sorting(int option){
	int size, temp, k;
	int *block;

	printf("\n-- Enter the number of size of massive:\n-- ");
	scanf("%d", &size);

	// allocate memory
	block = calloc(size, sizeof(int));

	// fill in massive with random values
	printf("\n-- Initial massive:\n");
	for (int i = 0; i < size; i++){
		block[i] = rand() % 500;
		printf("-- %d. %d \n", i, block[i]);
	}

	printf("\n-- Sorted massive:\n");
	switch (option)
	{		
		// Bubble Sorting
		case 1:
			temp = 0;
			for (int j = 0; j < size; j++){
				for (int k = size - 1; k > j; k--){
					if (block[k - 1] > block[k]){
						temp = block[k - 1];
						block[k - 1] = block[k];
						block[k] = temp;
					}
				}
			}
		break;

		// Select sorting
		case 2:
			temp = 0;
			for (int i = 0; i < size; i++){
				k = i;
				temp = block[i];

				for (int j = i + 1; j < size; j++){
					if (block[j] < temp){
						k = j;
						temp = block[j];
					}
				}

				block[k] = block[i];
				block[i] = temp;
			}
		break;
	};

	for (int x = 0; x < size; x++){
		printf("-- %d. %d\n", x, block[x]);
	}
	free(block);
}

void mass_different(){
	int sizeA, sizeB, k, s;
	int *r, *a, *b,;

	printf("Enter the size of massivies per space:\n");
	scanf("%d %d", &sizeA, &sizeB);

	a = malloc(sizeA * sizeof(int));
	b = malloc(sizeB * sizeof(int));
	r = malloc(1 * sizeof(int));

	for(int i = 0; i < sizeA; i++){
		a[i] = rand() % 15;
		printf("%d. %d\n", i+1, a[i]);
	}
	printf("\n");
	for(int i = 0; i < sizeB; i++){
		b[i] = rand() % 15;
		printf("%d. %d\n", i+1, b[i]);
	}

	//1,2,3,5
	//1,2,4,5
	//3
	s = 0; //cчётчик значений для массива с результатами
	for (int i = 0; i < sizeA; i++){ //двигаемся по основному массиву "А"
		k = 0;
		for (int j = 0; j < sizeB; j++){//двигаемся по массиву "В" и проверяем чтобы a[i] элемент не совпал с b[j] элементом
			if (a[i] != b[j]){
				k++;
			}
		}
		if (k == sizeB){ //если a[i] элементе не разу не совпал то проверяем:
			k = 0;
			n++;
			if (s > 0){ //есть ли он в массиве, 
				for (int n = 0; n < s; n++){
					if (r[n] == a[i]){
						k++;
					}
				}
			}
			if(k == 0){ // и если нет, то добавляем его
				r[s] = a[i];
				r = realloc(r, ++s * sizeof(int)); //попутно увеличиваем размер массива, чтобы он не занемал в памяти много места
			}
		}
	}

	printf("\n");

	for(int i = 0; i < s; i++){
		printf("%d. %d\n", i+1, r[i]);
	}
	
}



