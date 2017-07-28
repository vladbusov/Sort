#include <iostream>
#include <string>
#include <time.h>
#define TEST_ARR_SIZE 40000


using namespace std;

void swap(int *a, int* b);


/*
Худшее время
O(n2)
Лучшее время
O(n log2 n)
Среднее время
зависит от выбранных шагов
Затраты памяти
О(n) всего, O(1) дополнительно
*/

void sort(int * g, int n){
	for (int gap = n / 2; gap > 0; gap /= 2)
		for (int i = gap; i < n; i++)
			for (int j = i - gap; j >= 0; j -= gap)
				if (g[j + gap] < g[j]){
					swap(&(g[j + gap]), &(g[j]));
				}
	/*else break*/;
}

void swap(int* a, int *b){
	int buff = *a;
	*a = *b;
	*b = buff;
}



// БЫСТРАЯ СОРТИРОВКА
// Разбиение Нико Ломуто (опорный последний элемент)
int partition(int * Arr, int low, int hight){
	int pivot = Arr[hight]; //стержень равен последнему числу
	int i = low - 1; // уменьшаем счетчик на единицу
	for (int j = low; j < hight; j++) // пробегаемся по массиву
		if (Arr[j] <= pivot){ // если элемент меньше или равен последнему
			i = i + 1; // счетчик увеличивается
			swap(&(Arr[i]), &(Arr[j])); //  меняем данный элемент с одним из первых на месте i
		}
	swap(&(Arr[i + 1]), &(Arr[hight])); // меняем последний элемент с последним элементом из тех, что уже переставили
	return i + 1;
}

void quicksortl(int * Arr, int low, int hight){
	if (low < hight){
		int p = partition(Arr, low, hight); // разбиение
		quicksortl(Arr, low, p - 1); // повторяем опирацию для левой части сортировки
		quicksortl(Arr, p + 1, hight); // повторяем операцию для правой части
	}
}
// Разбиение Разбиение Хоара (два индекса приближаются с разных сторон и возвращается средний)

int partitionh(int * Arr, int low, int hight){
	int pivot = Arr[low];
	int i = low - 1;
	int j = hight + 1;
	while (true){
		do {
			i = i + 1;
		} while (Arr[i] < pivot);
		do {
			j = j - 1;
		} while (Arr[j] > pivot);
		if (i >= j)
			return j;
		swap(&(Arr[i]), &(Arr[j]));
	}
}
void quicksorth(int *Arr, int low, int hight){
	if (low < hight){
		int p = partitionh(Arr, low, hight);
		quicksorth(Arr, low, p);
		quicksorth(Arr, p + 1, hight);
	}
}
/*
Предназначение
Алгоритм сортировки
Худшее время
O(n2)
Лучшее время
O(n log n) (обычное разделение)
или O(n) (разделение на 3 части)
Среднее время
O(n log n)
Затраты памяти
O(n) вспомогательных
O(log n) вспомогательных (Седжвик 1978)
*/
// Разбиение Хоара 
//
int main(){


	setlocale(LC_ALL, "Russian");
	int arr[TEST_ARR_SIZE];

	for (int i = 0; i < TEST_ARR_SIZE; i++)
		arr[i] = rand();

	cout << "Сортировка Шелла:" << endl;
	//for (int i = 0; i < TEST_ARR_SIZE; i++)
	//cout << arr[i] << " ";
	//cout << endl;

	unsigned int start_time = clock();
	sort(arr, TEST_ARR_SIZE);
	unsigned int end_time = clock();

	//for (int i = 0; i < TEST_ARR_SIZE; i++)
	//cout << arr[i]<< " ";
	//cout << endl;

	unsigned int search_time = end_time - start_time;

	cout << "Время после сортировки Шелла: " << search_time << " мс" << endl;


	cout << "Быстрая сортировка с раззбиением Нико Ломуто:" << endl;
	int arr2[TEST_ARR_SIZE];
	for (int i = 0; i < TEST_ARR_SIZE; i++)
		arr2[i] = rand();




	//for (int i = 0; i < TEST_ARR_SIZE; i++)
	//cout << arr2[i] << " ";
	//cout << endl;

	unsigned int start_time1 = clock();
	quicksortl(arr2, 0, (TEST_ARR_SIZE - 1));
	unsigned int end_time1 = clock();


	//for (int i = 0; i < TEST_ARR_SIZE; i++)
	//cout << arr2[i] << " ";
	//cout << endl;

	unsigned int search_time1 = end_time1 - start_time1;

	cout << "Время после быстрой сортировки Ломуто: " << search_time1 << " мс" << endl;




	cout << "Быстрая сортировка с раззбиением Хоара:" << endl;


	int arr3[TEST_ARR_SIZE];
	for (int i = 0; i < TEST_ARR_SIZE; i++)
		arr3[i] = rand();

	unsigned int start_time2 = clock();
	quicksorth(arr3, 0, (TEST_ARR_SIZE - 1));
	unsigned int end_time2 = clock();


	unsigned int search_time2 = end_time2 - start_time2;

	cout << "Время после быстрой сортировки Хоара: " << search_time2 << " мс" << endl;



	system("PAUSE");
	return 0;
}
