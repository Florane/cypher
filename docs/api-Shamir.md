# class `Shamir` 

Имплементация разделения ключа Шамира

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Shamir`](#classShamir_1a6f4e66672289893f1db66f90df9d7323)`(int r,int q)` | 
`public inline  `[`Shamir`](#classShamir_1ac0c307e4eaa164b18710c689fac31fc1)`()` | 
`public void `[`split`](#classShamir_1a74fdde5cb5e16425c03201dfc4d176d8)`(std::string & key,std::string * piecestreams)` | Разделить ключ
`public void `[`glue`](#classShamir_1a5c130793e9286d8775938c6d27b4a7cc)`(std::string * shares,int * parts,std::string & key)` | Восстановить ключ
`public inline int `[`producedCount`](#classShamir_1a8aab0ab27eb1cf4d16d4a6fe732fd4cb)`()` | Вернуть produced.
`public inline int `[`requiredCount`](#classShamir_1aa3a435acebcbe26433a3ff475856b802)`()` | Вернуть required.
`private const int `[`required`](#classShamir_1ab819adf385fde8128890294a9644e593) | <Кол-во частей, нужных для восстановления ключа
`private const int `[`produced`](#classShamir_1a61ce71138a2aa8a2845a2097f1c95575) | Кол-во созданых частей
`private const `[`InfInt`](docs/api-InfInt.md#classInfInt)` `[`prime`](#classShamir_1a0f5603f5a61202866a689e2541455654) | Простое число, близкое к сложности шифрования
`private `[`InfInt`](docs/api-InfInt.md#classInfInt)` `[`pow`](#classShamir_1a113139de8a7609e53bdf3eca40ddddb5)`(int a,int b)` | Степень a^b.
`private `[`InfInt`](docs/api-InfInt.md#classInfInt)` `[`bitString`](#classShamir_1a8816f4125eaff4d759ffe04d1af466b9)`(std::string & str)` | Вернуть уникальное число на основе порядковых значений в строке
`private std::string `[`toBitString`](#classShamir_1a276ee62e0ab3fa5b56aae428537cb9dd)`(`[`InfInt`](docs/api-InfInt.md#classInfInt)` i)` | Вернуть строку на основе его уникального числа
`private `[`InfInt`](docs/api-InfInt.md#classInfInt)` `[`getShare`](#classShamir_1a9ac3b28952cdad61ff9c7996cc431cbf)`()` | Вернуть уникальное 4-байтное число

## Members

#### `public inline  `[`Shamir`](#classShamir_1a6f4e66672289893f1db66f90df9d7323)`(int r,int q)` 

#### `public inline  `[`Shamir`](#classShamir_1ac0c307e4eaa164b18710c689fac31fc1)`()` 

#### `public void `[`split`](#classShamir_1a74fdde5cb5e16425c03201dfc4d176d8)`(std::string & key,std::string * piecestreams)` 

Разделить ключ

Разделить ключ на несколько частей 
#### Parameters
* `key` ключ 

* `piecestreams` массив строк для хранения частей размера required

#### `public void `[`glue`](#classShamir_1a5c130793e9286d8775938c6d27b4a7cc)`(std::string * shares,int * parts,std::string & key)` 

Восстановить ключ

Восстановить ключ методом интерполяции Лагранжа на основе частей ключа 
#### Parameters
* `shares` части ключа 

* `parts` значения x, на которых были взяты части ключа 

* `key` ключ

#### `public inline int `[`producedCount`](#classShamir_1a8aab0ab27eb1cf4d16d4a6fe732fd4cb)`()` 

Вернуть produced.

#### `public inline int `[`requiredCount`](#classShamir_1aa3a435acebcbe26433a3ff475856b802)`()` 

Вернуть required.

#### `private const int `[`required`](#classShamir_1ab819adf385fde8128890294a9644e593) 

<Кол-во частей, нужных для восстановления ключа

#### `private const int `[`produced`](#classShamir_1a61ce71138a2aa8a2845a2097f1c95575) 

Кол-во созданых частей

#### `private const `[`InfInt`](docs/api-InfInt.md#classInfInt)` `[`prime`](#classShamir_1a0f5603f5a61202866a689e2541455654) 

Простое число, близкое к сложности шифрования

#### `private `[`InfInt`](docs/api-InfInt.md#classInfInt)` `[`pow`](#classShamir_1a113139de8a7609e53bdf3eca40ddddb5)`(int a,int b)` 

Степень a^b.

#### `private `[`InfInt`](docs/api-InfInt.md#classInfInt)` `[`bitString`](#classShamir_1a8816f4125eaff4d759ffe04d1af466b9)`(std::string & str)` 

Вернуть уникальное число на основе порядковых значений в строке

#### `private std::string `[`toBitString`](#classShamir_1a276ee62e0ab3fa5b56aae428537cb9dd)`(`[`InfInt`](docs/api-InfInt.md#classInfInt)` i)` 

Вернуть строку на основе его уникального числа

#### `private `[`InfInt`](docs/api-InfInt.md#classInfInt)` `[`getShare`](#classShamir_1a9ac3b28952cdad61ff9c7996cc431cbf)`()` 

Вернуть уникальное 4-байтное число

