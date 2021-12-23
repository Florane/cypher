# class `Method` 

Шаблон для создания методов шифрования

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Method`](#classMethod_1a57b28296f89146d2ab86ef6e25713d7c)`(int _size)` | 
`public inline  `[`Method`](#classMethod_1ab48717dc68d3c057b65574a539a480f7)`()` | 
`public virtual unsigned char * `[`expandKey`](#classMethod_1a2c4a7ffcc5c2ab0558b07e210a202d5a)`(const char * key)` | Увеличить ключ до 16 символов
`public virtual void `[`encrypt`](#classMethod_1a99e8f3d2b1c892ed4a0d08766479ab1a)`(unsigned char * output,unsigned char * input,unsigned char * key)` | Зашифровать блок
`public virtual void `[`decrypt`](#classMethod_1af861d97a37de1ca7c8f9b0de1112555e)`(unsigned char * output,unsigned char * input,unsigned char * key)` | Расшифровать блок
`protected const int `[`blockSize`](#classMethod_1a8cd9c2ee060a5bc9a466010a1771ebcc) | Размер шифруемого блока

## Members

#### `public inline  `[`Method`](#classMethod_1a57b28296f89146d2ab86ef6e25713d7c)`(int _size)` 

#### `public inline  `[`Method`](#classMethod_1ab48717dc68d3c057b65574a539a480f7)`()` 

#### `public virtual unsigned char * `[`expandKey`](#classMethod_1a2c4a7ffcc5c2ab0558b07e210a202d5a)`(const char * key)` 

Увеличить ключ до 16 символов

#### Parameters
* `key` оригинальный ключ 

#### Returns
расширенный ключ

#### `public virtual void `[`encrypt`](#classMethod_1a99e8f3d2b1c892ed4a0d08766479ab1a)`(unsigned char * output,unsigned char * input,unsigned char * key)` 

Зашифровать блок

#### Parameters
* `output` Выходной блок 

* `input` Входной блок 

* `key` 16-символьный Ключ

#### `public virtual void `[`decrypt`](#classMethod_1af861d97a37de1ca7c8f9b0de1112555e)`(unsigned char * output,unsigned char * input,unsigned char * key)` 

Расшифровать блок

#### Parameters
* `output` Выходной блок 

* `input` Входной блок 

* `key` 16-символьный Ключ

#### `protected const int `[`blockSize`](#classMethod_1a8cd9c2ee060a5bc9a466010a1771ebcc) 

Размер шифруемого блока

