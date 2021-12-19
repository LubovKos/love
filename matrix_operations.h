#ifndef MATRIX_OPERATIONS
#define MATRIX_OPERATIONS

//���������� ������ � ���������� ���-��� �����
int finding_row_with_max_nulls(double** source_matrix, int n);

//���������� ������ �������, ���������� ������������� idx1 ������ � idx2 �������
void minor_matrix(double** matrix, double** source_matrix, int idx1, int idx2, int n);

//���������� ������������ ���������� �������
double det_matrix(double** matrix, int row, int n);

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

//�������� ������� 2�2
double** inverse_matrix(double** matrix, int n);

//����� �������
void matrix_output(double** matrix, int n);

//������� ����������� ���������� ������
void clear_memory(double** matrix, int n);

//������ ������� f(x) = x^3 + 2x^2 + 5x + 10
double** function_evaluation(double** source_matrix, int n);

//���������� ������� � �� ��������� �X+�=�
double** evaluation_matrix_X(double** matrix_a, double** matrix_b, double** matrix_c, int n);

#endif MATRIX_OPERATIONS
