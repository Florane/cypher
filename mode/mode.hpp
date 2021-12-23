#pragma once
#include <iostream>
#include "../method/method.hpp"

/**
 * \defgroup Mode_template
 * \{
 */
///Шаблон режима шифрования
class Mode
{
protected:
    const int size;///< Размер блока
    Method* method;///< Метод шифрования
public:
    Mode(int _size, Method* _method) : size(_size), method(_method) {}
    Mode(Method* _method) : Mode(16,_method) {}
    Mode() : Mode(new Method()) {}

    ///Зашифровать входной поток
    /**
     * \param output Выходной поток
     * \param input Входной поток
     * \param key Ключ
     */
    virtual void encrypt(std::ostream& output, std::istream& input, std::string key) {}
    ///Расшифровать входной поток
    /**
     * \param output Выходной поток
     * \param input Входной поток
     * \param key Ключ
     */
    virtual void decrypt(std::ostream& output, std::istream& input, std::string key);
    ///Расшифровать часть входного потока
    /**
     * \param output Выходной поток
     * \param input Входной поток
     * \param key Ключ
     */
    virtual void decrypt(std::ostream& output, std::istream& input, size_t blocks, std::string key) {}
};///\}
