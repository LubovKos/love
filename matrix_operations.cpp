#include "matrix_operations.h"
#include <iostream>
#include <iomanip>
using namespace std;

//нахождение строки с наибольшим кол-вом нулей
int finding_row_with_max_nulls(double** source_matrix, int n) {
	int row = 0, count_nulls = 0, max_count_nulls = 0;
	for (int i = 0; i < n; i++) {
		count_nulls = 0;
		for (int j = 0; j < n; j++) {
			if (source_matrix[i][j] == 0)
				count_nulls++;
		}
		if (count_nulls > max_count_nulls) {
			max_count_nulls = count_nulls;
			row = i;
		}
	}
	return row;
}

//нахождение минора матрицы, полученный вычеркиванием idx1 строки и idx2 столбца
void minor_matrix(double** matrix, double** source_matrix, int idx1, int idx2, int n) {
	int row = 0, column = 0;
	for (int i = 0; i < n; i++) {
		column = 0;
		if (i != idx1) {
			for (int j = 0; j < n; j++)
				if (j != idx2) {
					matrix[row][column] = source_matrix[i][j];
					column++;
				}
			row++;
		}
	}
}

//вычисление определител€ квадратной матрицы
double det_matrix(double** matrix, int row, int n) {
	double det = 0;

	//определитель матрицы 2x2
	if (n == 2)
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

	for (int j = 0; j < n; j++) {
		double** minor = create_zero_matrix(n - 1);
		minor_matrix(minor, matrix, row, j, n);

		cout << "Ѕерем элемент: " << matrix[row][j] << '\n' << "ћинор: " << endl;
		matrix_output(minor, n - 1);

		//нахождение строки с наибольшим кол-вом нулей дл€ минора
		int row_minor = finding_row_with_max_nulls(minor, n - 1);

		double minor_det = det_matrix(minor, row_minor, n - 1);
		cout << "det += " << pow(-1, row + j) << " * " << matrix[row][j] << " * " << minor_det << endl;
		det += (pow(-1, row + j) * matrix[row][j] * minor_det);
		cout << "det = " << det << '\n' << endl;
	}
	return det;
}

//создание нулевой квадратной матрицы
double** create_zero_matrix(int n) {
	double** zero_matrix = new double* [n];
	for (int i = 0; i < n; i++)
		zero_matrix[i] = new double[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			zero_matrix[i][j] = 0;
	return zero_matrix;
}

//ввод исходной квадратной матрицы (source_matrix)
double** input_source_matrix(int n) {
	double** source_matrix = create_zero_matrix(n);
	double element;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> element;
			source_matrix[i][j] = element;
		}
	cout << endl;
	return source_matrix;
}

//умножение матриц
double** multiply_matrix_by_matrix(double** matrix1, double** matrix2, int n) {
	double** res_multiply_matrix = create_zero_matrix(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				res_multiply_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
	return res_multiply_matrix;
}

//сложение матриц
double** multiply_matrix_by_num(double** matrix, int num, int n) {
	double** res_multiply_matrix = create_zero_matrix(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			res_multiply_matrix[i][j] = num * matrix[i][j];
	return res_multiply_matrix;
}

//умножение матрицы на число
double** sum_matrix_with_matrix(double** matrix1, double** matrix2, int n) {
	double** res_sum_matrix = create_zero_matrix(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			res_sum_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
	return res_sum_matrix;
}

//сложение матрицы с числом
double** sum_matrix_with_num(double** matrix, int num, int n) {
	double** res_sum_matrix = create_zero_matrix(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j)
				res_sum_matrix[i][j] = num + matrix[i][j];
			else
				res_sum_matrix[i][j] = matrix[i][j];
		}
	return res_sum_matrix;
}

//обратна€ матрица 2x2
double** inverse_matrix(double** matrix, int n) {
	double** res_inverse_matrix = create_zero_matrix(n);
	double det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j)
				res_inverse_matrix[i][j] = (1 / det) * matrix[1 - i][1 - j];
			else {
				if (matrix[i][j] == 0)
					res_inverse_matrix[i][j] = 0;
				else
					res_inverse_matrix[i][j] = (1 / det) * (-1) * matrix[i][j];
			}
		}
	return res_inverse_matrix;
}

//вывод матрицы
void matrix_output(double** matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << "A[" << i + 1 << "][" << j + 1 << "] = " << matrix[i][j] << endl;
	}
	cout << endl;
}

//очистка динамически выделенной пам€ти
void clear_memory(double** matrix, int n) {
	for (int i = 0; i < n; i++)
		delete[] matrix[i];
	delete[] matrix;
}

//расчЄт функции f(x) = x^3 + 2x^2 + 5x + 10
double** function_evaluation(double** source_matrix, int n) {
	cout << '\n' << "Matrix: x^2 " << '\n' << endl;
	double** x_pow_2 = multiply_matrix_by_matrix(source_matrix, source_matrix, n);
	matrix_output(x_pow_2, n);

	cout << "Matrix: x^3 " << '\n' << endl;
	double** x_pow_3 = multiply_matrix_by_matrix(source_matrix, x_pow_2, n);
	matrix_output(x_pow_3, n);

	cout << "Matrix: 2x^2" << '\n' << endl;
	double** first_term = multiply_matrix_by_num(x_pow_2, 2, n);
	matrix_output(first_term, n);
	clear_memory(x_pow_2, n);

	cout << "Matrix: x^3 + 2x^2 " << '\n' << endl;
	double** first_sum = sum_matrix_with_matrix(x_pow_3, first_term, n);
	matrix_output(first_sum, n);
	clear_memory(x_pow_3, n);
	clear_memory(first_term, n);

	cout << "Matrix: 5x" << '\n' << endl;
	double** second_term = multiply_matrix_by_num(source_matrix, 5, n);
	matrix_output(second_term, n);

	cout << "Matrix: x^3 + 2x^2 + 5x" << '\n' << endl;
	double** second_sum = sum_matrix_with_matrix(first_sum, second_term, n);
	matrix_output(second_sum, n);
	clear_memory(first_sum, n);
	clear_memory(second_term, n);

	cout << "Matrix: f(x) = x^3 + 2x^2 + 5x + 10" << '\n' << endl;
	double** res = sum_matrix_with_num(second_sum, 10, n);
	clear_memory(second_sum, n);

	return res;
}

//вычисление матрицы X
double** evaluation_matrix_X(double** matrix_a, double** matrix_b, double** matrix_c, int n) {
	//—начала вычислим -B
	double** matrix_minus_b = multiply_matrix_by_num(matrix_b, -1, n);
	cout << "ћатрица -B: " << endl;
	matrix_output(matrix_minus_b, n);

	//¬ычислим C - B
	double** matrix_diff_c_b = sum_matrix_with_matrix(matrix_c, matrix_minus_b, n);
	cout << "ћатрица C - B: " << endl;
	matrix_output(matrix_diff_c_b, n);

	//Ќаходим обратную к A матрицу
	double** inverse_matrix_a = inverse_matrix(matrix_a, n);
	cout << "ќбратна€ к ј матрица: " << endl;
	matrix_output(inverse_matrix_a, n);

	//X = A^(-1) * (C - B)
	double** matrix_x = multiply_matrix_by_matrix(inverse_matrix_a, matrix_diff_c_b, n);

	clear_memory(matrix_minus_b, n);
	clear_memory(matrix_diff_c_b, n);
	clear_memory(inverse_matrix_a, n);

	return matrix_x;
}