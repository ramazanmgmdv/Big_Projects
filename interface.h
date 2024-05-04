#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#include "database.h"
#include <stdio.h>

typedef int (*fnc_comp) (void *, void *);

typedef double (*fnc_divide) (street *, street *);

typedef double (*fnc_sum) (street *, size_t len);

typedef double (*fnc_divide_num) (street *, double);


/** ������� ����������� ����, ������� ������ �������� list ������ len
 *  � ���� �������, ������ ������ "�������", "���������", "��������� ���"
 *  � ������ "+" - ���������� ������ �������� � ������
 */
void table (street *list, size_t len);


/** ���������� ��������� a � b (��� ������ - street) �� ���� length
 *  ���������� 1, ���� a > b, ����� 0
 */
int cmp_length_incr (void *a, void *b);


/** ���������� ��������� a � b (��� ������ - street) �� ���� houses
 *  ���������� 1, ���� a > b, ����� 0
 */
int cmp_houses_incr (void *a, void *b);


/** ���������� ��������� a � b (��� ������ - street) �� ���� name
 *  ���������� 1, ���� a ������ � ��������, ��� b, ����� 0
 */
int cmp_name_incr (void *a, void *b);


/** ���������� ��������� a � b (��� ������ - street) �� ���� length
 *  ���������� 1, ���� a < b, ����� 0
 */
int cmp_length_decr (void *a, void *b);


/** ���������� ��������� a � b (��� ������ - street) �� ���� houses
 *  ���������� 1, ���� a < b, ����� 0
 */
int cmp_houses_decr (void *a, void *b);


/** ���������� ��������� a � b (��� ������ - street) �� ���� name
 *  ���������� 1, ���� a ������ � ��������, ��� b, ����� 0
 */
int cmp_name_decr (void *a, void *b);


/** ��������� ������ ������ ���� ������
 *  array - ��������� �� ������, len - ������ �������, size - ������ ������ �������� �������
 *  cmp - ������� ��������� ���� ��������� �������
 *  ���� cmp ���������� 1, ����� ������ ������� ������, �� ������ ����� ������������ �� �����������, ����� �� ��������
 */
void sort(void *array, size_t len, size_t size, fnc_comp cmp);


/** ���� �������� ����� � ������� � ����������� ����
 *  left, top, right, bottom - ���������� ���������� ������
 *  ���������� ��������� �� ������ � �������� ���������
 *  ��� NULL, ���� ���� ������ ��� �� ������� �������� ������
 *  ���������� ����� - Enter, ������ ����� - Home
 */
char * input_name (int left, int top, int right , int bottom);


/** ���� ����� ����� � ������� � ����������� ����
 *  left, top, right, bottom - ���������� ���������� ������
 *  ���������� �������� ����� ��� NULL, ���� ���� ������ ��� �� ������� �������� ������
 *  ���������� ����� - Enter, ������ ����� - Home
 */
double input_length (int left, int top, int right , int bottom);


/** ���� ���������� ����� �� ����� � ������� � ����������� ����
 *  left, top, right, bottom - ���������� ���������� ������
 *  ���������� �������� ����� ��� NULL, ���� ���� ������ ��� �� ������� �������� ������
 *  ���������� ����� - Enter, ������ ����� - Home
 */
double input_houses (int left, int top, int right , int bottom);


/** ���� ����� ����� � ����������� ����
 *  ���������� ��������� �� ������ � �������� ������
 *  ��� NULL, ���� ���� ������ ��� �� ������� �������� ������
 *  ���������� ����� - Enter, ������ ����� - Home
 */
char * input_filename ();


/** ���������� ������������ ������� � ������� list ����� len
 *  cmp - ������� ��������� ���� ���������, ������� ������
 *  ���������� 1, ���� a < b, ����� 0
 */
street * maximum (street *list, size_t len, fnc_comp cmp);


/** ���������� ����� ����� �� ����� length ��������� ������� list ����� len */
double sum_length (street *list, size_t len);


/** ���������� ����� ����� �� ����� houses ��������� ������� list ����� len */
double sum_houses (street *list, size_t len);


/** ���������� ��������� ������� ����� �� ����� houses �������� � � b */
double divide_houses (street *a, street *b);


/** ���������� ��������� ������� ����� �� ����� length �������� � � b */
double divide_length (street *a, street *b);


/** ���������� ��������� ������� ������ �� ���� houses ��������� a �� ����� b */
double divide_houses_num (street *a, double b);


/** ���������� ��������� ������� ������ �� ���� length ��������� a �� ����� b */
double divide_length_num (street *a, double b);


/** ������ ���������� ��������� �� �������� ������� list ����� len
 *  cmp - ������� ��������� ���� ��������� ������� (���������� 1, ���� a < b, ����� 0)
 *  div - ������� ������� ���� ��������� �������
 */
void bar_chart(street *list, size_t len, fnc_comp cmp, fnc_divide div);


/** ������ �������� ��������� �� �������� ������� list ����� len
 *  list_sum - ������� ������������ ���� ��������� �������
 *  div - ������� ������� �������� ������� �� ������������ �����
 */
void pie_chart(street *list, size_t len, fnc_sum list_sum, fnc_divide_num div);


/** ������ � �������� list ������ len_list � ������������ ����
 *  ������������ ��������� � ������� ����
 *  filename - ��� �����, �� ������� �������� ������ list
 */
void interface (street *list, size_t len_list, const char *filename);

#endif // INTERFACE_H_INCLUDED
