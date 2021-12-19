#ifndef MATRIX_OPERATIONS
#define MATRIX_OPERATIONS

//нахождение строки с наибольшим кол-вом нулей
int finding_row_with_max_nulls(double** source_matrix, int n);

//нахождение минора матрицы, полученный вычеркиванием idx1 строки и idx2 столбца
void minor_matrix(double** matrix, double** source_matrix, int idx1, int idx2, int n);

//вычисление определител€ квадратной матрицы
double det_matrix(double** matrix, int row, int n);

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

//обратна€ матрица 2х2
double** inverse_matrix(double** matrix, int n);

//вывод матрицы
void matrix_output(double** matrix, int n);

//очистка динамически выделенной пам€ти
void clear_memory(double** matrix, int n);

//расчЄт функции f(x) = x^3 + 2x^2 + 5x + 10
double** function_evaluation(double** source_matrix, int n);

//вычисление матрицы ’ из уравнени€ јX+¬=—
double** evaluation_matrix_X(double** matrix_a, double** matrix_b, double** matrix_c, int n);

#endif MATRIX_OPERATIONS
