#pragma once

/**
 * \defgroup Method_template
 * \{
 */
///Шаблон для создания методов шифрования
class Method
{
protected:
    const int blockSize; ///< Размер шифруемого блока
public:
    Method(int _size) : blockSize(_size) {}
    Method() : Method(16) {};

    ///Увеличить ключ до 16 символов
    /**
     * \param key оригинальный ключ
     * \return расширенный ключ
     */
    virtual unsigned char* expandKey(const char* key);
    ///Зашифровать блок
    /**
     * \param output Выходной блок
     * \param input Входной блок
     * \param key 16-символьный Ключ
     */
    virtual void encrypt(unsigned char* output, unsigned char* input, unsigned char* key);
    ///Расшифровать блок
    /**
     * \param output Выходной блок
     * \param input Входной блок
     * \param key 16-символьный Ключ
     */
    virtual void decrypt(unsigned char* output, unsigned char* input, unsigned char* key);
};///\}
