#ifndef POL_H_INCLUDED
#define POL_H_INCLUDED

#include <stdio.h>

/**
 * \brief Функция вычисления значения выражения
 * \param x Значение переменной x
 * \param str Массив подстрок выражения
 * \param len Количество подстрок
 * \param x_places Массив указателей на места, где встречается x
 * \return Значение выражения
 */
double f (double x, char **str, size_t len, char ***x_places);

/**
 * \brief Функция обработки интеграла
 * \param p Указатель на начало выражения
 * \param r Указатель на переменную, куда будет записано значение интеграла
 * \param str_end Указатель на конец выражения
 * \return Указатель на позицию после обработанного интеграла
 */
char ** integral (char **p, double *r, char **str_end);

/**
 * \brief Функция численного интегрирования методом средних прямоугольников
 * \param a Нижний предел интегрирования
 * \param b Верхний предел интегрирования
 * \param n Количество разбиений
 * \param str Массив подстрок выражения
 * \param len Количество подстрок
 * \param x_places Массив указателей на места, где встречается x
 * \return Значение интеграла
 */
double quad_middle_rec (double a, double b, size_t n, char **str, size_t len, char ***x_places);

/**
 * \brief Функция численного интегрирования методом последовательных приближений
 * \param a Нижний предел интегрирования
 * \param b Верхний предел интегрирования
 * \param eps Требуемая точность
 * \param str Массив подстрок выражения
 * \param len Количество подстрок
 * \param x_places Массив указателей на места, где встречается x
 * \return Значение интеграла
 */
double iter_formula (double a, double b, double eps, char **str, size_t len, char ***x_places);


char * input();

/**
 * \brief Функция разделения строки на подстроки
 * \param str Исходная строка
 * \param sep Разделитель
 * \param len Указатель на переменную, куда будет записано количество подстрок
 * \return Массив указателей на подстроки
 */
char ** sep (char *str, char *sep, size_t *len);

double pol (char **str, size_t len);

#endif // POL_H_INCLUDED
