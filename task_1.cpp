#include <iostream>
#include <Windows.h>
#include <cmath>
#include <ctime>

using namespace std;
int TaskOne(int* array,int length) {
	int count = 0;
	for (size_t index = 1; index <= length; index+=2) {

		if (array[index-1] < 0)
		{
			count++;
		}
	}
	return count;
}

void Generate(int* array, int length) {
	for (size_t index = 0; index < length; index++)
	{
		array[index] = (int)(((rand() % 100) + 1) - 30);
	}
}

void DisplayArrays(int* array, int length) {
	for (size_t index = 0; index < length; index++)
	{
		std::cout << array[index] << " ";
	}
}

int RepeatCount(int* array, int* array2, int length) {
	int count = 0;
	for (size_t index = 0; index < length; index++)
	{
		int repeat = 0;

		for (size_t pos = 0; pos < length; pos++)
		{
			if (array[index] == array2[pos]) {
				repeat++;
			}
		}
		if (repeat > 0)
		{
			count++;
		}
	}
	return count;
}

void GenerateMatrix(int** matrixA, int count) {
	for (int row = 0; row < count; row++)
	{
		for (int col = 0; col < count; col++)
		{
			matrixA[row][col] = (int)(((rand() % 100) + 1) - 30);
		}
	}
}

int* NewArrayForTask4(int** matrixA, int count) {
	int* result = new int[count];
	for (int row = 0; row < count; row++)
	{
		int min = matrixA[row][0];
		int max = matrixA[row][0];

		for (int col = 0; col < count; col++)
		{
			if (min > matrixA[row][col])
			{
				min = matrixA[row][col];
			}
			if (max < matrixA[row][col])
			{
				max = matrixA[row][col];
			}
		}
		result[row] = min + max;
	}
	return result;
}

int* ArrayForTask5(int** matrixA, int count) {
	int* result = new int[count];
	for (int index = 0; index < count; index++)
	{
		result[index] = matrixA[index][index];
	}
	return result;
}

int main()
{
   // кодіровка для програми
   SetConsoleCP(CP_UTF8);
   SetConsoleOutputCP(CP_UTF8);
  srand(time(NULL));
    int length; 
	std::cout << "Enter length of array: ";
	std::cin >> length;
	std::cout << std::endl;
	int* array = new int[length];
	for (size_t index = 0; index < length; index++) {

		array[index] = (int)(((rand() % 100) + 1)-30);

		std::cout << array[index] << " ";
	}
	int count = TaskOne(array, length);

	std::cout << std::endl;
	std::cout << "\nNegative number(s) at the odd index is/are: " << count << std::endl;
	
	std::cout << "\nEeach 3rd elements of array: " << std::endl;
	int* array2 = new int[length];
	for (size_t index = 3; index <= length; index+=3)
	{   

		array2[index - 1] = array[index - 1];
		std::cout << array2[index - 1] << " ";
	}
	
	array, array2 = nullptr;
	std::cout << std::endl;
	std::cout << "\nEnter length of arrays: ";
	std::cin >> length;
	array = new int[length];
	array2 = new int[length];
	Generate(array, length);
	Generate(array2, length);

	DisplayArrays(array, length);
	std::cout << std::endl;
	DisplayArrays(array2, length);
	
	std::cout << std::endl;
	int repeat = RepeatCount(array2, array, length);
	std::cout << "\nRepeat count in mass B: " << repeat;

	std::cout << std::endl;
	int* repeatelements = new int[length - repeat];
	int pos = 0;
	for (size_t index = 0; index < length; index++)
	{
		int repeat = 0;
		
		for (size_t pos = 0; pos < length; pos++)
		{
			if (array2[index] == array[pos]) {
				repeat++;
			}
		}
		if (repeat == 0)
		{	
			repeatelements[pos] = array2[index];
			
			pos++;
		}
	}
	std::cout << "\nRepeat elements in massB & massA: ";
	DisplayArrays(repeatelements, length - repeat);

	std::cout << std::endl;

	int* crossingelem = new int[repeat];

	pos = 0;
	for (size_t index = 0; index < length; index++)
	{
		int repeat = 0;

		for (size_t pos = 0; pos < length; pos++)
		{
			if (array2[index] == array[pos]) {
				repeat++;
			}
		}
		if (repeat > 0)
		{
			crossingelem[pos] = array2[index];

			pos++;
		}
	}

	std::cout << "\nCrossing elements in massB & massA: ";
	DisplayArrays(crossingelem, repeat);
	std::cout << std::endl;
	int count2;
	
	std::cout << "\nEnter nxn of matrix: ";
	std::cin >> count2;
	int** matrixA = new int*[count2];
	for (int str = 0; str < count2; str++) {
		matrixA[str] = new int[count2];
	}
	GenerateMatrix(matrixA, count2);
	for (int row2 = 0; row2 < count2; row2++)
	{
		for (int col = 0; col < count2; col++)
		{
			std::cout << matrixA[row2][col] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	int* arrayfor4 = NewArrayForTask4(matrixA, count2);
	std::cout << "\nThe sum min, max in each row: ";
	DisplayArrays(arrayfor4, count2);

	std::cout << std::endl;
	
	int* Diaganoli = ArrayForTask5(matrixA, count2);
	std::cout << "\nThe diagonal of the matrix: ";
	DisplayArrays(Diaganoli, count2);
	std::cout << std::endl;

	system("pause");
}