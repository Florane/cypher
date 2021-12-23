# class `Mode` 

Шаблон режима шифрования

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Mode`](#classMode_1aec022ce25b9e21bcfe41ce53b8fd6f8d)`(int _size,`[`Method`](docs/api-Method.md#classMethod)` * _method)` | 
`public inline  `[`Mode`](#classMode_1a36a0f0ae2e6449bbcc35ebb81899008b)`(`[`Method`](docs/api-Method.md#classMethod)` * _method)` | 
`public inline  `[`Mode`](#classMode_1a098246baedeee64fa0ed3b53547cf55f)`()` | 
`public inline virtual void `[`encrypt`](#classMode_1aad3ae0fc41b40d5138a23e711d4b7491)`(std::ostream & output,std::istream & input,std::string key)` | Зашифровать входной поток
`public virtual void `[`decrypt`](#classMode_1a7b5ecfb74c564969c3141f7a2cbe81dd)`(std::ostream & output,std::istream & input,std::string key)` | Расшифровать входной поток
`public inline virtual void `[`decrypt`](#classMode_1a2ee745186aa5e4cb2b51d2b106b0ce7d)`(std::ostream & output,std::istream & input,size_t blocks,std::string key)` | Расшифровать часть входного потока
`protected const int `[`size`](#classMode_1a5f5bff10c221ba9fa57f3e9a654e6740) | Размер блока
`protected `[`Method`](docs/api-Method.md#classMethod)` * `[`method`](#classMode_1a7ed18cc875f58fc12649f295bc9608e8) | Метод шифрования

## Members

#### `public inline  `[`Mode`](#classMode_1aec022ce25b9e21bcfe41ce53b8fd6f8d)`(int _size,`[`Method`](docs/api-Method.md#classMethod)` * _method)` 

#### `public inline  `[`Mode`](#classMode_1a36a0f0ae2e6449bbcc35ebb81899008b)`(`[`Method`](docs/api-Method.md#classMethod)` * _method)` 

#### `public inline  `[`Mode`](#classMode_1a098246baedeee64fa0ed3b53547cf55f)`()` 

#### `public inline virtual void `[`encrypt`](#classMode_1aad3ae0fc41b40d5138a23e711d4b7491)`(std::ostream & output,std::istream & input,std::string key)` 

Зашифровать входной поток

#### Parameters
* `output` Выходной поток 

* `input` Входной поток 

* `key` Ключ

#### `public virtual void `[`decrypt`](#classMode_1a7b5ecfb74c564969c3141f7a2cbe81dd)`(std::ostream & output,std::istream & input,std::string key)` 

Расшифровать входной поток

#### Parameters
* `output` Выходной поток 

* `input` Входной поток 

* `key` Ключ

#### `public inline virtual void `[`decrypt`](#classMode_1a2ee745186aa5e4cb2b51d2b106b0ce7d)`(std::ostream & output,std::istream & input,size_t blocks,std::string key)` 

Расшифровать часть входного потока

#### Parameters
* `output` Выходной поток 

* `input` Входной поток 

* `key` Ключ

#### `protected const int `[`size`](#classMode_1a5f5bff10c221ba9fa57f3e9a654e6740) 

Размер блока

#### `protected `[`Method`](docs/api-Method.md#classMethod)` * `[`method`](#classMode_1a7ed18cc875f58fc12649f295bc9608e8) 

Метод шифрования

