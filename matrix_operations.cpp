#include "matrix_operations.h"
#include <iostream>
#include <iomanip>
using namespace std;

double** create_zero_matrix(int n) {
	double** zero_matrix = new double*[n];
	for (int i = 0; i < n; i++)
		zero_matrix[i] = new double[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			zero_matrix[i][j] = 0;
	return zero_matrix;
}

double** input_source_matrix(int n) {
	double** source_matrix = create_zero_matrix(n);
	double element;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> element;
			source_matrix[i][j] = element;
		}
	return source_matrix;
}

double** multiply_matrix_by_matrix(double** matrix1, double** matrix2, int n) {
	double** res_multiply_matrix = create_zero_matrix(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				res_multiply_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
	return res_multiply_matrix;
} 

double** multiply_matrix_by_num(double** matrix, int num, int n) {
	double** res_multiply_matrix = create_zero_matrix(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			res_multiply_matrix[i][j] = num * matrix[i][j];
	return res_multiply_matrix;
}

double** sum_matrix_with_matrix(double** matrix1, double** matrix2, int n) {
	double** res_sum_matrix = create_zero_matrix(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			res_sum_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
	return res_sum_matrix;
}

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

void matrix_output(double** matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << "A[" << i + 1 << "][" << j + 1 << "] = " << matrix[i][j] << endl;
	}
	cout << endl;
}

void clear_memory(double** matrix, int n) {
	for (int i = 0; i < n; i++)
		delete[] matrix[i];
	delete[] matrix;
}

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