#ifndef MATRIX_OPERATIONS
#define MATRIX_OPERATIONS

//�������� ������� ���������� �������
double** create_zero_matrix(int n);

//���� �������� ���������� ������� (source_matrix)
double** input_source_matrix(int n);

//��������� ������
double** multiply_matrix_by_matrix(double** matrix1, double** matrix2, int n);

//�������� ������
double** sum_matrix_with_matrix(double** matrix1, double** matrix2, int n);

//��������� ������� �� �����
double** multiply_matrix_by_num(double** matrix, int num, int n);

//�������� ������� � ������
double** sum_matrix_with_num(double** matrix, int num, int n);

//����� �������
void matrix_output(double** matrix, int n);

//������� ����������� ���������� ������
void clear_memory(double** matrix, int n);

//������ ������� f(x) = x^3 + 2x^2 + 5x + 10
double** function_evaluation(double** source_matrix, int n);

#endif MATRIX_OPERATIONS
