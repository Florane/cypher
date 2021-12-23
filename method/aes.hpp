#pragma once
#include "method.hpp"

/**
 * \defgroup AES_Method
 * \{
 */
///Имплементация AES_128
class AES : public Method
{
    int sBox[256]/**Таблица замены байтов */,invSBox[256];
    int mult2[256], mult3[256], mult9[256], mult11[256], mult13[256], mult14[256];///<Таблицы модульного умножения
    int rCon[10];
    unsigned char roundKey[16*11];///<Расширение ключа
    void subBytes(unsigned char* input);///<Замена байтов через S-box
    void subBytes(unsigned char* input, int size);
    void invSubBytes(unsigned char* input);

    void shiftRows(unsigned char* input, int move);///<Смещение строки блока
    void shiftRows(unsigned char* input);
    void invShiftRows(unsigned char* input);

    void mixColumns(unsigned char* input);///<Объединение столбцов блока с помощью модульного перемножения
    void invMixColumns(unsigned char* input);

    void shiftRoundKey(unsigned char* key);///<Генерирует расширенный ключ
    void addRoundKey(unsigned char* input, int round);///<Добавляет раунд расширенного ключа
public:
    using Method::Method;
    AES();

    void encrypt(unsigned char* output, unsigned char* input, unsigned char* key);
    void decrypt(unsigned char* output, unsigned char* input, unsigned char* key);
};///\}