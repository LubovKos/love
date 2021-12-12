#ifndef MATRIX_OPERATIONS
#define MATRIX_OPERATIONS

//создание нулевой квадратной матрицы
double** create_zero_matrix(int n);

//ввод исходной квадратной матрицы (source_matrix)
double** input_source_matrix(int n);

//умножение матриц
double** multiply_matrix_by_matrix(double** matrix1, double** matrix2, int n);

//сложение матриц
double** sum_matrix_with_matrix(double** matrix1, double** matrix2, int n);

//умножение матрицы на число
double** multiply_matrix_by_num(double** matrix, int num, int n);

//сложение матрицы с числом
double** sum_matrix_with_num(double** matrix, int num, int n);

//вывод матрицы
void matrix_output(double** matrix, int n);

//очистка динамически выделенной пам€ти
void clear_memory(double** matrix, int n);

//расчЄт функции f(x) = x^3 + 2x^2 + 5x + 10
double** function_evaluation(double** source_matrix, int n);

#endif MATRIX_OPERATIONS
