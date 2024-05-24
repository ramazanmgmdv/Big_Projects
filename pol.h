#ifndef POL_H_INCLUDED
#define POL_H_INCLUDED

#include <stdio.h>

/**
 * \brief ������� ���������� �������� ���������
 * \param x �������� ���������� x
 * \param str ������ �������� ���������
 * \param len ���������� ��������
 * \param x_places ������ ���������� �� �����, ��� ����������� x
 * \return �������� ���������
 */
double f (double x, char **str, size_t len, char ***x_places);

/**
 * \brief ������� ��������� ���������
 * \param p ��������� �� ������ ���������
 * \param r ��������� �� ����������, ���� ����� �������� �������� ���������
 * \param str_end ��������� �� ����� ���������
 * \return ��������� �� ������� ����� ������������� ���������
 */
char ** integral (char **p, double *r, char **str_end);

/**
 * \brief ������� ���������� �������������� ������� ������� ���������������
 * \param a ������ ������ ��������������
 * \param b ������� ������ ��������������
 * \param n ���������� ���������
 * \param str ������ �������� ���������
 * \param len ���������� ��������
 * \param x_places ������ ���������� �� �����, ��� ����������� x
 * \return �������� ���������
 */
double quad_middle_rec (double a, double b, size_t n, char **str, size_t len, char ***x_places);

/**
 * \brief ������� ���������� �������������� ������� ���������������� �����������
 * \param a ������ ������ ��������������
 * \param b ������� ������ ��������������
 * \param eps ��������� ��������
 * \param str ������ �������� ���������
 * \param len ���������� ��������
 * \param x_places ������ ���������� �� �����, ��� ����������� x
 * \return �������� ���������
 */
double iter_formula (double a, double b, double eps, char **str, size_t len, char ***x_places);


char * input();

/**
 * \brief ������� ���������� ������ �� ���������
 * \param str �������� ������
 * \param sep �����������
 * \param len ��������� �� ����������, ���� ����� �������� ���������� ��������
 * \return ������ ���������� �� ���������
 */
char ** sep (char *str, char *sep, size_t *len);

double pol (char **str, size_t len);

#endif // POL_H_INCLUDED
