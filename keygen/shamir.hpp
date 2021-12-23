#pragma once
#include <vector>
#include "InfInt.h"

/** \defgroup Keygen
 * \{
 */

///Имплементация разделения ключа Шамира
class Shamir
{
    const int required /**<Кол-во частей, нужных для восстановления ключа */
    , produced; /**<Кол-во созданых частей */
    /// Степень a^b
    InfInt pow(int a, int b); 
    ///Вернуть уникальное число на основе порядковых значений в строке
    InfInt bitString(std::string &str);
    ///Вернуть строку на основе его уникального числа
    std::string toBitString(InfInt i);
    ///Вернуть уникальное 4-байтное число
    InfInt getShare();
    ///Простое число, близкое к сложности шифрования
    const InfInt prime = pow(2,127)-1;
public:
    Shamir(int r, int q) : required(r), produced(q) {}
    Shamir() : Shamir(3,5) {}

    ///Разделить ключ
    /**
     * Разделить ключ на несколько частей
     * \param key ключ
     * \param piecestreams массив строк для хранения частей размера required
     */
    void split(std::string &key, std::string *piecestreams);
    ///Восстановить ключ
    /**
     * Восстановить ключ методом интерполяции Лагранжа на основе частей ключа
     * \param shares части ключа
     * \param parts значения x, на которых были взяты части ключа
     * \param key ключ
     */
    void glue(std::string *shares, int *parts, std::string &key);

    int producedCount() {return produced;} ///< Вернуть produced
    int requiredCount() {return required;} ///< Вернуть required
};///\}
