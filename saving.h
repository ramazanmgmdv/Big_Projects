#ifndef SAVING_H_INCLUDED
#define SAVING_H_INCLUDED
#include "database.h"

/** ��������� ������ �������� street �� �����, ���������� � ������� ������� saving
 *  len - ����� ����������, � ������� ��������� ������ �������
 *  filename - ��� �����, �� �������� ���������
 *  ���������� ��������� �� ������ ��� NULL � ������ ������
 */
street * loading(size_t *len, const char *filename);


/** ��������� � ���� � ������ filename ������ �� ������� list ����� len */
void saving (street *list, size_t len, const char *filename);

#endif // SAVING_H_INCLUDED
