# class `AES` 

```
class AES
  : public Method
```  

Имплементация AES_128.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`AES`](#classAES_1aead4c030c140418b2d2330d646f3d87f)`()` | 
`public virtual void `[`encrypt`](#classAES_1a3069f0cf28cc3a129e4af2be645698cf)`(unsigned char * output,unsigned char * input,unsigned char * key)` | Зашифровать блок
`public virtual void `[`decrypt`](#classAES_1afad653cc093da53691eb533a6572d0dc)`(unsigned char * output,unsigned char * input,unsigned char * key)` | Расшифровать блок
`public inline  `[`Method`](#classAES_1a57b28296f89146d2ab86ef6e25713d7c)`(int _size)` | 
`public inline  `[`Method`](#classAES_1ab48717dc68d3c057b65574a539a480f7)`()` | 
`private int `[`sBox`](#classAES_1a1c6df1c570c2c6ad3c16a6cca9f0b037) | Таблица замены байтов
`private int `[`invSBox`](#classAES_1a80b5df8a733fd513e2a5438374dc2f56) | 
`private int `[`mult2`](#classAES_1a14b6eacac54155e7def1c987548df9ca) | 
`private int `[`mult3`](#classAES_1a509da076f1eb69214f5f8420866f43ce) | 
`private int `[`mult9`](#classAES_1ad629efa792b0acda34023bf2cb48fec5) | 
`private int `[`mult11`](#classAES_1a5c176af44cd83f8b600ccae68af03dc9) | 
`private int `[`mult13`](#classAES_1aa8fcc4f324ccc3bad85ebad90bfe1dcb) | 
`private int `[`mult14`](#classAES_1a6e7a5d9d90c9960c6436f0ac064a6e68) | Таблицы модульного умножения
`private int `[`rCon`](#classAES_1a4eec346c5097c36d946681109b3431e6) | 
`private unsigned char `[`roundKey`](#classAES_1a039e1a754eaa976bb5d2947583dd77a6) | Расширение ключа
`private void `[`subBytes`](#classAES_1a73b3c3f49a65b247eef14bacbe2d4406)`(unsigned char * input)` | Замена байтов через S-box.
`private void `[`subBytes`](#classAES_1a03dbb860c6eabc2814af214f91198887)`(unsigned char * input,int size)` | 
`private void `[`invSubBytes`](#classAES_1a2c2848b0933aac48ea0cdbefa69ed0f8)`(unsigned char * input)` | 
`private void `[`shiftRows`](#classAES_1ae8e214017562fa784eb1225876939187)`(unsigned char * input,int move)` | Смещение строки блока
`private void `[`shiftRows`](#classAES_1a81f7206abd213e0d6285dbcef32e8fb8)`(unsigned char * input)` | 
`private void `[`invShiftRows`](#classAES_1a4c21945202b01383baee67e65ad8f939)`(unsigned char * input)` | 
`private void `[`mixColumns`](#classAES_1a0444cedabdb794880b63d67bd39b801c)`(unsigned char * input)` | Объединение столбцов блока с помощью модульного перемножения
`private void `[`invMixColumns`](#classAES_1a1ee950b47cecdf7163d7ac83844d8a95)`(unsigned char * input)` | 
`private void `[`shiftRoundKey`](#classAES_1afe689ed605209e989b56e885ee05e150)`(unsigned char * key)` | Генерирует расширенный ключ
`private void `[`addRoundKey`](#classAES_1a7f787958c93b9de963255d9e4871563b)`(unsigned char * input,int round)` | Добавляет раунд расширенного ключа

## Members

#### `public  `[`AES`](#classAES_1aead4c030c140418b2d2330d646f3d87f)`()` 

#### `public virtual void `[`encrypt`](#classAES_1a3069f0cf28cc3a129e4af2be645698cf)`(unsigned char * output,unsigned char * input,unsigned char * key)` 

Зашифровать блок

#### Parameters
* `output` Выходной блок 

* `input` Входной блок 

* `key` 16-символьный Ключ

#### `public virtual void `[`decrypt`](#classAES_1afad653cc093da53691eb533a6572d0dc)`(unsigned char * output,unsigned char * input,unsigned char * key)` 

Расшифровать блок

#### Parameters
* `output` Выходной блок 

* `input` Входной блок 

* `key` 16-символьный Ключ

#### `public inline  `[`Method`](#classAES_1a57b28296f89146d2ab86ef6e25713d7c)`(int _size)` 

#### `public inline  `[`Method`](#classAES_1ab48717dc68d3c057b65574a539a480f7)`()` 

#### `private int `[`sBox`](#classAES_1a1c6df1c570c2c6ad3c16a6cca9f0b037) 

Таблица замены байтов

#### `private int `[`invSBox`](#classAES_1a80b5df8a733fd513e2a5438374dc2f56) 

#### `private int `[`mult2`](#classAES_1a14b6eacac54155e7def1c987548df9ca) 

#### `private int `[`mult3`](#classAES_1a509da076f1eb69214f5f8420866f43ce) 

#### `private int `[`mult9`](#classAES_1ad629efa792b0acda34023bf2cb48fec5) 

#### `private int `[`mult11`](#classAES_1a5c176af44cd83f8b600ccae68af03dc9) 

#### `private int `[`mult13`](#classAES_1aa8fcc4f324ccc3bad85ebad90bfe1dcb) 

#### `private int `[`mult14`](#classAES_1a6e7a5d9d90c9960c6436f0ac064a6e68) 

Таблицы модульного умножения

#### `private int `[`rCon`](#classAES_1a4eec346c5097c36d946681109b3431e6) 

#### `private unsigned char `[`roundKey`](#classAES_1a039e1a754eaa976bb5d2947583dd77a6) 

Расширение ключа

#### `private void `[`subBytes`](#classAES_1a73b3c3f49a65b247eef14bacbe2d4406)`(unsigned char * input)` 

Замена байтов через S-box.

#### `private void `[`subBytes`](#classAES_1a03dbb860c6eabc2814af214f91198887)`(unsigned char * input,int size)` 

#### `private void `[`invSubBytes`](#classAES_1a2c2848b0933aac48ea0cdbefa69ed0f8)`(unsigned char * input)` 

#### `private void `[`shiftRows`](#classAES_1ae8e214017562fa784eb1225876939187)`(unsigned char * input,int move)` 

Смещение строки блока

#### `private void `[`shiftRows`](#classAES_1a81f7206abd213e0d6285dbcef32e8fb8)`(unsigned char * input)` 

#### `private void `[`invShiftRows`](#classAES_1a4c21945202b01383baee67e65ad8f939)`(unsigned char * input)` 

#### `private void `[`mixColumns`](#classAES_1a0444cedabdb794880b63d67bd39b801c)`(unsigned char * input)` 

Объединение столбцов блока с помощью модульного перемножения

#### `private void `[`invMixColumns`](#classAES_1a1ee950b47cecdf7163d7ac83844d8a95)`(unsigned char * input)` 

#### `private void `[`shiftRoundKey`](#classAES_1afe689ed605209e989b56e885ee05e150)`(unsigned char * key)` 

Генерирует расширенный ключ

#### `private void `[`addRoundKey`](#classAES_1a7f787958c93b9de963255d9e4871563b)`(unsigned char * input,int round)` 

Добавляет раунд расширенного ключа

