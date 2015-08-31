/*
 * Copyright (c) 2014, Roman Meyta <theshrodingerscat@gmail.com>
 * All rights reserved
 */

#ifndef TOKENS_H
#define TOKENS_H

#include <string>
#include <vector>

/**
 * @brief Токенизировать строку данных
 *
 * @param str исходная строка
 * @param splitter разделяющий символ
 * @return std::vector<std::string>
 */
std::vector<std::string> tokenize(const std::string& str, char splitter = ' ');

/**
 * @brief Токенизировать строку данных
 *
 * @param str исходная строка
 * @param splitters разделяющие символы (подходит любой из строки)
 * @return std::vector<std::string>
 */
std::vector<std::string> tokenize(const std::string& str, const std::string& splitters);

/**
 * @brief Токенизировать строку данных
 *
 * @param str исходная строка
 * @param splitter разделяющая последовательность (только вся)
 * @return std::vector<std::string>
 */
std::vector<std::string> tokenizeByString(const std::string& str, const std::string& splitter);

/**
 * @brief Обрезать посторонние символы с левого конца строки
 * NOTE работает только с ASCII символами
 *
 * @param str
 * @return const string
 */
const std::string ltrimCopy(const std::string& str);

/**
 * @brief Обрезать посторонние символы с правого конца строки
 * NOTE работает только с ASCII символами
 *
 * @param str
 * @return const string
 */
const std::string rtrimCopy(const std::string& str);

/**
 * @brief Обрезать посторонние символы с правого и левого конца строки
 * NOTE работает только с ASCII символами
 *
 * @param str
 * @return const string
 */
const std::string trimCopy(const std::string& str);

#endif // TOKENS_H
