#include <stdio.h> 
#include <stdlib.h>


//Список определённых функций
void sort(int *x, int size, int option); //сортировка
void find(int *x, int size); //поиск
void generate(int *x, int size); //заполнение
void print_m(int *x, int size, char *desc); //вывод 


int main(int argc, char const *argv[]){
    
    //инициализируем необходимые переменные
    int *A, sA;

    //предложим пользователю ввести размер массива
    printf("Enter the size of massive:");
    scanf("%d", &sA);

    //зададим размер
    A = malloc(sA * sizeof(int));

    //Заполним массив и выведем его на консоль
    generate(A, sA);
    print_m(A, sA, "===Origin massive===");

    //Отсортируем с помощью алгоритма Пузырёк по возрастанию
    sort(A, sA, 1);
    print_m(A, sA, "===Bubble Sorting===");

    //Отсортируем с помощью алгоритма Выборки по убыванию
    sort(A, sA, 2);
    print_m(A, sA, "===Selection Sorting===");

    //Найдем искомый элемент
    find(A, sA);

    //Для возможности просмотра результатов
    printf("Execution end. Please enter other symbol and press ENTER...");
    scanf("%d", sA);
    return 0;
}

void generate(int *x, int size){
    int rand(void);
    for (int i = 0; i < size; i++){
        x[i] = rand() % 99;
    }
}

void print_m(int *x, int size, char *desc){
    printf("%s \n", desc);
    for (int i = 0; i < size; i++){
        printf("%d. %d \n", i+1, x[i]);
    }
    printf("\n");
}

void sort(int *x, int size, int option){
    int temp, k;

	switch (option)
	{		
		// Bubble Sorting
		case 1:
			temp = 0;
			for (int i = 0; i < size; i++){
				for (int j = size - 1; j > i; j--){
					if (x[j - 1] > x[j]){
						temp = x[j - 1];
						x[j - 1] = x[j];
						x[j] = temp;
					}
				}
			}
		break;

		// Select sorting
		case 2:
			temp = 0;
			for (int i = 0; i < size; i++){
				k = i;
				temp = x[i];

				for (int j = i + 1; j < size; j++){
					if (x[j] > temp){
						k = j;
						temp = x[j];
					}
				}

				x[k] = x[i];
				x[i] = temp;
			}
		break;
	};
}

void find(int *x, int size){
	int k, f, def;
    do{
        k = 0; f = 0;
		printf("\nEnter the number for search:\n");
		scanf("%d", &f);

		
		for (int j = 0; j < size; j++){
			if (x[j] == f) k++;
		}

		if (k == 0){
			printf("Entered number %d not included in massive!", f);
		} 
		else{
			k = 0;
			printf("Entered number %d find and have next indexes:\n", f);
			for (int j = 0; j < size; j++){
				if (x[j] == f) printf("%d. [%d]: %d \n", ++k, j, x[j]);
			}
		}
		
		printf("\nDo you want to continue the searching? Yes=0, No=1\n");
		scanf("%d", &def);
	}while(def == 0);
}