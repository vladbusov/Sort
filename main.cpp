#include <iostream>
#include <string>
#include <time.h>
#define TEST_ARR_SIZE 100000


using namespace std;

void swap(int *a, int* b);


/*
������ �����	
O(n2)
������ �����	
O(n log2 n)
������� �����	
������� �� ��������� �����
������� ������	
�(n) �����, O(1) �������������
*/

void sort(int * g, int n){
	for (int gap = n / 2; gap > 0; gap /= 2)
		for (int i = gap; i < n; i++)
			for (int j = i - gap; j >= 0; j-=gap)
				if (g[j + gap] < g[j]){
					swap(    &(g[j + gap])    , &(g[j])   );
				}
				/*else break*/;
}

void swap(int* a, int *b){
	int buff = *a;
	*a = *b;
	*b = buff;
}



// ������� ����������
// ��������� ���� ������ (������� ��������� �������)
int partition(int * Arr, int low, int hight){
	int pivot = Arr[hight]; //�������� ����� ���������� �����
	int i = low - 1; // ��������� ������� �� �������
	for (int j = low; j < hight; j++) // ����������� �� �������
		if (Arr[j] <= pivot){ // ���� ������� ������ ��� ����� ����������
			i = i + 1; // ������� �������������
			swap(&(Arr[i]), &(Arr[j])); //  ������ ������ ������� � ����� �� ������ �� ����� i
		}
	swap(&(Arr[i + 1]), &(Arr[hight])); // ������ ��������� ������� � ��������� ��������� �� ���, ��� ��� �����������
	return i + 1;
}

void quicksortl(int * Arr, int low, int hight){
	if (low < hight){
		int p = partition(Arr, low, hight); // ���������
		quicksortl(Arr, low, p - 1); // ��������� �������� ��� ����� ����� ����������
		quicksortl(Arr, p + 1, hight); // ��������� �������� ��� ������ �����
	}
}
/*
��������������	
�������� ����������
������ �����	
O(n2)
������ �����	
O(n log n) (������� ����������)
��� O(n) (���������� �� 3 �����)
������� �����	
O(n log n)
������� ������	
O(n) ���������������
O(log n) ��������������� (������� 1978)
*/
// ��������� ����� 
//
int main(){


	setlocale(LC_ALL, "Russian");
	int arr[TEST_ARR_SIZE];

	for (int i = 0; i < TEST_ARR_SIZE; i++)
		arr[i] = rand();

	cout << "���������� �����:" << endl;
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

	cout<< "����� ����� ���������� �����: " << search_time << " ��" << endl;


	cout << "������� ���������� � ����������� ���� ������:" << endl;
	int arr2[TEST_ARR_SIZE];
	for (int i = 0; i < TEST_ARR_SIZE; i++)
		arr2[i] = rand();




	//for (int i = 0; i < TEST_ARR_SIZE; i++)
		//cout << arr2[i] << " ";
	//cout << endl;

	unsigned int start_time1 = clock();
	quicksortl(arr2, 0, (TEST_ARR_SIZE-1) );
	unsigned int end_time1 = clock();


	//for (int i = 0; i < TEST_ARR_SIZE; i++)
		//cout << arr2[i] << " ";
	//cout << endl;

	unsigned int search_time1 = end_time1 - start_time1;

	cout <<"����� ����� ������� ����������: " << search_time1 << " ��" << endl;

	system("PAUSE");
	return 0;
}