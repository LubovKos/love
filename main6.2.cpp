//ƒана матрица. Ќайдите ее определитель, разложением по строке,
//содержащей наибольшее количество нулей. ѕри равенстве по пер -
//вой из таких строк. ¬ыведите результаты вычислений пошагово.

#include <iostream>
#include <iomanip>
#include "matrix_operations.h"

using namespace std;

int main() {
	setlocale(0, "RUS");
	int n;
	double det = 0;
	cout << "¬ведите размерность квадратной матрицы A: ";
	cin >> n;
	cout << "¬ведите матрицу A: \n";
	double** original_matrix = input_source_matrix(n);
	//находим строку с наибольшим кол-вом нулей, разложением по которой вычисл€ем определитель
	int row_with_nulls = finding_row_with_max_nulls(original_matrix, n);
	det = det_matrix(original_matrix, row_with_nulls, n);
	cout << "ќпределитель матрицы A = " << det;
	clear_memory(original_matrix, n);
	return 0;
}