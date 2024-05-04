#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED
#include <stdio.h>

typedef struct
{
    char *name; // �������� �����
    double length; // ����� �����
    int houses; // ���������� ����� �� �����
} street;


/** ��������� � ����� ������� �������� street ����� ������� � ��������� ���� ���������
 *  list - ��������� �� ������, len - ������ �������, n_name, n_length, n_houses - �������� �����
 *  ���� ������ ��� ����� ������� ��������, �� ������������ ����� ��������� �� ������, ����� NULL
 *  ���� list = NULL � len = 0, �� �������� ����� ������ � ���������� ������ �������
 */
street * street_insert (street * list, size_t len, char *n_name, double n_length, int n_houses);


/** ������� �� ������ �������� street ���� �������
 *  list - ��������� �� ������, len - ������ �������, place - ������ ��������, ������� ����� �������
 */
void street_delete (street *list, size_t len, size_t place);


/** ������� ������ �������� street
 *  list - ��������� �� ������, len - ������ �������
 */
void street_free (street *list, size_t len);

#endif // DATABASE_H_INCLUDED
