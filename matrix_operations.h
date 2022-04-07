#ifndef MATRIX_OPERATIONS
#define MATRIX_OPERATIONS

#include <iostream>
#include <iomanip>
#include "matrix_operations.h"
using namespace std;

//создание нулевой квадратной матрицы
double** create_zero_matrix(int n);

// проверка корректности ввода
template <class T>
T read_and_check(T a);

//ввод исходной квадратной матрицы (source_matrix)
double** input_source_matrix(int n, const char *name_matrix);

// создание квадратной матрицы
double** creating_matrix(int n);

//сложение матриц
double** multiply_matrix_by_num(double** matrix, int num, int n);

//умножение матрицы на число
double** sum_matrix_with_matrix(double** matrix1, double** matrix2, int n);

//сложение матрицы с числом
double** sum_matrix_with_num(double** matrix, int num, int n);

//умножение матриц
double** multiply_matrix_by_matrix(double** matrix1, double** matrix2, int n);

//нахождение строки с наибольшим кол-вом нулей
int finding_row_with_max_nulls(double** source_matrix, int n);

//нахождение минора матрицы, полученный вычеркиванием idx1 строки и idx2 столбца
void minor_matrix(double** matrix, double** source_matrix, int idx1, int idx2, int n);

//вычисление определителя квадратной матрицы
double det_matrix(double** matrix, int row, int n);

//расчёт функции f(x) = x^3 + 2x^2 + 5x + 10
double** function_evaluation(double** source_matrix, int n, const char *name_matrix);

//вычисление матрицы A'
double **new_matrix_a(double** matrix_a, int n);

// получение матрицы без i-й строки и j-го столбца (т. е. перенумеровывание элементов)
double** create_minor(double** matrix, int n, int row_idx, int column_idx);

// вычисление определителя матрицы
double determinant(double** matrix, int n);

// создание обратной матрицы
double** create_inverse_matrix(double** matrix, int n);

//вычисление матрицы X
double** evaluation_matrix_X(double** matrix_a, double** matrix_b, double** matrix_c, int n);

//вывод матрицы
void matrix_output(double** matrix, int n, const char *name_matrix);

// итоговая очистка памяти
void end_clear_memory(double **res_matrix_a, double **res_matrix_b, double **matrix_a,
	double **matrix_b, double **matrix_c, int n);

//очистка динамически выделенной памяти
void clear_memory(double** matrix, int n);

#endif MATRIX_OPERATIONS